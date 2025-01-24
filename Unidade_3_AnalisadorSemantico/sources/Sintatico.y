%{
// Includes
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <stack>
using namespace std;

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

// Variáveis que serão adicionadas no struct Classes ou Auxiliáres
set<string> t;                          // Tipos de uma class
set<string> props;                      // Serve para identificar se todas as classes foram fechadas
stack<string> properties;               // Serve para guardar as propriedades
stack<string> posproperties;            // Serve para guardar o tipo de propriedade que aparecem em suas ordens
unordered_map<string, set<string>> p    // Tipo de cada propriedade
{
    {"Data Property", {}},
    {"Object Property", {}}
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
%}

%union {
    double numD;
    int numI;
    const char * str;
}

%token <str> TAG_CLASS TAG_INDIVIDUOS TAG_NAMESPACE TAG_PROPERTY TAG_DATATYPE
%token <numD> TAG_NUMD
%token <numI> TAG_NUMI
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
%%
// ontology: Dentro de uma ontologia possuí declarações
ontology:
    declarations
;

// declarations: Vira declarações de classes
declarations:
    class_declaration
    | class_declaration declarations
;

// class_declaration: Defini a estrutura base de uma classe
class_declaration:
    CLASS TAG_CLASS class_type class_body { 
        string theLastTP;
        while (!properties.empty()) {
            if (!posproperties.empty()) {
                theLastTP = posproperties.top();
                posproperties.pop();
            }
            p[theLastTP].insert(properties.top());
            properties.pop();
        }

        classes.push_back({string($2),t,p}); 

        t.clear();
        p["Data Property"].clear();
        p["Object Property"].clear();
        while (!posproperties.empty()) {
            posproperties.pop();
        }
    }
    | CLASS error { 
        yyerror("Erro de Sintaxe.#Esperava um nome de classe após a palavra-chave 'class:'"); 
    }
;

// class_type: Define como é a estrutura dos dois tipos de classes existentes
class_type:
    primitive_class { t.insert("Primitiva"); }
    | defined_class optional_subclass { t.insert("Definida"); }
    | error { 
        yyerror("Erro de Sintaxe.#Esperava uma classe Primitiva ou Definida (SubClassOf ou EquivalentTo)"); 
    }
    | primitive_class error {
        yyerror("Erro semântico.#Uma classe primitiva 'SubClassOf' não pode ser seguida por 'EquivalentTo'"); 
    }
;

// primitive_class: Define a estrutura obrigatória de uma classe primitiva
primitive_class:
    SUBCLASSOF expression_list
    | SUBCLASSOF
;

// primitive_class: Define a estrutura obrigatória de uma classe definida
defined_class:
    EQUIVALENTTO expression_list
    | EQUIVALENTTO TAG_ABRECHAVE individuals_list TAG_FECHACHAVE { t.insert("Enumerada"); }
;

// optional_subclass: Define a estrutura opcional de uma classe definida
optional_subclass:
    SUBCLASSOF expression_list
    |
;

// expression_list: Define a estrutura de uma expressão que pode ter vírgulas
expression_list:
    TAG_CLASS
    | TAG_CLASS expression_format
    | expression
    | list_expression
    | pos_class { t.insert("coberta"); }
;

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
    | complex_expression { t.insert("aninhada"); }
;

// Simple_expression: Define a estrutura de uma expressão simples
simple_expression:
    separador expression simples_expression_no_parent
    | separador expression
    | separador error { 
        yyerror("Erro de Sintaxe.#Esperava algo após uma vírgula ou operador lógico!"); 
    }
;

simples_expression_no_parent:
    separador expression
    | separador expression simples_expression_no_parent
    | separador error { 
        yyerror("Erro de Sintaxe.#Esperava algo após uma vírgula ou operador lógico!"); 
    }
    | expression error {
        yyerror("Erro de Sintaxe.#Esperava um separador [',' ou 'and' ou 'or'] entre as expressões.");
    }
;

// Complex_expression: Define a estrutura de uma expressão complexa
complex_expression:
    separador TAG_ABREPARANTESIS elements additional_expressions TAG_FECHAPARANTESIS additional_expressions 
    | separador TAG_ABREPARANTESIS elements additional_expressions TAG_FECHAPARANTESIS 
    | separador TAG_ABREPARANTESIS element TAG_FECHAPARANTESIS additional_expressions 
    | separador TAG_ABREPARANTESIS element TAG_FECHAPARANTESIS
    | separador TAG_ABREPARANTESIS elements error { 
        yyerror("Erro de Sintaxe.#Esperava um fechamento de parênteses!"); 
    }
    | TAG_ABREPARANTESIS error {
        yyerror("Erro de Sintaxe.#Esperava um separador [',' ou 'and' ou 'or'] entre as expressões.");
    }
;

additional_expressions:
    additional_expressions_parent
    | additional_expressions_no_parent
;

additional_expressions_parent:
    separador TAG_ABREPARANTESIS elements TAG_FECHAPARANTESIS additional_expressions
    | separador TAG_ABREPARANTESIS elements TAG_FECHAPARANTESIS
    | separador error { 
        yyerror("Erro de Sintaxe.#Esperava algo após uma vírgula ou operador lógico!"); 
    }
    | separador TAG_ABREPARANTESIS elements error { 
        yyerror("Erro de Sintaxe.#Esperava um fechamento de parênteses!"); 
    }
    | TAG_ABREPARANTESIS error {
        yyerror("Erro de Sintaxe.#Esperava um separador [',' ou 'and' ou 'or'] entre as expressões.");
    }
;

additional_expressions_no_parent:
    separador element additional_expressions
    | separador element
    | element error {
        yyerror("Erro de Sintaxe.#Esperava um separador [',' ou 'and' ou 'or'] entre as expressões.");
    }
;

element:
    expression
;

elements:
    expression
    | TAG_ABREPARANTESIS expression TAG_FECHAPARANTESIS
    | TAG_ABREPARANTESIS expression error { 
        yyerror("Erro de Sintaxe.#Esperava um fechamento de parênteses!"); 
    }
;

// Expression: Define a estrutura de uma expressão de como se monta expressões
expression:
    TAG_PROPERTY pos_property { properties.push(std::string($1)); }
    | TAG_PROPERTY error { 
        yyerror("Erro de Sintaxe.#Esperava um quantificador, cardinalidade ou 'Value' após uma propriedade!"); 
    }
;

pos_property:
    op_quantifier corp_expre1
    | ONLY class_op {
        t.insert("Fechamento");
        if (!props.empty()) {
            yyerror("Erro semântico.#Erro ao tentar fechar o axioma, classes faltantes não foram fechadas.");
        }
    }
    | op_cardinality corp_expre2
    | VALUE pos_value
;

corp_expre1:
    TAG_CLASS { props.insert(std::string($1)); posproperties.push("Object Property"); }
    | type_expre { posproperties.push("Data Property"); }
    | TAG_ABREPARANTESIS expression TAG_FECHAPARANTESIS
    | error { yyerror("Erro de Sintaxe#Após um quantificador, esperava-se uma classe, um tipo de dado ou mais expressões."); }
;

corp_expre2:
    TAG_NUMD sub_corp
    | TAG_NUMI sub_corp
;

sub_corp:
    object_property { posproperties.push("Object Property"); }
    | type_expre { posproperties.push("Data Property"); }
    | error { yyerror("Erro de Sintaxe#Após uma cardinalidade, esperava-se uma Class ou um Tipo de dado."); }
;

object_property:
    TAG_CLASS
    | class_op
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

type_expre:
    namespace_datatype
    | namespace_datatype TAG_ABRECOLCHETE op_rel TAG_NUMI TAG_FECHACOLCHETE {
        if (!is_int_type(std::string($1))) {
            char error_message[512];
            snprintf(error_message, 512, "Erro semântico.#O tipo de dado [%s] não é compatível o dado passado.", $1);
            yyerror(error_message);
        } 
    }
    | namespace_datatype TAG_ABRECOLCHETE op_rel TAG_NUMD TAG_FECHACOLCHETE {
        if (!is_decimal_type(std::string($1))) {
            char error_message[512];
            snprintf(error_message, 512, "Erro semântico.#O tipo de dado [%s] não é compatível o dado passado.", $1);
            yyerror(error_message);
        } 
    }
    | namespace_datatype TAG_ABRECOLCHETE error { 
        yyerror("Erro de Sintaxe.#Esperava um operador de relação após o tipo de dado"); 
    }
    | namespace_datatype TAG_ABRECOLCHETE op_rel error { 
        yyerror("Erro de Sintaxe.#Esperava um número após o operador de relação"); 
    }
    | namespace_datatype TAG_ABRECOLCHETE op_rel TAG_NUMI error { 
        yyerror("Erro de Sintaxe.#Esperava um fechamento de colchetes"); 
    }
    | namespace_datatype TAG_ABRECOLCHETE op_rel TAG_NUMD error { 
        yyerror("Erro de Sintaxe.#Esperava um fechamento de colchetes"); 
    }
;

class_body:
    disjointclasses_section
    | individuals_section
    | disjointclasses_section individuals_section
    | individuals_section disjointclasses_section { 
        yyerror("Erro de semântica.#A seção 'disjointclasses:' deve vir antes da seção 'individuals:'"); 
    }
    |
;

disjointclasses_section:
    DISJOINTCLASSES class_list
    | DISJOINTWITH class_list
    | DISJOINTCLASSES error { 
        yyerror("Erro de Sintaxe.#Esperava uma lista de classes após a palavra-chave 'disjointclasses:'");
    }
    | DISJOINTWITH error { 
        yyerror("Erro de Sintaxe.#Esperava uma lista de classes após a palavra-chave 'disjointwith:'");
    }
;

individuals_section:
    INDIVIDUALS individuals_list
    | INDIVIDUALS error { 
        yyerror("Erro de Sintaxe.#Esperava uma lista de indivíduos após a palavra-chave 'individuals:'");
    }
;

individuals_list:
   TAG_INDIVIDUOS TAG_VIRGULA individuals_list
   | TAG_INDIVIDUOS
   | TAG_INDIVIDUOS TAG_VIRGULA error { 
        yyerror("Erro de Sintaxe.#Esperava algo após a vírgula");
    }
;

// Class_list: Classes separadas por vírgula ou entre parênteses e separadas por vírgula
class_list:
    class_v
    | TAG_ABREPARANTESIS class_v TAG_FECHAPARANTESIS
    | TAG_ABREPARANTESIS class_v error { 
        yyerror("Erro de Sintaxe.#Esperava um fechamento de parênteses"); 
    }
;

// Class_v: Classes separadas por vírgula
class_v:
    TAG_CLASS TAG_VIRGULA class_v
    | TAG_CLASS
    | TAG_CLASS TAG_VIRGULA error { 
        yyerror("Erro de Sintaxe.#Esperava algo após a vírgula");
    }
;

// Class_op: Classes entre parênteses separadas por operadores lógicos
class_op: 
    TAG_ABREPARANTESIS class_l TAG_FECHAPARANTESIS  
    | TAG_ABREPARANTESIS class_l error { 
        yyerror("Erro de Sintaxe.#Esperava um fechamento de parênteses"); 
    }
;

// Class_l: Classes separadas por operadores lógicos
class_l:
    TAG_CLASS op_logic class_l {
         if (props.find(std::string($1)) != props.end()) {
            props.erase(std::string($1));
        } else {
            char error_message[512];
            snprintf(error_message, 512, "Erro Semântico.#A class [%s] não foi fechada corretamente nas propriedades.", $1);
            yyerror(error_message);
        }
    }
    | TAG_CLASS {
        if (props.find(std::string($1)) != props.end()) {
            props.erase(std::string($1));
        } else {
            char error_message[512];
            snprintf(error_message, 512, "Erro Semântico.#A class [%s] não foi fechada corretamente nas propriedades.", $1);
            yyerror(error_message);
        }   
    }
    | TAG_CLASS op_logic error { 
        yyerror("Erro de Sintaxe.#Esperava algo após o operador lógico");
    }
    | TAG_CLASS TAG_CLASS error { 
        yyerror("Erro de Sintaxe.#Esperava um operador lógico entre as classes");
    }
;

// Op_quantifier: Quantificadores
op_quantifier:
    ONLY
    | SOME
    | ALL
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
    TAG_NAMESPACE TAG_DATATYPE 
    { 
        char * result = (char *)malloc(256); 
        if (result == NULL) {
            yyerror("Erro de memória ao processar namespace e datatype");
            YYABORT;
        }

        if (!is_namespace_valid(std::string($1))) {
            free(result);
            char error_message[512];
            snprintf(error_message, 512, "Namespace inválido.#O namespace %s não é válido", $1);
            yyerror(error_message);
            $$ = NULL;
        } else if (strcmp($1, "xsd:") == 0 && is_valid_xsd_type(std::string($2))) {
            snprintf(result, 256, "xsd:%s", $2);
            $$ = result;
        }
        else if (strcmp($1, "owl:") == 0 && is_valid_owl_type(std::string($2))) {
            snprintf(result, 256, "owl:%s", $2);
            $$ = result;
        }
        else if (strcmp($1, "rdf:") == 0 && is_valid_rdf_type(std::string($2))) {
            snprintf(result, 256, "rdf:%s", $2);
            $$ = result;
        }
        else if (strcmp($1, "rdfs:") == 0 && is_valid_rdfs_type(std::string($2))) {
            snprintf(result, 256, "rdfs:%s", $2);
            $$ = result;
        }
        else {
            free(result);
            char error_message[512];
            snprintf(error_message, 512, "Tipo incompatível com o namespace.#O namespace %s não é compatível com o tipo %s", $1, $2);
            yyerror(error_message);
            $$ = NULL;
        }
    }
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