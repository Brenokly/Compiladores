/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "Sintatico.y"

//----------------------------------------------
// Includes
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cctype>    
#include <unordered_map>
#include <stack>
#include <functional>
using namespace std;
//----------------------------------------------
// Definição da estrutura Error
struct Error
{
    int line;
    string message;
    string suggestion;
};

// Definição da estrutura de Classes
struct Classes
{
  string name;
  set<string> tipos;
  unordered_map<string, set<string>> propriedades;
};

// Variáveis Externas
extern int yylineno;
extern vector<Error> errors;
extern vector<Classes> classes;

// Variáveis Globais que auxiliam na análise
set<string> t;                          // Serve para guarda os possíveis tipos de uma Classe
set<string> theLastProp;                // Serve para guardar as propriedades de um fechamento
set<string> props;                      // Serve para identificar se todas as classes foram fechadas
bool isFechamento = false;              // Serve para identificar se a estrutura é de fechamento
bool fechada = false;                   // Auxilia a variável isFechamento!
bool isClass = false;                   // Serve para identificar se a estrutura é de classe
stack<string> properties;               // Serve para guardar as propriedades de uma classe
stack<string> posproperties;            // Serve para guardar o tipo de propriedade que aparecem em suas ordens
unordered_map<string, set<string>> p    // Tipo de cada propriedade
{
    {"Data Property", {}},
    {"Object Property", {}},
    {"Nenhum Tipo", {}}
};

// Funções Obrigatórias do Bison e Flex
int yylex(void);
int yyparse(void);
void yyerror(const char *msg);

// Funções auxiliares de validação
bool is_valid_xsd_type(const std::string& datatype);
bool is_valid_owl_type(const std::string& datatype);
bool is_valid_rdf_type(const std::string& datatype);
bool is_valid_rdfs_type(const std::string& datatype);
bool is_namespace_valid(const std::string& space);
bool is_int_type(const std::string& space);
bool is_decimal_type(const std::string& space);
void class_declaration(const char * name);
void tag_class_der(const char * name);
void expression_der(const char * name);
const char * namespace_datatype_der(const char * name, const char * datatype);

