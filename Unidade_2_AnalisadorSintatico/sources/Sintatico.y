%{
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <cstring>
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::set;
using std::strcmp;

// Definição da estrutura Error
struct Error
{
    int line;
    std::string message;
    std::string suggestion;
};

struct Classes
{
  string name;
  std::set<string> tipos;
};

extern int yylineno;
extern vector<Error> errors;
extern vector<Classes> classes;
char * currentClass;
Classes * c = nullptr;
set<string> t;

int yylex(void);
int yyparse(void);
void yyerror(const char *msg);
bool is_valid_xsd_type(const std::string& datatype);
bool is_valid_owl_type(const std::string& datatype);
bool is_valid_rdf_type(const std::string& datatype);
bool is_valid_rdfs_type(const std::string& datatype);
bool is_namespace_valid(const std::string& space);
void addClass(const string& className);
%}

%union {
    double num;
    const char * str;
}

%token <str> TAG_CLASS TAG_INDIVIDUOS TAG_NAMESPACE TAG_PROPERTY TAG_DATATYPE
%token <num> TAG_NUM
%token <str> ONLY SOME ALL VALUE MIN MAX EXACTLY THAT NOT AND OR CLASS EQUIVALENTTO INDIVIDUALS SUBCLASSOF DISJOINTCLASSES DISJOINTWITH
%token <str> TAG_MENORIGUAL TAG_MAIORIGUAL TAG_MENOR TAG_MAIOR TAG_ABRECOLCHETE TAG_FECHACOLCHETE TAG_ABRECHAVE TAG_FECHACHAVE TAG_ABREPARANTESIS TAG_FECHAPARANTESIS TAG_VIRGULA TAG_DOISPONTOS

%left AND
%left OR

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
    CLASS TAG_CLASS class_type { classes.push_back({string($2),t}); t.clear(); }
    | CLASS error { 
        yyerror("Erro de sintaxe.#Esperava um nome de classe após a palavra-chave 'class:'");
    }
;

// class_type: Define como é a estrutura dos dois tipos de classes existentes
class_type:
    primitive_class class_body  { t.insert("primitiva"); }
    | defined_class class_body  { t.insert("definida"); }
    | error {
        yyerror("Erro de sintaxe.#Esperava uma classe primitiva ou definida");
    }
;

// primitive_class: Define a estrutura obrigatória de uma classe primitiva
primitive_class:
    SUBCLASSOF expression_list
    | SUBCLASSOF 
;

// primitive_class: Define a estrutura obrigatória de uma classe definida
defined_class:
    EQUIVALENTTO expression_list optional_subclass
    | EQUIVALENTTO TAG_ABRECHAVE individuals_list TAG_FECHACHAVE optional_subclass { t.insert("enumerada"); }
    | optional_subclass EQUIVALENTTO expression_list
    | optional_subclass EQUIVALENTTO TAG_ABRECHAVE individuals_list TAG_FECHACHAVE { t.insert("enumerada"); }
    | EQUIVALENTTO error { 
        yyerror("Erro de sintaxe.#Esperava uma expressão após a palavra-chave 'equivalentto:'");
    }
;

// optional_subclass: Define a estrutura opcional de uma classe definida
optional_subclass:
    SUBCLASSOF expression_list
    | SUBCLASSOF 
    |
;

// expression_list: Define a estrutura de uma expressão que pode ter vírgulas
expression_list:
    TAG_CLASS
    | pos_class { t.insert("coberta"); }
    | TAG_CLASS expression_format
    | expression_format2
;

pos_class:
    TAG_CLASS op_logic pos_class 
    | TAG_CLASS
;

expression_format:
    separador expression expression_format
    | separador TAG_ABREPARANTESIS expression TAG_FECHAPARANTESIS expression_format
    | separador expression TAG_FECHAPARANTESIS error { 
        yyerror("Erro de sintaxe.#Esperava um abre parênteses"); 
    }
    | 
;

expression_format2:
    expression separador expression_format2
    | TAG_ABREPARANTESIS expression TAG_FECHAPARANTESIS separador expression_format2
    |
;

