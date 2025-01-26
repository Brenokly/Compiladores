%{
//----------------------------------------------
// Includes
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cctype>    
#include <unordered_map>
#include <stack>
#include <functional>
using namespace std;
//----------------------------------------------
// Definição da estrutura Error
struct Error
{
    int line;
    string message;
    string suggestion;
};

// Definição da estrutura de Classes
struct Classes
{
  string name;
  set<string> tipos;
  unordered_map<string, set<string>> propriedades;
};

// Variáveis Externas
extern int yylineno;
extern vector<Error> errors;
extern vector<Classes> classes;

// Variáveis Globais que auxiliam na análise
set<string> t;                          // Serve para guarda os possíveis tipos de uma Classe
set<string> theLastProp;                // Serve para guardar as propriedades de um fechamento
set<string> props;                      // Serve para identificar se todas as classes foram fechadas
bool isFechamento = false;              // Serve para identificar se a estrutura é de fechamento
bool fechada = false;                   // Auxilia a variável isFechamento!
bool isClass = false;                   // Serve para identificar se a estrutura é de classe
stack<string> properties;               // Serve para guardar as propriedades de uma classe
stack<string> posproperties;            // Serve para guardar o tipo de propriedade que aparecem em suas ordens
unordered_map<string, set<string>> p    // Tipo de cada propriedade
{
    {"Data Property", {}},
    {"Object Property", {}},
    {"Nenhum Tipo", {}}
};

// Funções Obrigatórias do Bison e Flex
int yylex(void);
int yyparse(void);
void yyerror(const char *msg);

// Funções auxiliares de validação
bool is_valid_xsd_type(const std::string& datatype);
bool is_valid_owl_type(const std::string& datatype);
bool is_valid_rdf_type(const std::string& datatype);
bool is_valid_rdfs_type(const std::string& datatype);
bool is_namespace_valid(const std::string& space);
bool is_int_type(const std::string& space);
bool is_decimal_type(const std::string& space);
void class_declaration(const char * name);
void tag_class_der(const char * name);
void expression_der(const char * name);
const char * namespace_datatype_der(const char * name, const char * datatype);
%}

%union {
    double numD;
    int numI;
    const char * str;
}

%token <numD> TAG_NUMD
%token <numI> TAG_NUMI
%token <str> TAG_CLASS TAG_INDIVIDUOS TAG_NAMESPACE TAG_PROPERTY TAG_DATATYPE
%token <str> ONLY SOME ALL VALUE MIN MAX EXACTLY THAT NOT AND OR CLASS EQUIVALENTTO INDIVIDUALS SUBCLASSOF DISJOINTCLASSES DISJOINTWITH ERROR
%token <str> TAG_MENORIGUAL TAG_MAIORIGUAL TAG_MENOR TAG_MAIOR TAG_ABRECOLCHETE TAG_FECHACOLCHETE TAG_ABRECHAVE TAG_FECHACHAVE TAG_ABREPARANTESIS TAG_FECHAPARANTESIS TAG_VIRGULA TAG_DOISPONTOS

%left AND OR
%left TAG_VIRGULA
%left TAG_FECHAPARANTESIS

%start ontology

%type <str> class_declaration
%type <str> op_rel
%type <str> op_cardinality
%type <str> namespace_datatype
%type <str> class_op
%type <str> list_class
%type <str> op_quantifier
%type <str> corp_expre1

%%
// ontology: Dentro de uma ontologia possuí declarações
ontology:
    declarations
    | error { yyerror("Erro de Sintaxe.#Esperava uma declaração de classe começando com 'Class:'!"); YYABORT; }
;

// declarations: Vira declarações de classes
declarations:
    class_declaration
    | class_declaration declarations
;

// class_declaration: Defini a estrutura base de uma classe
class_declaration:
    CLASS TAG_CLASS class_type class_body   { class_declaration($2); }
    | CLASS error                           { yyerror("Erro de Sintaxe.#Esperava um nome de classe após a palavra-chave 'class:'"); }                      
;

// class_type: Define como é a estrutura dos dois tipos de classes existentes
class_type:
    primitive_class                         { t.insert("Primitiva"); }
    | defined_class optional_subclass       { t.insert("Definida"); }
    | error                                 { yyerror("Erro de Sintaxe.#Esperava uma classe Primitiva ou Definida (SubClassOf ou EquivalentTo)"); }
    | primitive_class error                 { yyerror("Erro semântico.#Uma classe primitiva 'SubClassOf' não pode ser seguida por 'EquivalentTo'"); }
;

// primitive_class: Define a estrutura obrigatória de uma classe primitiva
primitive_class:
    SUBCLASSOF expression_list
    | SUBCLASSOF