#line 142 "Sintatico.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "Sintatico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TAG_NUMD = 3,                   /* TAG_NUMD  */
  YYSYMBOL_TAG_NUMI = 4,                   /* TAG_NUMI  */
  YYSYMBOL_TAG_CLASS = 5,                  /* TAG_CLASS  */
  YYSYMBOL_TAG_INDIVIDUOS = 6,             /* TAG_INDIVIDUOS  */
  YYSYMBOL_TAG_NAMESPACE = 7,              /* TAG_NAMESPACE  */
  YYSYMBOL_TAG_PROPERTY = 8,               /* TAG_PROPERTY  */
  YYSYMBOL_TAG_DATATYPE = 9,               /* TAG_DATATYPE  */
  YYSYMBOL_ONLY = 10,                      /* ONLY  */
  YYSYMBOL_SOME = 11,                      /* SOME  */
  YYSYMBOL_ALL = 12,                       /* ALL  */
  YYSYMBOL_VALUE = 13,                     /* VALUE  */
  YYSYMBOL_MIN = 14,                       /* MIN  */
  YYSYMBOL_MAX = 15,                       /* MAX  */
  YYSYMBOL_EXACTLY = 16,                   /* EXACTLY  */
  YYSYMBOL_THAT = 17,                      /* THAT  */
  YYSYMBOL_NOT = 18,                       /* NOT  */
  YYSYMBOL_AND = 19,                       /* AND  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_CLASS = 21,                     /* CLASS  */
  YYSYMBOL_EQUIVALENTTO = 22,              /* EQUIVALENTTO  */
  YYSYMBOL_INDIVIDUALS = 23,               /* INDIVIDUALS  */
  YYSYMBOL_SUBCLASSOF = 24,                /* SUBCLASSOF  */
  YYSYMBOL_DISJOINTCLASSES = 25,           /* DISJOINTCLASSES  */
  YYSYMBOL_DISJOINTWITH = 26,              /* DISJOINTWITH  */
  YYSYMBOL_ERROR = 27,                     /* ERROR  */
  YYSYMBOL_TAG_MENORIGUAL = 28,            /* TAG_MENORIGUAL  */
  YYSYMBOL_TAG_MAIORIGUAL = 29,            /* TAG_MAIORIGUAL  */
  YYSYMBOL_TAG_MENOR = 30,                 /* TAG_MENOR  */
  YYSYMBOL_TAG_MAIOR = 31,                 /* TAG_MAIOR  */
  YYSYMBOL_TAG_ABRECOLCHETE = 32,          /* TAG_ABRECOLCHETE  */
  YYSYMBOL_TAG_FECHACOLCHETE = 33,         /* TAG_FECHACOLCHETE  */
  YYSYMBOL_TAG_ABRECHAVE = 34,             /* TAG_ABRECHAVE  */
  YYSYMBOL_TAG_FECHACHAVE = 35,            /* TAG_FECHACHAVE  */
  YYSYMBOL_TAG_ABREPARANTESIS = 36,        /* TAG_ABREPARANTESIS  */
  YYSYMBOL_TAG_FECHAPARANTESIS = 37,       /* TAG_FECHAPARANTESIS  */
  YYSYMBOL_TAG_VIRGULA = 38,               /* TAG_VIRGULA  */
  YYSYMBOL_TAG_DOISPONTOS = 39,            /* TAG_DOISPONTOS  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_ontology = 41,                  /* ontology  */
  YYSYMBOL_declarations = 42,              /* declarations  */
  YYSYMBOL_class_declaration = 43,         /* class_declaration  */
  YYSYMBOL_class_type = 44,                /* class_type  */
  YYSYMBOL_primitive_class = 45,           /* primitive_class  */
  YYSYMBOL_defined_class = 46,             /* defined_class  */
  YYSYMBOL_pos_defined_class = 47,         /* pos_defined_class  */
  YYSYMBOL_optional_subclass = 48,         /* optional_subclass  */
  YYSYMBOL_expression_list = 49,           /* expression_list  */
  YYSYMBOL_list_expression = 50,           /* list_expression  */
  YYSYMBOL_pos_class = 51,                 /* pos_class  */
  YYSYMBOL_additional_classes = 52,        /* additional_classes  */
  YYSYMBOL_expression_format = 53,         /* expression_format  */
  YYSYMBOL_simple_expression = 54,         /* simple_expression  */
  YYSYMBOL_simples_expression_no_parent = 55, /* simples_expression_no_parent  */
  YYSYMBOL_complex_expression = 56,        /* complex_expression  */
  YYSYMBOL_additional_expressions = 57,    /* additional_expressions  */
  YYSYMBOL_additional_expressions_parent = 58, /* additional_expressions_parent  */
  YYSYMBOL_additional_expressions_no_parent = 59, /* additional_expressions_no_parent  */
  YYSYMBOL_element = 60,                   /* element  */
  YYSYMBOL_elements = 61,                  /* elements  */
  YYSYMBOL_expression = 62,                /* expression  */
  YYSYMBOL_pos_property = 63,              /* pos_property  */
  YYSYMBOL_corp_expre1 = 64,               /* corp_expre1  */
  YYSYMBOL_corp_expre2 = 65,               /* corp_expre2  */
  YYSYMBOL_corp_expre3 = 66,               /* corp_expre3  */
  YYSYMBOL_sub_corp = 67,                  /* sub_corp  */
  YYSYMBOL_object_property = 68,           /* object_property  */
  YYSYMBOL_separador = 69,                 /* separador  */
  YYSYMBOL_pos_value = 70,                 /* pos_value  */
  YYSYMBOL_type_expre = 71,                /* type_expre  */
  YYSYMBOL_class_body = 72,                /* class_body  */
  YYSYMBOL_disjointclasses_section = 73,   /* disjointclasses_section  */
  YYSYMBOL_individuals_section = 74,       /* individuals_section  */
  YYSYMBOL_individuals_list = 75,          /* individuals_list  */
  YYSYMBOL_class_list = 76,                /* class_list  */
  YYSYMBOL_class_v = 77,                   /* class_v  */
  YYSYMBOL_class_op = 78,                  /* class_op  */
  YYSYMBOL_class_l = 79,                   /* class_l  */
  YYSYMBOL_list = 80,                      /* list  */
  YYSYMBOL_list_class = 81,                /* list_class  */
  YYSYMBOL_op_quantifier = 82,             /* op_quantifier  */
  YYSYMBOL_op_logic = 83,                  /* op_logic  */
  YYSYMBOL_op_rel = 84,                    /* op_rel  */
  YYSYMBOL_op_cardinality = 85,            /* op_cardinality  */
  YYSYMBOL_namespace_datatype = 86         /* namespace_datatype  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   201

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   102,   102,   103,   108,   109,   114,   115,   120,   121,
     122,   123,   128,   129,   134,   139,   140,   144,   145,   146,
     151,   152,   153,   154,   155,   160,   165,   170,   171,   176,
     177,   182,   183,   184,   188,   189,   190,   191,   196,   197,
     198,   199,   200,   201,   206,   207,   211,   212,   213,   214,
     215,   219,   220,   221,   225,   229,   230,   231,   236,   237,
     238,   239,   243,   244,   245,   250,   251,   252,   253,   254,
     259,   260,   265,   266,   267,   268,   272,   273,   274,   278,
     279,   284,   285,   290,   291,   292,   297,   298,   305,   312,
     313,   314,   315,   319,   320,   321,   322,   323,   327,   328,
     329,   330,   334,   335,   339,   340,   341,   346,   347,   348,
     353,   354,   355,   360,   361,   366,   367,   368,   369,   374,
     375,   380,   381,   382,   383,   388,   389,   394,   395,   400,
     401,   402,   403,   408,   409,   410,   415
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TAG_NUMD", "TAG_NUMI",
  "TAG_CLASS", "TAG_INDIVIDUOS", "TAG_NAMESPACE", "TAG_PROPERTY",
  "TAG_DATATYPE", "ONLY", "SOME", "ALL", "VALUE", "MIN", "MAX", "EXACTLY",
  "THAT", "NOT", "AND", "OR", "CLASS", "EQUIVALENTTO", "INDIVIDUALS",
  "SUBCLASSOF", "DISJOINTCLASSES", "DISJOINTWITH", "ERROR",
  "TAG_MENORIGUAL", "TAG_MAIORIGUAL", "TAG_MENOR", "TAG_MAIOR",
  "TAG_ABRECOLCHETE", "TAG_FECHACOLCHETE", "TAG_ABRECHAVE",
  "TAG_FECHACHAVE", "TAG_ABREPARANTESIS", "TAG_FECHAPARANTESIS",
  "TAG_VIRGULA", "TAG_DOISPONTOS", "$accept", "ontology", "declarations",
  "class_declaration", "class_type", "primitive_class", "defined_class",
  "pos_defined_class", "optional_subclass", "expression_list",
  "list_expression", "pos_class", "additional_classes",
  "expression_format", "simple_expression", "simples_expression_no_parent",
  "complex_expression", "additional_expressions",
  "additional_expressions_parent", "additional_expressions_no_parent",
  "element", "elements", "expression", "pos_property", "corp_expre1",
  "corp_expre2", "corp_expre3", "sub_corp", "object_property", "separador",
  "pos_value", "type_expre", "class_body", "disjointclasses_section",
  "individuals_section", "individuals_list", "class_list", "class_v",
  "class_op", "class_l", "list", "list_class", "op_quantifier", "op_logic",
  "op_rel", "op_cardinality", "namespace_datatype", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-134)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-9)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      60,  -134,   111,    57,  -134,    65,  -134,   109,  -134,  -134,
    -134,    80,   110,   129,    96,    85,   104,   133,    94,  -134,
    -134,  -134,  -134,    70,  -134,    19,    23,    37,  -134,    97,
     141,  -134,   110,  -134,  -134,  -134,   126,  -134,  -134,  -134,
    -134,    48,   124,  -134,    22,  -134,  -134,   155,  -134,  -134,
    -134,  -134,    30,   166,   100,   138,  -134,   163,    18,  -134,
    -134,  -134,  -134,   137,   169,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,     3,    70,   152,  -134,  -134,   167,
     148,  -134,  -134,  -134,   145,  -134,  -134,  -134,  -134,  -134,
    -134,   160,  -134,  -134,  -134,    67,    67,  -134,    69,  -134,
    -134,  -134,    70,   127,     6,   170,    14,  -134,  -134,  -134,
     174,  -134,   106,   143,     8,    76,   131,   144,     9,  -134,
    -134,   177,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,    16,  -134,   182,    63,   147,  -134,
    -134,   184,  -134,    59,   152,   185,   134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,   159,   186,   136,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,    63,  -134,  -134,     3,    63,
    -134,  -134,  -134,  -134,  -134,     7,    15,  -134,  -134,  -134,
    -134,    17,  -134,  -134,  -134,  -134,  -134,  -134,    63,  -134
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     2,     4,     7,     0,     1,     5,
      10,     0,    13,    97,     0,    19,    20,     0,     0,    14,
      15,    23,    24,    22,    12,     0,     0,     0,     6,    93,
      94,    11,    18,     9,   127,   128,     0,    81,    21,    29,
      30,     0,    82,    61,     0,   125,   126,     0,   133,   134,
     135,    58,     0,     0,   105,     0,    25,     0,     0,    82,
     103,   102,   100,   111,     0,    98,   107,   101,    99,    95,
      96,    17,    43,    33,     0,    32,    28,    75,    72,     0,
       0,    59,    73,    60,    86,    84,    83,    85,    64,    69,
      65,     0,    62,    66,    68,     0,     0,    63,     0,    16,
      37,    36,    34,     0,     0,     0,     0,    55,    31,    26,
       0,   136,   116,     0,     0,     0,   122,     0,     0,    78,
      79,     0,    70,    76,    77,    80,    71,   106,   104,    35,
     112,   110,   109,   108,     0,    42,     0,    41,     0,    44,
      45,     0,    54,     0,    28,     0,     0,    74,   114,   113,
      89,   132,   130,   131,   129,     0,     0,     0,    67,   120,
     119,    57,    56,    50,    40,    39,    53,    48,     0,    52,
      27,   118,   117,   115,    90,     0,     0,   124,   123,   121,
      38,     0,    51,    92,    88,    91,    87,    49,    47,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,   183,  -134,  -134,  -134,  -134,  -134,  -134,    81,
    -134,  -134,    45,  -134,  -134,   -61,  -134,  -133,  -134,  -134,
      47,    24,   -11,  -134,  -134,  -134,  -134,    95,  -134,   -10,
    -134,    35,  -134,   164,   168,   -22,   171,   -59,  -134,    49,
     149,    36,  -134,   -14,  -134,  -134,  -134
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,    13,    14,    15,    19,    33,    20,
      21,    22,   109,    38,    39,    56,    40,   138,   139,   140,
     141,   106,   142,    51,    92,    97,    81,   122,   123,   143,
      88,   124,    28,    29,    30,    55,    65,    66,    83,   114,
     125,   118,    52,    59,   155,    53,    84
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,    23,    42,    61,   164,   104,    41,   132,   183,   148,
     159,    17,    57,    58,   108,   135,   185,   161,   187,   101,
      60,    23,    17,    77,    62,    54,    17,    78,    63,    79,
      75,    89,   180,    34,    35,    90,   182,    79,    67,   105,
     184,   129,    63,   133,   131,   149,   160,   102,   186,    73,
     136,   137,    37,   162,   188,   189,    17,     8,    80,    64,
     167,     1,   110,   107,    57,    58,    91,    17,   119,   113,
     127,    17,   120,    64,    79,    54,   128,   150,    17,    82,
     117,     2,    34,    35,    74,    16,     2,    93,    17,    34,
      35,    57,    58,    24,   134,   168,    -8,    31,   146,   136,
      54,    37,   157,   121,   151,   152,   153,   154,    37,    32,
      10,   145,     6,    71,    18,    16,     7,    -8,    17,    -8,
      25,    -8,    -8,    34,    35,    34,    35,    72,   130,    76,
     110,    11,    63,    12,    43,   172,   156,   178,    98,   112,
      36,   116,    37,    44,    45,    46,    47,    48,    49,    50,
      34,    35,    25,   112,    26,    27,    17,   107,    85,    86,
     174,    87,   175,   176,   100,   116,    26,    27,    17,    95,
      96,    34,    35,    99,    63,   103,   111,   115,    17,   144,
     147,   158,   116,   163,   165,   166,   171,   177,     9,   170,
     169,   126,   181,   179,    70,   173,     0,    69,    68,     0,
       0,    94
};

static const yytype_int16 yycheck[] =
{
      11,    12,    16,    25,   137,    64,    16,     1,     1,     1,
       1,     8,    23,    23,    75,     1,     1,     1,     1,     1,
       1,    32,     8,     1,     1,     6,     8,     5,     5,     7,
      41,     1,   165,    19,    20,     5,   169,     7,     1,    36,
      33,   102,     5,    37,   103,    37,    37,    58,    33,     1,
      36,    37,    38,    37,    37,   188,     8,     0,    36,    36,
       1,     1,    76,    74,    75,    75,    36,     8,     1,    80,
       1,     8,     5,    36,     7,     6,    98,     1,     8,    44,
      91,    21,    19,    20,    36,     5,    21,    52,     8,    19,
      20,   102,   102,    12,   105,    36,     0,     1,   112,    36,
       6,    38,   116,    36,    28,    29,    30,    31,    38,    24,
       1,     5,     1,    32,    34,     5,     5,    21,     8,    23,
      23,    25,    26,    19,    20,    19,    20,     1,     1,     5,
     144,    22,     5,    24,     1,     1,     5,     1,    38,     5,
      36,     5,    38,    10,    11,    12,    13,    14,    15,    16,
      19,    20,    23,     5,    25,    26,     8,   168,     3,     4,
       1,     6,     3,     4,     1,     5,    25,    26,     8,     3,
       4,    19,    20,    35,     5,    38,     9,    32,     8,     5,
      37,    37,     5,     1,    37,     1,     1,     1,     5,   144,
     143,    96,   168,   157,    30,   146,    -1,    29,    27,    -1,
      -1,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    21,    41,    42,    43,     1,     5,     0,    42,
       1,    22,    24,    44,    45,    46,     5,     8,    34,    47,
      49,    50,    51,    62,    49,    23,    25,    26,    72,    73,
      74,     1,    24,    48,    19,    20,    36,    38,    53,    54,
      56,    69,    83,     1,    10,    11,    12,    13,    14,    15,
      16,    63,    82,    85,     6,    75,    55,    62,    69,    83,
       1,    75,     1,     5,    36,    76,    77,     1,    76,    74,
      73,    49,     1,     1,    36,    62,     5,     1,     5,     7,
      36,    66,    71,    78,    86,     3,     4,     6,    70,     1,
       5,    36,    64,    71,    80,     3,     4,    65,    38,    35,
       1,     1,    62,    38,    77,    36,    61,    62,    55,    52,
      83,     9,     5,    62,    79,    32,     5,    62,    81,     1,
       5,    36,    67,    68,    71,    80,    67,     1,    75,    55,
       1,    77,     1,    37,    62,     1,    36,    37,    57,    58,
      59,    60,    62,    69,     5,     5,    83,    37,     1,    37,
       1,    28,    29,    30,    31,    84,     5,    83,    37,     1,
      37,     1,    37,     1,    57,    37,     1,     1,    36,    60,
      52,     1,     1,    79,     1,     3,     4,     1,     1,    81,
      57,    61,    57,     1,    33,     1,    33,     1,    37,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    43,    43,    44,    44,
      44,    44,    45,    45,    46,    47,    47,    48,    48,    48,
      49,    49,    49,    49,    49,    50,    51,    52,    52,    53,
      53,    54,    54,    54,    55,    55,    55,    55,    56,    56,
      56,    56,    56,    56,    57,    57,    58,    58,    58,    58,
      58,    59,    59,    59,    60,    61,    61,    61,    62,    62,
      62,    62,    63,    63,    63,    64,    64,    64,    64,    64,
      65,    65,    66,    66,    66,    66,    67,    67,    67,    68,
      68,    69,    69,    70,    70,    70,    71,    71,    71,    71,
      71,    71,    71,    72,    72,    72,    72,    72,    73,    73,
      73,    73,    74,    74,    75,    75,    75,    76,    76,    76,
      77,    77,    77,    78,    78,    79,    79,    79,    79,    80,
      80,    81,    81,    81,    81,    82,    82,    83,    83,    84,
      84,    84,    84,    85,    85,    85,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     4,     2,     1,     2,
       1,     2,     2,     1,     2,     1,     3,     2,     1,     0,
       1,     2,     1,     1,     1,     2,     4,     3,     0,     1,
       1,     3,     2,     2,     2,     3,     2,     2,     6,     5,
       5,     4,     4,     2,     1,     1,     5,     4,     2,     4,
       2,     3,     2,     2,     1,     1,     3,     3,     2,     3,
       3,     2,     2,     2,     2,     1,     1,     3,     1,     1,
       2,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     5,     3,
       4,     5,     5,     1,     1,     2,     2,     0,     2,     2,
       2,     2,     2,     2,     3,     1,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* ontology: error  */
