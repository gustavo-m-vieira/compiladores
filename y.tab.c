/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "compilador/glc_js.y"

// Includes em C/C++ e outras definições.
#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <vector>

using namespace std;

struct Atributos {
vector<string> c;
int linha, coluna;
};

struct Simbolo {
int linha, coluna; 
string tipo_decl; // "let", "const" e "var"
};

    // Pilha de Tabela de símbolos
vector< map< string, Simbolo > > ts = { { } };

// Tenta declarar uma variável "let", "var" ou "const"
void tenta_declarar_let( string nome, int linha, int coluna );
void tenta_declarar_const( string nome, int linha, int coluna );

// Verifica se a variável já foi declarada como "var" anteriormente
bool ja_declarou_var( string nome, int linha, int coluna );
void checa_ja_declarou(string nome, int linha, int coluna);

vector<string> concatena( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, string b );
vector<string> operator+( string a, vector<string> b );
string gera_label( string prefixo );
vector<string> resolve_enderecos( vector<string> entrada );

int linha = 1;
int coluna = 1;

// Tipo dos atributos: YYSTYPE é o tipo usado para os atributos.
#define YYSTYPE Atributos

void erro( string msg );
void imprime_codigo( vector<string> codigo );

// protótipo para o analisador léxico (gerado pelo lex)
extern "C" int yylex();
void yyerror( const char* );


#line 123 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    _ID = 258,
    _NUM = 259,
    _STRING = 260,
    _LET = 261,
    _VAR = 262,
    _CONST = 263,
    _FOR = 264,
    _FUNCTION = 265,
    _IF = 266,
    _ELSE = 267,
    _INC = 268,
    _RETURN = 269,
    _SETA = 270,
    _FPSETA = 271,
    _MAIS_IGUAL = 272,
    _IGUAL_IGUAL = 273,
    _MENOS_IGUAL = 274,
    _WHILE = 275
  };
#endif
/* Tokens.  */
#define _ID 258
#define _NUM 259
#define _STRING 260
#define _LET 261
#define _VAR 262
#define _CONST 263
#define _FOR 264
#define _FUNCTION 265
#define _IF 266
#define _ELSE 267
#define _INC 268
#define _RETURN 269
#define _SETA 270
#define _FPSETA 271
#define _MAIS_IGUAL 272
#define _IGUAL_IGUAL 273
#define _MENOS_IGUAL 274
#define _WHILE 275

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   454

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  197

#define YYUNDEFTOK  2
#define YYMAXUTOK   275


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    29,     2,     2,
      31,    37,    27,    25,    21,    26,    32,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    34,
      23,    22,    24,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    71,    71,    74,    75,    76,    77,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    91,   101,   111,   112,
     115,   118,   119,   122,   123,   124,   127,   128,   131,   134,
     137,   138,   141,   142,   145,   146,   149,   150,   153,   156,
     161,   166,   173,   176,   182,   183,   186,   187,   190,   198,
     203,   208,   209,   210,   211,   212,   213,   217,   218,   222,
     223,   224,   225,   226,   227,   228,   229,   232,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   251,   252,   256,   257,   261,   262
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_ID", "_NUM", "_STRING", "_LET", "_VAR",
  "_CONST", "_FOR", "_FUNCTION", "_IF", "_ELSE", "_INC", "_RETURN",
  "_SETA", "_FPSETA", "_MAIS_IGUAL", "_IGUAL_IGUAL", "_MENOS_IGUAL",
  "_WHILE", "','", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'['", "'('", "'.'", "':'", "';'", "'{'", "'}'", "')'", "']'", "$accept",
  "S", "CMDs", "CMD", "CMD_IF", "CMD_FOR", "CMD_WHILE", "E_OPC",
  "DECL_VAR", "DECL_FUN", "NOVO_ESCOPO", "DESTROI_ESCOPO", "PARAMs",
  "PARAM", "LVARs", "VVARs", "LVAR", "VVAR", "CTEs", "E_V", "EE", "E", "F",
  "FUNC_ANON", "CAMPOs", "ARGs", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    44,    61,    60,    62,    43,    45,    42,    47,    37,
      91,    40,    46,    58,    59,   123,   125,    41,    93
};
# endif