;

// primitive_class: Define a estrutura obrigatória de uma classe definida
defined_class:
    EQUIVALENTTO pos_defined_class
;

// pos_defined_class: Define o que pode vir após EQUIVALENTTO:
pos_defined_class:
    expression_list
    | TAG_ABRECHAVE individuals_list TAG_FECHACHAVE { t.insert("Enumerada"); }

// optional_subclass: Define a estrutura opcional de uma classe definida
optional_subclass:
    SUBCLASSOF expression_list
    | SUBCLASSOF
    |
;

// expression_list: Define a estrutura de uma expressão que pode ter vírgulas
expression_list:
    TAG_CLASS
    | TAG_CLASS expression_format
    | expression
    | list_expression
    | pos_class { t.insert("Coberta"); }
;

// list_expression: Define a estrutura de uma lista de expressões
list_expression:
    expression simples_expression_no_parent
;

// Descreve a estrutura de uma classe coberta (CLASS OPERADOR CLASS ...)
pos_class:
    TAG_CLASS op_logic TAG_CLASS additional_classes
;

// Completa a estrutura de uma classe coberta (CLASS OPERADOR CLASS ...)
additional_classes:
    op_logic TAG_CLASS additional_classes
    |
;

// Expression_format: define a estrutura de possíveis
expression_format:
    simple_expression
    | complex_expression
;

// Simple_expression: Define a estrutura de uma expressão simples
simple_expression:
    separador expression simples_expression_no_parent
    | separador expression
    | separador error { yyerror("Erro de Sintaxe.#Esperava algo após uma vírgula ou operador lógico!"); }
;

simples_expression_no_parent:
    separador expression
    | separador expression simples_expression_no_parent
    | separador error  { yyerror("Erro de Sintaxe.#Esperava algo após uma vírgula ou operador lógico!"); }
    | expression error { yyerror("Erro de Sintaxe.#Esperava um separador [',' ou 'and' ou 'or'] entre as expressões."); }
;

// Complex_expression: Define a estrutura de uma expressão complexa
complex_expression:
    separador TAG_ABREPARANTESIS elements additional_expressions TAG_FECHAPARANTESIS additional_expressions 
    | separador TAG_ABREPARANTESIS elements additional_expressions TAG_FECHAPARANTESIS 
    | separador TAG_ABREPARANTESIS element TAG_FECHAPARANTESIS additional_expressions 
    | separador TAG_ABREPARANTESIS element TAG_FECHAPARANTESIS
    | separador TAG_ABREPARANTESIS elements error   { yyerror("Erro de Sintaxe.#Esperava um fechamento de parênteses!"); }
    | TAG_ABREPARANTESIS error                      { yyerror("Erro de Sintaxe.#Esperava um separador [',' ou 'and' ou 'or'] entre as expressões."); YYABORT; }
;

// additional_expressions: Define a estrutura de expressões adicionais (Quando precisa de uma estrutura com muitas expressões)
additional_expressions:
    additional_expressions_parent
    | additional_expressions_no_parent
;

additional_expressions_parent:
    separador TAG_ABREPARANTESIS elements TAG_FECHAPARANTESIS additional_expressions
    | separador TAG_ABREPARANTESIS elements TAG_FECHAPARANTESIS
    | separador error                               { yyerror("Erro de Sintaxe.#Esperava algo após uma vírgula ou operador lógico!"); }
    | separador TAG_ABREPARANTESIS elements error   { yyerror("Erro de Sintaxe.#Esperava um fechamento de parênteses!"); }
    | TAG_ABREPARANTESIS error                      { yyerror("Erro de Sintaxe.#Esperava um separador [',' ou 'and' ou 'or'] entre as expressões."); }
;

additional_expressions_no_parent:
    separador element additional_expressions
    | separador element
    | element error                                 { yyerror("Erro de Sintaxe.#Esperava um separador [',' ou 'and' ou 'or'] entre as expressões."); }
;

element:
    expression
;

elements:
    expression
    | TAG_ABREPARANTESIS expression TAG_FECHAPARANTESIS
    | TAG_ABREPARANTESIS expression error               { yyerror("Erro de Sintaxe.#Esperava um fechamento de parênteses!"); }
;

// Expression: Define a estrutura de uma expressão de como se monta expressões
expression:
    TAG_PROPERTY pos_property                           { properties.push(std::string($1)); }
    | TAG_PROPERTY ONLY class_op                        { expression_der($1); }
    | TAG_PROPERTY error                                { yyerror("Erro de Sintaxe.#Esperava um quantificador, cardinalidade ou 'Value' após uma propriedade!"); }