#line 103 "Sintatico.y"
            { yyerror("Erro de Sintaxe.#Esperava uma declaração de classe começando com 'Class:'!"); YYABORT; }
#line 1365 "Sintatico.tab.c"
    break;

  case 6: /* class_declaration: CLASS TAG_CLASS class_type class_body  */
#line 114 "Sintatico.y"
                                                { class_declaration((yyvsp[-2].str)); }
#line 1371 "Sintatico.tab.c"
    break;

  case 7: /* class_declaration: CLASS error  */
#line 115 "Sintatico.y"
                                                { yyerror("Erro de Sintaxe.#Esperava um nome de classe após a palavra-chave 'class:'"); }
#line 1377 "Sintatico.tab.c"
    break;

  case 8: /* class_type: primitive_class  */
#line 120 "Sintatico.y"
                                                { t.insert("Primitiva"); }
#line 1383 "Sintatico.tab.c"
    break;

  case 9: /* class_type: defined_class optional_subclass  */
#line 121 "Sintatico.y"
                                                { t.insert("Definida"); }
#line 1389 "Sintatico.tab.c"
    break;

  case 10: /* class_type: error  */
#line 122 "Sintatico.y"
                                                { yyerror("Erro de Sintaxe.#Esperava uma classe Primitiva ou Definida (SubClassOf ou EquivalentTo)"); }
