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

extern int yylineno;
extern vector<Error> errors;
char * currentClass;

int yylex(void);
int yyparse(void);
void yyerror(const char *msg);
bool is_valid_xsd_type(const std::string& datatype);
bool is_valid_owl_type(const std::string& datatype);
bool is_valid_rdf_type(const std::string& datatype);
bool is_valid_rdfs_type(const std::string& datatype);
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
%type <str> class_name_exp
%type <str> type
%type <str> namespace_datatype

%%
ontology:
    declarations
;

declarations:
    class_declaration
    | class_declaration declarations
;

class_declaration:
    CLASS TAG_CLASS class_type { cout << " reconhecida: " << $2 << endl; }
;

class_type:
    primitive_class class_body  { cout << "Classe primitiva"; }
    | defined_class class_body  { cout << "Classe definida"; }
;

primitive_class:
    SUBCLASSOF property_restriction_list
    | SUBCLASSOF expression_list
;

defined_class:
    EQUIVALENTTO property_restriction_list subclass
    | EQUIVALENTTO TAG_ABRECHAVE individuals_list TAG_FECHACHAVE subclass
    | subclass EQUIVALENTTO property_restriction_list
    | subclass EQUIVALENTTO TAG_ABRECHAVE individuals_list TAG_FECHACHAVE
;

subclass:
    SUBCLASSOF property_restriction_list
    | SUBCLASSOF expression_list
    |
;

expression_list:
    TAG_PROPERTY   
;

property_restriction_list:
    property_restriction op_c
    | TAG_ABREPARANTESIS property_restriction_list TAG_FECHAPARANTESIS op_c
;

op_c:
    op_logic property_restriction_list
    |
;

property_restriction:
    TAG_CLASS
    | TAG_PROPERTY op_quantifier type
    | TAG_PROPERTY op_cardinality TAG_NUM type
    | TAG_PROPERTY VALUE TAG_INDIVIDUOS
    | TAG_PROPERTY VALUE TAG_NUM
    | TAG_ABREPARANTESIS property_restriction TAG_FECHAPARANTESIS
;

class_body:
    disjointclasses_section
    | individuals_section
    | disjointclasses_section individuals_section
    | individuals_section disjointclasses_section
    |
;

disjointclasses_section:
    DISJOINTCLASSES class_name_list
    | DISJOINTWITH class_name_list
;

individuals_section:
    INDIVIDUALS individuals_list
;

individuals_list:
    TAG_INDIVIDUOS
    | TAG_INDIVIDUOS TAG_VIRGULA individuals_list
;

class_name_list:
    TAG_CLASS
    | TAG_CLASS TAG_VIRGULA class_name_list
;

class_name_exp:
    TAG_CLASS
    | TAG_CLASS op_logic class_name_exp
    | TAG_ABREPARANTESIS class_name_exp TAG_FECHAPARANTESIS
;

type:
    class_name_exp
    | namespace_datatype
    | namespace_datatype TAG_ABRECOLCHETE op_rel TAG_NUM TAG_FECHACOLCHETE
;

op_quantifier:
    ONLY
    | SOME
    | ALL
;

op_logic:
    AND
    | OR
;

op_rel:
    TAG_MAIOR           { $$ = ">"; }
    | TAG_MAIORIGUAL    { $$ = ">="; }
    | TAG_MENOR         { $$ = "<"; }
    | TAG_MENORIGUAL    { $$ = "<="; }
;

op_cardinality:
    MIN
    | MAX
    | EXACTLY
;

namespace_datatype:
    TAG_NAMESPACE TAG_DATATYPE 
    { 
        char * result = (char *)malloc(256); 
        if (result == NULL) {
            yyerror("Erro de memória ao processar namespace e datatype");
            YYABORT;
        }

        if (strcmp($1, "xsd:") == 0 && is_valid_xsd_type(std::string($2))) {
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
            yyerror("Datatype incompatível com o namespace.");
            $$ = NULL;
        }
    }
;

%%

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

void yyerror(const char * msg, const char * sug) {
    Error err;
    err.line = yylineno;
    err.message = string(msg);
    err.

    errors.push_back(err);
}