;

pos_property:
    op_quantifier corp_expre1                           { if (strcmp($1,"some") == 0 && isClass) { props.insert(std::string($2)); } }
    | op_cardinality corp_expre2
    | VALUE pos_value                                   { while (!properties.empty()) { properties.pop();} }
;

// Corp_expre1: Define o que pode vir após um quantificador
corp_expre1:
    TAG_CLASS                                           { $$ = $1; isClass = true; posproperties.push("Object Property"); }
    | type_expre                                        { posproperties.push("Data Property"); }
    | TAG_ABREPARANTESIS expression TAG_FECHAPARANTESIS { t.insert("Aninhada"); }
    | list                                              { posproperties.push("Object Property"); }
    | error                                             { yyerror("Erro de Sintaxe#Após um quantificador, esperava-se uma classe, um tipo de dado ou mais expressões."); }
;

// Corp_expre2: Define o que pode vir após uma cardinalidade
corp_expre2:
    TAG_NUMD sub_corp
    | TAG_NUMI sub_corp
;

sub_corp:
    object_property                                     { posproperties.push("Object Property"); }
    | type_expre                                        { posproperties.push("Data Property"); }
    | error                                             { yyerror("Erro de Sintaxe#Após uma cardinalidade, esperava-se uma Class ou um Tipo de dado."); }
;

object_property:
    TAG_CLASS
    | list
;

// Separador: Define a estrutura de um separador que pode ser uma vírgula ou um operador lógico
separador:
    TAG_VIRGULA
    | op_logic
;

// Pos_value: Define a estrutura do que pode vim após a palavra-chave 'value'
pos_value:
    TAG_NUMI
    | TAG_NUMD
    | TAG_INDIVIDUOS
;

// Type_expre: Define a estrutura de um tipo de expressão que pode ser um namespace e um datatype [restrição de dados]
type_expre:
    namespace_datatype
    | namespace_datatype TAG_ABRECOLCHETE op_rel TAG_NUMI TAG_FECHACOLCHETE {
        if (!is_int_type(std::string($1))) {
            char error_message[512];
            snprintf(error_message, 512, "Erro semântico.#O tipo de dado [%s] não é compatível com o dado passado.", $1);
            yyerror(error_message);
        } 
    }
    | namespace_datatype TAG_ABRECOLCHETE op_rel TAG_NUMD TAG_FECHACOLCHETE {
        if (!is_decimal_type(std::string($1))) {
            char error_message[512];
            snprintf(error_message, 512, "Erro semântico.#O tipo de dado [%s] não é compatível com o dado passado.", $1);
            yyerror(error_message);
        } 
    }
    | namespace_datatype TAG_ABRECOLCHETE error                 { yyerror("Erro de Sintaxe.#Esperava um operador de relação após o tipo de dado"); }
    | namespace_datatype TAG_ABRECOLCHETE op_rel error          { yyerror("Erro de Sintaxe.#Esperava um número após o operador de relação"); }
    | namespace_datatype TAG_ABRECOLCHETE op_rel TAG_NUMI error { yyerror("Erro de Sintaxe.#Esperava um fechamento de colchetes"); }
    | namespace_datatype TAG_ABRECOLCHETE op_rel TAG_NUMD error { yyerror("Erro de Sintaxe.#Esperava um fechamento de colchetes"); }
;

class_body:
    disjointclasses_section
    | individuals_section
    | disjointclasses_section individuals_section
    | individuals_section disjointclasses_section               { yyerror("Erro de semântica.#A seção 'disjointclasses:' deve vir antes da seção 'individuals:'"); }
    |
;

disjointclasses_section:
    DISJOINTCLASSES class_list
    | DISJOINTWITH class_list
    | DISJOINTCLASSES error                                     { yyerror("Erro de Sintaxe.#Esperava uma lista de classes após a palavra-chave 'disjointclasses:'");}
    | DISJOINTWITH error                                        { yyerror("Erro de Sintaxe.#Esperava uma lista de classes após a palavra-chave 'disjointwith:'");}
;

individuals_section:
    INDIVIDUALS individuals_list
    | INDIVIDUALS error                                         { yyerror("Erro de Sintaxe.#Esperava uma lista de indivíduos após a palavra-chave 'individuals:'");}
;

individuals_list:
   TAG_INDIVIDUOS TAG_VIRGULA individuals_list
   | TAG_INDIVIDUOS
   | TAG_INDIVIDUOS TAG_VIRGULA error                           { yyerror("Erro de Sintaxe.#Esperava algo após a vírgula");}
;

