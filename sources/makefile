# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Ferramentas Flex e Bison
FLEX = flex
BISON = bison

# Arquivos fonte
LEXER = Lexico.l
PARSER = Sintatico.y
SYMTABLE = symtable.cpp
MAIN = main.cpp

# Arquivos gerados
LEXER_OUT = lex.yy.c
PARSER_OUT = Sintatico.tab.c
PARSER_HEADER = Sintatico.tab.h

# Nome do executável
EXEC = owl_compiler

# Diretório de saída do executável
EXE = ..

# Regras padrão
all: $(EXEC)

$(EXEC): $(LEXER_OUT) $(PARSER_OUT) $(SYMTABLE) $(MAIN)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $^ 
	mv $(EXEC) $(EXE)/$(EXEC)           

$(LEXER_OUT): $(LEXER)
	$(FLEX) -o $@ $<

$(PARSER_OUT): $(PARSER)
	$(BISON) -d -o $@ $<

clean:
	rm -f $(LEXER_OUT) $(PARSER_OUT) $(PARSER_HEADER) $(EXE)/$(EXEC)