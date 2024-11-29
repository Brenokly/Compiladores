cmake_minimum_required(VERSION 3.10)
project(Lexer)

set(CMAKE_CXX_STANDARD 17)

# Adicionar os arquivos de código-fonte
set(SOURCE_FILES lexer.cpp main.cpp error.cpp)

# Criar o executável
add_executable(lexer ${SOURCE_FILES})