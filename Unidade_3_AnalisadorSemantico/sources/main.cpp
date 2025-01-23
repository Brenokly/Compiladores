//--------------------------------------------------------------------------
// Inclusões de bibliotecas
#include <iostream>
#include <vector>
#include <set>
#include "symtable.h"
#include "Sintatico.tab.h"
using namespace std;
//--------------------------------------------------------------------------
// Declaração de variáveis e funções globais

// Estrutura para armazenar os erros
struct Error
{
  int line;
  string message;
  string suggestion;
};

// Estrutura para armazenar as classes e seus tipos
struct Classes
{
  string name;
  set<string> tipos;
};

extern int yyparse(); // Função gerada pelo Bison
extern FILE *yyin;    // Arquivo de entrada para o analisador léxico
extern int yylineno;  // Linha atual do analisador léxico
void printClasses(const vector<Classes> &classes);
void printErrors(const vector<Error> &errors);

// Variáveis globais
vector<Error> errors;
vector<Classes> classes;
SymTable *globalTable = new SymTable(std::string("Escopo Global"));
SymTable *currentTable = globalTable;

//--------------------------------------------------------------------------

int main(int argc, char *argv[])
{
#if defined(_WIN32) || defined(_WIN64)
  system("chcp 65001 > nul"); // Configura o terminal para UTF-8
#endif

  if (argc < 2)
  {
    cerr << "Uso: " << argv[0] << " <arquivo.owl>\n";
    return 1;
  }

  yyin = fopen(argv[1], "r");
  if (!yyin)
  {
    cerr << "Erro ao abrir o arquivo: " << argv[1] << "\n";
    return 1;
  }
  cout << "------------------------------------" << endl;
  cout << "Iniciando análise...\n";
  if (yyparse() == 0 && errors.empty())
  {
    cout << "------------------------------------" << endl;
    cout << "Análise concluída com sucesso!" << endl;
    cout << "------------------------------------\n";

    // printClasses(classes); // Exibir as classes (Não é necessário para a Unidade 3)
  }
  else
  {
    cout << "------------------------------------" << endl;
    cerr << "Erros encontrados durante a análise!" << endl;
    cout << "------------------------------------\n";
    cout << "Erros:\n\n";
  }

  // Exibir os erros, se houver
  if (!errors.empty())
  {
    printErrors(errors);
  }

  fclose(yyin);
  return 0;
}

// Função para exibir as classes e seus tipos
void printClasses(const vector<Classes> &classes)
{
  cout << "Lista de Classes:\n";
  cout << "=================\n";

  for (const auto &cls : classes)
  {
    cout << "Classe: " << cls.name << "\n";
    cout << "Tipos: ";
    if (cls.tipos.empty())
    {
      cout << "Nenhum tipo registrado.\n";
    }
    else
    {
      bool first = true;
      for (const auto &tipo : cls.tipos)
      {
        if (!first)
          cout << ", ";
        cout << tipo;
        first = false;
      }
      cout << "\n";
    }
    cout << "-----------------\n";
  }
}

// Função para exibir os erros
void printErrors(const vector<Error> &errors)
{
  int count = 1;
  for (const auto &error : errors)
  {
    if (error.message != "syntax error")
    {
      cerr << count << "°: " << "Erro na linha " << error.line << ": " << error.message << "\n";
      cerr << error.suggestion;
      cout << "\n-------------------------------------------------------------------" << endl;
      count++;
    }
  }
}