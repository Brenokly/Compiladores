%{
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;

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
    {"Class:", CLASS},
    {"EquivalentTo:", EQUIVALENTTO},
    {"Individuals:", INDIVIDUALS},
    {"SubClassOf:", SUBCLASSOF},
    {"DisjointClasses:", DISJOINTCLASSES},
};

void inserir(int tipo, string palavra);
int buscar(string palavra);
string toLower(string str);

char **fileList;
unsigned nFiles;
unsigned currentFile = 0;
bool openFile = false;
ifstream fin;
int numClasses, numProperties, numIndividuos, numSimbolos, numReservadas, numCardinalidades, numTipos = 0;
%}

delim [ \t\n]
brancos {delim}+
letra [a-zA-Z]
maiuscula [A-Z]
minuscula [a-z]
digito [0-9]
relop (<=|>=|<|>|!=|=)

NUM {digito}+(\.{digito}+)?([eE][+-]?{digito}+)?
RESERVADAS {maiuscula}({letra})*
PROPERTYS {minuscula}({letra})*
CLASS {maiuscula}({letra})*(_({letra})+)*       
SIMBOLO [\[\]\{\}\(\),]
INDIVIDUOS {maiuscula}({letra})*{NUM}
TYPEOWL (rational|real)

%%
{brancos}+          ;
{RESERVADAS}":"     {
    auto it = symbolTable.find(yytext); 
    if (it != symbolTable.end()) {
        numReservadas++;
        return it->second;
    }

    cout << "Erro de sintaxe: " << yytext << "\n";
}
{CLASS}             {
    auto it = symbolTable.find(toLower(yytext)); 
    if (it != symbolTable.end()) {
        numReservadas++;
        return it->second;
    } else if (isupper(yytext[0])) {
        numClasses++;
        return PROPERTY;
    }

    cout << "Erro de sintaxe: " << yytext << "\n";
}
{PROPERTYS}        {
    auto it = symbolTable.find(toLower(yytext)); 
    if (it != symbolTable.end()) {
        numReservadas++;
        return it->second;
    } else {
        numProperties++;
        return PROPERTY;
    }

    cout << "Erro de sintaxe: " << yytext << "\n";
}
{INDIVIDUOS}        {numIndividuos++; return INDIVIDUOS;}
{NUM}               {numCardinalidades++; return NUM;}
{SIMBOLO}           {numSimbolos++; return yytext[0];}
{relop}             {numSimbolos++; return yytext[0];}
xsd":"{TYPEOWL}     {numTipos++; return ID;}
owl":"{TYPEOWL}     {numTipos++; return ID;}
.|\n                {cout << "Erro de sintaxe: " << yytext << "\n";}
%%

int main(int argc, char ** argv)
{	
    fileList = argv + 1;        
    nFiles = argc - 1;  	     
	
	yyFlexLexer lexer;	 		
    lexer.switch_streams(&fin);  
	lexer.yywrap();				 


	if (openFile)
	{
		lexer.yylex();

    	cout << "Ocorrencia dos elementos presentes no texto\n";
        cout << "Classes: " << numClasses << "\n";
        cout << "Propriedades: " << numProperties << "\n";
        cout << "Individuos: " << numIndividuos << "\n";
        cout << "Cardinalidades: " << numCardinalidades << "\n";
        cout << "Tipos: " << numTipos << "\n";
        cout << "Simbolos: " << numSimbolos << "\n";
        cout << "Palavras reservadas: " << numReservadas << "\n";
	}
}

int yyFlexLexer::yywrap()
{
	if (openFile)
	{    
		openFile = false;
		fin.close();
	}

	while (!openFile && (fileList[currentFile] != nullptr)) 
    {
		fin.open(fileList[currentFile++]);
		if (fin.is_open()) 
        {
			openFile = true;
		}
		else
		{

			cout << fileList[currentFile-1] << " = nao foi possivel abrir\n";
		}		
	}

	return (openFile ? 0 : 1);
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

string toLower(string str) {
    for (int i = 0; i < str.size(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}