#include "parser.h"
#include <iostream>
using namespace std;

// Definição do método Start que recebe um stream de entrada
void Parser::Start(istream &input)
{
  // Associa o scanner (Flex) ao stream de entrada
  scanner.switch_streams(&input, &cout); // Scanner vai ler de 'input' e escrever em 'cout'

  // Inicia o parsing
  yyparse(); // Chama o parser gerado pelo Bison
}