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
#line 1 "calc-sintaxis.y"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast/ast.h"
#include "table_of_symbols/table_symbols.h"
#include "table_of_symbols/symbol_to_image.h"

Node* root;
Symbol* head = NULL;


#line 85 "calc-sintaxis.tab.c"

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

#include "calc-sintaxis.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_INT = 3,                  /* TOKEN_INT  */
  YYSYMBOL_TOKEN_BOOL = 4,                 /* TOKEN_BOOL  */
  YYSYMBOL_TOKEN_VOID = 5,                 /* TOKEN_VOID  */
  YYSYMBOL_TOKEN_MAIN = 6,                 /* TOKEN_MAIN  */
  YYSYMBOL_TOKEN_RETURN = 7,               /* TOKEN_RETURN  */
  YYSYMBOL_TOKEN_OP_RES = 8,               /* TOKEN_OP_RES  */
  YYSYMBOL_TOKEN_OP_MAS = 9,               /* TOKEN_OP_MAS  */
  YYSYMBOL_TOKEN_OP_MULT = 10,             /* TOKEN_OP_MULT  */
  YYSYMBOL_TOKEN_OP_DIV = 11,              /* TOKEN_OP_DIV  */
  YYSYMBOL_TOKEN_IGUAL = 12,               /* TOKEN_IGUAL  */
  YYSYMBOL_TOKEN_PYC = 13,                 /* TOKEN_PYC  */
  YYSYMBOL_TOKEN_PAR_A = 14,               /* TOKEN_PAR_A  */
  YYSYMBOL_TOKEN_PAR_C = 15,               /* TOKEN_PAR_C  */
  YYSYMBOL_TOKEN_LLA_A = 16,               /* TOKEN_LLA_A  */
  YYSYMBOL_TOKEN_LLA_C = 17,               /* TOKEN_LLA_C  */
  YYSYMBOL_TOKEN_VTRUE = 18,               /* TOKEN_VTRUE  */
  YYSYMBOL_TOKEN_VFALSE = 19,              /* TOKEN_VFALSE  */
  YYSYMBOL_TOKEN_OP_AND = 20,              /* TOKEN_OP_AND  */
  YYSYMBOL_TOKEN_OP_OR = 21,               /* TOKEN_OP_OR  */
  YYSYMBOL_TOKEN_OP_NOT = 22,              /* TOKEN_OP_NOT  */
  YYSYMBOL_TOKEN_ID = 23,                  /* TOKEN_ID  */
  YYSYMBOL_TOKEN_NUM = 24,                 /* TOKEN_NUM  */
  YYSYMBOL_TRUE = 25,                      /* TRUE  */
  YYSYMBOL_YYACCEPT = 26,                  /* $accept  */
  YYSYMBOL_prog = 27,                      /* prog  */
  YYSYMBOL_tipo = 28,                      /* tipo  */
  YYSYMBOL_decs = 29,                      /* decs  */
  YYSYMBOL_dec = 30,                       /* dec  */
  YYSYMBOL_sentens = 31,                   /* sentens  */
  YYSYMBOL_senten = 32,                    /* senten  */
  YYSYMBOL_exp = 33                        /* exp  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   70

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  25
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  50

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


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
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    52,    52,    75,    81,    87,    95,    99,   108,   137,
     141,   150,   169,   176,   185,   198,   211,   224,   237,   250,
     263,   276,   280,   288,   298,   307
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
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_INT",
  "TOKEN_BOOL", "TOKEN_VOID", "TOKEN_MAIN", "TOKEN_RETURN", "TOKEN_OP_RES",
  "TOKEN_OP_MAS", "TOKEN_OP_MULT", "TOKEN_OP_DIV", "TOKEN_IGUAL",
  "TOKEN_PYC", "TOKEN_PAR_A", "TOKEN_PAR_C", "TOKEN_LLA_A", "TOKEN_LLA_C",
  "TOKEN_VTRUE", "TOKEN_VFALSE", "TOKEN_OP_AND", "TOKEN_OP_OR",
  "TOKEN_OP_NOT", "TOKEN_ID", "TOKEN_NUM", "TRUE", "$accept", "prog",
  "tipo", "decs", "dec", "sentens", "senten", "exp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-23)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      64,   -23,   -23,   -23,     2,    10,   -23,    -6,     4,     9,
      64,    23,    -3,    64,    14,    38,    41,    15,    -3,   -23,
     -23,   -23,   -13,   -23,   -23,   -13,   -23,   -23,    13,   -13,
     -23,   -23,    20,    55,   -13,   -13,   -13,   -13,   -23,   -13,
     -13,    34,   -23,    39,    39,   -23,   -23,    55,    28,   -23
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     4,     5,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     6,     0,     0,     0,     0,     9,     7,
       8,    13,     0,    24,    25,     0,    23,    22,     0,     0,
       2,    10,     0,    20,     0,     0,     0,     0,    12,     0,
       0,     0,    21,    16,    14,    15,    17,    18,    19,    11
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -23,   -23,    58,    46,   -23,    52,   -23,   -22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,    11,    12,    13,    17,    18,    28
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      32,    22,     6,    33,    15,    23,    24,    41,     8,    25,
      26,    27,    43,    44,    45,    46,     7,    47,    48,     9,
      16,    34,    35,    36,    37,    10,    38,    20,    34,    35,
      36,    37,    30,    39,    40,    42,    34,    35,    36,    37,
      39,    40,    34,    35,    36,    37,    14,    49,    39,    36,
      37,    21,    22,    29,    39,    40,    23,    24,     5,    19,
      25,    26,    27,    34,    35,    36,    37,     1,     2,     3,
      31
};

static const yytype_int8 yycheck[] =
{
      22,    14,     0,    25,     7,    18,    19,    29,    14,    22,
      23,    24,    34,    35,    36,    37,     6,    39,    40,    15,
      23,     8,     9,    10,    11,    16,    13,    13,     8,     9,
      10,    11,    17,    20,    21,    15,     8,     9,    10,    11,
      20,    21,     8,     9,    10,    11,    23,    13,    20,    10,
      11,    13,    14,    12,    20,    21,    18,    19,     0,    13,
      22,    23,    24,     8,     9,    10,    11,     3,     4,     5,
      18
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    27,    28,     0,     6,    14,    15,
      16,    28,    29,    30,    23,     7,    23,    31,    32,    29,
      13,    13,    14,    18,    19,    22,    23,    24,    33,    12,
      17,    31,    33,    33,     8,     9,    10,    11,    13,    20,
      21,    33,    15,    33,    33,    33,    33,    33,    33,    13
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    26,    27,    28,    28,    28,    29,    29,    30,    31,
      31,    32,    32,    32,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     1,     1,     1,     1,     2,     3,     1,
       2,     4,     3,     2,     3,     3,     3,     3,     3,     3,
       2,     3,     1,     1,     1,     1
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
  case 2: /* prog: tipo TOKEN_MAIN TOKEN_PAR_A TOKEN_PAR_C TOKEN_LLA_A decs sentens TOKEN_LLA_C  */