#line 1395 "Sintatico.tab.c"
    break;

  case 11: /* class_type: primitive_class error  */
#line 123 "Sintatico.y"
                                                { yyerror("Erro semântico.#Uma classe primitiva 'SubClassOf' não pode ser seguida por 'EquivalentTo'"); }
#line 1401 "Sintatico.tab.c"
    break;

  case 16: /* pos_defined_class: TAG_ABRECHAVE individuals_list TAG_FECHACHAVE  */
#line 140 "Sintatico.y"
                                                    { t.insert("Enumerada"); }
#line 1407 "Sintatico.tab.c"
    break;

  case 24: /* expression_list: pos_class  */
#line 155 "Sintatico.y"
                { t.insert("Coberta"); }
#line 1413 "Sintatico.tab.c"
    break;

  case 33: /* simple_expression: separador error  */
#line 184 "Sintatico.y"
                                                       { yyerror("Erro de Sintaxe.#Esperava algo após uma vírgula ou operador lógico!"); }
#line 1419 "Sintatico.tab.c"
    break;

  case 36: /* simples_expression_no_parent: separador error  */
#line 190 "Sintatico.y"
                                                       { yyerror("Erro de Sintaxe.#Esperava algo após uma vírgula ou operador lógico!"); }
#line 1425 "Sintatico.tab.c"
    break;

  case 37: /* simples_expression_no_parent: expression error  */
