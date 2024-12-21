#include "parser.h"
#include "tokens.h"
#include <iostream>
using namespace std;

void Parser::Start()
{
  while ((lookahead = scanner.yylex()) != 0)
  {
    switch (lookahead)
    {
    case TAG_RESERVADAS:
      cout << "RESERVADAS: " << scanner.YYText() << "\n";
      break;
    case TAG_CLASS:
      cout << "CLASS: " << scanner.YYText() << "\n";
      break;
    case TAG_PROPERTY:
      cout << "PROPERTY: " << scanner.YYText() << "\n";
      break;
    case TAG_INDIVIDUOS:
      cout << "INDIVIDUOS: " << scanner.YYText() << "\n";
      break;
    case TAG_NAMESPACE:
      cout << "NAMESPACE: " << scanner.YYText() << "\n";
      break;
    case TAG_DATATYPE:
      cout << "DATATYPE: " << scanner.YYText() << "\n";
      break;
    case TAG_BRANCA:
      cout << "BRANCA: " << scanner.YYText() << "\n";
      break;
    case TAG_NUM:
      cout << "NUM: " << scanner.YYText() << "\n";
      break;
    case TAG_SIMBOLO:
      cout << "SIMBOLO: " << scanner.YYText() << "\n";
      break;
    default:
      cout << "Token desconhecido\n";
      break;
    }
  }
}