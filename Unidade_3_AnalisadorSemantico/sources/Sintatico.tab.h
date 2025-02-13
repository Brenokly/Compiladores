/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SINTATICO_TAB_H_INCLUDED
# define YY_YY_SINTATICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TAG_NUMD = 258,                /* TAG_NUMD  */
    TAG_NUMI = 259,                /* TAG_NUMI  */
    TAG_CLASS = 260,               /* TAG_CLASS  */
    TAG_INDIVIDUOS = 261,          /* TAG_INDIVIDUOS  */
    TAG_NAMESPACE = 262,           /* TAG_NAMESPACE  */
    TAG_PROPERTY = 263,            /* TAG_PROPERTY  */
    TAG_DATATYPE = 264,            /* TAG_DATATYPE  */
    ONLY = 265,                    /* ONLY  */
    SOME = 266,                    /* SOME  */
    ALL = 267,                     /* ALL  */
    VALUE = 268,                   /* VALUE  */
    MIN = 269,                     /* MIN  */
    MAX = 270,                     /* MAX  */
    EXACTLY = 271,                 /* EXACTLY  */
    THAT = 272,                    /* THAT  */
    NOT = 273,                     /* NOT  */
    AND = 274,                     /* AND  */
    OR = 275,                      /* OR  */
    CLASS = 276,                   /* CLASS  */
    EQUIVALENTTO = 277,            /* EQUIVALENTTO  */
    INDIVIDUALS = 278,             /* INDIVIDUALS  */
    SUBCLASSOF = 279,              /* SUBCLASSOF  */
    DISJOINTCLASSES = 280,         /* DISJOINTCLASSES  */
    DISJOINTWITH = 281,            /* DISJOINTWITH  */
    ERROR = 282,                   /* ERROR  */
    TAG_MENORIGUAL = 283,          /* TAG_MENORIGUAL  */
    TAG_MAIORIGUAL = 284,          /* TAG_MAIORIGUAL  */
    TAG_MENOR = 285,               /* TAG_MENOR  */
    TAG_MAIOR = 286,               /* TAG_MAIOR  */
    TAG_ABRECOLCHETE = 287,        /* TAG_ABRECOLCHETE  */
    TAG_FECHACOLCHETE = 288,       /* TAG_FECHACOLCHETE  */
    TAG_ABRECHAVE = 289,           /* TAG_ABRECHAVE  */
    TAG_FECHACHAVE = 290,          /* TAG_FECHACHAVE  */
    TAG_ABREPARANTESIS = 291,      /* TAG_ABREPARANTESIS  */
    TAG_FECHAPARANTESIS = 292,     /* TAG_FECHAPARANTESIS  */
    TAG_VIRGULA = 293,             /* TAG_VIRGULA  */
    TAG_DOISPONTOS = 294           /* TAG_DOISPONTOS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 72 "Sintatico.y"

    double numD;
    int numI;
    const char * str;

#line 109 "Sintatico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SINTATICO_TAB_H_INCLUDED  */
