#include <iostream>
#include <fstream>
#include "parser.h"
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2) // Verifica se foi passado exatamente um argumento
    {
        cerr << "Uso: " << argv[0] << " <arquivo_de_entrada>" << endl;
        return 1;
    }

    const char *filename = argv[1]; // Nome do arquivo passado como argumento
    ifstream input(filename);

    if (!input) // Verifica se o arquivo foi aberto corretamente
    {
        cerr << "Erro ao abrir o arquivo: " << filename << endl;
        return 1;
    }

    Parser parser;
    parser.Start(input); // Passa o arquivo de entrada para o parser

    return 0;
}