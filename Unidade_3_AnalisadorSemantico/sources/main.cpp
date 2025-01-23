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
  unordered_map<string, set<string>> propriedades{
      {"Data Property", {}},
      {"Object Property", {}}};
};

extern int yyparse(); // Função gerada pelo Bison
extern FILE *yyin;    // Arquivo de entrada para o analisador léxico
extern int yylineno;  // Linha atual do analisador léxico
void printErrors(const vector<Error> &errors);
void exibirClasses(const vector<Classes> &classes);

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
    cout << "\n\tInformações das classes:\n\n";

    exibirClasses(classes); // Exibir as classes (Não é necessário para a Unidade 3)
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

// Função para exibir o vetor de Classes
void exibirClasses(const vector<Classes> &classes)
{
  for (const auto &classe : classes)
  {
    cout << "=============================\n";
    cout << "| Classe: " << classe.name << "\n";
    cout << "=============================\n";

    // Exibir tipos da classe
    cout << "| Tipos\n";
    cout << "| {\n";
    if (classe.tipos.empty())
    {
      cout << "|   [Nenhum tipo definido]\n";
    }
    else
    {
      for (const auto &tipo : classe.tipos)
      {
        cout << "|   - " << tipo << "\n";
      }
    }
    cout << "| }\n";

    // Exibir propriedades
    cout << "| Propriedades\n";
    cout << "| {\n";
    for (const auto &[tipoPropriedade, propriedades] : classe.propriedades)
    {
      cout << "|   " << tipoPropriedade << "\n";
      cout << "|   {\n";
      if (propriedades.empty())
      {
        cout << "|     [Nenhuma propriedade encontrada]\n";
      }
      else
      {
        for (const auto &propriedade : propriedades)
        {
          cout << "|     - " << propriedade << "\n";
        }
      }
      cout << "|   }\n";
    }
    cout << "| }\n";
    cout << "=============================\n\n";
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