## Disciplina: Compiladores 🛠️  
### Curso: Ciência da Computação 💻  
### Universidade: UFERSA - Universidade Federal Rural do Semi-Árido 🌱  
### Ano: 2024 📅  

## Sobre o Projeto

Bem-vindo ao repositório **Compiladores**! Aqui, você encontrará o material de estudo, exercícios e implementações práticas para explorar os conceitos fundamentais da construção de compiladores, tradutores e interpretadores de linguagens de programação. Este repositório não abrange todas as fases do processo de compilação, mas vai da análise léxica à análise sintática, proporcionando uma visão prática e teórica sobre quase todo o tema.

## Linguagem OWL2 - Manchester Syntax

Este projeto foca no desenvolvimento de um analisador léxico para reconhecer tokens da linguagem **OWL2 (Web Ontology Language)** no formato **Manchester Syntax**. OWL é usada para descrever ontologias na web, conectando recursos e conceitos através de relações semânticas. O objetivo é identificar palavras reservadas, identificadores de classes e propriedades, símbolos especiais e tipos de dados dessa linguagem.

## Sumário

- [Sobre o Projeto](#sobre-o-projeto)
- [Objetivos](#objetivos)
- [Conteúdo Programático](#conteúdo-programático)
  - [Unidade I: Fundamentos da Compilação](#unidade-i-fundamentos-da-compilação)
  - [Unidade II: Análise Léxica e Sintática](#unidade-ii-análise-léxica-e-sintática)
  - [Unidade III: Análise Sintática e Geração de Código](#unidade-iii-análise-sintática-e-geração-de-código)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Referências Bibliográficas](#referências-bibliográficas)
  - [Obrigatórias](#obrigatórias)
  - [Complementares](#complementares)

---

## Objetivos  
- Entender e implementar as principais etapas de um compilador.  
- Aprender a construir e utilizar ferramentas de análise léxica e sintática.  
- Desenvolver a habilidade de gerar e otimizar código para linguagens simplificadas.  

---

## Conteúdo Programático  

### Unidade I: Fundamentos da Compilação  

Esta unidade abrange os conceitos iniciais relacionados à construção de compiladores, focando na **análise léxica**, onde o código fonte é transformado em uma sequência de tokens.

- **Arquivos envolvidos**:
  - `Lexico.exe`: Executável para rodar o analisador léxico.
  - `Lexico.l`: Arquivo fonte do analisador léxico, contendo as expressões regulares e a lógica de análise.
  - Arquivo `Teste1` & `Teste2`: Contém um arquivo de entrada para testar o funcionamento do analisador léxico.

**Como usar a Unidade I**:

Para executar a análise léxica, siga os seguintes passos após clonar o repositório:

1. Clone o repositório para o seu computador:
   ```bash
   git clone https://github.com/Brenokly/Compiladores.git
   ```

2. Abra o projeto na sua IDE de preferência na pasta do projeto que surgiu ("Compiladores") quando você clonou.

3. Abra o **Terminal** da IDE e navegue até a pasta `Unidade_1_AnalisadorLexico`, conforme o sistema operacional:

### Windows:
1. No **Terminal**, dentro da pasta do projeto "Compiladores", navegue até a pasta:
   ```bash
   cd Unidade_1_AnalisadorLexico
   ```
2. Agora, entre dentro da pasta **Windows**:
   ```bash
   cd Windows
   ``
3. Execute o analisador léxico, via terminal, passando o arquivo de teste como argumento:
   ```bash
   Lexico.exe Teste1
   ```

4. O resultado será mostrado no terminal, exibindo informações sobre **classes**, **propriedades**, **indivíduos** e **outros** elementos encontrados no arquivo.

### Linux:
1. No **Terminal**, navegue até a pasta:
   ```bash
   cd Unidade_1_AnalisadorLexico/
   ```
2. Agora, entre dentro da pasta **Linux**:
   ```bash
   cd Linux/
   ```
3. Execute o comando:
   ```bash
   ./Lexico.exe Teste1
   ```
4. O resultado será exibido no terminal conforme o esperado.

---

### Unidade II: Análise Léxica e Sintática  

---

### Unidade III: Análise Sintática e Geração de Código  

---

## Estrutura do Projeto

```plaintext
.
├── .vscode               # Configurações da IDE Visual Studio Code
├── Compilador_BAGCompiler.pdf  # Documentação técnica do compilador
├── README.md             # Documentação principal do projeto
├── Unidade_1_AnalisadorLexico/
│   ├── build_files/
│   │   ├── lex.yy.c
│   │   ├── Lexico.l
│   │   └── makefile
│   ├── Lexico.exe
│   ├── Teste1             # Arquivo de entrada para testes
│   └── Teste2
```

---

## Referências Bibliográficas  

### Obrigatórias  
- Aho, Alfred V. *Compiladores: Princípios, Técnicas e Ferramentas*. 2ª ed. Pearson Addison-Wesley, 2008. ISBN: 978-85-88639-84-9.  
- Cooper, Keith D. *Construindo Compiladores*. Elsevier, 2014. ISBN: 978-85-352-5564-5.  
- Louden, Kenneth C. *Compiladores: Princípios e Práticas*. 2ª ed. Cengage Learning, 2004. ISBN: 978-85-221-0422-2.  

### Complementares  
- Patterson, David A. *Organização e Projeto de Computadores: A Interface Hardware/Software*. Elsevier, 2014. ISBN: 978-85-352-3585-2.  
- Tanenbaum, Andrew S. *Sistemas Operacionais Modernos*. Pearson, 2010. ISBN: 978-85-7605-237-1.  
- Hopcroft, John E. *Introdução à Teoria de Autômatos, Linguagens e Computação*. Elsevier, 2002. ISBN: 85-352-1072-5.  

---

Explore, programe e aprenda! 🚀