#line 191 "Sintatico.y"
                                                       { yyerror("Erro de Sintaxe.#Esperava um separador [',' ou 'and' ou 'or'] entre as expressões."); }
#line 1431 "Sintatico.tab.c"
    break;

  case 42: /* complex_expression: separador TAG_ABREPARANTESIS elements error  */
#line 200 "Sintatico.y"
                                                        { yyerror("Erro de Sintaxe.#Esperava um fechamento de parênteses!"); }
#line 1437 "Sintatico.tab.c"
    break;

  case 43: /* complex_expression: TAG_ABREPARANTESIS error  */
#line 201 "Sintatico.y"
                                                        { yyerror("Erro de Sintaxe.#Esperava um separador [',' ou 'and' ou 'or'] entre as expressões."); }
#line 1443 "Sintatico.tab.c"
    break;

  case 48: /* additional_expressions_parent: separador error  */
#line 213 "Sintatico.y"
                                                        { yyerror("Erro de Sintaxe.#Esperava algo após uma vírgula ou operador lógico!"); }
#line 1449 "Sintatico.tab.c"
    break;

  case 49: /* additional_expressions_parent: separador TAG_ABREPARANTESIS elements error  */
#line 214 "Sintatico.y"
                                                        { yyerror("Erro de Sintaxe.#Esperava um fechamento de parênteses!"); }
#line 1455 "Sintatico.tab.c"
    break;

  case 50: /* additional_expressions_parent: TAG_ABREPARANTESIS error  */
#line 215 "Sintatico.y"
                                                        { yyerror("Erro de Sintaxe.#Esperava um separador [',' ou 'and' ou 'or'] entre as expressões."); }
#line 1461 "Sintatico.tab.c"
    break;

  case 53: /* additional_expressions_no_parent: element error  */
#line 221 "Sintatico.y"
                                                        { yyerror("Erro de Sintaxe.#Esperava um separador [',' ou 'and' ou 'or'] entre as expressões."); }
#line 1467 "Sintatico.tab.c"
    break;

  case 57: /* elements: TAG_ABREPARANTESIS expression error  */
#line 231 "Sintatico.y"
                                                        { yyerror("Erro de Sintaxe.#Esperava um fechamento de parênteses!"); }
#line 1473 "Sintatico.tab.c"
    break;

  case 58: /* expression: TAG_PROPERTY pos_property  */
#line 236 "Sintatico.y"
                                                        { properties.push(std::string((yyvsp[-1].str))); }
#line 1479 "Sintatico.tab.c"
    break;

  case 59: /* expression: TAG_PROPERTY ONLY corp_expre3  */
#line 237 "Sintatico.y"
                                                        { properties.push(std::string((yyvsp[-2].str))); }
#line 1485 "Sintatico.tab.c"
    break;

  case 60: /* expression: TAG_PROPERTY ONLY class_op  */
#line 238 "Sintatico.y"
                                                        { expression_der((yyvsp[-2].str)); }
#line 1491 "Sintatico.tab.c"
    break;

  case 61: /* expression: TAG_PROPERTY error  */
#line 239 "Sintatico.y"
                                                        { yyerror("Erro de Sintaxe.#Esperava um quantificador, cardinalidade ou 'Value' após uma propriedade!"); }
#line 1497 "Sintatico.tab.c"
    break;

  case 62: /* pos_property: op_quantifier corp_expre1  */
#line 243 "Sintatico.y"
                                                        { if (strcmp((yyvsp[-1].str),"some") == 0 && isClass) { props.insert(std::string((yyvsp[0].str))); } }
#line 1503 "Sintatico.tab.c"
    break;

  case 64: /* pos_property: VALUE pos_value  */
#line 245 "Sintatico.y"
                                                        { while (!properties.empty()) { properties.pop();} }
#line 1509 "Sintatico.tab.c"
    break;

  case 65: /* corp_expre1: TAG_CLASS  */
#line 250 "Sintatico.y"
                                                        { (yyval.str) = (yyvsp[0].str); isClass = true; posproperties.push("Object Property"); }
