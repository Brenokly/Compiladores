%{
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;

// Definição da estrutura Error
struct Error
{
    int line;
    std::string message;
    std::string suggestion;
};

extern int yylineno;
extern vector<Error> errors;

int yylex(void);
int yyparse(void);
void yyerror(const char *msg);

%}

%union {
    double num;
    char *str;
}

%token <str> TAG_CLASS TAG_INDIVIDUOS TAG_NAMESPACE TAG_PROPERTY TAG_DATATYPE
%token <num> TAG_NUM
%token <str> ONLY SOME ALL VALUE MIN MAX EXACTLY THAT NOT AND OR CLASS EQUIVALENTTO INDIVIDUALS SUBCLASSOF DISJOINTCLASSES DISJOINTWITH
%token <str> TAG_MENORIGUAL TAG_MAIORIGUAL TAG_MENOR TAG_MAIOR TAG_ABRECOLCHETE TAG_FECHACOLCHETE TAG_ABRECHAVE TAG_FECHACHAVE TAG_ABREPARANTESIS TAG_FECHAPARANTESIS TAG_VIRGULA TAG_DOISPONTOS

%start ontology

%type <str> class_name
%type <str> class_declaration
%type <str> op_rel
%type <str> op_cardinality

%%

ontology:
    declarations
;

declarations:
    class_declaration
    | class_declaration declarations
;

class_declaration:
    CLASS class_name class_type { cout << " reconhecida: " << $2 << endl; }
;

class_name:
    TAG_CLASS { $$ = $1; }
;

class_type:
    primitive_class class_body  { cout << "Classe primitiva"; }
    | defined_class class_body  { cout << "Classe definida"; }
;

primitive_class:
    SUBCLASSOF property_restriction_list
;

defined_class:
    EQUIVALENTTO expression_list
    | EQUIVALENTTO expression_list SUBCLASSOF property_restriction_list
;

expression_list:
    property_restriction_list
    | expression_list op_logic expression_list
    | TAG_ABREPARANTESIS expression_list TAG_FECHAPARANTESIS
;

property_restriction_list:
    property_restriction
    | property_restriction TAG_VIRGULA property_restriction_list
    | property_restriction op_logic property_restriction_list
    | TAG_ABREPARANTESIS property_restriction TAG_FECHAPARANTESIS
;

property_restriction:
    class_name
    | TAG_PROPERTY op_quantifier type
    | TAG_PROPERTY op_cardinality TAG_NUM type
    | TAG_PROPERTY VALUE TAG_INDIVIDUOS
    | TAG_PROPERTY VALUE TAG_NUM
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
    class_name
    | class_name TAG_VIRGULA class_name_list
;

class_name_exp:
    class_name
    | class_name op_logic class_name_exp
    | TAG_ABREPARANTESIS class_name_exp TAG_FECHAPARANTESIS
;

type:
    class_name_exp
    | TAG_NAMESPACE TAG_DATATYPE
    | TAG_NAMESPACE TAG_DATATYPE TAG_ABRECOLCHETE op_rel TAG_NUM TAG_FECHACOLCHETE
    |
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

%%

void yyerror(const char *msg) {
    Error err;
    err.line = yylineno;
    err.message = string(msg);

    errors.push_back(err);
}