#line 53 "calc-sintaxis.y"
        {   
            printf("There are no errors \n"); 
            
            Info *tipo_info = malloc(sizeof(Info));
            tipo_info->name = strdup((yyvsp[-7].tipo_info).name);
            tipo_info->token = (yyvsp[-7].tipo_info).token;

            Info *main_info = malloc(sizeof(Info));
            main_info->name = strdup("main");
            main_info->token = MAIN;

            Node* main_node = createTree(main_info, (yyvsp[-2].node), (yyvsp[-1].node));
            (yyval.node) = createTree(tipo_info, main_node, NULL);
            root = (yyval.node);
                        
            if (root != NULL && head != NULL) {
                generateASTDotFile(root, "prog_ast");
                generateTSDotFile(head, "symbol_table");
            }
        }
#line 1150 "calc-sintaxis.tab.c"
    break;

  case 3: /* tipo: TOKEN_INT  */
#line 76 "calc-sintaxis.y"
        {
            (yyval.tipo_info).name = strdup("int");
            (yyval.tipo_info).token = INT;
            (yyval.tipo_info).type = INTEGER;
        }
#line 1160 "calc-sintaxis.tab.c"
    break;

  case 4: /* tipo: TOKEN_BOOL  */
#line 82 "calc-sintaxis.y"
        {
            (yyval.tipo_info).name = strdup("bool");
            (yyval.tipo_info).token = BOOL;
            (yyval.tipo_info).type = BOOLEAN;
        }