#line 1515 "Sintatico.tab.c"
    break;

  case 66: /* corp_expre1: type_expre  */
#line 251 "Sintatico.y"
                                                        { posproperties.push("Data Property"); }
#line 1521 "Sintatico.tab.c"
    break;

  case 67: /* corp_expre1: TAG_ABREPARANTESIS expression TAG_FECHAPARANTESIS  */
#line 252 "Sintatico.y"
                                                        { t.insert("Aninhada"); }
#line 1527 "Sintatico.tab.c"
    break;

  case 68: /* corp_expre1: list  */
#line 253 "Sintatico.y"
                                                        { posproperties.push("Object Property"); }
#line 1533 "Sintatico.tab.c"
    break;

  case 69: /* corp_expre1: error  */
#line 254 "Sintatico.y"
                                                        { yyerror("Erro de Sintaxe#Após um quantificador, esperava-se uma classe, um tipo de dado ou mais expressões."); }
#line 1539 "Sintatico.tab.c"
    break;

  case 72: /* corp_expre3: TAG_CLASS  */
#line 265 "Sintatico.y"
                                                        { (yyval.str) = (yyvsp[0].str); isClass = true; posproperties.push("Object Property"); }
#line 1545 "Sintatico.tab.c"
    break;

  case 73: /* corp_expre3: type_expre  */
#line 266 "Sintatico.y"
                                                        { posproperties.push("Data Property"); }
#line 1551 "Sintatico.tab.c"
    break;

  case 74: /* corp_expre3: TAG_ABREPARANTESIS expression TAG_FECHAPARANTESIS  */
#line 267 "Sintatico.y"
                                                        { t.insert("Aninhada"); }
#line 1557 "Sintatico.tab.c"
    break;

  case 75: /* corp_expre3: error  */
#line 268 "Sintatico.y"
                                                        { yyerror("Erro de Sintaxe#Após um quantificador, esperava-se uma classe, um tipo de dado ou mais expressões."); }
#line 1563 "Sintatico.tab.c"
    break;

  case 76: /* sub_corp: object_property  */
#line 272 "Sintatico.y"
                                                        { posproperties.push("Object Property"); }
#line 1569 "Sintatico.tab.c"
    break;

  case 77: /* sub_corp: type_expre  */
#line 273 "Sintatico.y"
                                                        { posproperties.push("Data Property"); }
#line 1575 "Sintatico.tab.c"
    break;

  case 78: /* sub_corp: error  */
#line 274 "Sintatico.y"
                                                        { yyerror("Erro de Sintaxe#Após uma cardinalidade, esperava-se uma Class ou um Tipo de dado."); }
#line 1581 "Sintatico.tab.c"
    break;

  case 87: /* type_expre: namespace_datatype TAG_ABRECOLCHETE op_rel TAG_NUMI TAG_FECHACOLCHETE  */
#line 298 "Sintatico.y"
                                                                            {
        if (!is_int_type(std::string((yyvsp[-4].str)))) {
            char error_message[512];
            snprintf(error_message, 512, "Erro semântico.#O tipo de dado [%s] não é compatível com o dado passado.", (yyvsp[-4].str));
            yyerror(error_message);
        } 
    }
#line 1593 "Sintatico.tab.c"
    break;

  case 88: /* type_expre: namespace_datatype TAG_ABRECOLCHETE op_rel TAG_NUMD TAG_FECHACOLCHETE  */
#line 305 "Sintatico.y"
                                                                            {
        if (!is_decimal_type(std::string((yyvsp[-4].str)))) {
            char error_message[512];
            snprintf(error_message, 512, "Erro semântico.#O tipo de dado [%s] não é compatível com o dado passado.", (yyvsp[-4].str));
            yyerror(error_message);
        } 
    }
#line 1605 "Sintatico.tab.c"
    break;

  case 89: /* type_expre: namespace_datatype TAG_ABRECOLCHETE error  */
#line 312 "Sintatico.y"
                                                                { yyerror("Erro de Sintaxe.#Esperava um operador de relação após o tipo de dado"); }
#line 1611 "Sintatico.tab.c"
    break;

  case 90: /* type_expre: namespace_datatype TAG_ABRECOLCHETE op_rel error  */
#line 313 "Sintatico.y"
                                                                { yyerror("Erro de Sintaxe.#Esperava um número após o operador de relação"); }
#line 1617 "Sintatico.tab.c"
    break;

  case 91: /* type_expre: namespace_datatype TAG_ABRECOLCHETE op_rel TAG_NUMI error  */
#line 314 "Sintatico.y"
                                                                { yyerror("Erro de Sintaxe.#Esperava um fechamento de colchetes"); }
#line 1623 "Sintatico.tab.c"
    break;

  case 92: /* type_expre: namespace_datatype TAG_ABRECOLCHETE op_rel TAG_NUMD error  */
#line 315 "Sintatico.y"
                                                                { yyerror("Erro de Sintaxe.#Esperava um fechamento de colchetes"); }
#line 1629 "Sintatico.tab.c"
    break;

  case 96: /* class_body: individuals_section disjointclasses_section  */
#line 322 "Sintatico.y"
                                                                { yyerror("Erro de semântica.#A seção 'disjointclasses:' deve vir antes da seção 'individuals:'"); }
#line 1635 "Sintatico.tab.c"
    break;

  case 100: /* disjointclasses_section: DISJOINTCLASSES error  */
#line 329 "Sintatico.y"
                                                                { yyerror("Erro de Sintaxe.#Esperava uma lista de classes após a palavra-chave 'disjointclasses:'");}
#line 1641 "Sintatico.tab.c"
    break;

  case 101: /* disjointclasses_section: DISJOINTWITH error  */