// Class_list: Classes separadas por vírgula ou entre parênteses e separadas por vírgula
class_list:
    class_v
    | TAG_ABREPARANTESIS class_v TAG_FECHAPARANTESIS
    | TAG_ABREPARANTESIS class_v error                          { yyerror("Erro de Sintaxe.#Esperava um fechamento de parênteses"); }
;

// Class_v: Classes separadas por vírgula
class_v:
    TAG_CLASS TAG_VIRGULA class_v
    | TAG_CLASS
    | TAG_CLASS TAG_VIRGULA error                               { yyerror("Erro de Sintaxe.#Esperava algo após a vírgula"); }
;

// Class_op: Classes entre parênteses separadas por operadores lógicos (fechamento)
class_op: 
    TAG_ABREPARANTESIS class_l TAG_FECHAPARANTESIS  
    | TAG_ABREPARANTESIS class_l error                      { yyerror("Erro de Sintaxe.#Esperava um fechamento de parênteses"); }
;

// Class_l: Classes separadas por operadores lógicos (fechamento)
class_l:
    TAG_CLASS op_logic class_l                                  { tag_class_der($1); }
    | TAG_CLASS                                                 { tag_class_der($1); }
    | TAG_CLASS op_logic error                                  { yyerror("Erro de Sintaxe.#Esperava algo após o operador lógico"); }
    | TAG_CLASS TAG_CLASS error                                 { yyerror("Erro de Sintaxe.#Esperava um operador lógico entre as classes");}
;

// Class_op: Classes entre parênteses separadas por operadores lógicos
list: 
    TAG_ABREPARANTESIS list_class TAG_FECHAPARANTESIS  
    | TAG_ABREPARANTESIS list_class error                      { yyerror("Erro de Sintaxe.#Esperava um fechamento de parênteses"); }
;

// Class_l: Classes separadas por operadores lógicos
list_class:
    TAG_CLASS op_logic list_class                               { $$ = $1; }
    | TAG_CLASS                                                 { $$ = $1; }                                                
    | TAG_CLASS op_logic error                                  { yyerror("Erro de Sintaxe.#Esperava algo após o operador lógico"); }
    | TAG_CLASS TAG_CLASS error                                 { yyerror("Erro de Sintaxe.#Esperava um operador lógico entre as classes");}
;

// Op_quantifier: Quantificadores
op_quantifier:
    SOME { $$ = "some"; }
    | ALL { $$ = "all"; }
    | ONLY { $$ = "only"; }
;

// Op_logic: Operadores lógicos
op_logic:
    AND
    | OR
;

// Op_rel: Operadores de relação
op_rel:
    TAG_MAIOR           { $$ = ">"; }
    | TAG_MAIORIGUAL    { $$ = ">="; }
    | TAG_MENOR         { $$ = "<"; }
    | TAG_MENORIGUAL    { $$ = "<="; }
;

// Op_cardinality: Quantificador de cardinalidade
op_cardinality:
    MIN
    | MAX
    | EXACTLY
;

// Namespace_datatype: Namespace e datatype cada um correspondendo a um tipo válido
namespace_datatype:
    TAG_NAMESPACE TAG_DATATYPE { $$ = namespace_datatype_der($1, $2); }
;
%%

bool is_int_type(const std::string& space) {
    static const std::set<std::string> numeric_types = {
        "xsd:integer", "xsd:decimal", "xsd:double", "xsd:float", "xsd:long", "xsd:int", "xsd:short", "xsd:nonNegativeInteger",
        "xsd:positiveInteger", "xsd:negativeInteger", "xsd:nonPositiveInteger", "xsd:unsignedLong", "xsd:unsignedInt", "xsd:unsignedShort",
        "xsd:unsignedByte", "owl:real"
    };

    return numeric_types.count(space) > 0;
}

bool is_decimal_type(const std::string& space) {
    static const std::set<std::string> numeric_types = {
        "xsd:decimal", "xsd:double", "xsd:float", "owl:real"
    };

    return numeric_types.count(space) > 0;
}

bool is_namespace_valid(const std::string& space) {
    static const std::set<std::string> xsd_types = {
        "xsd:", "owl:", "rdf:" , "rdfs:"
    };

    return xsd_types.count(space) > 0;
}

bool is_valid_xsd_type(const std::string& datatype) {
    static const std::set<std::string> xsd_types = {
        "anyURI", "base64Binary", "boolean", "byte", "dateTime", "dateTimeStamp", "decimal", "double", "float", "hexBinary", 
        "int", "integer", "language", "long", "Name", "NCName", "negativeInteger", "NMTOKEN", "nonNegativeInteger", "nonPositiveInteger", 
        "normalizedString", "positiveInteger", "short", "string", "token", "unsignedByte", "unsignedInt", "unsignedLong", "unsignedShort"
    };

    return xsd_types.count(datatype) > 0;
}