#line 1170 "calc-sintaxis.tab.c"
    break;

  case 5: /* tipo: TOKEN_VOID  */
#line 88 "calc-sintaxis.y"
        {
            (yyval.tipo_info).name = strdup("void");
            (yyval.tipo_info).token = T_VOID;
            (yyval.tipo_info).type = TYPE_VOID;
        }
#line 1180 "calc-sintaxis.tab.c"
    break;

  case 6: /* decs: dec  */
#line 96 "calc-sintaxis.y"
        {
            (yyval.node) = (yyvsp[0].node);
        }
#line 1188 "calc-sintaxis.tab.c"
    break;

  case 7: /* decs: dec decs  */
#line 100 "calc-sintaxis.y"
        {
            Info *decs_info = malloc(sizeof(Info));
            decs_info->name = strdup("decs");
            decs_info->token = DECS;
            (yyval.node) = createTree(decs_info, (yyvsp[-1].node), (yyvsp[0].node));
        }
#line 1199 "calc-sintaxis.tab.c"
    break;

  case 8: /* dec: tipo TOKEN_ID TOKEN_PYC  */
#line 109 "calc-sintaxis.y"
    {
        Info *id_buscado = searchByName(head, (yyvsp[-1].sval));
        if (id_buscado != NULL) {
            printf("Error: Variable '%s' already declared\n", (yyvsp[-1].sval));
            YYERROR;
        }

        Info *dec_info = malloc(sizeof(Info));
        dec_info->name = strdup("dec");
        dec_info->token = DEC;

        Info *tipo_info = malloc(sizeof(Info));
        tipo_info->name = strdup((yyvsp[-2].tipo_info).name);
        tipo_info->token = (yyvsp[-2].tipo_info).token;
        Node* tipo = createLeaf(tipo_info);

        Info *id_info = malloc(sizeof(Info));
        id_info->name = strdup((yyvsp[-1].sval));
        id_info->token = ID;
        id_info->type = (yyvsp[-2].tipo_info).type;
        Node* id = createLeaf(id_info);

        head = insertByName(head, id_info);

        (yyval.node) = createTree(dec_info, tipo, id);
    }
#line 1230 "calc-sintaxis.tab.c"
    break;

  case 9: /* sentens: senten  */
#line 138 "calc-sintaxis.y"
        {
            (yyval.node) = (yyvsp[0].node);
        }
#line 1238 "calc-sintaxis.tab.c"
    break;

  case 10: /* sentens: senten sentens  */
#line 142 "calc-sintaxis.y"
        {
            Info *sentens_info = malloc(sizeof(Info));
            sentens_info->name = strdup("sentest");
            sentens_info->token = SENTENS;
            (yyval.node) = createTree(sentens_info, (yyvsp[-1].node), (yyvsp[0].node));
        }
#line 1249 "calc-sintaxis.tab.c"
    break;

  case 11: /* senten: TOKEN_ID TOKEN_IGUAL exp TOKEN_PYC  */
#line 151 "calc-sintaxis.y"
        {
            Info *id_buscado = searchByName(head, (yyvsp[-3].sval));
            if (id_buscado == NULL) {
                printf("Error: Undeclared variable '%s'\n", (yyvsp[-3].sval));
                YYERROR;
            } else if (id_buscado->type != (yyvsp[-1].node)->info->type) {
                printf("Error: Incompatible types in assignment\n");
                YYERROR;
            } else {
                Node *id = createLeaf(id_buscado);

                Info *igual_info = malloc(sizeof(Info));
                igual_info->op = strdup("=");
                igual_info->token = OP;

                (yyval.node) = createTree(igual_info, id, (yyvsp[-1].node));
            }
        }
