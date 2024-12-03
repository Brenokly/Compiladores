%{
#include <iostream>
#include <string>
#include <unordered_map>
using std::cout;
using std::string;
using std::unordered_map;

enum {SOME = 256, ALL, VALUE, MIN, MAX, EXACTLY, THAT, NOT, AND, OR, CLASS, EQUIVALENTTO, INDIVIDUALS, 
SUBCLASSOF, DISJOINTCLASSES, CLASSE, PROPERTY, ID, NUM, INDIVIDUO};

unordered_map<string, int> symbolTable = {
    {"Some", SOME},
    {"All", ALL},
    {"Value", VALUE},
    {"Min", MIN},
    {"Max", MAX},
    {"Exactly", EXACTLY},
    {"That", THAT},
    {"Not", NOT},
    {"And", AND},
    {"Or", OR},
};

%}

%option noyywrap

delim [ \t\n]
brancos {delim}+
letra [a-zA-Z]
maiuscula [A-Z]
digito [0-9]

Id {letra}({letra}|{digito})*
Num {digito}+(\.{digito}+)?([eE][+-]?{digito}+)?
IDCLASS {maiuscula}({letra})*(_{maiuscula}{letra}*)*
INDIVIDUO {maiuscula}({letra})*(_{maiuscula}{letra}*)*{digito}+
PROP1 has{maiuscula}({letra})*
PROP2 is{maiuscula}({letra})*Of

%%
{brancos}+        ;
{INDIVIDUO}       {cout << "Identificador individuo: " << yytext << "\n"; return INDIVIDUO;}
Class":"          {cout << "Palavra reservada: Class: " << "\n"; return CLASS;}
EquivalentTo":"   {cout << "Palavra reservada: EquivalentTo: " << "\n"; return EQUIVALENTTO;}
Individuals":"    {cout << "Palavra reservada: Individuals: " << "\n"; return INDIVIDUALS;}
SubClassOf":"     {cout << "Palavra reservada: SubClassOf: " << "\n"; return SUBCLASSOF;}
DisjointClasses":" {cout << "Palavra reservada: DisjointClasses: " << "\n"; return DISJOINTCLASSES;}
{PROP1}           {cout << "IDPROPERTY " << yytext << "\n"; return PROPERTY;} 
{PROP2}           {cout << "IDPROPERTY" << yytext << "\n"; return PROPERTY;} 
{IDCLASS} {
    auto it = symbolTable.find(yytext); 
    if (it != symbolTable.end()) { 
        cout << "Palavra reservada: " << it->first << " -> " << it->second << "\n"; 
        return it->second; 
    } else {
        cout << "Identificador classe: " << yytext << "\n";
        return ID;
    }
}
{Num}             {cout << "NUM\n"; return NUM;}
.|\n              {cout << "Unexpected token: " << yytext << "\n"; }
%%

int main() {
  while (yylex()) { }
  return 0;
}
