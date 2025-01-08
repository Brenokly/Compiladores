#include <iostream>
#include <vector>
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

// Variáveis globais

vector<Error> errors;
SymTable *currentTable = nullptr;

int main(int argc, char *argv[])
{
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
    std::cerr << "Erros encontrados durante a análise.\n";
  }

  // Exibir os erros, se houver
  if (!errors.empty())
  {
    cout << "-------------------------------------------------------------------" << endl;
    for (const auto &error : errors)
    {
      std::cerr << "Erro na linha " << error.line << ": " << error.message << "\n";
      std::cerr << error.suggestion;
      cout << "-------------------------------------------------------------------" << endl;
    }
  }

  fclose(yyin);
  return 0;
}