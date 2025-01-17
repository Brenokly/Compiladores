#include <iostream>
#include <vector>
#include <set>
#include "symtable.h"
#include "Sintatico.tab.h"
using namespace std;

extern int yyparse(); // Função gerada pelo Bison
extern FILE *yyin;    // Arquivo de entrada para o analisador léxico
extern int yylineno;  // Linha atual do analisador léxico

// Estrutura para armazenar os erros
struct Error
{
  int line;
  std::string message;
  std::string suggestion;
};

struct Classes
{
  string name;
  set<string> tipos;
};

void printClasses(const vector<Classes> &classes);

// Variáveis globais
vector<Error> errors;
vector<Classes> classes;
SymTable *currentTable = nullptr;

int main(int argc, char *argv[])
{
  system("chcp 65001 > nul");
  if (argc < 2)
  {
    std::cerr << "Uso: " << argv[0] << " <arquivo.owl>\n";
    return 1;
  }

  yyin = fopen(argv[1], "r");
  if (!yyin)
  {
    std::cerr << "Erro ao abrir o arquivo: " << argv[1] << "\n";
    return 1;
  }

  std::cout << "Iniciando análise...\n";
  if (yyparse() == 0)
  {
    std::cout << "Análise concluída com sucesso!\n";
  }
  else
  {
    cout << "\n-------------------------------------------------------------------" << endl;
    std::cerr << "Erros encontrados durante a análise." << endl;
  }

  printClasses(classes);

  // Exibir os erros, se houver
  if (!errors.empty())
  {
    for (const auto &error : errors)
    {
      if (error.message != "syntax error")
      {
        cout << "-------------------------------------------------------------------" << endl;
        std::cerr << "Erro na linha " << error.line << ": " << error.message << "\n";
        std::cerr << error.suggestion;
        cout << "\n-------------------------------------------------------------------" << endl;
      }
    }
  }

  fclose(yyin);
  return 0;
}

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