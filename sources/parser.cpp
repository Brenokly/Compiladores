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
    case SOME:
    case ALL:
    case VALUE:
    case MIN:
    case MAX:
    case EXACTLY:
    case THAT:
    case NOT:
    case AND:
    case OR:
    case CLASS:
    case EQUIVALENTTO:
    case INDIVIDUALS:
    case SUBCLASSOF:
    case DISJOINTCLASSES:
    case DISJOINTWITH:
      cout << "RESERVADA: " << scanner.YYText() << "\n";
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