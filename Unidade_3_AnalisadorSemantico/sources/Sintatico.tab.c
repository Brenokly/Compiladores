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

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <cstring>
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::set;
using std::strcmp;

// Definição da estrutura Error
struct Error
{
    int line;
    string message;
    string suggestion;
};

struct Classes
{
  string name;
  set<string> tipos;
};

extern int yylineno;
extern vector<Error> errors;
extern vector<Classes> classes;
char * currentClass;
Classes * c = nullptr;
set<string> t;

int yylex(void);
int yyparse(void);
void yyerror(const char *msg);
bool is_valid_xsd_type(const std::string& datatype);
bool is_valid_owl_type(const std::string& datatype);
bool is_valid_rdf_type(const std::string& datatype);
bool is_valid_rdfs_type(const std::string& datatype);
bool is_namespace_valid(const std::string& space);
void addClass(const string& className);

#line 117 "Sintatico.tab.c"

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
  YYSYMBOL_TAG_CLASS = 3,                  /* TAG_CLASS  */
  YYSYMBOL_TAG_INDIVIDUOS = 4,             /* TAG_INDIVIDUOS  */
  YYSYMBOL_TAG_NAMESPACE = 5,              /* TAG_NAMESPACE  */
  YYSYMBOL_TAG_PROPERTY = 6,               /* TAG_PROPERTY  */
  YYSYMBOL_TAG_DATATYPE = 7,               /* TAG_DATATYPE  */
  YYSYMBOL_TAG_NUM = 8,                    /* TAG_NUM  */
  YYSYMBOL_ONLY = 9,                       /* ONLY  */
  YYSYMBOL_SOME = 10,                      /* SOME  */
  YYSYMBOL_ALL = 11,                       /* ALL  */
  YYSYMBOL_VALUE = 12,                     /* VALUE  */
  YYSYMBOL_MIN = 13,                       /* MIN  */
  YYSYMBOL_MAX = 14,                       /* MAX  */
  YYSYMBOL_EXACTLY = 15,                   /* EXACTLY  */
  YYSYMBOL_THAT = 16,                      /* THAT  */
  YYSYMBOL_NOT = 17,                       /* NOT  */
  YYSYMBOL_AND = 18,                       /* AND  */
  YYSYMBOL_OR = 19,                        /* OR  */
  YYSYMBOL_CLASS = 20,                     /* CLASS  */
  YYSYMBOL_EQUIVALENTTO = 21,              /* EQUIVALENTTO  */
  YYSYMBOL_INDIVIDUALS = 22,               /* INDIVIDUALS  */
  YYSYMBOL_SUBCLASSOF = 23,                /* SUBCLASSOF  */
  YYSYMBOL_DISJOINTCLASSES = 24,           /* DISJOINTCLASSES  */
  YYSYMBOL_DISJOINTWITH = 25,              /* DISJOINTWITH  */
  YYSYMBOL_TAG_MENORIGUAL = 26,            /* TAG_MENORIGUAL  */
  YYSYMBOL_TAG_MAIORIGUAL = 27,            /* TAG_MAIORIGUAL  */
  YYSYMBOL_TAG_MENOR = 28,                 /* TAG_MENOR  */
  YYSYMBOL_TAG_MAIOR = 29,                 /* TAG_MAIOR  */
  YYSYMBOL_TAG_ABRECOLCHETE = 30,          /* TAG_ABRECOLCHETE  */
  YYSYMBOL_TAG_FECHACOLCHETE = 31,         /* TAG_FECHACOLCHETE  */
  YYSYMBOL_TAG_ABRECHAVE = 32,             /* TAG_ABRECHAVE  */
  YYSYMBOL_TAG_FECHACHAVE = 33,            /* TAG_FECHACHAVE  */
  YYSYMBOL_TAG_ABREPARANTESIS = 34,        /* TAG_ABREPARANTESIS  */
  YYSYMBOL_TAG_FECHAPARANTESIS = 35,       /* TAG_FECHAPARANTESIS  */
  YYSYMBOL_TAG_VIRGULA = 36,               /* TAG_VIRGULA  */
  YYSYMBOL_TAG_DOISPONTOS = 37,            /* TAG_DOISPONTOS  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_ontology = 39,                  /* ontology  */
  YYSYMBOL_declarations = 40,              /* declarations  */
  YYSYMBOL_class_declaration = 41,         /* class_declaration  */
  YYSYMBOL_class_type = 42,                /* class_type  */
  YYSYMBOL_primitive_class = 43,           /* primitive_class  */
  YYSYMBOL_defined_class = 44,             /* defined_class  */
  YYSYMBOL_optional_subclass = 45,         /* optional_subclass  */
  YYSYMBOL_expression_list = 46,           /* expression_list  */
  YYSYMBOL_list_expression = 47,           /* list_expression  */
  YYSYMBOL_pos_class = 48,                 /* pos_class  */
  YYSYMBOL_additional_classes = 49,        /* additional_classes  */
  YYSYMBOL_expression_format = 50,         /* expression_format  */
  YYSYMBOL_simple_expression = 51,         /* simple_expression  */
  YYSYMBOL_simples_expression_no_parent = 52, /* simples_expression_no_parent  */
  YYSYMBOL_complex_expression = 53,        /* complex_expression  */
  YYSYMBOL_additional_expressions = 54,    /* additional_expressions  */
  YYSYMBOL_additional_expressions_parent = 55, /* additional_expressions_parent  */
  YYSYMBOL_additional_expressions_no_parent = 56, /* additional_expressions_no_parent  */
  YYSYMBOL_element = 57,                   /* element  */
  YYSYMBOL_elements = 58,                  /* elements  */
  YYSYMBOL_expression = 59,                /* expression  */
  YYSYMBOL_corp_expre1 = 60,               /* corp_expre1  */
  YYSYMBOL_corp_expre2 = 61,               /* corp_expre2  */
  YYSYMBOL_separador = 62,                 /* separador  */
  YYSYMBOL_pos_value = 63,                 /* pos_value  */
  YYSYMBOL_type_expre = 64,                /* type_expre  */
  YYSYMBOL_class_body = 65,                /* class_body  */
  YYSYMBOL_disjointclasses_section = 66,   /* disjointclasses_section  */
  YYSYMBOL_individuals_section = 67,       /* individuals_section  */
  YYSYMBOL_individuals_list = 68,          /* individuals_list  */
  YYSYMBOL_class_list = 69,                /* class_list  */
  YYSYMBOL_class_v = 70,                   /* class_v  */
  YYSYMBOL_class_op = 71,                  /* class_op  */
  YYSYMBOL_class_l = 72,                   /* class_l  */
  YYSYMBOL_op_quantifier = 73,             /* op_quantifier  */
  YYSYMBOL_op_logic = 74,                  /* op_logic  */
  YYSYMBOL_op_rel = 75,                    /* op_rel  */
  YYSYMBOL_op_cardinality = 76,            /* op_cardinality  */
  YYSYMBOL_namespace_datatype = 77         /* namespace_datatype  */
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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   148

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    72,    72,    77,    78,    83,    84,    89,    90,    91,
      98,   103,   104,   109,   110,   115,   116,   117,   118,   119,
     123,   128,   133,   134,   139,   140,   145,   146,   147,   153,
     154,   155,   162,   163,   164,   165,   166,   172,   173,   177,
     178,   179,   182,   188,   189,   193,   197,   198,   199,   206,
     207,   208,   209,   215,   216,   217,   218,   222,   223,   228,
     229,   234,   235,   239,   240,   241,   242,   245,   248,   254,
     255,   256,   257,   258,   262,   263,   264,   267,   273,   274,
     280,   281,   282,   289,   290,   291,   298,   299,   300,   307,
     308,   315,   316,   317,   320,   327,   328,   329,   334,   335,
     340,   341,   342,   343,   348,   349,   350,   355
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
  "\"end of file\"", "error", "\"invalid token\"", "TAG_CLASS",
  "TAG_INDIVIDUOS", "TAG_NAMESPACE", "TAG_PROPERTY", "TAG_DATATYPE",
  "TAG_NUM", "ONLY", "SOME", "ALL", "VALUE", "MIN", "MAX", "EXACTLY",
  "THAT", "NOT", "AND", "OR", "CLASS", "EQUIVALENTTO", "INDIVIDUALS",
  "SUBCLASSOF", "DISJOINTCLASSES", "DISJOINTWITH", "TAG_MENORIGUAL",
  "TAG_MAIORIGUAL", "TAG_MENOR", "TAG_MAIOR", "TAG_ABRECOLCHETE",
  "TAG_FECHACOLCHETE", "TAG_ABRECHAVE", "TAG_FECHACHAVE",
  "TAG_ABREPARANTESIS", "TAG_FECHAPARANTESIS", "TAG_VIRGULA",
  "TAG_DOISPONTOS", "$accept", "ontology", "declarations",
  "class_declaration", "class_type", "primitive_class", "defined_class",
  "optional_subclass", "expression_list", "list_expression", "pos_class",
  "additional_classes", "expression_format", "simple_expression",
  "simples_expression_no_parent", "complex_expression",
  "additional_expressions", "additional_expressions_parent",
  "additional_expressions_no_parent", "element", "elements", "expression",
  "corp_expre1", "corp_expre2", "separador", "pos_value", "type_expre",
  "class_body", "disjointclasses_section", "individuals_section",
  "individuals_list", "class_list", "class_v", "class_op", "class_l",
  "op_quantifier", "op_logic", "op_rel", "op_cardinality",
  "namespace_datatype", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-110)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-46)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,   117,     7,  -110,    -5,  -110,    63,  -110,  -110,  -110,
      53,   109,    77,  -110,    43,    51,    96,    69,  -110,  -110,
    -110,    51,  -110,    79,    17,    23,  -110,    45,   101,   109,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,     8,    76,  -110,
    -110,  -110,  -110,    88,  -110,  -110,  -110,    14,    81,    55,
      65,  -110,    89,  -110,  -110,  -110,  -110,    67,   120,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,    31,    51,   111,
    -110,  -110,  -110,  -110,   124,   110,  -110,   122,  -110,  -110,
      97,    24,   113,  -110,  -110,    51,   118,     9,   122,    98,
       4,    99,  -110,  -110,   129,  -110,    75,   100,    10,  -110,
      48,  -110,   133,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,    11,    51,  -110,   102,  -110,  -110,    29,   111,
     137,   121,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
      60,  -110,  -110,  -110,    51,  -110,    31,    51,  -110,  -110,
    -110,  -110,  -110,  -110,     5,  -110,    12,  -110,  -110,  -110,
    -110,  -110,    51,  -110
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     3,     6,     0,     1,     4,     9,
       0,     0,    73,     7,    14,    15,     0,     0,    11,    18,
      19,    17,    10,     0,     0,     0,     5,    69,    70,     0,
       8,    98,    99,    59,    16,    24,    25,     0,    60,    52,
      95,    96,    97,     0,   104,   105,   106,     0,     0,    81,
       0,    20,     0,    60,    79,    78,    76,    87,     0,    74,
      83,    77,    75,    71,    72,    13,    28,     0,    27,    23,
      62,    61,    51,    53,     0,     0,    49,     0,    54,    63,
      64,     0,     0,    12,    31,    29,     0,     0,     0,     0,
       0,    46,    26,    21,     0,   107,    92,     0,     0,    55,
       0,    57,     0,    50,    58,    82,    80,    30,    88,    86,
      85,    84,     0,    35,    36,     0,    37,    38,     0,    23,
       0,     0,    56,    90,    89,    66,   103,   101,   102,   100,
       0,    48,    47,    34,    33,    41,     0,    44,    45,    22,
      94,    93,    91,    67,     0,    32,     0,    46,    43,    68,
      65,    42,    40,    39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,   135,  -110,  -110,  -110,  -110,  -110,    42,  -110,
    -110,    21,  -110,  -110,   -47,  -110,  -109,  -110,  -110,    25,
       6,   -36,  -110,  -110,   -13,  -110,    64,  -110,   116,   114,
     -20,   123,     2,  -110,    26,  -110,   -15,  -110,  -110,  -110
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    12,    13,    14,    30,    18,    19,
      20,    93,    34,    35,    51,    36,   115,   116,   117,    89,
      90,    21,    76,   103,   118,    72,    78,    26,    27,    28,
      50,    59,    60,    79,    98,    47,    53,   130,    48,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    68,    37,    55,   133,   114,   149,     7,    52,    66,
     110,   123,   131,   151,    16,     1,    85,    73,    56,    74,
      57,    92,    31,    32,    61,   145,    57,   101,   148,    74,
     135,    91,    31,    32,    77,    16,   150,    16,   107,    97,
      33,    99,    67,   153,   111,   124,   132,   152,    75,   125,
      33,    58,   112,    22,    94,    52,    15,    58,   102,    16,
      87,   143,   106,   136,     9,    88,    29,    23,   144,    31,
      32,    65,    52,    49,   126,   127,   128,   129,   120,    69,
      54,   121,   138,    49,    10,    17,    11,    33,   109,    81,
      84,    82,    70,    31,    32,    16,    71,    39,    83,    23,
     147,    24,    25,    86,    94,    40,    41,    42,    43,    44,
      45,    46,    15,    96,   105,    16,    16,    49,     5,   108,
       6,    57,   141,    57,    96,    24,    25,   100,    16,    31,
      32,    95,   119,   113,   -45,   122,    96,   134,   140,     8,
     139,    63,   146,   137,    64,   104,     0,   142,    62
};

