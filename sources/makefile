# Definições de variáveis
CC=g++
LEX=flex++
BISON=bison
INCLUDES=-IC:/msys64/usr/include
SOURCES=../sources
BUILDS=../builds
EXE=..

# Alvo principal para gerar o arquivo compilador.exe
all: $(EXE)/compilador.exe

# Regra para gerar o arquivo compilador.exe
$(EXE)/compilador.exe: $(BUILDS)/compilador.o $(BUILDS)/parser.o $(BUILDS)/lex.yy.o $(BUILDS)/symtable.o
	$(CC) $(INCLUDES) $(BUILDS)/compilador.o $(BUILDS)/parser.o $(BUILDS)/lex.yy.o $(BUILDS)/symtable.o -o $(EXE)/compilador.exe

# Regra para gerar lex.yy.cc com o Flex (arquivo ficará em sources)
$(SOURCES)/lex.yy.cc: $(SOURCES)/Lexico.l $(SOURCES)/Sintatico.tab.h
	$(LEX) $(SOURCES)/Lexico.l > $(SOURCES)/lex.yy.cc

# Regra para gerar o arquivo de tokens com o Bison
$(SOURCES)/Sintatico.tab.h: $(SOURCES)/Sintatico.y
	$(BISON) -d $(SOURCES)/Sintatico.y

# Regra para compilar o código do parser gerado pelo Bison
$(BUILDS)/parser.o: $(SOURCES)/parser.cpp $(SOURCES)/Sintatico.tab.h
	$(CC) $(INCLUDES) -c -o $(BUILDS)/parser.o $(SOURCES)/parser.cpp

# Regra para compilar o código do scanner gerado pelo Flex
$(BUILDS)/lex.yy.o: $(SOURCES)/lex.yy.cc $(SOURCES)/Sintatico.tab.h
	$(CC) $(INCLUDES) -c -o $(BUILDS)/lex.yy.o $(SOURCES)/lex.yy.cc

# Regra para compilar o arquivo symtable.cpp
$(BUILDS)/symtable.o: $(SOURCES)/symtable.cpp $(SOURCES)/Sintatico.tab.h
	$(CC) $(INCLUDES) -c -o $(BUILDS)/symtable.o $(SOURCES)/symtable.cpp

# Regra para compilar o código restante
$(BUILDS)/compilador.o: $(SOURCES)/compilador.cpp $(SOURCES)/Sintatico.tab.h
	$(CC) $(INCLUDES) -c -o $(BUILDS)/compilador.o $(SOURCES)/compilador.cpp

# Limpeza de arquivos temporários
clean:
	rm -f $(BUILDS)/*.o $(SOURCES)/lex.yy.* $(SOURCES)/Sintatico.tab.* $(EXE)/compilador.exe