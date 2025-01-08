%{
#include <iostream>
#include <string>
#include <cstring>
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
void yyerror(const char * msg);

%}

%union {
    double num;
    char * str;
}

%token <str> TAG_CLASS TAG_INDIVIDUOS TAG_NAMESPACE TAG_PROPERTY TAG_DATATYPE
%token <num> TAG_NUM
%token SOME ALL VALUE MIN MAX EXACTLY THAT NOT AND OR CLASS EQUIVALENTTO INDIVIDUALS SUBCLASSOF DISJOINTCLASSES DISJOINTWITH
%token TAG_MENORIGUAL TAG_MAIORIGUAL TAG_MENOR TAG_MAIOR TAG_ABRECOLCHETE TAG_FECHACOLCHETE TAG_ABRECHAVE TAG_FECHACHAVE TAG_ABREPARANTESIS TAG_FECHAPARANTESIS TAG_VIRGULA TAG_DOISPONTOS

%start ontologia

%%

ontologia: lista_classes { cout << "Reconhecendo a ontologia..." << endl; }
    ;

lista_classes: lista_classes classe
    | classe 
    | 
    ;

classe:
    CLASS TAG_CLASS { cout << "Reconhecendo a classe: " << $2 << endl; }
    ;

%%

void yyerror(const char *s) {
    Error err;
    err.line = yylineno;
    err.message = string(s);

    errors.push_back(err);
}