bool is_valid_owl_type(const std::string& datatype) {
    static const std::set<std::string> owl_types = {
        "rational", "real"
    };
    return owl_types.count(datatype) > 0;
}

bool is_valid_rdf_type(const std::string& datatype) {
    static const std::set<std::string> rdf_types = {
        "langString", "PlainLiteral", "XMLLiteral"
    };
    return rdf_types.count(datatype) > 0;
}

bool is_valid_rdfs_type(const std::string& datatype) {
    static const std::set<std::string> rdfs_types = {
        "Literal"
    };
    return rdfs_types.count(datatype) > 0;
}

void tag_class_der(const char * name) {
    if (!props.empty() && props.find(std::string(name)) != props.end()) {
        props.erase(std::string(name));
    } else {
        char error_message[512];
        snprintf(error_message, 512, "Erro Semântico.#A class [%s] não foi fechada corretamente nas propriedades.", name);
        yyerror(error_message);
    }
}

void expression_der(const char * name){
    properties.push(std::string(name));  
    theLastProp.insert(std::string(name)); 

    if (theLastProp.size() > 1) {
        yyerror("Erro Semântico.#Uma das propriedades não se encaixa com as outras.");
    } else {
        theLastProp.clear();
    }

    t.insert("Fechamento");

    posproperties.push("Object Property");

    if (!props.empty()) {
        yyerror("Erro semântico.#Erro ao tentar fechar o axioma, classes faltantes não foram fechadas.");
    }
}

void class_declaration(const char * name) {
    string theLastTP = "Nenhum Tipo";           // Por padrão é Nenhum Tipo
    while (!properties.empty()) {               // Lopping para adicionar as propriedades e seus tipos
        if (!posproperties.empty()) {
            theLastTP = posproperties.top();
            posproperties.pop();
        }
        p[theLastTP].insert(properties.top());
        properties.pop();
    }
    classes.push_back({string(name),t,p});

    // Limpa as variáveis globais
    while (!posproperties.empty()) {
        posproperties.pop();
    }
    while (!properties.empty()) {
        properties.pop();
    }
    p["Data Property"].clear();
    p["Object Property"].clear();
    p["Nenhum Tipo"].clear();
    isFechamento = false;
    fechada = false;
    isClass = false;
    theLastProp.clear();
    t.clear();
    props.clear();
}

const char * namespace_datatype_der(const char * name, const char * datatype) {
    char * result = (char *)malloc(256); 
    if (result == NULL) {
        yyerror("Erro de memória ao processar namespace e datatype");
    }

    if (!is_namespace_valid(string(name))) {
        free(result);
        char error_message[512];
        snprintf(error_message, sizeof(error_message), "Namespace inválido.#O namespace %s não é válido", name);
        yyerror(error_message);
        return nullptr;
    }

    // Mapear namespaces para funções de validação
    const unordered_map<string, function<bool(const string &)>> namespace_validators = {
        {"xsd:", is_valid_xsd_type},
        {"owl:", is_valid_owl_type},
        {"rdf:", is_valid_rdf_type},
        {"rdfs:", is_valid_rdfs_type},
    };

    auto it = namespace_validators.find(name);
    if (it != namespace_validators.end() && it->second(string(datatype))) {
        snprintf(result, 256, "%s%s", name, datatype);
        return result;
    }

    // Caso nenhum namespace válido tenha sido encontrado
    char error_message[512];
    snprintf(error_message, sizeof(error_message),"Tipo incompatível com o namespace.#O namespace %s não é compatível com o tipo %s", name, datatype);
    yyerror(error_message);
    // Parar a execução
    return datatype;
}

void yyerror(const char * msg) {
    // Encontra a posição do delimitador '#'
    const char *delimiter = strchr(msg, '#');

    // Declara variáveis para as mensagens
    std::string msg1, msg2;

    if (delimiter != nullptr) {
        // Se o delimitador foi encontrado, divide a mensagem
        msg1 = std::string(msg, delimiter); // Parte antes de '#'
        msg2 = std::string(delimiter + 1);  // Parte depois de '#'
    } else {
        // Se não houver delimitador, coloca a mensagem inteira em msg1
        msg1 = std::string(msg);
        msg2 = ""; // Deixa msg2 vazia
    }

    // Cria e armazena o erro
    Error err;
    err.line = yylineno;
    err.message = msg1;
    err.suggestion = msg2;

    errors.push_back(err);
}