#line 330 "Sintatico.y"
                                                                { yyerror("Erro de Sintaxe.#Esperava uma lista de classes após a palavra-chave 'disjointwith:'");}
#line 1647 "Sintatico.tab.c"
    break;

  case 103: /* individuals_section: INDIVIDUALS error  */
#line 335 "Sintatico.y"
                                                                { yyerror("Erro de Sintaxe.#Esperava uma lista de indivíduos após a palavra-chave 'individuals:'");}
#line 1653 "Sintatico.tab.c"
    break;

  case 106: /* individuals_list: TAG_INDIVIDUOS TAG_VIRGULA error  */
#line 341 "Sintatico.y"
                                                                { yyerror("Erro de Sintaxe.#Esperava algo após a vírgula");}
#line 1659 "Sintatico.tab.c"
    break;

  case 109: /* class_list: TAG_ABREPARANTESIS class_v error  */
#line 348 "Sintatico.y"
                                                                { yyerror("Erro de Sintaxe.#Esperava um fechamento de parênteses"); }
#line 1665 "Sintatico.tab.c"
    break;

  case 112: /* class_v: TAG_CLASS TAG_VIRGULA error  */
#line 355 "Sintatico.y"
                                                                { yyerror("Erro de Sintaxe.#Esperava algo após a vírgula"); }
#line 1671 "Sintatico.tab.c"
    break;

  case 114: /* class_op: TAG_ABREPARANTESIS class_l error  */
#line 361 "Sintatico.y"
                                                                { yyerror("Erro de Sintaxe.#Esperava um fechamento de parênteses"); }
#line 1677 "Sintatico.tab.c"
    break;

  case 115: /* class_l: TAG_CLASS op_logic class_l  */
#line 366 "Sintatico.y"
                                                                { tag_class_der((yyvsp[-2].str)); }
#line 1683 "Sintatico.tab.c"
    break;

  case 116: /* class_l: TAG_CLASS  */
#line 367 "Sintatico.y"
                                                                { tag_class_der((yyvsp[0].str)); }
#line 1689 "Sintatico.tab.c"
    break;

  case 117: /* class_l: TAG_CLASS op_logic error  */
#line 368 "Sintatico.y"
                                                                { yyerror("Erro de Sintaxe.#Esperava algo após o operador lógico"); }
#line 1695 "Sintatico.tab.c"
    break;

  case 118: /* class_l: TAG_CLASS TAG_CLASS error  */
#line 369 "Sintatico.y"
                                                                { yyerror("Erro de Sintaxe.#Esperava um operador lógico entre as classes");}
#line 1701 "Sintatico.tab.c"
    break;

  case 120: /* list: TAG_ABREPARANTESIS list_class error  */
#line 375 "Sintatico.y"
                                                               { yyerror("Erro de Sintaxe.#Esperava um fechamento de parênteses"); }
#line 1707 "Sintatico.tab.c"
    break;

  case 121: /* list_class: TAG_CLASS op_logic list_class  */
#line 380 "Sintatico.y"
                                                                { (yyval.str) = (yyvsp[-2].str); }
#line 1713 "Sintatico.tab.c"
    break;

  case 122: /* list_class: TAG_CLASS  */
#line 381 "Sintatico.y"
                                                                { (yyval.str) = (yyvsp[0].str); }
#line 1719 "Sintatico.tab.c"
    break;

  case 123: /* list_class: TAG_CLASS op_logic error  */
#line 382 "Sintatico.y"
                                                                { yyerror("Erro de Sintaxe.#Esperava algo após o operador lógico"); }
#line 1725 "Sintatico.tab.c"
    break;

  case 124: /* list_class: TAG_CLASS TAG_CLASS error  */
#line 383 "Sintatico.y"
                                                                { yyerror("Erro de Sintaxe.#Esperava um operador lógico entre as classes");}
#line 1731 "Sintatico.tab.c"
    break;

  case 125: /* op_quantifier: SOME  */
#line 388 "Sintatico.y"
         { (yyval.str) = "some"; }
#line 1737 "Sintatico.tab.c"
    break;

  case 126: /* op_quantifier: ALL  */
#line 389 "Sintatico.y"
          { (yyval.str) = "all"; }
#line 1743 "Sintatico.tab.c"
    break;

  case 129: /* op_rel: TAG_MAIOR  */
#line 400 "Sintatico.y"
                        { (yyval.str) = ">"; }
#line 1749 "Sintatico.tab.c"
    break;

  case 130: /* op_rel: TAG_MAIORIGUAL  */
#line 401 "Sintatico.y"
                        { (yyval.str) = ">="; }
#line 1755 "Sintatico.tab.c"
    break;

  case 131: /* op_rel: TAG_MENOR  */
#line 402 "Sintatico.y"
                        { (yyval.str) = "<"; }
#line 1761 "Sintatico.tab.c"
    break;

  case 132: /* op_rel: TAG_MENORIGUAL  */
#line 403 "Sintatico.y"
                        { (yyval.str) = "<="; }
#line 1767 "Sintatico.tab.c"
    break;

  case 136: /* namespace_datatype: TAG_NAMESPACE TAG_DATATYPE  */
#line 415 "Sintatico.y"
                               { (yyval.str) = namespace_datatype_der((yyvsp[-1].str), (yyvsp[0].str)); }
#line 1773 "Sintatico.tab.c"
    break;


#line 1777 "Sintatico.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 417 "Sintatico.y"


bool is_int_type(const std::string& space) {
    static const std::set<std::string> numeric_types = {
        "xsd:integer", "xsd:decimal", "xsd:double", "xsd:float", "xsd:long", "xsd:int", "xsd:short", "xsd:nonNegativeInteger",
        "xsd:positiveInteger", "xsd:negativeInteger", "xsd:nonPositiveInteger", "xsd:unsignedLong", "xsd:unsignedInt", "xsd:unsignedShort",
        "xsd:unsignedByte", "owl:real"
    };

    return numeric_types.count(space) > 0;
}