expression:
    TAG_ABREPARANTESIS expression TAG_FECHAPARANTESIS expre_pos { t.insert("aninhada"); }
    | TAG_PROPERTY op_quantifier TAG_CLASS
    | TAG_PROPERTY op_quantifier type_expre
    | TAG_PROPERTY op_quantifier expression
    | TAG_PROPERTY op_cardinality TAG_NUM TAG_CLASS
    | TAG_PROPERTY op_cardinality TAG_NUM type_expre
    | TAG_PROPERTY VALUE pos_value
    | TAG_ABREPARANTESIS expression error { 
        yyerror("Erro de sintaxe.#Esperava um fechamento de parênteses"); 
    }
    | TAG_PROPERTY error { 
        yyerror("Erro de sintaxe.#Propriedade inválida [Esperava = 'property' 'operador' 'expressão']"); 
    }

;

pos_value:
    TAG_NUM
    | TAG_INDIVIDUOS
    | error {
        yyerror("Erro de sintaxe.#Esperava um número ou indivíduo após a palavra-chave 'value'");
    }
;

expre_pos:
    separador expression
    |
;

separador:
    TAG_VIRGULA
    | op_logic
    | 
;

type_expre:
    class_op
    | namespace_datatype
    | namespace_datatype TAG_ABRECOLCHETE op_rel TAG_NUM TAG_FECHACOLCHETE
    | namespace_datatype TAG_ABRECOLCHETE error { 
        yyerror("Erro de sintaxe.#Esperava um operador de relação após o tipo de dado"); 
    }
    | namespace_datatype TAG_ABRECOLCHETE op_rel error { 
        yyerror("Erro de sintaxe.#Esperava um número após o operador de relação"); 
    }
    | namespace_datatype TAG_ABRECOLCHETE op_rel TAG_NUM error { 
        yyerror("Erro de sintaxe.#Esperava um fechamento de colchetes"); 
    }
;

class_body:
    disjointclasses_section
    | individuals_section
    | disjointclasses_section individuals_section
    | individuals_section disjointclasses_section
    |
;

disjointclasses_section:
    DISJOINTCLASSES class_list
    | DISJOINTWITH class_list
    | DISJOINTCLASSES error { 
        yyerror("Erro de sintaxe.#Esperava uma lista de classes após a palavra-chave 'disjointclasses:'");
    }
    | DISJOINTWITH error { 
        yyerror("Erro de sintaxe.#Esperava uma lista de classes após a palavra-chave 'disjointwith:'");
    }
;

individuals_section:
    INDIVIDUALS individuals_list
    | INDIVIDUALS error { 
        yyerror("Erro de sintaxe.#Esperava uma lista de indivíduos após a palavra-chave 'individuals:'");
    }
;

individuals_list:
   TAG_INDIVIDUOS TAG_VIRGULA individuals_list
   | TAG_INDIVIDUOS
   | TAG_INDIVIDUOS TAG_VIRGULA error { 
        yyerror("Erro de sintaxe.#Esperava algo após a vírgula");
    }
;

// Class_list: Classes separadas por vírgula ou entre parênteses
class_list:
    TAG_CLASS TAG_VIRGULA class_list
    | TAG_CLASS
    | TAG_ABREPARANTESIS TAG_CLASS TAG_VIRGULA class_list TAG_FECHAPARANTESIS
    | TAG_CLASS TAG_VIRGULA error { 
        yyerror("Erro de sintaxe.#Esperava algo após a vírgula");
    }
    | TAG_ABREPARANTESIS TAG_CLASS TAG_VIRGULA class_list error {
        yyerror("Erro de sintaxe.#Esperava um fechamento de parênteses");
    } 
    | TAG_CLASS TAG_VIRGULA class_list TAG_FECHAPARANTESIS error {
        yyerror("Erro de sintaxe.#Esperava um abre parênteses");
    }
;

class_op: 
    TAG_ABREPARANTESIS class_l TAG_FECHAPARANTESIS 
;

class_l:
    TAG_CLASS op_logic class_l
    | TAG_CLASS
;

// Op_quantifier: Quantificadores
op_quantifier:
    ONLY { t.insert("fechamento"); }
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

void addClass(const string& className) {
    c = &classes.emplace_back();  // Adiciona um novo elemento no vetor e obtém o ponteiro
    c->name = className;
}