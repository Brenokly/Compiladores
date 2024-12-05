%{
#include <iostream>
#include <string>
#include <unordered_map>
using std::cout;
using std::string;
using std::unordered_map;

enum {SOME = 256, ALL, VALUE, MIN, MAX, EXACTLY, THAT, NOT, AND, OR, CLASS, EQUIVALENTTO, INDIVIDUALS, 
SUBCLASSOF, DISJOINTCLASSES, CLASSE, PROPERTY, ID, NUM, INDIVIDUOS};

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
};

void inserir(int tipo, string palavra);
int buscar(string palavra);

int numClasses, numProperties, numIndividuals, numIndividuos, numSimbolos, numReservadas, numCardinalidades = 0;
%}

%option noyywrap
delim [ \t\n]
brancos {delim}+
letra [a-zA-Z]
maiuscula [A-Z]
minuscula [a-z]
digito [0-9]

NUM {digito}+(\.{digito}+)?([eE][+-]?{digito}+)?
CLASSES {maiuscula}({letra})*(_{maiuscula}{letra}*)*
RESERVADAS ({minuscula})+({letra})*    
SIMBOLO [\[\]\{\}\(\)<>,]
INDIVIDUOS {maiuscula}({letra})*{NUM}

%%
{brancos}+          ;
Class":"            {cout << "Palavra reservada: Class:\n"; numReservadas++; return CLASSE;}
EquivalentTo":"     {cout << "Palavra reservada: EquivalentTo:\n"; numReservadas++; return EQUIVALENTTO;}
Individuals":"      {cout << "Palavra reservada: Individuals:\n"; numReservadas++; return INDIVIDUALS;}
SubClassOf":"       {cout << "Palavra reservada: SubClassOf:\n"; numReservadas++; return SUBCLASSOF;}
DisjointClasses":"  {cout << "Palavra reservada: DisjointClasses:\n"; numReservadas++; return DISJOINTCLASSES;}
{RESERVADAS}        {
    auto it = symbolTable.find(yytext); 
    if (it != symbolTable.end()) {
        numReservadas++;
        cout << "Palavra reservada: " << it->first << " -> " << it->second << "\n"; 
        return it->second;
    } else {
        cout << "Propriedade: " << yytext << "\n";
        numProperties++;
        return PROPERTY;
    }
}
{CLASSES}           {cout << "Identificador classe: " << yytext << "\n"; numClasses++; return ID;}
{INDIVIDUOS}        {cout << "Identificador individuo: " << yytext << "\n"; numIndividuos++; return INDIVIDUOS;}
{NUM}               {cout << "NUM\n"; numCardinalidades++; return NUM;}
{SIMBOLO}           {cout << "Simbolo: " << yytext << "\n"; numSimbolos++; return yytext[0]; }
.|\n                {cout << "Unexpected token: " << yytext << "\n"; }
%%

int main() {
  while (yylex()) { }
  return 0;
}

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