#define YYPACT_NINF (-128)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-49)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     257,   123,  -128,  -128,    14,    17,    18,    -9,     5,     2,
     279,    11,    21,   290,  -128,    64,    32,  -128,   257,  -128,
    -128,  -128,    24,   257,    29,   398,     6,    59,  -128,   221,
     314,   314,   314,    26,  -128,    43,    44,  -128,    55,    57,
    -128,   116,    52,     1,   314,    61,  -128,     3,    84,  -128,
     314,  -128,   374,    48,   200,   314,    72,    82,   344,    -3,
     410,   257,    -8,  -128,  -128,   257,  -128,  -128,   314,   314,
     314,   314,   314,   314,   314,   314,    90,   314,  -128,   314,
      50,   101,   198,   398,   398,   398,   398,   314,    14,   314,
      17,   314,    71,    81,  -128,    69,    95,    92,    91,    98,
      96,  -128,  -128,   102,   314,  -128,   314,   398,   314,   146,
    -128,   314,   114,   149,  -128,  -128,   422,   422,   422,   163,
     163,   121,   121,   121,  -128,  -128,   328,  -128,   117,    12,
     257,   398,  -128,   398,  -128,   386,   314,   314,   125,   146,
     314,   257,   130,   152,   152,  -128,   359,   398,  -128,   398,
    -128,  -128,    40,  -128,   314,   314,   122,    18,   134,   136,
    -128,   147,   398,   135,   257,   181,  -128,   314,   314,   398,
     398,  -128,  -128,   314,   314,   257,   159,  -128,   160,   152,
     398,   398,   167,   169,   174,   257,  -128,  -128,   152,   152,
    -128,   175,  -128,  -128,  -128,  -128,  -128
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,    68,    69,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,     0,     2,     6,     8,
       7,     9,     0,     6,     0,     0,    46,    67,    79,     0,
       0,     0,     0,    39,    23,    35,    41,    24,    37,     0,
      25,    22,     0,     0,     0,     0,    14,     0,     0,    46,
       0,    75,    87,     0,    68,     0,     0,    31,     0,    68,
      12,     6,     0,     1,     3,     6,     5,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,     0,
       0,     0,     0,    51,    49,    50,    48,     0,     0,     0,
       0,     0,     0,     0,    21,    28,    33,     0,     0,    46,
       0,    47,    15,    46,     0,    76,     0,    53,     0,     0,
      71,     0,     0,     0,    77,     4,    66,    59,    64,    61,
      62,    60,    63,    65,    78,    44,     0,    72,     0,    80,
       6,    38,    34,    40,    36,    43,    22,    22,     0,     0,
       0,     6,     0,     0,     0,    86,    32,    54,    30,    85,
      11,    84,    73,    74,     0,     0,     0,     0,     0,     0,
      28,     0,    32,     0,     6,    17,    20,     0,     0,    56,
      55,    52,    42,    22,    22,     6,     0,    82,     0,     0,
      58,    57,     0,     0,     0,     6,    83,    16,     0,     0,
      29,     0,    18,    19,    26,    29,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,   -16,   -12,  -128,  -128,  -128,  -127,   164,  -128,
      53,    19,   -38,  -128,   132,   137,  -128,  -128,    73,   -40,
     168,     0,  -128,  -128,   131,   -69
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    17,    18,    19,    20,    21,    92,    22,    23,
     139,   194,    56,    57,    34,    37,    35,    38,    40,    24,
      25,    49,    27,    28,    62,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    94,    64,    61,    96,    98,   100,    66,    42,   158,
     159,   128,    29,   113,    30,    26,    31,    33,    26,    32,
      36,    39,    41,    26,     1,     2,     3,    77,   114,   154,
     111,    45,    63,    44,   155,   145,    43,   125,    97,   101,
     -45,    26,    50,   -45,    99,   112,   182,   183,    87,   115,
     103,    12,    13,     1,     2,     3,    47,   167,    65,    51,
      45,    26,   168,    67,    88,    26,    89,    59,     2,     3,
     130,   148,    78,     7,    45,     9,    90,    26,    10,    91,
      12,    13,    26,    95,    11,    47,   105,   127,   108,    79,
      80,    81,    43,   124,    12,    13,    94,    94,    14,    15,
      60,   161,    68,   109,   129,   136,   138,    69,    70,    71,
      72,    73,    74,    75,   156,   137,    76,   140,   102,     1,
       2,     3,     4,     5,     6,   163,    45,   141,   142,   111,
      26,   165,   166,    94,    94,   143,    26,    26,    29,   144,
      30,    26,    31,    26,    26,    32,    12,    13,   178,    96,
     150,    47,   100,    76,   153,     1,     2,     3,   171,   184,
     160,     7,    45,     9,    26,   164,    10,   187,   173,   191,
     174,   177,    11,    26,    26,    26,   192,   193,    48,    26,
      52,    58,    12,    13,   176,    26,    14,    15,    26,    26,
      73,    74,    75,   179,   185,    76,   186,    83,    84,    85,
      86,    59,     2,     3,   188,    93,   189,     7,    45,     9,
     190,   195,    10,   175,   196,    29,   -33,    30,    11,    31,
     132,   -33,   106,   107,     1,     2,     3,   134,    12,    13,
     172,    45,    14,    15,   101,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   151,     0,     0,   126,    52,     0,
       0,    12,    13,     0,     0,   131,    82,   133,     0,   135,
       1,     2,     3,     4,     5,     6,     7,     8,     9,     0,
       0,    10,    52,     0,   146,     0,   147,    11,     0,   149,
       0,     0,     1,     2,     3,     0,     0,    12,    13,    45,
       0,    14,    15,    54,     2,     3,     0,     0,     0,     0,
      45,     0,     0,     0,     0,     0,    55,     0,   162,    12,
      13,     0,     0,    46,    47,     0,     0,     1,     2,     3,
      12,    13,   169,   170,    45,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   180,   181,     0,     0,     0,
       0,     0,     0,     0,    12,    13,    68,     0,     0,    47,
       0,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,     0,    68,     0,     0,     0,   152,    69,    70,    71,
      72,    73,    74,    75,     0,     0,    76,    68,     0,     0,
       0,   110,    69,    70,    71,    72,    73,    74,    75,     0,
       0,    76,    68,     0,     0,   104,   -48,    69,    70,    71,
      72,    73,    74,    75,    68,     0,    76,   157,     0,    69,
      70,    71,    72,    73,    74,    75,    68,     0,    76,     0,
       0,    69,    70,    71,    72,    73,    74,    75,   -47,     0,
      76,     0,     0,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
     -49,     0,   -47,     0,     0,   -49,   -49,    71,    72,    73,
      74,    75,     0,     0,    76
};

