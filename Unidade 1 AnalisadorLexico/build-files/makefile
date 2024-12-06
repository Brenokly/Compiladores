CC=g++
LEX=flex++

# Diretório onde o executável deve ser gerado
TARGET_DIR=..

all: $(TARGET_DIR)/Lexico.exe

$(TARGET_DIR)/Lexico.exe: lex.yy.cc
	$(CC) lex.yy.cc -std=c++17 -I"C:\msys64\usr\include" -o $(TARGET_DIR)/Lexico.exe

lex.yy.cc: Lexico.l
	$(LEX) Lexico.l

clean:
	rm -f lex.yy.cc $(TARGET_DIR)/Lexico.exe