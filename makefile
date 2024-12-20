# Definições de variáveis
CC=g++
LEX=flex++

CXXFLAGS = -I"C:/msys64/usr/include" -std=c++17

# Alvo principal para gerar o arquivo compilador.exe
all: compilador.exe

# Regra para gerar o arquivo compilador.exe
compilador.exe: compilador.o parser.o lex.yy.o
	$(CC) $(CXXFLAGS) compilador.o parser.o lex.yy.o -o compilador.exe

# Regra para gerar lex.yy.cc com o Flex
lex.yy.cc: Lexico.l tokens.h
	$(LEX) Lexico.l

# Regras para gerar os arquivos objeto
compilador.o: compilador.cpp
	$(CC) $(CXXFLAGS) -c -o compilador.o compilador.cpp

parser.o: parser.cpp parser.h tokens.h
	$(CC) $(CXXFLAGS) -c -o parser.o parser.cpp

lex.yy.o: lex.yy.cc tokens.h
	$(CC) $(CXXFLAGS) -c -o lex.yy.o lex.yy.cc

# Limpeza de arquivos temporários
clean:
	rm -f lex.yy.cc lex.yy.o compilador.o parser.o compilador.exe