static const yytype_int16 yycheck[] =
{
       0,    41,    18,    15,     3,    43,     3,    23,     3,   136,
     137,    80,    15,    21,    17,    15,    19,     3,    18,    22,
       3,     3,    31,    23,     3,     4,     5,    21,    36,    17,
      33,    10,     0,    31,    22,   104,    31,    77,    37,    36,
      34,    41,    31,    37,    44,    61,   173,   174,    22,    65,
      50,    30,    31,     3,     4,     5,    35,    17,    34,    38,
      10,    61,    22,    34,    21,    65,    22,     3,     4,     5,
      82,   109,    13,     9,    10,    11,    21,    77,    14,    22,
      30,    31,    82,    31,    20,    35,    38,    37,    16,    30,
      31,    32,    31,     3,    30,    31,   136,   137,    34,    35,
      36,   139,    18,    21,     3,    34,    37,    23,    24,    25,
      26,    27,    28,    29,   130,    34,    32,    22,    34,     3,
       4,     5,     6,     7,     8,   141,    10,    35,    37,    33,
     130,   143,   144,   173,   174,    37,   136,   137,    15,    37,
      17,   141,    19,   143,   144,    22,    30,    31,   164,     3,
      36,    35,     3,    32,    37,     3,     4,     5,    36,   175,
      35,     9,    10,    11,   164,    35,    14,   179,    34,   185,
      34,    36,    20,   173,   174,   175,   188,   189,    10,   179,
      12,    13,    30,    31,    37,   185,    34,    35,   188,   189,
      27,    28,    29,    12,    35,    32,    36,    29,    30,    31,
      32,     3,     4,     5,    37,    41,    37,     9,    10,    11,
      36,    36,    14,   160,   195,    15,    16,    17,    20,    19,
      88,    21,    22,    55,     3,     4,     5,    90,    30,    31,
     157,    10,    34,    35,    36,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,   113,    -1,    -1,    79,    80,    -1,
      -1,    30,    31,    -1,    -1,    87,    35,    89,    -1,    91,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,   104,    -1,   106,    -1,   108,    20,    -1,   111,
      -1,    -1,     3,     4,     5,    -1,    -1,    30,    31,    10,
      -1,    34,    35,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    16,    -1,   140,    30,
      31,    -1,    -1,    34,    35,    -1,    -1,     3,     4,     5,
      30,    31,   154,   155,    10,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    18,    -1,    -1,    35,
      -1,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      32,    -1,    18,    -1,    -1,    -1,    38,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    18,    -1,    -1,
      -1,    37,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    18,    -1,    -1,    21,    37,    23,    24,    25,
      26,    27,    28,    29,    18,    -1,    32,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    18,    -1,    32,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    18,    -1,
      32,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      18,    -1,    32,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      14,    20,    30,    31,    34,    35,    40,    41,    42,    43,
      44,    45,    47,    48,    58,    59,    60,    61,    62,    15,
      17,    19,    22,     3,    53,    55,     3,    54,    56,     3,
      57,    31,     3,    31,    31,    10,    34,    35,    59,    60,
      31,    38,    59,    64,     3,    16,    51,    52,    59,     3,
      36,    42,    63,     0,    41,    34,    41,    34,    18,    23,
      24,    25,    26,    27,    28,    29,    32,    21,    13,    30,
      31,    32,    35,    59,    59,    59,    59,    22,    21,    22,
      21,    22,    46,    47,    58,    31,     3,    37,    51,    60,
       3,    36,    34,    60,    21,    38,    22,    59,    16,    21,
      37,    33,    41,    21,    36,    41,    59,    59,    59,    59,
      59,    59,    59,    59,     3,    58,    59,    37,    64,     3,
      42,    59,    53,    59,    54,    59,    34,    34,    37,    49,
      22,    35,    37,    37,    37,    64,    59,    59,    51,    59,
      36,    63,    38,    37,    17,    22,    41,    21,    46,    46,
      35,    51,    59,    41,    35,    42,    42,    17,    22,    59,
      59,    36,    57,    34,    34,    49,    37,    36,    41,    12,
      59,    59,    46,    46,    41,    35,    36,    42,    37,    37,
      36,    41,    42,    42,    50,    36,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    41,    41,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    43,    43,    44,    44,
      45,    46,    46,    47,    47,    47,    48,    48,    49,    50,
      51,    51,    52,    52,    53,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    63,    63,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     2,     0,     1,     1,     1,
       2,     4,     2,     1,     2,     3,     7,     5,     9,     9,
       5,     1,     0,     2,     2,     2,     9,    10,     0,     0,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     3,     3,     1,     1,     2,     3,     3,
       3,     3,     6,     3,     4,     5,     5,     6,     6,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     3,     3,     4,     4,     2,     3,     3,     3,     1,
       3,     2,     6,     7,     3,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 71 "compilador/glc_js.y"
          { imprime_codigo( resolve_enderecos( yyvsp[0].c + "." ) ); cout << endl;}
#line 1556 "y.tab.c"
    break;

  case 3:
#line 74 "compilador/glc_js.y"
                            { yyval.c = yyvsp[-1].c + yyvsp[0].c; }
#line 1562 "y.tab.c"
    break;

  case 4:
#line 75 "compilador/glc_js.y"
                            { yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1568 "y.tab.c"
    break;

  case 5:
#line 76 "compilador/glc_js.y"
                            { yyval.c = yyvsp[-1].c + yyvsp[0].c; }
#line 1574 "y.tab.c"
    break;

  case 6:
#line 77 "compilador/glc_js.y"
                            { yyval.c.clear(); }
#line 1580 "y.tab.c"
    break;

  case 11:
#line 84 "compilador/glc_js.y"
                           { yyval.c = "<{" + yyvsp[-1].c + "}>"; }
#line 1586 "y.tab.c"
    break;

  case 12:
#line 85 "compilador/glc_js.y"
                       {  yyval.c.clear(); yyval.c.push_back("<{}>"); }
#line 1592 "y.tab.c"
    break;

  case 13:
#line 86 "compilador/glc_js.y"
                       { yyval.c.clear(); }
#line 1598 "y.tab.c"
    break;

  case 16:
#line 92 "compilador/glc_js.y"
        {  string lbl_fim = gera_label( "fim_if" ), 
                   lbl_true = gera_label( "then" ), 
                   lbl_false = gera_label( "else" );
                   
            yyval.c = yyvsp[-4].c + lbl_true + "?" + lbl_false + "#" + 
                   (":" + lbl_true) + yyvsp[-2].c + lbl_fim + "#" +
                   (":" + lbl_false) + yyvsp[0].c + 
                   (":" + lbl_fim);
         }
#line 1612 "y.tab.c"
    break;

  case 17:
#line 102 "compilador/glc_js.y"
       {  string lbl_fim = gera_label( "fim_if" ), 
                    lbl_true = gera_label( "then" );
                    
                yyval.c = yyvsp[-2].c + lbl_true + "?" + lbl_fim + "#" + 
                    (":" + lbl_true) + yyvsp[0].c + 
                    (":" + lbl_fim);
        }
#line 1624 "y.tab.c"
    break;

  case 23:
#line 122 "compilador/glc_js.y"
                         { yyval = yyvsp[0]; }
#line 1630 "y.tab.c"
    break;

  case 24:
#line 123 "compilador/glc_js.y"
                         { yyval = yyvsp[0]; }
#line 1636 "y.tab.c"
    break;

  case 25:
#line 124 "compilador/glc_js.y"
                         { yyval = yyvsp[0]; }
#line 1642 "y.tab.c"
    break;

  case 28:
#line 131 "compilador/glc_js.y"
                { ts.push_back( {} ); }
#line 1648 "y.tab.c"
    break;

  case 29:
#line 134 "compilador/glc_js.y"
                 { ts.pop_back(); }
#line 1654 "y.tab.c"
    break;

  case 34:
#line 145 "compilador/glc_js.y"
                           { yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1660 "y.tab.c"
    break;

  case 36:
#line 149 "compilador/glc_js.y"
                           { yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1666 "y.tab.c"
    break;

  case 38:
#line 154 "compilador/glc_js.y"
       { tenta_declarar_let( yyvsp[-2].c[0], yyvsp[-2].linha, yyvsp[-2].coluna );
         yyval.c = yyvsp[-2].c + "&" + yyvsp[-2].c + yyvsp[0].c + "=" + "^"; }
#line 1673 "y.tab.c"
    break;

  case 39:
#line 157 "compilador/glc_js.y"
       { tenta_declarar_let( yyvsp[0].c[0], yyvsp[0].linha, yyvsp[0].coluna );
         yyval.c = yyvsp[0].c + "&"; }
#line 1680 "y.tab.c"
    break;

  case 40:
#line 162 "compilador/glc_js.y"
        { if( ja_declarou_var( yyvsp[-2].c[0], yyvsp[-2].linha, yyvsp[-2].coluna ) )
            yyval.c = yyvsp[-2].c + yyvsp[0].c + "=" + "^";
          else
            yyval.c = yyvsp[-2].c + "&" + yyvsp[-2].c + yyvsp[0].c + "=" + "^"; }
#line 1689 "y.tab.c"
    break;

  case 41:
#line 167 "compilador/glc_js.y"
       { if( !ja_declarou_var( yyvsp[0].c[0], yyvsp[0].linha, yyvsp[0].coluna ) )
           yyval.c = yyvsp[0].c + "&";
         else
           yyval.c.clear(); }
#line 1698 "y.tab.c"
    break;

  case 42:
#line 174 "compilador/glc_js.y"
       { tenta_declarar_const( yyvsp[-4].c[0], yyvsp[-4].linha, yyvsp[-4].coluna );
         yyval.c = yyvsp[-4].c + "&" + yyvsp[-4].c + yyvsp[-2].c + "=" + "^"; }
#line 1705 "y.tab.c"
    break;

  case 43:
#line 177 "compilador/glc_js.y"
       { tenta_declarar_const( yyvsp[-2].c[0], yyvsp[-2].linha, yyvsp[-2].coluna );
         yyval.c = yyvsp[-2].c + "&" + yyvsp[-2].c + yyvsp[0].c + "=" + "^"; }
#line 1712 "y.tab.c"
    break;

  case 47:
#line 187 "compilador/glc_js.y"
              {  yyval.c.clear(); yyval.c.push_back("{}"); }
#line 1718 "y.tab.c"
    break;

  case 48:
#line 191 "compilador/glc_js.y"
    {
        checa_ja_declarou( yyvsp[-2].c[0], yyvsp[-2].linha, yyvsp[-2].coluna );
        if ( yyvsp[0].c[yyvsp[0].c.size()-1] == "^" ) {
            yyvsp[0].c.pop_back();
        }
        yyval.c = yyvsp[-2].c + yyvsp[0].c + "=" + "^";
    }
#line 1730 "y.tab.c"
    break;

  case 49:
#line 199 "compilador/glc_js.y"
    {
        checa_ja_declarou( yyvsp[-2].c[0], yyvsp[-2].linha, yyvsp[-2].coluna );
        yyval.c = yyvsp[-2].c + yyvsp[-2].c + "@" + yyvsp[0].c + "+" + "=" + "^"; 
    }
#line 1739 "y.tab.c"
    break;

  case 50:
#line 204 "compilador/glc_js.y"
    {
        checa_ja_declarou( yyvsp[-2].c[0], yyvsp[-2].linha, yyvsp[-2].coluna );
        yyval.c = yyvsp[-2].c + yyvsp[-2].c + "@" + yyvsp[0].c + "-" + "=" + "^"; 
    }
#line 1748 "y.tab.c"
    break;

  case 55:
#line 212 "compilador/glc_js.y"
                       { yyval.c = yyvsp[-4].c + "@" + yyvsp[-2].c + yyvsp[0].c + "[=]" + "^"; }
#line 1754 "y.tab.c"
    break;

  case 56:
#line 214 "compilador/glc_js.y"
    { 
        yyval.c =  yyvsp[-4].c + "@" + yyvsp[-2].c + yyvsp[-4].c + "@" + yyvsp[-2].c + "[@]" + yyvsp[0].c + "+" + "=" + "^";
    }
#line 1762 "y.tab.c"
    break;

  case 57:
#line 217 "compilador/glc_js.y"
                          { yyval.c = yyvsp[-5].c + yyvsp[-3].c + yyvsp[0].c + "[=]" + "^"; }
#line 1768 "y.tab.c"
    break;

  case 58:
#line 219 "compilador/glc_js.y"
    { 
        // $$.c =  // pensar nisso amanha
    }
#line 1776 "y.tab.c"
    break;

  case 59:
#line 222 "compilador/glc_js.y"
                       { yyval.c = yyvsp[-2].c + yyvsp[0].c + "<"; }
#line 1782 "y.tab.c"
    break;

  case 60:
#line 223 "compilador/glc_js.y"
                       { yyval.c = yyvsp[-2].c + yyvsp[0].c + "*"; }
#line 1788 "y.tab.c"
    break;

  case 61:
#line 224 "compilador/glc_js.y"
                       { yyval.c = yyvsp[-2].c + yyvsp[0].c + "+"; }
#line 1794 "y.tab.c"
    break;

  case 62:
#line 225 "compilador/glc_js.y"
                       { yyval.c = yyvsp[-2].c + yyvsp[0].c + "-"; }
#line 1800 "y.tab.c"
    break;

  case 63:
#line 226 "compilador/glc_js.y"
                       { yyval.c = yyvsp[-2].c + yyvsp[0].c + "/"; }
#line 1806 "y.tab.c"
    break;

  case 64:
#line 227 "compilador/glc_js.y"
                       { yyval.c = yyvsp[-2].c + yyvsp[0].c + ">"; }
#line 1812 "y.tab.c"
    break;

  case 65:
#line 228 "compilador/glc_js.y"
                       { yyval.c = yyvsp[-2].c + yyvsp[0].c + "%"; }
#line 1818 "y.tab.c"
    break;

  case 66:
#line 229 "compilador/glc_js.y"
                             { yyval.c = yyvsp[-2].c + yyvsp[0].c + "=="; }
#line 1824 "y.tab.c"
    break;

  case 68:
#line 235 "compilador/glc_js.y"
            { yyval.c = yyvsp[0].c + "@"; }
#line 1830 "y.tab.c"
    break;

  case 69:
#line 236 "compilador/glc_js.y"
            { yyval.c = yyvsp[0].c; }
#line 1836 "y.tab.c"
    break;

  case 70:
#line 237 "compilador/glc_js.y"
            { yyval.c = yyvsp[0].c; }
#line 1842 "y.tab.c"
    break;

  case 71:
#line 238 "compilador/glc_js.y"
               { yyval = yyvsp[-1]; }
#line 1848 "y.tab.c"
    break;

  case 75:
#line 242 "compilador/glc_js.y"
            { yyval.c.clear(); yyval.c.push_back("[]");}
#line 1854 "y.tab.c"
    break;

  case 80:
#line 247 "compilador/glc_js.y"
              { yyval.c = yyvsp[-2].c + "@" + yyvsp[0].c; }
#line 1860 "y.tab.c"
    break;

  case 81:
#line 248 "compilador/glc_js.y"
           { yyval.c = yyvsp[-1].c + yyvsp[-1].c + "@" + "1" + "+" + "="; }
#line 1866 "y.tab.c"
    break;


#line 1870 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 265 "compilador/glc_js.y"


#include "lex.yy.c"

vector<string> concatena ( vector<string> a, vector<string> b ) {
  a.insert( a.end(), b.begin(), b.end() );
  return a;
}

void yyerror( const char* msg ) {
    cout << endl << "Erro: " << msg << endl
        << "Perto de : '" << yylval.c[0] << "'" << endl
        << "Linha: " << yylval.linha << ", coluna: " << yylval.coluna << endl;
  
  exit(1);
}

vector<string> operator+( vector<string> a, vector<string> b ) {
  return concatena( a, b );
}

vector<string> operator+( vector<string> a, string b ) {
  a.push_back( b );
  return a;
}

vector<string> operator+( string a, vector<string> b ) {
  vector<string> aux{ a };

  return aux + b;
}

string gera_label( string prefixo ) {
  static int n = 0;
  return prefixo + "_" + to_string( ++n ) + ":";
}

vector<string> resolve_enderecos( vector<string> entrada ) {
  map<string,int> label;
  vector<string> saida;
  for( int i = 0; i < entrada.size(); i++ ) 
    if( entrada[i][0] == ':' ) 
        label[entrada[i].substr(1)] = saida.size();
    else
      saida.push_back( entrada[i] );
  
  for( int i = 0; i < saida.size(); i++ ) 
    if( label.count( saida[i] ) > 0 )
        saida[i] = to_string(label[saida[i]]);
    
  return saida;
}

void imprime_codigo( vector<string> codigo ) {
    for( int i = 0; i < codigo.size(); i++ )
        cout << codigo[i] << " ";
}

void tenta_declarar_let( string nome, int linha, int coluna ){   
    if( ts.back().count( nome ) > 0 ) {
       erro("Erro: a variável '" + nome + "' já foi declarada na linha " + to_string( ts.back()[nome].linha ) + ".");
    }
    
    ts.back()[nome] = Simbolo{ linha, coluna, "let" }; 
}

void tenta_declarar_const( string nome, int linha, int coluna ){  
    if( ts.back().count( nome ) > 0 ) {
        erro("Erro: a variável '" + nome + "' já foi declarada na linha " + to_string( ts.back()[nome].linha ) + ".");
    }
    
    ts.back()[nome] = Simbolo{ linha, coluna, "const" }; 
}

bool ja_declarou_var( string nome, int linha, int coluna ){   
    if( ts.back().count( nome ) > 0 ) {
      if( ts.back()[nome].tipo_decl != "var" ) 
        erro("Erro: a variável '" + nome + "' já foi declarada na linha " + to_string( ts.back()[nome].linha ) + ".");
      
      return true;
    }
    
    ts.back()[nome] = Simbolo{ linha, coluna, "var" }; 
    return false;
}

void checa_ja_declarou(string nome, int linha, int coluna) {
    if( ts.back().count( nome ) > 0 ) {
        if( ts.back()[nome].tipo_decl == "const" ) 
            erro("Erro: a variável '" + nome + "' já foi declarada na linha " + to_string( ts.back()[nome].linha ) + ".");
    } else {
        erro("Erro: a variável '" + nome + "' não foi declarada.");
    }
}

void erro( string msg ) {
    cout << msg << endl;
    exit( 1 );
}
