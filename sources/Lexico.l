%{
// Inclusões de bibliotecas
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
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

extern YYSTYPE yylval;

// Definição de funções auxiliares
string toLower(string str);

// Definição de variáveis globais
bool erro = false;

%}

%option noyywrap

delim [ \t\n]
BRANCOS {delim}*
letra [a-zA-Z]
maiuscula [A-Z]
minuscula [a-z]
digito [0-9]
NUM {digito}+(\.{digito}+)?([eE][+-]?{digito}+)?
PROP_HAS has({letra})+
PROP_IS is({letra})+Of
CLASS {maiuscula}({letra})*(_({letra})+)*   
INDIVIDUOS {maiuscula}({letra})*{NUM}
RESERVADAS ({letra})+
PROPERTYS {minuscula}{letra}*
PROPINVALIDA {minuscula}({letra})*{NUM}
NAMESPACE (owl\:|rdf\:|rdfs\:|xsd\:)
DATATYPE (rational|real|langString|PlainLiteral|XMLLiteral|Literal|anyURL|base64Binary|boolean|byte|dateTime|dateTimeStamp|decimal|double|float|hexBinary|int|integer|language|long|Name|NCName|negativeInteger|NMTOKEN|nonNegativeInteger|nonPositiveInteger|normalizedString|positiveInteger|short|string|token|unsignedByte|unsignedInt|unsignedLong|unsignedShort)
CARDILIDADE {NUM}
SIMBOLO  (\<=|\>=|<|>|\[|\]|\{|\}|\(|\)|,)

%%
{BRANCOS}          {}
{SIMBOLO}          { }
{PROP_HAS}         { yylval.str = std::string(yytext); return TAG_HASPROPERTY; }
{PROP_IS}          { yylval.str = std::string(yytext); return TAG_ISPROPERTY; }
{NAMESPACE}        { yylval.str = std::string(yytext); return TAG_NAMESPACE; }
{DATATYPE}         { yylval.str = std::string(yytext); return TAG_DATATYPE; }
{CARDILIDADE}      { yylval.num = atof(yytext); return TAG_NUM; }
{INDIVIDUOS}       { yylval.str = std::string(yytext); return TAG_INDIVIDUOS; }
{CLASS}            {
    yylval.str = std::string(yytext);
    auto it = reservadas.find(toLower(yytext)); 
    if (it != reservadas.end()) {
        return it->second;
    } else {
        return TAG_CLASS;
    }
}
{PROPINVALIDA}     { cout << "Erro lexico encontrado na linha " << yyFlexLexer::lineno() << ": " << yytext << "\n"; erro = true; }
{PROPERTYS}        {
    yylval.str = std::string(yytext);
    auto it = reservadas.find(toLower(yytext));
    if (it != reservadas.end()) {
        return it->second;
    } else {
        return TAG_PROPERTY;
    }
}
{RESERVADAS}":"    {
    yylval.str = std::string(yytext);
    auto it = reservadas.find(toLower(yytext)); 
    if (it != reservadas.end()) {
        return it->second; 
    } else {
        cout << "Erro lexico encontrado na linha " << yyFlexLexer::lineno() << ": " << yytext << "\n";
        erro = true;
    }
}
.                  { cout << "\nErro lexico encontrado na linha " << yyFlexLexer::lineno() << ": " << yytext << "\n"; erro = true; }
%%

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return tolower(c); });
    return str;
}