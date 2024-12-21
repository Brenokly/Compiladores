# Definições de variáveis
CC=g++
LEX=flex++
INCLUDES=-IC:/msys64/usr/include
SOURCES=../sources
BUILDS=../builds
EXE=..

# Alvo principal para gerar o arquivo compilador.exe
all: $(EXE)/compilador.exe

# Regra para gerar o arquivo compilador.exe
$(EXE)/compilador.exe: $(BUILDS)/compilador.o $(BUILDS)/parser.o $(BUILDS)/lex.yy.o
	$(CC) $(INCLUDES) $(BUILDS)/compilador.o $(BUILDS)/parser.o $(BUILDS)/lex.yy.o -o $(EXE)/compilador.exe

# Regra para gerar lex.yy.cc com o Flex (arquivo ficará em sources)
$(SOURCES)/lex.yy.cc: $(SOURCES)/Lexico.l $(SOURCES)/tokens.h
	$(LEX) $(SOURCES)/Lexico.l > $(SOURCES)/lex.yy.cc

# Regras para gerar os arquivos objeto
$(BUILDS)/compilador.o: $(SOURCES)/compilador.cpp
	$(CC) $(INCLUDES) -c -o $(BUILDS)/compilador.o $(SOURCES)/compilador.cpp

$(BUILDS)/parser.o: $(SOURCES)/parser.cpp $(SOURCES)/parser.h $(SOURCES)/tokens.h
	$(CC) $(INCLUDES) -c -o $(BUILDS)/parser.o $(SOURCES)/parser.cpp

$(BUILDS)/lex.yy.o: $(SOURCES)/lex.yy.cc $(SOURCES)/tokens.h
	$(CC) $(INCLUDES) -c -o $(BUILDS)/lex.yy.o $(SOURCES)/lex.yy.cc

# Limpeza de arquivos temporários
clean:
	rm -f $(BUILDS)/*.o $(SOURCES)/lex.yy.* $(EXE)/compilador.exe