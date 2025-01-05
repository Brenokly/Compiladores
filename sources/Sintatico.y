%{
#include <iostream>
#include <string>
using namespace std;

int yylex(void);
int yyparse(void);
void yyerror(const char *);
%}

%union {
    int num;            // Para números
    std::string str;    // Para strings
}

%token TAG_CLASS TAG_HASPROPERTY TAG_ISPROPERTY TAG_NUM TAG_INDIVIDUOS TAG_NAMESPACE TAG_PROPERTY TAG_DATATYPE
%token SOME ALL VALUE MIN MAX EXACTLY THAT NOT AND OR CLASS EQUIVALENTTO INDIVIDUALS SUBCLASSOF DISJOINTCLASSES DISJOINTWITH
%token TAG_MENORIGUAL TAG_MAIORIGUAL
%%

programa:
    lista_classes
;

lista_classes:
    lista_classes classe
    | classe
;

classe:
    CLASS ':' nome_classe definicao_classe
;

nome_classe:
    TAG_CLASS
;

definicao_classe:
    SUBCLASSOF ':' lista_descricoes
    | EQUIVALENTTO ':' lista_descricoes
    | DISJOINTCLASSES ':' lista_disjuntas
    | DISJOINTWITH ':' TAG_CLASS
    | INDIVIDUALS ':' lista_individuos
    | SUBCLASSOF ':' lista_descricoes DISJOINTCLASSES ':' lista_disjuntas
    | SUBCLASSOF ':' lista_descricoes DISJOINTWITH ':' TAG_CLASS
    | SUBCLASSOF ':' lista_descricoes INDIVIDUALS ':' lista_individuos
    | EQUIVALENTTO ':' lista_descricoes DISJOINTCLASSES ':' lista_disjuntas
    | EQUIVALENTTO ':' lista_descricoes DISJOINTWITH ':' TAG_CLASS
    | EQUIVALENTTO ':' lista_descricoes INDIVIDUALS ':' lista_individuos
;

lista_descricoes:
    lista_descricoes AND descricao
    | lista_descricoes OR descricao
    | descricao
;

descricao:
    NOT descricao
    | THAT descricao
    | propriedade_quantificada
    | propriedade_restrita
;

propriedade_quantificada:
    TAG_HASPROPERTY quantificador tipo_classe
    | TAG_HASPROPERTY VALUE TAG_CLASS
;

propriedade_restrita:
    TAG_HASPROPERTY TAG_NAMESPACE ':' tipo_dado
;

quantificador:
    SOME
    | ALL
    | EXACTLY TAG_NUM
    | MIN TAG_NUM
    | MAX TAG_NUM
;

tipo_classe:
    TAG_CLASS
;

tipo_dado:
    TAG_NAMESPACE ':' TAG_PROPERTY
    | TAG_DATATYPE
;

lista_disjuntas:
    lista_disjuntas ',' TAG_CLASS
    | TAG_CLASS
;

lista_individuos:
    lista_individuos ',' TAG_INDIVIDUOS
    | TAG_INDIVIDUOS
;
%%


void yyerror(const char* s) {
    cerr << "Erro Sintático: " << s << endl;
}