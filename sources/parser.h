#include <istream>
#include "FlexLexer.h"
#include "Sintatico.tab.h"

class Parser
{
private:
  yyFlexLexer scanner; // Scanner gerado pelo Flex

public:
  void Start(std::istream &input); // Recebe um stream de entrada
};