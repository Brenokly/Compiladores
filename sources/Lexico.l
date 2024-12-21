%{
// Inclusões de bibliotecas
#include "tokens.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <sstream>
using namespace std;

// Definição da tabela de palavras reservadas
unordered_map<string, int> symbolTable = {
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

// Definição dos tokens
// Em tokens podemos guardar info de tokens que são representados por eles mesmos, como: Simbolos '(', ')', ',', '{', '}', '[', ']', '"', '|', '<', '>', '='
struct Token {
    int tag;
    Token() : tag(0) {}
    Token(int t) : tag(t) {}
    virtual string toString() { stringstream ss; ss << (char)tag; return ss.str(); }
};

// Em Num podemos guardar info de tokens que são representados por números, como: Números
struct Num : Token {
    int value;
    Num() : Token(TAG_NUM), value(0) {}
    Num(int v) : Token(TAG_NUM), value(v) {}
    virtual string toString() { stringstream ss; ss << value; return ss.str(); }
};

// Em Word podemos guardar info de tokens que são representados por palavras com uma tag, como: Palavras reservadas, propriedades
// namespaces, datatypes.
struct Word : Token {
    string lexeme;
    Word() : Token(TAG_CLASS), lexeme("") {}
    Word(string s, int tag) : Token(tag), lexeme(s) {}
    virtual string toString() { return lexeme; }
};

// Crie, Para armazenar: Classes e Individuos precisamos de uma estrutura mais completa, que tenha: Escopo, nome, tag...

// Definição de funções auxiliares
void inserir(int tipo, string palavra);
int buscar(string palavra);
string toLower(string str);

// Definição de variáveis globais
int linha = 1;
bool erro = false;
%}

%option noyywrap
delim [ \t]
brancos {delim}*
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
SIMBOLO [\[\]\{\}\(\),\"\"|<|>|=|>=]
CARDILIDADE {NUM}

%%

\n                 {linha++;}
{brancos}          
{PROP_HAS}         { return TAG_PROPERTY; }
{PROP_IS}          { return TAG_PROPERTY; }
{NAMESPACE}        { return TAG_NAMESPACE; }
{DATATYPE}         { return TAG_DATATYPE; }
{SIMBOLO}          { return TAG_SIMBOLO; }
{CARDILIDADE}      { return TAG_NUM; }
{INDIVIDUOS}       { return TAG_INDIVIDUOS; }
{CLASS}            {
    auto it = symbolTable.find(toLower(yytext)); 
    if (it != symbolTable.end()) {
        return TAG_RESERVADAS;
    } else {
        return TAG_CLASS;
    }
}
{PROPINVALIDA}     { cout << "Erro lexico encontrado na linha " << linha << ": " << yytext << "\n"; erro = true; }
{PROPERTYS}        {
    auto it = symbolTable.find(toLower(yytext));
    if (it != symbolTable.end()) {
        return TAG_RESERVADAS;
    } else {
        return TAG_PROPERTY;
    }
}
{RESERVADAS}":"    {
    auto it = symbolTable.find(toLower(yytext)); 
    if (it != symbolTable.end()) {
        return TAG_RESERVADAS; 
    } else {
        cout << "Erro lexico encontrado na linha " << linha << ": " << yytext << "\n";
        erro = true;
    }
}
.                  { cout << "\nErro lexico encontrado na linha " << linha << ": " << yytext << "\n"; erro = true; }

%%

void inserir(int tipo, string palavra) {
    if (symbolTable.find(palavra) == symbolTable.end()) {
        symbolTable[palavra] = tipo;
    }
}

int buscar(string palavra) {
    auto it = symbolTable.find(palavra);
    if (it != symbolTable.end()) {
        return it->second;
    }
    return 0;
}

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return tolower(c); });
    return str;
}