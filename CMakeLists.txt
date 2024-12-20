cmake_minimum_required(VERSION 3.10)
project(compilador)

# Definir o padrão C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)
set(SOURCES compilador.cpp parser.cpp ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cc)

# Incluir os diretórios necessários
include_directories(${CMAKE_SOURCE_DIR})
include_directories(C:/msys64/usr/include)

# Configuração do Flex
find_package(FLEX REQUIRED)
FLEX_TARGET(Lexico Lexico.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cc)

# Adicionar o executável
add_executable(compilador ${SOURCES} ${FLEX_Lexico_OUTPUTS})

# Garantir que a saída do Flex seja gerada corretamente
add_dependencies(compilador ${FLEX_Lexico_OUTPUTS})