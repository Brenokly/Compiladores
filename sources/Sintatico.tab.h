
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TAG_CLASS = 258,
     TAG_INDIVIDUOS = 259,
     TAG_NAMESPACE = 260,
     TAG_PROPERTY = 261,
     TAG_DATATYPE = 262,
     TAG_NUM = 263,
     ONLY = 264,
     SOME = 265,
     ALL = 266,
     VALUE = 267,
     MIN = 268,
     MAX = 269,
     EXACTLY = 270,
     THAT = 271,
     NOT = 272,
     AND = 273,
     OR = 274,
     CLASS = 275,
     EQUIVALENTTO = 276,
     INDIVIDUALS = 277,
     SUBCLASSOF = 278,
     DISJOINTCLASSES = 279,
     DISJOINTWITH = 280,
     TAG_MENORIGUAL = 281,
     TAG_MAIORIGUAL = 282,
     TAG_MENOR = 283,
     TAG_MAIOR = 284,
     TAG_ABRECOLCHETE = 285,
     TAG_FECHACOLCHETE = 286,
     TAG_ABRECHAVE = 287,
     TAG_FECHACHAVE = 288,
     TAG_ABREPARANTESIS = 289,
     TAG_FECHAPARANTESIS = 290,
     TAG_VIRGULA = 291,
     TAG_DOISPONTOS = 292
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 28 "Sintatico.y"

    double num;
    char *str;



/* Line 1676 of yacc.c  */
#line 96 "Sintatico.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