#line 1272 "calc-sintaxis.tab.c"
    break;

  case 12: /* senten: TOKEN_RETURN exp TOKEN_PYC  */
#line 170 "calc-sintaxis.y"
        {
            Info *ret_info = malloc(sizeof(Info));
            ret_info->name = strdup("return");
            ret_info->token = RETURN;
            (yyval.node) = createTree(ret_info, (yyvsp[-1].node), NULL);
        }
#line 1283 "calc-sintaxis.tab.c"
    break;

  case 13: /* senten: TOKEN_RETURN TOKEN_PYC  */
#line 177 "calc-sintaxis.y"
        {
            Info *ret_info = malloc(sizeof(Info));
            ret_info->name = strdup("return");
            ret_info->token = RETURN;
            (yyval.node) = createLeaf(ret_info);
        }
#line 1294 "calc-sintaxis.tab.c"
    break;

  case 14: /* exp: exp TOKEN_OP_MAS exp  */
#line 186 "calc-sintaxis.y"
        {
            if ((yyvsp[-2].node)->info->type != INTEGER || (yyvsp[0].node)->info->type != INTEGER) {
                printf("Error: Addition (+) operation requires integer operands\n");
                YYERROR;
            }

            Info *op_info = malloc(sizeof(Info));
            op_info->op = strdup("+");
            op_info->token = OP;
            op_info->type = INTEGER;
            (yyval.node) = createTree(op_info, (yyvsp[-2].node), (yyvsp[0].node));
        }
#line 1311 "calc-sintaxis.tab.c"
    break;

  case 15: /* exp: exp TOKEN_OP_MULT exp  */
#line 199 "calc-sintaxis.y"
        {
            if ((yyvsp[-2].node)->info->type != INTEGER || (yyvsp[0].node)->info->type != INTEGER) {
                printf("Error: Multiplication (*) operation requires integer operands\n");
                YYERROR;
            }

            Info *op_info = malloc(sizeof(Info));
            op_info->op = strdup("*");
            op_info->token = OP;
            op_info->type = INTEGER;
            (yyval.node) = createTree(op_info, (yyvsp[-2].node), (yyvsp[0].node));
        }
#line 1328 "calc-sintaxis.tab.c"
    break;

  case 16: /* exp: exp TOKEN_OP_RES exp  */
#line 212 "calc-sintaxis.y"
        {
            if ((yyvsp[-2].node)->info->type != INTEGER || (yyvsp[0].node)->info->type != INTEGER) {
                printf("Error: Subtraction (-) operation requires integer operands\n");
                YYERROR;
            }

            Info *op_info = malloc(sizeof(Info));
            op_info->op = strdup("-");
            op_info->token = OP;
            op_info->type = INTEGER;
            (yyval.node) = createTree(op_info, (yyvsp[-2].node), (yyvsp[0].node));
        }
#line 1345 "calc-sintaxis.tab.c"
    break;

  case 17: /* exp: exp TOKEN_OP_DIV exp  */
#line 225 "calc-sintaxis.y"
        {
            if ((yyvsp[-2].node)->info->type != INTEGER || (yyvsp[0].node)->info->type != INTEGER) {
                printf("Error: Division (/) operation requires integer operands\n");
                YYERROR;
            }

            Info *op_info = malloc(sizeof(Info));
            op_info->op = strdup("/");
            op_info->token = OP;
            op_info->type = INTEGER;
            (yyval.node) = createTree(op_info, (yyvsp[-2].node), (yyvsp[0].node));
        }
#line 1362 "calc-sintaxis.tab.c"
    break;

  case 18: /* exp: exp TOKEN_OP_AND exp  */