bool is_decimal_type(const std::string& space) {
    static const std::set<std::string> numeric_types = {
        "xsd:decimal", "xsd:double", "xsd:float", "owl:real"
    };

    return numeric_types.count(space) > 0;
}

bool is_namespace_valid(const std::string& space) {
    static const std::set<std::string> xsd_types = {
        "xsd:", "owl:", "rdf:" , "rdfs:"
    };

    return xsd_types.count(space) > 0;
}

bool is_valid_xsd_type(const std::string& datatype) {
    static const std::set<std::string> xsd_types = {
        "anyURI", "base64Binary", "boolean", "byte", "dateTime", "dateTimeStamp", "decimal", "double", "float", "hexBinary", 
        "int", "integer", "language", "long", "Name", "NCName", "negativeInteger", "NMTOKEN", "nonNegativeInteger", "nonPositiveInteger", 
        "normalizedString", "positiveInteger", "short", "string", "token", "unsignedByte", "unsignedInt", "unsignedLong", "unsignedShort"
    };

    return xsd_types.count(datatype) > 0;
}

bool is_valid_owl_type(const std::string& datatype) {
    static const std::set<std::string> owl_types = {
        "rational", "real"
    };
    return owl_types.count(datatype) > 0;
}

bool is_valid_rdf_type(const std::string& datatype) {
    static const std::set<std::string> rdf_types = {
        "langString", "PlainLiteral", "XMLLiteral"
    };
    return rdf_types.count(datatype) > 0;
}

bool is_valid_rdfs_type(const std::string& datatype) {
    static const std::set<std::string> rdfs_types = {
        "Literal"
    };
    return rdfs_types.count(datatype) > 0;
}

void tag_class_der(const char * name) {
    if (!props.empty() && props.find(std::string(name)) != props.end()) {
        props.erase(std::string(name));
    } else {
        char error_message[512];
        snprintf(error_message, 512, "Erro Semântico.#A class [%s] não foi fechada corretamente nas propriedades.", name);
        yyerror(error_message);
    }
}

void expression_der(const char * name){
    properties.push(std::string(name));  
    theLastProp.insert(std::string(name)); 

    if (theLastProp.size() > 1) {
        yyerror("Erro Semântico.#Uma das propriedades não se encaixa com as outras.");
    } else {
        theLastProp.clear();
    }

    t.insert("Fechamento");

    posproperties.push("Object Property");

    if (!props.empty()) {
        yyerror("Erro semântico.#Erro ao tentar fechar o axioma, classes faltantes não foram fechadas.");
    }
}

void class_declaration(const char * name) {
    string theLastTP = "Nenhum Tipo";           // Por padrão é Nenhum Tipo
    while (!properties.empty()) {               // Lopping para adicionar as propriedades e seus tipos
        if (!posproperties.empty()) {
            theLastTP = posproperties.top();
            posproperties.pop();
        }
        p[theLastTP].insert(properties.top());
        properties.pop();
    }
    classes.push_back({string(name),t,p});

    // Limpa as variáveis globais
    while (!posproperties.empty()) {
        posproperties.pop();
    }
    while (!properties.empty()) {
        properties.pop();
    }
    p["Data Property"].clear();
    p["Object Property"].clear();
    p["Nenhum Tipo"].clear();
    isFechamento = false;
    fechada = false;
    isClass = false;
    theLastProp.clear();
    t.clear();
    props.clear();
}

const char * namespace_datatype_der(const char * name, const char * datatype) {
    char * result = (char *)malloc(256); 
    if (result == NULL) {
        yyerror("Erro de memória ao processar namespace e datatype");
    }

    if (!is_namespace_valid(string(name))) {
        free(result);
        char error_message[512];
        snprintf(error_message, sizeof(error_message), "Namespace inválido.#O namespace %s não é válido", name);
        yyerror(error_message);
        return nullptr;
    }

    // Mapear namespaces para funções de validação
    const unordered_map<string, function<bool(const string &)>> namespace_validators = {
        {"xsd:", is_valid_xsd_type},
        {"owl:", is_valid_owl_type},
        {"rdf:", is_valid_rdf_type},
        {"rdfs:", is_valid_rdfs_type},
    };

    auto it = namespace_validators.find(name);
    if (it != namespace_validators.end() && it->second(string(datatype))) {
        snprintf(result, 256, "%s%s", name, datatype);
        return result;
    }

    // Caso nenhum namespace válido tenha sido encontrado
    char error_message[512];
    snprintf(error_message, sizeof(error_message),"Tipo incompatível com o namespace.#O namespace %s não é compatível com o tipo %s", name, datatype);
    yyerror(error_message);
    // Parar a execução
    return datatype;
}

void yyerror(const char * msg) {
    // Encontra a posição do delimitador '#'
    const char *delimiter = strchr(msg, '#');

    // Declara variáveis para as mensagens
    std::string msg1, msg2;

    if (delimiter != nullptr) {
        // Se o delimitador foi encontrado, divide a mensagem
        msg1 = std::string(msg, delimiter); // Parte antes de '#'
        msg2 = std::string(delimiter + 1);  // Parte depois de '#'
    } else {
        // Se não houver delimitador, coloca a mensagem inteira em msg1
        msg1 = std::string(msg);
        msg2 = ""; // Deixa msg2 vazia
    }

    // Cria e armazena o erro
    Error err;
    err.line = yylineno;
    err.message = msg1;
    err.suggestion = msg2;

    errors.push_back(err);
}
