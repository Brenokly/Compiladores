%{
// Inclusões de bibliotecas
#include "tokens.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

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

// Definição dos tokens
// Em tokens podemos guardar info de tokens que são representados por eles mesmos, como: Simbolos '(', ')', ',', '{', '}', '[', ']', '"', '|', '<', '>', '='
struct Token {
	int tag;
	Token() : tag(0) {}
	Token(int t) : tag(t) {}
	virtual string toString() { stringstream ss; ss << char(tag); return ss.str(); }
};

// Em Num podemos guardar info de tokens que são representados por números, como: Números
struct Num : Token
{
	int value;
	Num(): Token(TAG_NUM), value(0) {}
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
struct Classe : Token {
    string nome;         // Nome da classe
    string classePai;    // Classe pai, se existir
    vector<string> relacoes; // Relacionamentos com outras classes

    Classe() : Token(TAG_CLASS), nome(""), classePai("") {}

    Classe(string n, string pai) : Token(TAG_CLASS), nome(n), classePai(pai) {}

    virtual string toString() {
        stringstream ss;
        ss << "Classe: " << nome;
        if (!classePai.empty()) {
            ss << " (Classe Pai: " << classePai << ")";
        }
        if (!relacoes.empty()) {
            ss << " Relacionamentos: ";
            for (const auto& r : relacoes) {
                ss << r << " ";
            }
        }
        return ss.str();
    }
};

struct Individuo : Token {
    string nome;         // Nome do indivíduo
    string classe;       // Classe a que o indivíduo pertence
    unordered_map<string, string> propriedades; // Propriedades e seus valores

    Individuo() : Token(TAG_INDIVIDUOS), nome(""), classe("") {}

    Individuo(string n, string c) : Token(TAG_INDIVIDUOS), nome(n), classe(c) {}

    virtual string toString() {
        stringstream ss;
        ss << "Indivíduo: " << nome << " (Classe: " << classe << ")";
        if (!propriedades.empty()) {
            ss << " Propriedades: ";
            for (const auto& p : propriedades) {
                ss << p.first << "=" << p.second << " ";
            }
        }
        return ss.str();
    }
};

// Definição de funções auxiliares
string toLower(string str);

// Definição de variáveis globais
bool erro = false;
%}

%option noyywrap

delim [ \t\n]
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
SIMBOLO  (\[|\]|\{|\}|\(|\)|>|<|>=|<=|,)
CARDILIDADE {NUM}

%%
{brancos}          {}
{PROP_HAS}         { return TAG_HASPROPERTY; }
{PROP_IS}          { return TAG_ISPROPERTY; }
{NAMESPACE}        { return TAG_NAMESPACE; }
{DATATYPE}         { return TAG_DATATYPE; }
{SIMBOLO}          { return TAG_SIMBOLO; }
{CARDILIDADE}      { return TAG_NUM; }
{INDIVIDUOS}       { return TAG_INDIVIDUOS; }
{CLASS}            {
    auto it = reservadas.find(toLower(yytext)); 
    if (it != reservadas.end()) {
        return it->second;
    } else {
        return TAG_CLASS;
    }
}
{PROPINVALIDA}     { cout << "Erro lexico encontrado na linha " << yyFlexLexer::lineno() << ": " << yytext << "\n"; erro = true; }
{PROPERTYS}        {
    auto it = reservadas.find(toLower(yytext));
    if (it != reservadas.end()) {
        return it->second;
    } else {
        return TAG_PROPERTY;
    }
}
{RESERVADAS}":"    {
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