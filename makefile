# Compiladores
CC=g++
LEX=flex++

# Dependências
all: Lexico

Lexico: lex.yy.cc
	$(CC) lex.yy.cc -std=c++17 -I"C:\msys64\usr\include" -o Lexico

lex.yy.cc: Lexico.l
	$(LEX) Lexico.l

clean:
	rm -f Lexico lex.yy.cc