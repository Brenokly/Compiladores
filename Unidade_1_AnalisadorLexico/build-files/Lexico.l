%{
// Inclusões de bibliotecas
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;

// Definição de constantes
enum {SOME = 256, ALL, VALUE, MIN, MAX, EXACTLY, THAT, NOT, AND, OR, CLASS, EQUIVALENTTO, INDIVIDUALS, 
SUBCLASSOF, DISJOINTCLASSES, CLASSE, PROPERTY, ID, NUM, INDIVIDUOS, NAMESPACEID, DATATYPE, BRANCA};

// Definição da tabela de símbolos (Temporária)
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

// Definição de mapas para armazenar as ocorrências (classes, propriedades e indivíduos)
unordered_map<string, int> classes;
unordered_map<string, int> individuos;
unordered_map<string, int> propriedades;

// Definição de funções auxiliares
void inserir(int tipo, string palavra);
int buscar(string palavra);
string toLower(string str); 

// Definição de variáveis globais
char **fileList;
unsigned nFiles;
unsigned currentFile = 0;
bool openFile, erro = false;
ifstream fin;
int numClasses, numProperties, numIndividuos, numSimbolos, numReservadas, numCardinalidades, numNamespace, numTipos = 0;
int linha = 1;
%}

delim [ \t]
brancos {delim}*
letra [a-zA-Z]
maiuscula [A-Z]
minuscula [a-z]
digito [0-9]

NUM {digito}+(\.{digito}+)?([eE][+-]?{digito}+)?
RESERVADAS {maiuscula}({letra})*
PROPINVALIDA {minuscula}({letra})*{digito}+
PROPERTYS {minuscula}({letra})*
CLASS {maiuscula}({letra})*(_({letra})+)*       
SIMBOLO [\[\]\{\}\(\),\"\"|<|>|=]
INDIVIDUOS {maiuscula}({letra})*{NUM}
NAMESPACE (owl\:|rdf\:|rdfs\:|xsd\:)
DATATYPE (rational|real|langString|PlainLiteral|XMLLiteral|Literal|anyURL|base64Binary|boolean|byte|dateTime|dateTimeStamp|decimal|double|float|hexBinary|int|integer|language|long|Name|NCName|negativeInteger|NMTOKEN|nonNegativeInteger|nonPositiveInteger|normalizedString|positiveInteger|short|string|token|unsignedByte|unsignedInt|unsignedLong|unsignedShort)
%%

\n                 {linha++;}
{brancos}+         {}
{RESERVADAS}":"    {
    auto it = symbolTable.find(yytext); 
    if (it != symbolTable.end()) {
        numReservadas++;
    } else {
        cout << "Erro de sintaxe encontrado na linha " << linha << ": " << yytext << "\n";
        erro = true;
    }
}
{CLASS}            {
    auto it = symbolTable.find(toLower(yytext)); 
    if (it != symbolTable.end()) {
        numReservadas++;
    } else if (isupper(yytext[0])) {
        if (classes.find(yytext) == classes.end()) {
            classes[yytext] = 1;
        } else {
            classes[yytext]++;
        }

        numClasses++;
    } else {
        cout << "Erro de sintaxe encontrado na linha " << linha << ": " << yytext << "\n";
        erro = true;
    }
}
{DATATYPE}         { numTipos++;}
{PROPINVALIDA}     {cout << "Erro de sintaxe encontrado na linha " << linha << ": " << yytext << "\n"; erro = true;}
{PROPERTYS}        {
    auto it = symbolTable.find(toLower(yytext));
    if (it != symbolTable.end()) {
        numReservadas++;
    } else {
        if (propriedades.find(yytext) == propriedades.end()) {
            propriedades[yytext] = 1;
        } else {
            propriedades[yytext]++;
        }
        numProperties++;
    }
}
{INDIVIDUOS}       {
        numIndividuos++;        
        if (individuos.find(yytext) == individuos.end()) {
            individuos[yytext] = 1;
        } else {
            individuos[yytext]++;
        }}
{NUM}              {numCardinalidades++;}
{SIMBOLO}          {numSimbolos++;}
{NAMESPACE}        {numNamespace++;}
.                  {cout << "Erro de sintaxe encontrado na linha " << linha << ": " << yytext << "\n"; erro = true;}
%%

// Função principal
int main(int argc, char ** argv)
{	
    fileList = argv + 1;                                                        // Lista de arquivos         
    nFiles = argc - 1;                                                          // Número de arquivos
	
	yyFlexLexer lexer;	 		                                                // Instância do analisador léxico
    lexer.switch_streams(&fin);                                                 // Alterando o fluxo de entrada
	lexer.yywrap();				                                                // Inicializando o fluxo de entrada

	if (openFile) {                                                            // Verificando se o arquivo foi aberto
        lexer.yylex();

        if (erro) { return 1; }                                                // Verificando se houve erro

        cout << "===============================================" << endl;
        cout << "     Ocorrencias dos Elementos Presentes      " << endl;
        cout << "===============================================" << endl;

        // Exibindo o resumo geral
        cout << "Resumo Geral:" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Classes        : " << numClasses << endl;
        cout << "Propriedades   : " << numProperties << endl;
        cout << "Individuos     : " << numIndividuos << endl;
        cout << "Simbolos       : " << numSimbolos << endl;
        cout << "Reservadas     : " << numReservadas << endl;
        cout << "Cardinalidades : " << numCardinalidades << endl;
        cout << "Namespace      : " << numNamespace << endl;
        cout << "Tipos          : " << numTipos << endl;
        cout << "-----------------------------------------------" << endl;

        // Exibindo as classes
        cout << "Classes Encontradas:" << endl;
        cout << "-----------------------------------------------" << endl;
        for (auto it = classes.begin(); it != classes.end(); it++) {
            cout << it->first << ": " << it->second << endl;
        }
        cout << "-----------------------------------------------" << endl;

        // Exibindo as propriedades
        cout << "Propriedades Encontradas:" << endl;
        cout << "-----------------------------------------------" << endl;
        for (auto it = propriedades.begin(); it != propriedades.end(); it++) {
            cout << it->first << ": " << it->second << endl;
        }
        cout << "-----------------------------------------------" << endl;

        // Exibindo os indivíduos
        cout << "Individuos Encontrados:" << endl;
        cout << "-----------------------------------------------" << endl;
        for (auto it = individuos.begin(); it != individuos.end(); it++) {
            cout << it->first << ": " << it->second << endl;
        }
        cout << "===============================================" << endl;
        cout << "\nApenas classes, propriedades e individuos foram exibidos por uma questao de estetica!\n" << endl;
    }
}

// Função de finalização
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
			cout << fileList[currentFile-1] << " = não foi possível abrir\n";
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