static const yytype_int16 yycheck[] =
{
      15,    37,    15,    23,   113,     1,     1,     0,    21,     1,
       1,     1,     1,     1,     6,    20,    52,     3,     1,     5,
       3,    68,    18,    19,     1,   134,     3,     3,   137,     5,
       1,    67,    18,    19,    47,     6,    31,     6,    85,    75,
      36,    77,    34,   152,    35,    35,    35,    35,    34,     1,
      36,    34,    88,    11,    69,    68,     3,    34,    34,     6,
      58,     1,    82,    34,     1,    34,    23,    22,     8,    18,
      19,    29,    85,     4,    26,    27,    28,    29,     3,     3,
       1,    96,   118,     4,    21,    32,    23,    36,    86,     8,
       1,    36,     4,    18,    19,     6,     8,     1,    33,    22,
     136,    24,    25,    36,   119,     9,    10,    11,    12,    13,
      14,    15,     3,     3,     1,     6,     6,     4,     1,     1,
       3,     3,     1,     3,     3,    24,    25,    30,     6,    18,
      19,     7,     3,    35,    35,    35,     3,    35,     1,     4,
     119,    27,   136,   118,    28,    81,    -1,   121,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    20,    39,    40,    41,     1,     3,     0,    40,     1,
      21,    23,    42,    43,    44,     3,     6,    32,    46,    47,
      48,    59,    46,    22,    24,    25,    65,    66,    67,    23,
      45,    18,    19,    36,    50,    51,    53,    62,    74,     1,
       9,    10,    11,    12,    13,    14,    15,    73,    76,     4,
      68,    52,    62,    74,     1,    68,     1,     3,    34,    69,
      70,     1,    69,    67,    66,    46,     1,    34,    59,     3,
       4,     8,    63,     3,     5,    34,    60,    62,    64,    71,
      77,     8,    36,    33,     1,    59,    36,    70,    34,    57,
      58,    59,    52,    49,    74,     7,     3,    59,    72,    59,
      30,     3,    34,    61,    64,     1,    68,    52,     1,    70,
       1,    35,    59,    35,     1,    54,    55,    56,    62,     3,
       3,    74,    35,     1,    35,     1,    26,    27,    28,    29,
      75,     1,    35,    54,    35,     1,    34,    57,    59,    49,
       1,     1,    72,     1,     8,    54,    58,    59,    54,     1,
      31,     1,    35,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    42,    42,
      43,    44,    44,    45,    45,    46,    46,    46,    46,    46,
      47,    48,    49,    49,    50,    50,    51,    51,    51,    52,
      52,    52,    53,    53,    53,    53,    53,    54,    54,    55,
      55,    55,    55,    56,    56,    57,    58,    58,    58,    59,
      59,    59,    59,    60,    60,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    64,    64,    64,    64,    64,    65,
      65,    65,    65,    65,    66,    66,    66,    66,    67,    67,
      68,    68,    68,    69,    69,    69,    70,    70,    70,    71,
      71,    72,    72,    72,    72,    73,    73,    73,    74,    74,
      75,    75,    75,    75,    76,    76,    76,    77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     4,     2,     1,     2,     1,
       2,     2,     4,     2,     0,     1,     2,     1,     1,     1,
       2,     4,     3,     0,     1,     1,     3,     2,     2,     2,
       3,     2,     6,     5,     5,     4,     4,     1,     1,     5,
       4,     2,     4,     3,     2,     1,     1,     3,     3,     3,
       4,     3,     2,     1,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     3,     4,     5,     1,
       1,     2,     2,     0,     2,     2,     2,     2,     2,     2,
       3,     1,     3,     1,     3,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2
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
  case 5: /* class_declaration: CLASS TAG_CLASS class_type class_body  */
#line 83 "Sintatico.y"
                                          { classes.push_back({string((yyvsp[-2].str)),t}); t.clear(); }
#line 1298 "Sintatico.tab.c"
    break;

  case 6: /* class_declaration: CLASS error  */
#line 84 "Sintatico.y"
                  { yyerror("Erro de sintaxe.#Esperava um nome de classe após a palavra-chave 'class:'"); }
#line 1304 "Sintatico.tab.c"
    break;

  case 7: /* class_type: primitive_class  */
#line 89 "Sintatico.y"
                    { t.insert("Primitiva"); }
#line 1310 "Sintatico.tab.c"
    break;

  case 8: /* class_type: defined_class optional_subclass  */
#line 90 "Sintatico.y"
                                      { t.insert("Definida"); }
#line 1316 "Sintatico.tab.c"
    break;

  case 9: /* class_type: error  */
#line 91 "Sintatico.y"
            { 
    yyerror("Erro de sintaxe.#Esperava uma classe Primitiva ou Definida (SubClassOf ou EquivalentTo)"); 
    }
#line 1324 "Sintatico.tab.c"
    break;

  case 12: /* defined_class: EQUIVALENTTO TAG_ABRECHAVE individuals_list TAG_FECHACHAVE  */
#line 104 "Sintatico.y"
                                                                 { t.insert("Enumerada"); }
#line 1330 "Sintatico.tab.c"
    break;

  case 19: /* expression_list: pos_class  */
#line 119 "Sintatico.y"
                { t.insert("coberta"); }
#line 1336 "Sintatico.tab.c"
    break;

  case 25: /* expression_format: complex_expression  */
#line 140 "Sintatico.y"
                         { t.insert("aninhada"); }
#line 1342 "Sintatico.tab.c"
    break;

  case 28: /* simple_expression: separador error  */
#line 147 "Sintatico.y"
                      { 
        yyerror("Erro de sintaxe.#Esperava algo após uma vírgula ou operador lógico!"); 
    }
#line 1350 "Sintatico.tab.c"
    break;

  case 31: /* simples_expression_no_parent: separador error  */
#line 155 "Sintatico.y"
                      { 
        yyerror("Erro de sintaxe.#Esperava algo após uma vírgula ou operador lógico!"); 
    }
#line 1358 "Sintatico.tab.c"
    break;

  case 36: /* complex_expression: separador TAG_ABREPARANTESIS elements error  */
#line 166 "Sintatico.y"
                                                  { 
        yyerror("Erro de sintaxe.#Esperava um fechamento de parênteses!"); 
    }
#line 1366 "Sintatico.tab.c"
    break;

  case 41: /* additional_expressions_parent: separador error  */
#line 179 "Sintatico.y"
                      { 
        yyerror("Erro de sintaxe.#Esperava algo após uma vírgula ou operador lógico!"); 
    }
#line 1374 "Sintatico.tab.c"
    break;

  case 42: /* additional_expressions_parent: separador TAG_ABREPARANTESIS elements error  */
#line 182 "Sintatico.y"
                                                  { 
        yyerror("Erro de sintaxe.#Esperava um fechamento de parênteses!"); 
    }
#line 1382 "Sintatico.tab.c"
    break;

  case 48: /* elements: TAG_ABREPARANTESIS expression error  */
#line 199 "Sintatico.y"
                                          { 
        yyerror("Erro de sintaxe.#Esperava um fechamento de parênteses!"); 
    }
#line 1390 "Sintatico.tab.c"
    break;

  case 52: /* expression: TAG_PROPERTY error  */
#line 209 "Sintatico.y"
                         { 
        yyerror("Erro de sintaxe.#Esperava um quantificador, cardinalidade ou 'Value' após uma propriedade!"); 
    }
#line 1398 "Sintatico.tab.c"
    break;

  case 66: /* type_expre: namespace_datatype TAG_ABRECOLCHETE error  */
#line 242 "Sintatico.y"
                                                { 
        yyerror("Erro de sintaxe.#Esperava um operador de relação após o tipo de dado"); 
    }
#line 1406 "Sintatico.tab.c"
    break;

  case 67: /* type_expre: namespace_datatype TAG_ABRECOLCHETE op_rel error  */
#line 245 "Sintatico.y"
                                                       { 
        yyerror("Erro de sintaxe.#Esperava um número após o operador de relação"); 
    }
#line 1414 "Sintatico.tab.c"
    break;

  case 68: /* type_expre: namespace_datatype TAG_ABRECOLCHETE op_rel TAG_NUM error  */
#line 248 "Sintatico.y"
                                                               { 
        yyerror("Erro de sintaxe.#Esperava um fechamento de colchetes"); 
    }
#line 1422 "Sintatico.tab.c"
    break;

  case 76: /* disjointclasses_section: DISJOINTCLASSES error  */
#line 264 "Sintatico.y"
                            { 
        yyerror("Erro de sintaxe.#Esperava uma lista de classes após a palavra-chave 'disjointclasses:'");
    }
#line 1430 "Sintatico.tab.c"
    break;

  case 77: /* disjointclasses_section: DISJOINTWITH error  */
#line 267 "Sintatico.y"
                         { 
        yyerror("Erro de sintaxe.#Esperava uma lista de classes após a palavra-chave 'disjointwith:'");
    }
#line 1438 "Sintatico.tab.c"
    break;

  case 79: /* individuals_section: INDIVIDUALS error  */
#line 274 "Sintatico.y"
                        { 
        yyerror("Erro de sintaxe.#Esperava uma lista de indivíduos após a palavra-chave 'individuals:'");
    }
#line 1446 "Sintatico.tab.c"
    break;

  case 82: /* individuals_list: TAG_INDIVIDUOS TAG_VIRGULA error  */
#line 282 "Sintatico.y"
                                      { 
        yyerror("Erro de sintaxe.#Esperava algo após a vírgula");
    }
#line 1454 "Sintatico.tab.c"
    break;

  case 85: /* class_list: TAG_ABREPARANTESIS class_v error  */
#line 291 "Sintatico.y"
                                       { 
        yyerror("Erro de sintaxe.#Esperava um fechamento de parênteses"); 
    }
#line 1462 "Sintatico.tab.c"
    break;

  case 88: /* class_v: TAG_CLASS TAG_VIRGULA error  */
#line 300 "Sintatico.y"
                                  { 
        yyerror("Erro de sintaxe.#Esperava algo após a vírgula");
    }
#line 1470 "Sintatico.tab.c"
    break;

  case 90: /* class_op: TAG_ABREPARANTESIS class_l error  */
#line 308 "Sintatico.y"
                                       { 
        yyerror("Erro de sintaxe.#Esperava um fechamento de parênteses"); 
    }
#line 1478 "Sintatico.tab.c"
    break;

  case 93: /* class_l: TAG_CLASS op_logic error  */
#line 317 "Sintatico.y"
                               { 
        yyerror("Erro de sintaxe.#Esperava algo após o operador lógico");
    }
#line 1486 "Sintatico.tab.c"
    break;

  case 94: /* class_l: TAG_CLASS TAG_CLASS error  */
#line 320 "Sintatico.y"
                                { 
        yyerror("Erro de sintaxe.#Esperava um operador lógico entre as classes");
    }
#line 1494 "Sintatico.tab.c"
    break;

  case 95: /* op_quantifier: ONLY  */
#line 327 "Sintatico.y"
         { t.insert("Fechamento"); }
#line 1500 "Sintatico.tab.c"
    break;

  case 100: /* op_rel: TAG_MAIOR  */
#line 340 "Sintatico.y"
                        { (yyval.str) = ">"; }
#line 1506 "Sintatico.tab.c"
    break;

  case 101: /* op_rel: TAG_MAIORIGUAL  */
#line 341 "Sintatico.y"
                        { (yyval.str) = ">="; }
#line 1512 "Sintatico.tab.c"
    break;

  case 102: /* op_rel: TAG_MENOR  */
#line 342 "Sintatico.y"
                        { (yyval.str) = "<"; }
#line 1518 "Sintatico.tab.c"
    break;

  case 103: /* op_rel: TAG_MENORIGUAL  */
#line 343 "Sintatico.y"
                        { (yyval.str) = "<="; }
#line 1524 "Sintatico.tab.c"
    break;

  case 107: /* namespace_datatype: TAG_NAMESPACE TAG_DATATYPE  */
#line 356 "Sintatico.y"
    { 
        char * result = (char *)malloc(256); 
        if (result == NULL) {
            yyerror("Erro de memória ao processar namespace e datatype");
            YYABORT;
        }

        if (!is_namespace_valid(std::string((yyvsp[-1].str)))) {
            free(result);
            char error_message[512];
            snprintf(error_message, 512, "Namespace inválido.#O namespace %s não é válido", (yyvsp[-1].str));
            yyerror(error_message);
            (yyval.str) = NULL;
        } else if (strcmp((yyvsp[-1].str), "xsd:") == 0 && is_valid_xsd_type(std::string((yyvsp[0].str)))) {
            snprintf(result, 256, "xsd:%s", (yyvsp[0].str));
            (yyval.str) = result;
        }
        else if (strcmp((yyvsp[-1].str), "owl:") == 0 && is_valid_owl_type(std::string((yyvsp[0].str)))) {
            snprintf(result, 256, "owl:%s", (yyvsp[0].str));
            (yyval.str) = result;
        }
        else if (strcmp((yyvsp[-1].str), "rdf:") == 0 && is_valid_rdf_type(std::string((yyvsp[0].str)))) {
            snprintf(result, 256, "rdf:%s", (yyvsp[0].str));
            (yyval.str) = result;
        }
        else if (strcmp((yyvsp[-1].str), "rdfs:") == 0 && is_valid_rdfs_type(std::string((yyvsp[0].str)))) {
            snprintf(result, 256, "rdfs:%s", (yyvsp[0].str));
            (yyval.str) = result;
        }
        else {
            free(result);
            char error_message[512];
            snprintf(error_message, 512, "Tipo incompatível com o namespace.#O namespace %s não é compatível com o tipo %s", (yyvsp[-1].str), (yyvsp[0].str));
            yyerror(error_message);
            (yyval.str) = NULL;
        }
    }
#line 1566 "Sintatico.tab.c"
    break;


#line 1570 "Sintatico.tab.c"

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

#line 394 "Sintatico.y"


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

void addClass(const string& className) {
    c = &classes.emplace_back();  // Adiciona um novo elemento no vetor e obtém o ponteiro
    c->name = className;
}
