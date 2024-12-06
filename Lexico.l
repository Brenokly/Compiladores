%{
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;

enum {SOME = 256, ALL, VALUE, MIN, MAX, EXACTLY, THAT, NOT, AND, OR, CLASS, EQUIVALENTTO, INDIVIDUALS, 
SUBCLASSOF, DISJOINTCLASSES, CLASSE, PROPERTY, ID, NUM, INDIVIDUOS, NAMESPACEID, DATATYPE};

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
int numClasses, numProperties, numIndividuos, numSimbolos, numReservadas, numCardinalidades, numNamespace, numTipos = 0;
%}

delim [ \t\n]
brancos {delim}+
letra [a-zA-Z]
maiuscula [A-Z]
minuscula [a-z]
digito [0-9]

NUM {digito}+(\.{digito}+)?([eE][+-]?{digito}+)?
RESERVADAS {maiuscula}({letra})*
PROPERTYS {minuscula}({letra})*
CLASS {maiuscula}({letra})*(_({letra})+)*       
SIMBOLO [\[\]\{\}\(\),\"\"|<|>|=]
INDIVIDUOS {maiuscula}({letra})*{NUM}
NAMESPACE (owl\:|rdf\:|rdfs\:|xsd\:)
DATATYPE (rational|real|langString|PlainLiteral|XMLLiteral|Literal|anyURL|base64Binary|boolean|byte|dateTime|dateTimeStamp|decimal|double|float|hexBinary|int|integer|language|long|Name|NCName|negativeInteger|NMTOKEN|nonNegativeInteger|nonPositiveInteger|normalizedString|positiveInteger|short|string|token|unsignedByte|unsignedInt|unsignedLong|unsignedShort)

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
{DATATYPE}          {numTipos++; return DATATYPE;}
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
{NAMESPACE}         {numNamespace++; return NAMESPACEID;}
.|\n                {cout << "Erro de sintaxe: " << yytext << "\n";}
%%

int main(int argc, char ** argv)
{	
    fileList = argv + 1;         // salta nome do programa
    nFiles = argc - 1;  	     // desconsidera nome do programa
	
	yyFlexLexer lexer;	 		 // analisador léxico
    lexer.switch_streams(&fin);  // altera entrada para arquivo
	lexer.yywrap();				 // abre arquivo

	// processa arquivo aberto
	if (openFile)
	{
		// yylex chama yywrap ao final de cada arquivo
		lexer.yylex();

        // exibe as estatísticas para o arquivo processado 
    	cout << "Ocorrencia dos elementos presentes no texto\n";
        cout << "Classes: " << numClasses << "\n";
        cout << "Propriedades: " << numProperties << "\n";
        cout << "Individuos: " << numIndividuos << "\n";
        cout << "Cardinalidades: " << numCardinalidades << "\n";
        cout << "Tipos: " << numTipos << "\n";
        cout << "Namespaces: " << numNamespace << "\n";
        cout << "Simbolos: " << numSimbolos << "\n";
        cout << "Palavras reservadas: " << numReservadas << "\n";	
	}
}


// a função yylex chama yywrap para tratar EOF, 
// permitindo assim a abertura de outros aquivos

int yyFlexLexer::yywrap()
{
	// se não for o primeiro nem o último arquivo de uma sequência válida
	if ((currentFile != 0) && (nFiles > 1)) 
    {
		// exibe as estatísticas para o arquivo processado 
    	cout << "Ocorrencia dos elementos presentes no texto\n";
        cout << "Classes: " << numClasses << "\n";
        cout << "Propriedades: " << numProperties << "\n";
        cout << "Individuos: " << numIndividuos << "\n";
        cout << "Cardinalidades: " << numCardinalidades << "\n";
        cout << "Tipos: " << numTipos << "\n";
        cout << "Namespaces: " << numNamespace << "\n";
        cout << "Simbolos: " << numSimbolos << "\n";
        cout << "Palavras reservadas: " << numReservadas << "\n";	
	}

	// fecha o arquivo processado
	if (openFile)
	{    
		openFile = false;
		fin.close();
	}

	// enquanto existir arquivos para processar, tentar abrir o próximo
	while (!openFile && (fileList[currentFile] != nullptr)) 
    {
		fin.open(fileList[currentFile++]);
		if (fin.is_open()) 
        {
			openFile = true;
		}
		else
		{
			cout << fileList[currentFile-1] << " = não foi possível abrir\n";
		}		
	}

	return (openFile ? 0 : 1);	// 0 significa que tem mais entrada para processar
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