#line 238 "calc-sintaxis.y"
        {
            if ((yyvsp[-2].node)->info->type != BOOLEAN || (yyvsp[0].node)->info->type != BOOLEAN) {
                printf("Error: Operation 'and' requires Boolean operators\n");
                YYERROR;
            }

            Info *op_info = malloc(sizeof(Info));
            op_info->op = strdup("and");
            op_info->token = OP;
            op_info->type = BOOLEAN;
            (yyval.node) = createTree(op_info, (yyvsp[-2].node), (yyvsp[0].node));
        }
#line 1379 "calc-sintaxis.tab.c"
    break;

  case 19: /* exp: exp TOKEN_OP_OR exp  */
#line 251 "calc-sintaxis.y"
        {
            if ((yyvsp[-2].node)->info->type != BOOLEAN || (yyvsp[0].node)->info->type != BOOLEAN) {
                printf("Error: Operation 'or' requires Boolean operators\n");
                YYERROR;
            }

            Info *op_info = malloc(sizeof(Info));
            op_info->op = strdup("or");
            op_info->token = OP;
            op_info->type = BOOLEAN;
            (yyval.node) = createTree(op_info, (yyvsp[-2].node), (yyvsp[0].node));
        }
#line 1396 "calc-sintaxis.tab.c"
    break;

  case 20: /* exp: TOKEN_OP_NOT exp  */
#line 264 "calc-sintaxis.y"
        {
            if ((yyvsp[0].node)->info->type != BOOLEAN) {
                printf("Error: Operation 'not' require Boolean operator\n");
                YYERROR;
            }

            Info *op_info = malloc(sizeof(Info));
            op_info->op = strdup("not");
            op_info->token = OP;
            op_info->type = BOOLEAN;
            (yyval.node) = createTree(op_info, NULL, (yyvsp[0].node));
        }
#line 1413 "calc-sintaxis.tab.c"
    break;

  case 21: /* exp: TOKEN_PAR_A exp TOKEN_PAR_C  */
#line 277 "calc-sintaxis.y"
        {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1421 "calc-sintaxis.tab.c"
    break;

  case 22: /* exp: TOKEN_NUM  */
#line 281 "calc-sintaxis.y"
        {
            Info *num_info = malloc(sizeof(Info));
            num_info->i_value = (yyvsp[0].ival);
            num_info->token = NUM;
            num_info->type = INTEGER;
            (yyval.node) = createLeaf(num_info);
        }
#line 1433 "calc-sintaxis.tab.c"
    break;

  case 23: /* exp: TOKEN_ID  */
#line 289 "calc-sintaxis.y"
        {
            Info *id_buscado = searchByName(head, (yyvsp[0].sval));
            if (id_buscado == NULL) {
                printf("Error: variable '%s' no declarada\n", (yyvsp[0].sval));
                YYERROR;
            } else {
                (yyval.node) = createLeaf(id_buscado);
            }
        }
#line 1447 "calc-sintaxis.tab.c"
    break;

  case 24: /* exp: TOKEN_VTRUE  */
#line 299 "calc-sintaxis.y"
        {
            Info *booleano = malloc(sizeof(Info));
            booleano->bool_string = strdup("true");
            booleano->b_value = true;
            booleano->type = BOOLEAN;
            booleano->token = BOOL;
            (yyval.node) = createLeaf(booleano);
        }
#line 1460 "calc-sintaxis.tab.c"
    break;

  case 25: /* exp: TOKEN_VFALSE  */
#line 308 "calc-sintaxis.y"
        {
            Info *booleano = malloc(sizeof(Info));
            booleano->bool_string = strdup("false");
            booleano->b_value = false;
            booleano->type = BOOLEAN;
            booleano->token = BOOL;
            (yyval.node) = createLeaf(booleano);
        }
#line 1473 "calc-sintaxis.tab.c"
    break;


#line 1477 "calc-sintaxis.tab.c"

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

#line 318 "calc-sintaxis.y"



