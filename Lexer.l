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
string toLower(string str);

int numClasses, numProperties, numIndividuos, numSimbolos, numReservadas, numCardinalidades = 0;
%}

%option noyywrap
delim [ \t\n]
brancos {delim}+
letra [a-zA-Z]
maiuscula [A-Z]
digito [0-9]
digitos {digito}+
relop (<=|>=|<|>|!=|=)

NUM {digito}+(\.{digito}+)?([eE][+-]?{digito}+)?
RESERVADAS ({letra})*    
SIMBOLO [\[\]\{\}\(\),]
INDIVIDUOS {maiuscula}({letra})*{NUM}
TIPO (string|integer(\[{relop}{digitos}\])?)

%%
{brancos}+          ;
Class":"            {cout << "Palavra reservada: Class:\n"; numReservadas++; return CLASSE;}
EquivalentTo":"     {cout << "Palavra reservada: EquivalentTo:\n"; numReservadas++; return EQUIVALENTTO;}
Individuals":"      {cout << "Palavra reservada: Individuals:\n"; numReservadas++; return INDIVIDUALS;}
SubClassOf":"       {cout << "Palavra reservada: SubClassOf:\n"; numReservadas++; return SUBCLASSOF;}
DisjointClasses":"  {cout << "Palavra reservada: DisjointClasses:\n"; numReservadas++; return DISJOINTCLASSES;}
{RESERVADAS}        {
    auto it = symbolTable.find(toLower(yytext)); 
    if (it != symbolTable.end()) {
        cout << "Palavra reservada: " << it->first << " -> " << it->second << "\n"; 
        numReservadas++;
        return it->second;
    } else if (islower(yytext[0])) {
        cout << "Propriedade: " << yytext << "\n";
        numProperties++;
        return PROPERTY;
    } else if (isupper(yytext[0])) {
        cout << "Classe: " << yytext << "\n";
        numClasses++;
        return CLASSE;
    }
}
{INDIVIDUOS}        {cout << "Identificador individuo: " << yytext << "\n"; numIndividuos++; return INDIVIDUOS;}
{NUM}               {cout << "NUM\n"; numCardinalidades++; return NUM;}
{SIMBOLO}           {cout << "Simbolo: " << yytext << "\n"; numSimbolos++; return yytext[0]; }
xsd":"{TIPO}        {cout << "Tipo: " << yytext << "\n"; return ID;}
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

// Função que recebe yytext e retorna a string em tolower case
string toLower(string str) {
    for (int i = 0; i < str.size(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}