%{
// Inclusões de bibliotecas
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include "symtable.h"
using std::cout;
using std::string;
using std::unordered_map;
using std::transform;
using std::vector;

#include "Sintatico.tab.h" 

// Definição da tabela de palavras reservadas
unordered_map<string, int> reservadas = {
    {"some", SOME},
    {"all", ALL},
    {"value", VALUE},
    {"min", MIN},
    {"max", MAX},
    {"exactly", EXACTLY},
    {"that", THAT},
    {"not", NOT},
    {"and", AND},
    {"or", OR},
    {"class:", CLASS},
    {"equivalentto:", EQUIVALENTTO},
    {"individuals:", INDIVIDUALS},
    {"subclassof:", SUBCLASSOF},
    {"disjointclasses:", DISJOINTCLASSES},
    {"disjointwith:", DISJOINTWITH}
};

// Definição de funções auxiliares
string toLower(string str);

// Definição de variáveis globais
bool erro = false;
int line_number = 1;
extern SymTable * currentTable;
%}

%option noyywrap
%option yylineno

delim [ \t]
BRANCOS {delim}*
letra [a-zA-Z]
maiuscula [A-Z]
minuscula [a-z]
digito [0-9]
NUM {digito}+(\.{digito}+)?([eE][+-]?{digito}+)?
CLASS {maiuscula}({letra})*(_({letra})+)*   
INDIVIDUOS {maiuscula}({letra})*{NUM}
RESERVADAS ({letra})+
PROPERTYS {minuscula}{letra}*
PROPINVALIDA {minuscula}({letra})*{NUM}
NAMESPACE (owl\:|rdf\:|rdfs\:|xsd\:)
DATATYPE (rational|real|langString|PlainLiteral|XMLLiteral|Literal|anyURL|base64Binary|boolean|byte|dateTime|dateTimeStamp|decimal|double|float|hexBinary|int|integer|language|long|Name|NCName|negativeInteger|NMTOKEN|nonNegativeInteger|nonPositiveInteger|normalizedString|positiveInteger|short|string|token|unsignedByte|unsignedInt|unsignedLong|unsignedShort)
CARDILIDADE {NUM}
SIMBOLO  (\<=|\>=|<|>|\[|\]|\{|\}|\(|\)|,|:)

%%
\n                 { line_number++; }
{BRANCOS}          {}
{SIMBOLO}          {
    switch (yytext[0]) {
        case '<':
            if (yytext[1] == '=') {
                return TAG_MENORIGUAL;  // '<='
            } else {
                return TAG_MENOR;       // '<'
            }
        case '>':
            if (yytext[1] == '=') {
                return TAG_MAIORIGUAL;  // '>='
            } else {
                return TAG_MAIOR;       // '>'
            }
        case '[':
            return TAG_ABRECOLCHETE;  // '['
        case ']':
            return TAG_FECHACOLCHETE;  // ']'
        case '{':
            return TAG_ABRECHAVE;     // '{'
        case '}':
            return TAG_FECHACHAVE;    // '}'
        case '(':
            return TAG_ABREPARANTESIS;  // '('
        case ')':
            return TAG_FECHAPARANTESIS;  // ')'
        case ',':
            return TAG_VIRGULA;        // ','
        case ':':
            return TAG_DOISPONTOS;     // ':'
        default:
            return 0;  // caso de erro
    }
}
{NAMESPACE}        { yylval.str = strdup(yytext); return TAG_NAMESPACE; }
{DATATYPE}         { yylval.str = strdup(yytext); return TAG_DATATYPE; }
{CARDILIDADE}      { yylval.num = atof(yytext); return TAG_NUM; }
{INDIVIDUOS}       { 
    std::string className = yytext;
    Symblo newSymblo = {currentTable->getClassName()};  
    currentTable->Insert(className, newSymblo);  
    yylval.str = strdup(yytext); 
    return TAG_INDIVIDUOS; 
}
{CLASS}            {
    auto it = reservadas.find(toLower(yytext)); 
    if (it != reservadas.end()) {
        return it->second;
    } else {
        if (currentTable->getClassName().empty())
        {
            std::string className = yytext;
            currentTable->setClassName(className);
        }
        yylval.str = strdup(yytext);
        return TAG_CLASS;
    }
}
{PROPINVALIDA}     { cout << "Erro lexico encontrado na linha " << line_number << ": " << yytext << "\n"; erro = true; }
{PROPERTYS}        {
    auto it = reservadas.find(toLower(yytext));
    if (it != reservadas.end()) {
        return it->second;
    } else {
        yylval.str = strdup(yytext);
        return TAG_PROPERTY;
    }
}
{RESERVADAS}":"    {
    auto it = reservadas.find(toLower(yytext)); 
    if (it != reservadas.end()) {
        if (it->second == CLASS) {
            // Nova tabela de símbolos
            SymTable * newScope = new SymTable(currentTable);
            currentTable = newScope;
        }
        return it->second; 
    } else {
        cout << "Erro lexico encontrado na linha " << line_number << ": " << yytext << "\n";
        erro = true;
    }
}
.                  { cout << "\nErro lexico encontrado na linha " << line_number << ": " << yytext << "\n"; erro = true; }
%%

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return tolower(c); });
    return str;
}