/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parse.y" /* yacc.c:339  */
     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 30 Jul 13   */

/* Copyright (c) 2013 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/* 14 Feb 01; 01 Oct 04; 02 Mar 07; 27 Feb 08; 24 Jul 09; 02 Aug 12 */

/*
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.

; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.

; You should have received a copy of the GNU General Public License
; along with this program; if not, see <http://www.gnu.org/licenses/>.
  */

/* NOTE:   Copy your lexan.l lexical analyzer to this directory.      */

/* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
    the IF statement, but Yacc's default resolves it in the right way.*/

/*
 * Lab 4 Submission
 * Name:		Brian Chow
 * Email:		brianj.chow@yahoo.com
 * EID:			bc23784
 * CS Login:	bc23784
 *
 * Last modified: 1730, 14/08/11
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"

/* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;


#line 122 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
    IDENTIFIER = 258,
    STRING = 259,
    NUMBER = 260,
    PLUS = 261,
    MINUS = 262,
    TIMES = 263,
    DIVIDE = 264,
    ASSIGN = 265,
    EQ = 266,
    NE = 267,
    LT = 268,
    LE = 269,
    GE = 270,
    GT = 271,
    POINT = 272,
    DOT = 273,
    AND = 274,
    OR = 275,
    NOT = 276,
    DIV = 277,
    MOD = 278,
    IN = 279,
    COMMA = 280,
    SEMICOLON = 281,
    COLON = 282,
    LPAREN = 283,
    RPAREN = 284,
    LBRACKET = 285,
    RBRACKET = 286,
    DOTDOT = 287,
    ARRAY = 288,
    BEGINBEGIN = 289,
    CASE = 290,
    CONST = 291,
    DO = 292,
    DOWNTO = 293,
    ELSE = 294,
    END = 295,
    FILEFILE = 296,
    FOR = 297,
    FUNCTION = 298,
    GOTO = 299,
    IF = 300,
    LABEL = 301,
    NIL = 302,
    OF = 303,
    PACKED = 304,
    PROCEDURE = 305,
    PROGRAM = 306,
    RECORD = 307,
    REPEAT = 308,
    SET = 309,
    THEN = 310,
    TO = 311,
    TYPE = 312,
    UNTIL = 313,
    VAR = 314,
    WHILE = 315,
    WITH = 316
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING 259
#define NUMBER 260
#define PLUS 261
#define MINUS 262
#define TIMES 263
#define DIVIDE 264
#define ASSIGN 265
#define EQ 266
#define NE 267
#define LT 268
#define LE 269
#define GE 270
#define GT 271
#define POINT 272
#define DOT 273
#define AND 274
#define OR 275
#define NOT 276
#define DIV 277
#define MOD 278
#define IN 279
#define COMMA 280
#define SEMICOLON 281
#define COLON 282
#define LPAREN 283
#define RPAREN 284
#define LBRACKET 285
#define RBRACKET 286
#define DOTDOT 287
#define ARRAY 288
#define BEGINBEGIN 289
#define CASE 290
#define CONST 291
#define DO 292
#define DOWNTO 293
#define ELSE 294
#define END 295
#define FILEFILE 296
#define FOR 297
#define FUNCTION 298
#define GOTO 299
#define IF 300
#define LABEL 301
#define NIL 302
#define OF 303
#define PACKED 304
#define PROCEDURE 305
#define PROGRAM 306
#define RECORD 307
#define REPEAT 308
#define SET 309
#define THEN 310
#define TO 311
#define TYPE 312
#define UNTIL 313
#define VAR 314
#define WHILE 315
#define WITH 316

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 292 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   259

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  241

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    81,    81,    86,    87,    89,    92,    93,    94,    95,
      97,   100,   103,   104,   108,   109,   113,   114,   118,   119,
     123,   124,   128,   129,   133,   134,   138,   139,   143,   146,
     150,   154,   155,   159,   161,   164,   167,   170,   173,   176,
     177,   182,   183,   187,   190,   194,   195,   199,   203,   204,
     208,   212,   213,   217,   218,   222,   226,   227,   228,   229,
     233,   237,   239,   244,   246,   249,   253,   254,   256,   259,
     263,   264,   265,   269,   270,   274,   275,   276,   277,   278,
     279,   280,   281,   285,   286,   287,   288,   292,   293,   294,
     298,   299,   300,   301,   302,   303,   307,   308,   309,   310,
     311,   312,   313,   314,   318,   319,   320,   321
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "NUMBER", "PLUS",
  "MINUS", "TIMES", "DIVIDE", "ASSIGN", "EQ", "NE", "LT", "LE", "GE", "GT",
  "POINT", "DOT", "AND", "OR", "NOT", "DIV", "MOD", "IN", "COMMA",
  "SEMICOLON", "COLON", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
  "DOTDOT", "ARRAY", "BEGINBEGIN", "CASE", "CONST", "DO", "DOWNTO", "ELSE",
  "END", "FILEFILE", "FOR", "FUNCTION", "GOTO", "IF", "LABEL", "NIL", "OF",
  "PACKED", "PROCEDURE", "PROGRAM", "RECORD", "REPEAT", "SET", "THEN",
  "TO", "TYPE", "UNTIL", "VAR", "WHILE", "WITH", "$accept", "program",
  "statement", "stmtlist", "idlist", "argslist", "lblock", "cblock",
  "tblock", "vblock", "block", "paramlist", "paramgroup", "llist", "clist",
  "tspecs", "tgroup", "varspecs", "vargroup", "endpart", "endif",
  "assignment", "var", "mergebracks", "mergelist", "fieldlist", "type",
  "simpletype", "simplelist", "expr", "simpexpr", "unaryexpr", "term",
  "factor", "factorlist", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

#define YYPACT_NINF -183

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-183)))

#define YYTABLE_NINF -99

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -42,    18,    22,     1,  -183,    27,    16,    19,    27,    23,
    -183,   105,    34,    50,    55,    54,    60,    99,    27,    78,
    -183,  -183,  -183,  -183,    47,  -183,    85,    69,   128,   128,
      34,    69,   106,   128,  -183,    34,   128,   -14,  -183,    -3,
    -183,   114,   109,    93,   129,   112,   137,   129,   127,   111,
     142,   145,     2,   148,  -183,   128,   128,  -183,    34,   143,
    -183,  -183,    69,    69,   149,   185,    11,  -183,   157,   150,
     146,   -14,   -31,  -183,   126,   158,   125,   152,    34,  -183,
    -183,  -183,   182,   128,   188,  -183,     7,   167,    54,   110,
     184,    37,  -183,    99,    37,  -183,    27,   183,   186,   187,
    -183,   128,  -183,  -183,  -183,   128,   128,   128,   128,   128,
     128,   128,    69,    69,    69,    69,    69,    69,    69,    69,
     128,  -183,  -183,   128,   128,    34,    34,   128,    34,   -14,
    -183,  -183,   189,    27,    27,    27,   190,  -183,   210,  -183,
    -183,     2,  -183,   191,   211,    27,   192,    27,  -183,  -183,
    -183,  -183,  -183,   206,   128,   194,   196,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,   195,   193,   197,   180,  -183,  -183,  -183,  -183,
      50,   199,    66,   200,   218,   202,   203,   227,  -183,   204,
      41,   208,   198,  -183,  -183,  -183,   128,    34,    34,    34,
    -183,  -183,   233,     7,  -183,   234,    72,     2,  -183,  -183,
    -183,   214,   209,    37,  -183,  -183,  -183,  -183,  -183,    74,
    -183,    84,     7,  -183,   215,    41,   201,   216,     7,  -183,
       7,  -183,  -183,  -183,  -183,    37,    27,  -183,  -183,  -183,
    -183
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    17,     0,     0,     0,
      16,     0,    13,     0,     0,     0,     0,     0,     0,     0,
      21,    23,    25,    27,    56,   102,    96,     0,     0,   107,
      13,     0,     0,     0,   103,    13,     0,     0,     4,    97,
      58,     0,     0,     0,    32,    42,     0,    32,     0,     0,
       0,     0,     0,     0,     2,     0,     0,    60,    13,    56,
      96,   100,     0,     0,     0,    82,    86,    89,    95,   104,
       0,     0,     0,    12,     0,    15,     0,     0,    13,    52,
      30,    59,     0,     0,     0,    22,     0,     0,     0,     0,
       0,     0,    24,    46,     0,    26,    49,     0,    19,     0,
       3,     0,    87,    88,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,     6,     0,     0,    13,    13,     0,    13,     0,
      57,    55,     0,     0,     0,     0,     0,    31,     0,    41,
      20,     0,    70,     0,     0,     0,     0,    65,    47,    66,
      45,    50,    48,     5,     0,    61,     0,    75,    78,    76,
      79,    80,    77,    81,    83,    84,    85,    90,    91,    94,
      92,    93,   106,     0,     0,    54,    14,     9,     8,    51,
      44,     0,     0,     0,     0,     0,     0,     0,    67,     0,
       0,     0,     0,    18,    62,    98,   107,    13,    13,    13,
       7,    43,     0,     0,    39,     0,     0,     0,    28,    72,
      71,    74,     0,     0,    69,   105,    11,    10,    53,     0,
      40,     0,     0,    33,     0,     0,     0,    63,     0,    35,
       0,    37,    34,    29,    73,     0,    65,    36,    38,    68,
      64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -183,  -183,    -7,   117,    -5,   -45,  -183,   155,   205,   207,
     -48,   212,  -142,   159,    65,   153,  -183,   154,  -183,   -69,
    -183,   220,  -183,  -183,    98,    21,   -88,  -182,    29,    -1,
      97,  -183,   -29,   -11,    56
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    75,    76,   136,    97,    19,    20,    21,    22,
      23,    87,   137,    46,    43,    49,    50,    52,    53,    80,
     200,    38,    39,    40,    57,   192,   148,   149,   212,    98,
      65,    66,    67,    68,    70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       7,    41,   122,    10,    95,    37,   151,   123,   211,     1,
       6,    99,    78,    51,    81,    82,    61,   112,   113,    41,
      41,     3,     4,    71,    41,   124,    79,    64,    69,     5,
       6,   114,    74,   102,   103,    77,    12,    24,    25,    26,
     142,     8,   143,   211,   142,    14,   143,    41,     9,    11,
     133,   100,    16,    42,   144,    27,   156,   134,    44,    45,
     179,   220,    28,    47,    29,   145,   135,    41,    30,   145,
     146,   129,    59,    25,    60,    55,    31,    56,    32,    33,
     232,    34,   131,   164,   165,   166,   237,    35,   238,   147,
      27,    51,   203,   186,    36,   204,    54,    28,   222,    29,
     228,   223,    48,   229,   167,   168,   169,   170,   171,   193,
     230,    73,    58,   231,    41,    41,    34,    41,   175,   172,
      84,   178,   173,   174,    83,   227,   177,    12,   181,   182,
     183,    59,    25,    60,    62,    63,    14,    88,    91,    12,
     189,    13,   191,    16,    12,    12,    13,   239,    14,    27,
      17,    15,    18,    14,    14,    16,    28,    86,    29,   224,
      16,    16,    17,    89,    18,   115,   116,    17,    93,    18,
      18,   101,    94,    56,    96,    34,   117,   121,   104,   118,
     119,   125,   120,   127,   126,   130,    41,    41,    41,   128,
     216,   217,   218,   132,   138,    69,   105,   106,   107,   108,
     109,   110,   157,   158,   159,   160,   161,   162,   163,   111,
     141,   154,   153,   185,   188,   180,   -98,   184,   155,   199,
     196,   206,   190,   187,    56,   195,   202,   205,   207,   208,
     197,   191,   209,   210,   198,   213,   219,   221,   214,   225,
     226,   233,   236,   176,   140,   201,   150,   139,    85,   235,
     152,    72,   215,   194,   234,     0,    92,   240,     0,    90
};

static const yytype_int16 yycheck[] =
{
       5,    12,    71,     8,    52,    12,    94,    38,   190,    51,
       3,    56,    26,    18,    17,    18,    27,     6,     7,    30,
      31,     3,     0,    30,    35,    56,    40,    28,    29,    28,
       3,    20,    33,    62,    63,    36,    34,     3,     4,     5,
       3,    25,     5,   225,     3,    43,     5,    58,    29,    26,
      43,    58,    50,     3,    17,    21,   101,    50,     3,     5,
     129,   203,    28,     3,    30,    28,    59,    78,    34,    28,
      33,    78,     3,     4,     5,    28,    42,    30,    44,    45,
     222,    47,    83,   112,   113,   114,   228,    53,   230,    52,
      21,    96,    26,   141,    60,    29,    18,    28,    26,    30,
      26,    29,     3,    29,   115,   116,   117,   118,   119,   154,
      26,     5,    27,    29,   125,   126,    47,   128,   125,   120,
      11,   128,   123,   124,    10,   213,   127,    34,   133,   134,
     135,     3,     4,     5,     6,     7,    43,    25,    11,    34,
     145,    36,   147,    50,    34,    34,    36,   235,    43,    21,
      57,    46,    59,    43,    43,    50,    28,    28,    30,   207,
      50,    50,    57,    26,    59,     8,     9,    57,    26,    59,
      59,    28,    27,    30,    26,    47,    19,    31,    29,    22,
      23,    55,    32,    58,    26,     3,   197,   198,   199,    37,
     197,   198,   199,     5,    27,   196,    11,    12,    13,    14,
      15,    16,   105,   106,   107,   108,   109,   110,   111,    24,
      26,    25,    29,     3,     3,    26,    10,    27,    31,    39,
      25,     3,    30,    32,    30,    29,    27,    27,    26,    26,
      37,   236,     5,    29,    37,    27,     3,     3,    40,    25,
      31,    26,    26,   126,    89,   180,    93,    88,    43,    48,
      96,    31,   196,   155,   225,    -1,    49,   236,    -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    63,     3,     0,    28,     3,    66,    25,    29,
      66,    26,    34,    36,    43,    46,    50,    57,    59,    68,
      69,    70,    71,    72,     3,     4,     5,    21,    28,    30,
      34,    42,    44,    45,    47,    53,    60,    64,    83,    84,
      85,    95,     3,    76,     3,     5,    75,     3,     3,    77,
      78,    66,    79,    80,    18,    28,    30,    86,    27,     3,
       5,    95,     6,     7,    91,    92,    93,    94,    95,    91,
      96,    64,    83,     5,    91,    64,    65,    91,    26,    40,
      81,    17,    18,    10,    11,    70,    28,    73,    25,    26,
      73,    11,    71,    26,    27,    72,    26,    67,    91,    67,
      64,    28,    94,    94,    29,    11,    12,    13,    14,    15,
      16,    24,     6,     7,    20,     8,     9,    19,    22,    23,
      32,    31,    81,    38,    56,    55,    26,    58,    37,    64,
       3,    91,     5,    43,    50,    59,    66,    74,    27,    75,
      69,    26,     3,     5,    17,    28,    33,    52,    88,    89,
      77,    88,    79,    29,    25,    31,    67,    92,    92,    92,
      92,    92,    92,    92,    94,    94,    94,    95,    95,    95,
      95,    95,    91,    91,    91,    64,    65,    91,    64,    81,
      26,    66,    66,    66,    27,     3,    72,    32,     3,    66,
      30,    66,    87,    67,    86,    29,    25,    37,    37,    39,
      82,    76,    27,    26,    29,    27,     3,    26,    26,     5,
      29,    89,    90,    27,    40,    96,    64,    64,    64,     3,
      74,     3,    26,    29,    72,    25,    31,    88,    26,    29,
      26,    29,    74,    26,    90,    48,    26,    74,    74,    88,
      87
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    70,    71,    71,    72,    72,
      72,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    76,    76,    77,    77,    78,    79,    79,
      80,    81,    81,    82,    82,    83,    84,    84,    84,    84,
      85,    86,    86,    87,    87,    87,    88,    88,    88,    88,
      89,    89,    89,    90,    90,    91,    91,    91,    91,    91,
      91,    91,    91,    92,    92,    92,    92,    93,    93,    93,
      94,    94,    94,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    96,    96,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     3,     1,     4,     3,     5,     4,     4,
       6,     6,     2,     0,     3,     1,     3,     1,     3,     1,
       4,     1,     3,     1,     3,     1,     3,     1,     6,     8,
       3,     2,     0,     4,     5,     5,     6,     5,     6,     3,
       4,     3,     1,     5,     4,     3,     2,     3,     3,     2,
       3,     3,     1,     2,     0,     3,     1,     3,     1,     2,
       2,     3,     4,     3,     5,     0,     1,     2,     6,     3,
       1,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     1,     2,     2,     1,
       3,     3,     3,     3,     3,     1,     1,     1,     4,     3,
       2,     3,     1,     1,     1,     5,     3,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 82 "parse.y" /* yacc.c:1646  */
    { parseresult = makeprogram((yyvsp[-6]), (yyvsp[-4]), (yyvsp[-1])); }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 86 "parse.y" /* yacc.c:1646  */
    { (yyval) = dolabel((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 87 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 90 "parse.y" /* yacc.c:1646  */
    { (yyval) = makefuncall((yyvsp[-2]), (yyvsp[-3]), (yyvsp[-1])); }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 92 "parse.y" /* yacc.c:1646  */
    { (yyval) = makepnb((yyvsp[-2]), cons((yyvsp[-1]), (yyvsp[0]))); }
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 93 "parse.y" /* yacc.c:1646  */
    { (yyval) = makeif((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-1]), (yyvsp[0])); }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 94 "parse.y" /* yacc.c:1646  */
    { (yyval) = makewhile((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 95 "parse.y" /* yacc.c:1646  */
    { (yyval) = makerepeat((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 98 "parse.y" /* yacc.c:1646  */
    { (yyval) = makefor(1, (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 101 "parse.y" /* yacc.c:1646  */
    { (yyval) = makefor(-1, (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 103 "parse.y" /* yacc.c:1646  */
    { (yyval) = dogoto((yyvsp[-1]), (yyvsp[0])); }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 104 "parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 108 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 109 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 113 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 114 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[0]), NULL); }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 118 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 119 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[0]), NULL); }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 123 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 124 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 128 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 129 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 133 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 134 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 138 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 139 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 144 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-5]); }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 148 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-7]); }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 150 "parse.y" /* yacc.c:1646  */
    { (yyval) = makepnb((yyvsp[-2]), cons((yyvsp[-1]), (yyvsp[0]))); }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 154 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 155 "parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 159 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-3]), (yyvsp[-1])); }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 162 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-4]), (yyvsp[-2])); }
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 165 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-3]), (yyvsp[-1])); }
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 168 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-4]), (yyvsp[-2])); }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 171 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-3]), (yyvsp[-1])); }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 174 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-4]), (yyvsp[-2])); }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 176 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 178 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]); }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 182 "parse.y" /* yacc.c:1646  */
    { instlabel((yyvsp[-2])); }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 183 "parse.y" /* yacc.c:1646  */
    { instlabel((yyvsp[0])); }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 188 "parse.y" /* yacc.c:1646  */
    { instconst((yyvsp[-4]), (yyvsp[-2])); }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 190 "parse.y" /* yacc.c:1646  */
    { instconst((yyvsp[-3]), (yyvsp[-1])); }
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 194 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 195 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 199 "parse.y" /* yacc.c:1646  */
    { insttype((yyvsp[-2]), (yyvsp[0])); }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 203 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 204 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 208 "parse.y" /* yacc.c:1646  */
    { instvars((yyvsp[-2]), (yyvsp[0])); }
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 212 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-1]), (yyvsp[0])); }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 213 "parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 217 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 218 "parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 222 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 226 "parse.y" /* yacc.c:1646  */
    { (yyval) = findid((yyvsp[0])); }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 227 "parse.y" /* yacc.c:1646  */
    { (yyval) = reducedot((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 228 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 229 "parse.y" /* yacc.c:1646  */
    { (yyval) = dopoint((yyvsp[-1]), (yyvsp[0])); }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 233 "parse.y" /* yacc.c:1646  */
    { (yyval) = arrayref((yyvsp[-1]), NULL, (yyvsp[0]), NULL); }
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 237 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 240 "parse.y" /* yacc.c:1646  */
    { (yyval) = nconc((yyvsp[-2]), (yyvsp[0])); }
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 244 "parse.y" /* yacc.c:1646  */
    { instfields((yyvsp[-2]), (yyvsp[0])); }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 247 "parse.y" /* yacc.c:1646  */
    { instfields((yyvsp[-4]), (yyvsp[-2])); (yyval) = nconc((yyvsp[-4]), (yyvsp[0])); }
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 249 "parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 253 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 254 "parse.y" /* yacc.c:1646  */
    { (yyval) = instpoint((yyvsp[-1]), (yyvsp[0])); }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 257 "parse.y" /* yacc.c:1646  */
    { (yyval) = instarray((yyvsp[-3]), (yyvsp[0])); }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 259 "parse.y" /* yacc.c:1646  */
    { (yyval) = instrec((yyvsp[-2]), (yyvsp[-1])); }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 263 "parse.y" /* yacc.c:1646  */
    { (yyval) = findtype((yyvsp[0])); }
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 264 "parse.y" /* yacc.c:1646  */
    { (yyval) = instenum((yyvsp[-1])); }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 265 "parse.y" /* yacc.c:1646  */
    { (yyval) = instdotdot((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 269 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[0]), (yyvsp[-2])); }
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 270 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 274 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 275 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 276 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 277 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 278 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 279 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 280 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 281 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 285 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 286 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 287 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 288 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 292 "parse.y" /* yacc.c:1646  */
    { (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 293 "parse.y" /* yacc.c:1646  */
    { (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 294 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 298 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 299 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 300 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 301 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 302 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 303 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 307 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 308 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 309 "parse.y" /* yacc.c:1646  */
    { (yyval) = makefuncall((yyvsp[-2]), (yyvsp[-3]), (yyvsp[-1])); }
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 310 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 311 "parse.y" /* yacc.c:1646  */
    { (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 312 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 313 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 314 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 318 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 319 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 320 "parse.y" /* yacc.c:1646  */
    { (yyval) = instdotdot((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 321 "parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2173 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 324 "parse.y" /* yacc.c:1906  */


/* Used in makefloat(). If true, the program will print	NUMBERTOKs being cast
   to float with their scientific notation values. Otherwise, it will print
   their values with the word "float" preceding them. Useful for debugging.

   E.g., y = 34: true - 3.400000e+01, false - (float 34) */
#define NUM_COERCE_IMPLICIT	1

#define ELIM_NESTED_PROGN 	1		/* disables makepnb() functionality and defaults to makeprogn() if 0 */

#define DEBUG_MASTER_SWITCH	0		/* 1 for true, 0 for false  */

/* See parse.h for all debug constants */

 int labelnumber = 0;  /* sequential counter for internal label numbers */
 int debug_call_num = 0;	/* sequential counter for finding a specific place during program execution */
 char *last_method = "makeprogram()"; 	/* the method that called the currently-executing method, if applicable */

/* arrayref processes an array reference a[i]
   subs is a list of subscript expressions.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN arrayref(TOKEN arr, TOKEN tok, TOKEN subs, TOKEN tokb) {
	if (DEBUG & DB_ARRAYREF) {
		printf("(%d)\n", debug_call_num++);
		printf("In arrayref(), from %s\n", last_method);
		dbugprint4args(arr, tok, subs, tokb);
		last_method = "arrayref()";
	}

	TOKEN array_ref = NULL;
	SYMBOL arr_varsym, typesym, temp;
	SYMBOL arrsyms[10];

	arr_varsym = searchst(arr->stringval);

	if (!arr_varsym) {
		printf(" Error: array \"%s\" not found in symbol table, arrayref().\n", arr->stringval);
		return NULL;
	}

	temp = arr_varsym->datatype;

	int counter = 0;
	int num_arr_dims = 0;	// not being used for anything

	/* Store the ARRAYSYMs into an array */
	while (temp && temp->kind != TYPESYM) {
		arrsyms[counter] = temp;
		num_arr_dims++;
		counter++;
		temp = temp->datatype;
	}

	/* The type of the array */
	typesym = temp;

	if (subs->link == NULL && subs->tokentype == NUMBERTOK) {
		int total_size = (subs->whichval - 1) * typesym->size;
		array_ref = makearef(arr, makeintc(total_size), NULL);
		array_ref->datatype = arr_varsym->basicdt;
		return array_ref;
	}
	// else if tokentype is IDENTIFIER?

	counter = 0;
	TOKEN curr_sub = subs;

	while (curr_sub) {

		if (counter == 0) {		// first iteration; need to make aref
			SYMBOL curr_sym = arrsyms[counter];
			int curr_size = curr_sym->size / (curr_sym->highbound - curr_sym->lowbound + 1);

			// TOKEN mul_op = maketimes(makeintc(curr_size), curr_sub, NULL);

			TOKEN mul_op = makeop(TIMESOP);
			TOKEN pos_typesym_size = makeintc(curr_size);
			TOKEN neg_typesym_size = makeintc(curr_size * -1);

			mul_op->operands = pos_typesym_size;
			pos_typesym_size->link = curr_sub;

			neg_typesym_size->link = mul_op;

			TOKEN plus_op = makeplus(neg_typesym_size, mul_op, NULL);

			array_ref = makearef(arr, plus_op, NULL);
			array_ref->datatype = arr_varsym->basicdt;

		}
		else {

			if (curr_sub->tokentype == NUMBERTOK) {		// smash constants (optimization)
				TOKEN add_to = array_ref->operands->link->operands;
				add_to = addint(add_to, makeintc(curr_sub->whichval * typesym->size), NULL);
			}
			else {
				/* Smash constants and add to tree */

				SYMBOL curr_sym = arrsyms[counter];
				int curr_size = curr_sym->size / (curr_sym->highbound - curr_sym->lowbound + 1);

				TOKEN mul_op = makeop(TIMESOP);
				TOKEN pos_typesym_size = makeintc(curr_size);
				TOKEN neg_typesym_size = makeintc(curr_size * -1);

				mul_op->operands = pos_typesym_size;
				pos_typesym_size->link = curr_sub;

				TOKEN added = array_ref->operands->link->operands;
				added = addint(added, neg_typesym_size, NULL);

				TOKEN add_to = array_ref->operands->link->operands->link;
				TOKEN plus_op = makeplus(add_to, mul_op, NULL);
				add_to = plus_op;

			}
		}

		/* Destroy the current link */
		TOKEN unlink = curr_sub;
		curr_sub = curr_sub->link;
		unlink->link = NULL;
		counter++;
	}

	if (DEBUG & DB_ARRAYREF) {
		printf(" Finished arrayref().\n");
		dbugprint1tok(array_ref);
		last_method = "arrayref()";
	}	
	
	return array_ref;
}

/* instarray installs an array declaration into the symbol table.
   bounds points to a SUBRANGE symbol table entry.
   The symbol table pointer is returned in token typetok. */
TOKEN instarray(TOKEN bounds, TOKEN typetok) {
	if (DEBUG & DB_INSTARRAY) {
		printf("(%d)\n", debug_call_num++);
		printf("In instarray(), from %s\n", last_method);
		dbugprint2args(bounds, typetok);
//		dbprsymbol(typetok->symtype);
		last_method = "instarray()";
	}

	// bounds->symtype->[low/highbound]

	TOKEN curr_bound = bounds;
	SYMBOL prev_sym = NULL;

	SYMBOL typesym = searchst(typetok->stringval);
	int low, high;

	// if (!typesym) {
	// 	printf(" Error: array \"%s\" not found in symbol table, instarray().\n", typetok->stringval);
	// 	return NULL;
	// }

	while (curr_bound) {
		SYMBOL arrsym = symalloc();
		arrsym->kind = ARRAYSYM;

		if (typesym) {
			arrsym->datatype = typesym;
		}
		else {
//			arrsym->basicdt = typetok->datatype;
		}

		low = curr_bound->symtype->lowbound;
		high = curr_bound->symtype->highbound;

		if (!prev_sym) {
			arrsym->size = (high - low + 1) * typesym->size;
		}
		else {
			arrsym->datatype = typetok->symtype;
			arrsym->size = (high - low + 1) * prev_sym->size;
		}

		typetok->symtype = arrsym;
		prev_sym = arrsym;

		arrsym->lowbound = low;
		arrsym->highbound = high;

		curr_bound = curr_bound->link;
	}

	if (DEBUG & DB_INSTARRAY) {
		printf(" Finished instarray().\n");
		dbugprint1tok(typetok);
	}
	
	return typetok;
}

/* instfields will install type in a list idlist of field name tokens:
   re, im: real    put the pointer to REAL in the RE, IM tokens.
   typetok is a token whose symtype is a symbol table pointer.
   Note that nconc() can be used to combine these lists after instrec() */
TOKEN instfields(TOKEN idlist, TOKEN typetok) {
	if (DEBUG & DB_INSTFIELDS) {
		printf("(%d)\n", debug_call_num++);
		printf("In instfields(), from %s\n", last_method);
		printf(" typetok: ");
		ppexpr(typetok);
		dbugprinttok(typetok);
		printf("\n Installing...\n");
		last_method = "instfields()";
	}

	int next = 0;
	int offset = 0;

	SYMBOL recsym, typesym;
	typesym = searchst(typetok->stringval);

	TOKEN temp = idlist;

	/* Set the symtype of each record field (each TOKEN in idlist).
	   These will be linked together in instrec(). */
	while (temp) {
		recsym = makesym(temp->stringval);
		recsym->datatype = typesym;

		// offset = next; next = next + n;
		offset = next;
		next = next + typesym->size;

		recsym->offset = offset;
		recsym->size = typesym->size;
		recsym->datatype = typesym;

		if (typesym->kind == BASICTYPE) {
			recsym->basicdt = typesym->basicdt;
		}

		temp->symtype = recsym;

		if (DEBUG & DB_INSTFIELDS) {
			dbprsymbol(typesym);
			dbugprintsym(recsym);
		}

		temp = temp->link;
	}

	if (DEBUG & DB_INSTFIELDS) {
//		printf(" Finished instfields().\n");
		printf("\n");
	}

	return idlist;
}

/* instpoint will install a pointer type in symbol table */
TOKEN instpoint(TOKEN tok, TOKEN typename) {
	if (DEBUG & DB_INSTPOINT) {
		printf("(%d)\n", debug_call_num++);
		printf("In instpoint(), from %s\n", last_method);
		dbugprint2args(tok, typename);
		last_method = "instpoint()";
	}

	SYMBOL ptrsym, sym;

	ptrsym = symalloc();
	ptrsym->kind = POINTERSYM;
	ptrsym->basicdt = POINTER;
	ptrsym->size = basicsizes[POINTER];
	tok->symtype = ptrsym;

	sym = searchins(typename->stringval);
	sym->kind = TYPESYM;
	ptrsym->datatype = sym;

	if (DEBUG & DB_INSTPOINT) {
		printf(" Finished instpoint().\n");
		dbugprint1tok(tok);
		printf(" ");
		dbprsymbol(tok->symtype);
		printf(" ");
		dbprsymbol(tok->symtype->datatype);
		printf("\n");
	}

	tok->datatype = POINTER;

	return tok;
}

/* instrec will install a record definition.  Each token in the linked list
   argstok has a pointer its type.  rectok is just a trash token to be
   used to return the result in its symtype */
TOKEN instrec(TOKEN rectok, TOKEN argstok) {
	if (DEBUG & DB_INSTREC) {
		printf("In instrec(), from %s\n", last_method);
		dbugprint2args(rectok, argstok);
		last_method = "instrec()";
	}

	int total_size, offset;

	SYMBOL recsym = symalloc();
	recsym->kind = RECORDSYM;
	rectok->symtype = recsym;
	recsym->datatype = argstok->symtype;
	offset = wordaddress(argstok->symtype->size, 8);	// TODO: test this w/ something size 8
	total_size = offset;

	if (DEBUG & DB_INSTREC) {
		printf(" Installing...\n");
		dbugprint1sym(recsym->datatype);
	}

	TOKEN curr = argstok;
	TOKEN next = argstok->link;
	while (next) {
		/* Link the symtypes of each TOKEN (the record fields) together
		   and calculate the total size of the record */

		curr->symtype->link = next->symtype;
		offset = wordaddress(next->symtype->size, 8);		
		next->symtype->offset = total_size;
		total_size += offset;

		if (DEBUG & DB_INSTREC) {
			printf("  ");
			dbprsymbol(next->symtype);
		}

		curr = next;
		next = next->link;
	}

	recsym->size = total_size;

	if (DEBUG & DB_INSTREC) {
		printf(" Finished instrec().\n");
		dbugprint1tok(rectok);
	}

	return rectok;
}

/* insttype will install a type name in symbol table.
   typetok is a token containing symbol table pointers. */
void insttype(TOKEN typename, TOKEN typetok) {
	if (DEBUG & DB_INSTTYPE) {
		printf("(%d)\n", debug_call_num++);
		printf("In insttype(), from %s\n", last_method);
		dbugprint2args(typename, typetok);
		printf(" Installing...\n");
		last_method = "insttype()";
	}

	SYMBOL sym, typesym;

	typesym = typetok->symtype;

	sym = searchins(typename->stringval);	// insert if not found
	sym->kind = TYPESYM;
	sym->size = typesym->size;
	sym->datatype = typesym;
	sym->basicdt = typesym->basicdt;

	if (DEBUG & DB_INSTTYPE) {
		printf(" ");
		dbugprinttok(typename);
		printf(" ");
		dbprsymbol(sym);
		printf(" ");
		dbprsymbol(typesym);
		printf("\n");
	}

}

/* makesubrange makes a SUBRANGE symbol table entry, puts the pointer to it
   into tok, and returns tok. */
TOKEN makesubrange(TOKEN tok, int low, int high) {
	if (DEBUG & DB_MAKESUBRANGE) {
		printf("(%d)\n", debug_call_num++);
		printf("In makesubrange(), from %s\n", last_method);
		dbugprint1arg(tok);
		printf("  low bound: %d\n  high bound: %d\n\n", low, high);		
		last_method = "makesubrange()";
	}
	if (low > high) {
		printf(" Error: low bound cannot be greater than high bound\n\n");
		return NULL;
	}

	TOKEN out = copytok(tok);

	SYMBOL subrange_entry = symalloc();
	subrange_entry->kind = SUBRANGE;
	subrange_entry->basicdt = INTEGER;
	subrange_entry->lowbound = low;
	subrange_entry->highbound = high;
	subrange_entry->size = basicsizes[INTEGER];	// each entry is a constant (int)

	out->symtype = subrange_entry;

	if (DEBUG & DB_ADDOFFS) {
		printf(" Finished makesubrange().\n");
		dbugprint1tok(out);
		last_method = "makesubrange()";
	}	
	
	return out;
}

/* nconc concatenates two token lists, destructively, by making the last link
   of lista point to listb.
   (nconc '(a b) '(c d e))  =  (a b c d e)  */
/* nconc is useful for putting together two fieldlist groups to
   make them into a single list in a record declaration. */
TOKEN nconc(TOKEN lista, TOKEN listb) {
	if (DEBUG & DB_NCONC) {
		printf("(%d)\n", debug_call_num++);
		printf("In nconc(), from %s\n", last_method);
		dbugprint2args(lista, listb);		
		last_method = "nconc()";
	}

	// TODO: check if lista contains members of listb or vice versa?

	get_last_link(lista)->link = listb;

	if (DEBUG & DB_NCONC) {
		printf(" Finished nconc().\n");
		dbugprintlinks(lista);
		last_method = "nconc()";
	}	
	
	return lista;
}

TOKEN get_rec(TOKEN rec, TOKEN offset) {
	TOKEN out = NULL;

	SYMBOL recsym = rec->symtype;
	while (recsym && !out) {
		
		if (recsym->offset == offset->whichval) {
			out = talloc();
			out->symtype = recsym;
		}
		else {
			recsym = recsym->link;
		}
	}

	return out;
}

/* Search the given record for the specified field.
   Returns a pointer to the record field SYMBOL if
   found (stored in TOKEN->symtype), NULL otherwise. */
TOKEN get_rec_field(TOKEN rec, TOKEN field) {

	TOKEN out = NULL;

	SYMBOL recsym = rec->symtype;
	while (recsym && !out) {
		if (strcmp(recsym->namestring, field->stringval) == 0) {
			out = talloc();
			out->symtype = recsym;
		}
		else {
			recsym = recsym->link;
		}
	}

	return out;
}

/* Helper method for reducedot(). Searches for the offset
   of the given field in var. Returns a NUMBERTOK whose
   whichval field is the offset if found, otherwise returns
   with a whichval of -1. */
TOKEN get_offset(TOKEN var, TOKEN field) {

	TOKEN offset = makeintc(-1);

	TOKEN root_name = get_last_operand(var);
	TOKEN last_offset = get_last_link(var->operands);

	SYMBOL found = NULL;
	SYMBOL varsym = searchst(root_name->stringval);

	boolean var_is_arefop = false;
	if (var->whichval == AREFOP) {
		var_is_arefop = true;
	}
	
	if (!varsym) {
		printf(" Error: could not find symbol \"%s\" in symbol table, get_offset():1.\n", root_name->stringval);
		return NULL;
	}

	SYMBOL temp = varsym;
	while (temp) {
		if (temp->datatype && temp->datatype->kind == BASICTYPE) {
			break;
		}
		temp = temp->datatype;
	}

	if (!temp) {
		printf(" Error: symbol table entry \"%s\" is corrupt, get_offset():2.\n", root_name->stringval);
		return NULL;
	}

	while (temp) {

		if ((strcmp(temp->namestring, field->stringval) == 0)) {
			found = temp;
			if (var_is_arefop) {

				/* TOKEN var is an aref TOKEN; ignore */
				if (last_offset->tokentype == OPERATOR) {
					offset->whichval = -1;
				}
				else {
					offset->whichval = last_offset->whichval + found->offset;	
				}

				/* Set offset's link field to a REAL NUMBERTOK.
				   Is necessary to ensure correct behaviour of
				   binop() during type checking/coercion.

				   The link MUST be nulled out after use, otherwise
				   the console output will be incorrect. */
				if (found->datatype->basicdt == REAL) {
					offset->link = makerealtok(0);
					offset->link->realval = -DBL_MAX;
				}
			}
			else {

				offset->whichval = found->offset;
				if (found->datatype->basicdt == REAL) {
					offset->link = makerealtok(0);
					offset->link->realval = -DBL_MAX;
				}
			}

			return offset;
		}
		else if (var_is_arefop && (temp->offset == last_offset->whichval)) {
			found = temp;
			break;
		}

		temp = temp->link;
	}

	/* NOT an error condition if !found here. */

	if (!var_is_arefop && found) {
		offset->whichval = found->offset;
		if (found->datatype->basicdt == REAL) {
			offset->link = makerealtok(0);
			offset->link->realval = -DBL_MAX;
		}
		return offset;
	}
	else if (var_is_arefop && found) {
		/* TOKEN field represents a record field; search for
		   the record in the symbol table and then search for
		   the field within that record. */

		SYMBOL temp1 = searchst(found->datatype->namestring);
		found = NULL;
		if (!temp1) {
			printf(" Error: symbol table entry \"%s\" is corrupt, get_offset():3.\n", root_name->stringval);
			return NULL;
		}

		while (temp1) {
			if (temp1->datatype && temp1->datatype->kind == BASICTYPE) {
				break;
			}
			temp1 = temp1->datatype;
		}

		if (!temp1) {
			printf(" Error: symbol table entry \"%s\" is corrupt, get_offset():4.\n", root_name->stringval);
			return NULL;
		}

		while (temp1 && !found) {
			if (strcmp(temp1->namestring, field->stringval) == 0) {
				found = temp1;
			}
			else {
				temp1 = temp1->link;
			}
		}

		/* NOT an error condition if !found here. */
		if (found) {
			offset->whichval = last_offset->whichval + found->offset;
			if (found->datatype->basicdt == REAL) {
				offset->link = makerealtok(0);
				offset->link->realval = -DBL_MAX;
			}

			return offset;
		}
	}

	return offset;
}

/* reducedot handles a record reference.
   dot is a (now) unused token that is recycled. */
TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field) {
	if (DEBUG & DB_REDUCEDOT) {
		printf("(%d)\n", debug_call_num++);
		printf("In reducedot(), from %s\n", last_method);
		dbugprint3args(var, dot, field);
		last_method = "reducedot()";
	}

	TOKEN aref;
	TOKEN offset = get_offset(var, field);

	if (var->whichval == AREFOP) {
		/* Avoid adding multiple copies to the tree. */

		if (offset->whichval >= 0) {
			var->operands->link = offset;
		}
		aref = var;
	}
	else {
		aref = makearef(var, offset, NULL);
	}

	/* Change aref's datatype to REAL to avoid incorrect
	   fixes/floats in binop(). NULL out the dummy link. */
	if (offset->link && offset->link->datatype == REAL &&
		offset->link->realval == -DBL_MAX) {

		aref->datatype = REAL;
		offset->link = NULL;
	}
	
	if (DEBUG & DB_REDUCEDOT) {
		printf(" Finished reducedot().\n");
		dbugprint1tok(aref);
		last_method = "reducedot()";
		// ppexpr(aref);
		// printf("\n");
	}

	return aref;
}

/* ############################################################################################################################################################### */

/* addint adds integer off to expression exp, possibly using tok */
TOKEN addint(TOKEN exp, TOKEN off, TOKEN tok) {
	if (!exp || !off) {
		return NULL;
	}

	int a = exp->intval;
	int b = off->intval;
	
	if (DEBUG & DB_ADDINT) {
		printf("(%d)\n", debug_call_num++);
		printf("In addint(), from %s\n Adding %d to %d\n", last_method, b, a);
		dbugprint3args(exp, off, tok);
		last_method = "addint()";
	}

	if ((b > 0) && (a > INT_MAX - b)) { // if ((INT_MAX / exp->intval) > off->intval)
		printf(" Error: integer overflow detected, addint()\n");
		printf(" Cannot add %d to %d\n", b, a);
	}
	else {
		exp->intval = a + b;
	}

	if (DEBUG & DB_ADDINT) {
		printf(" New value of exp: %d\n", exp->intval);
		dbugprint1tok(exp);
	}
	
	return exp;
}

/* addoffs adds offset, off, to an aref expression, exp */
TOKEN addoffs(TOKEN exp, TOKEN off) {
	if (DEBUG & DB_ADDOFFS) {
		printf("(%d)\n", debug_call_num++);
		printf("In addoffs(), from %s\n", last_method);
		dbugprint2args(exp, off);
		last_method = "addoffs()";
	}

	exp = addint(exp, off, NULL);

	if (DEBUG & DB_ADDOFFS) {
		printf(" Finished addoffs().\n");
		dbugprint1tok(exp);
		last_method = "addoffs()";
	}	
	
	return exp;
}

/* binop links a binary operator op to two operands, lhs and rhs.

   TODO
   - boolean types?
   - funcall return types?
*/
TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs) {

	if (DEBUG & DB_BINOP) {
		printf("(%d)\n", debug_call_num++);
		printf("In binop(), from %s\n", last_method);
		dbugprint3args(op, lhs, rhs);
		last_method = "binop()";
	}

	/* If rhs represents nil, convert rhs to
	   an INTEGER NUMBERTOK with ->whichval = 0. */
	if (rhs->whichval == (NIL - RESERVED_BIAS)) {
		rhs->tokentype = NUMBERTOK;
		rhs->datatype = INTEGER;
		rhs->whichval = 0;
		// rhs->stringval[0] = 'N';
		// rhs->stringval[1] = 'I';
		// rhs->stringval[2] = 'L';
		// rhs->stringval[3] = '\0';
	}

	int lhs_datatype = lhs->datatype;
	int rhs_datatype = rhs->datatype;
	int op_type = op->whichval;

	/* Type checking/coercion needed. */
	if (lhs_datatype != rhs_datatype) {
		op = binop_type_coerce(op, lhs, rhs);
	}
	else {
		op->datatype = lhs->datatype;
		op->operands = lhs;		// link operands to operator
		lhs->link = rhs;		// link second operand to first
		rhs->link = NULL;		// terminate operand list
	}
	
	if (DEBUG & DB_BINOP) {
		printf(" Finished binop().\n");
		dbugprint1tok(op);
		last_method = "binop()";
//		ppexpr(op);
	}

	return op;
}

/* This method fixes or floats a NUMBERTOK as necessary. */
TOKEN binop_type_coerce(TOKEN op, TOKEN lhs, TOKEN rhs) {

	TOKEN cast_tok;

	int lhs_datatype = lhs->datatype;
	int rhs_datatype = rhs->datatype;
	int op_type = op->whichval;

	if (lhs_datatype == INTEGER && rhs_datatype == REAL) {
		/* LHS is integer, RHS is real.
		   Fix if ASSIGNOP, else float the integer. */

		op->datatype = REAL;

		if (op_type == ASSIGNOP) {
			cast_tok = makefix(rhs);
			op->operands = lhs;
			lhs->link = cast_tok;
		}
		else {
			cast_tok = makefloat(lhs);
			op->operands = cast_tok;
			cast_tok->link = rhs;
		}

	}
	else if (lhs_datatype == REAL && rhs_datatype == INTEGER) {
		/* LHS is real, RHS is integer.
		   Float the integer value.
		   DO NOT fix; lhs still takes precedence. */

		cast_tok = makefloat(rhs);

		op->datatype = REAL;
		op->operands = lhs;
		lhs->link = cast_tok;
		cast_tok->link = NULL;
		rhs->link = NULL;

	}
	else {
		op->datatype = lhs->datatype;
		op->operands = lhs;		// link operands to operator
		lhs->link = rhs;		// link second operand to first
		rhs->link = NULL;		// terminate operand list
	}

	return op;
}

/* cons links a new item onto the front of a list.  Equivalent to a push.
   (cons 'a '(b c))  =  (a b c) */
TOKEN cons(TOKEN item, TOKEN list) {

	if (DEBUG & DB_CONS) {
		printf("(%d)\n", debug_call_num++);
		printf("In cons(), from %s\n", last_method);
		dbugprint2args(item, list);		
		last_method = "cons()";
	}

	item->link = list;

	if (DEBUG & DB_CONS) {
		printf(" Finished cons().\n");
		dbugprint1tok(item);
	}

	return item;
}

/* copytok makes a new token that is a copy of origtok */
TOKEN copytok(TOKEN origtok) {

	if (DEBUG & DB_COPYTOK) {
		printf("(%d)\n", debug_call_num++);
		printf("In copytok(), from %s\n", last_method);
		dbugprint1arg(origtok);
		last_method = "copytok()";
	}

	if (!origtok) {
		return NULL;
	}
	TOKEN out = talloc();
	if (!out) {
		printf(" Failed to alloc TOKEN, copytok().\n");
		return NULL;
	}

	out->tokentype = origtok->tokentype;
	out->datatype = origtok->datatype;

	/* Shallow copies only (as expected). */
	out->symtype = origtok->symtype;
	out->symentry = origtok->symentry;
	out->operands = origtok->operands;
	out->link = origtok->link;
	
	if (origtok->stringval[0] != '\0') {
		strncpy(out->stringval, origtok->stringval, 16);
	}
	else if (origtok->whichval != -1) {
		out->whichval = origtok->whichval;
	}
	else if (origtok->realval != -DBL_MIN) {
		out->realval = origtok->realval;
	}
	else {
		out->intval = origtok->intval;
	}

	if (DEBUG & DB_COPYTOK) {
		printf(" Finished copytok().\n");
		printf("  Original:\n    ");
		dbugprinttok(origtok);
		printf("  Copy:\n    ");
		dbugprinttok(out);
		printf("\n");
	}

	return out;
}

/* dogoto is the action for a goto statement.
   tok is a (now) unused token that is recycled. */
TOKEN dogoto(TOKEN tok, TOKEN labeltok) {

	// THIS METHOD SHOULD ONLY BE CALLED FOR A USER LABEL

	if (DEBUG & DB_DOGOTO) {
		printf("(%d)\n", debug_call_num++);
		printf("In dogoto(), from %s\n", last_method);
		dbugprint2args(tok, labeltok);		
		last_method = "dogoto()";
	}

	if (labeltok->intval < 0) {
		printf(" Warning: label number is negative, dogoto().\n");
	}

	int internal_label_num = get_internal_label_num(labeltok->intval);
	if (internal_label_num == -1) {
		printf(" Error: could not find internal label number corresponding to user label number %d\n", labeltok->intval);
		return NULL;
	}
	
	if (DEBUG & DB_DOGOTO) {
		printf(" Finished dogoto().\n");
		printf("  Found internal label number %d corresponding to user label number %d\n", internal_label_num, labeltok->intval);
		printf("  Transferring to makegoto()...\n\n");
	}

	return (makegoto(internal_label_num));
}

/* dolabel is the action for a label of the form   <number>: <statement>
   tok is a (now) unused token that is recycled. */
TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement) {

	if (DEBUG & DB_DOLABEL) {
		printf("(%d)\n", debug_call_num++);
		printf("In dolabel(), from %s\n", last_method);
		dbugprint3args(labeltok, tok, statement);		
		last_method = "dolabel()";
	}
	
	int internal_label_num = get_internal_label_num(labeltok->intval);
	if (internal_label_num == -1) {
		printf(" Error: label %d not found in label table\n", labeltok->intval);
		return NULL;
	}

	TOKEN do_progn_tok = makeop(PROGNOP);
	TOKEN label_tok = makeop(LABELOP);
//	TOKEN do_progn_tok = makeprogn(makeop(PROGNOP), makeop(LABELOP));	// second arg will never be progn, so skip makepnb()
	TOKEN label_num_tok = makeintc(internal_label_num);

	if (!do_progn_tok || !label_tok || !label_num_tok) {
		printf(" Failed to alloc label TOKEN(s), dolabel().\n");
		return NULL;
	}

	do_progn_tok->operands = label_tok;
	label_tok->operands = label_num_tok;
	label_tok->link = statement;

	if (DEBUG & DB_DOLABEL) {
		printf(" Finished dolabel().\n");
		dbugprint1tok(do_progn_tok);
		last_method = "dolabel()";
	}

	return do_progn_tok;
}

/* dopoint handles a ^ operator.
   tok is a (now) unused token that is recycled. */
TOKEN dopoint(TOKEN var, TOKEN tok) {
	if (DEBUG & DB_DOPOINT) {
		printf("(%d)\n", debug_call_num++);
		printf("In dopoint(), from %s\n", last_method);
		dbugprint2args(var, tok);		
		last_method = "dopoint()";
	}

	tok->operands = var;

	if (DEBUG & DB_DOPOINT) {
		printf(" Finished dopoint().\n");
		dbugprint1tok(tok);
	}

	return tok;
}

/* findid finds an identifier in the symbol table, sets up symbol table\n
   pointers, changes a constant to its number equivalent

   Adapted from Prof. Novak's class notes with permission. */
TOKEN findid(TOKEN tok) {

	if (DEBUG & DB_FINDID) {
		printf("(%d)\n", debug_call_num++);
		printf("In findid(), from %s\n", last_method);
		dbugprint1arg(tok);
		last_method = "findid()";
	}

	SYMBOL sym, typ;
	sym = searchst(tok->stringval);

	if (sym->kind == CONSTSYM) {
	
		tok->tokentype = NUMBERTOK;

		if (sym->basicdt == 0) {
			tok->datatype = INTEGER;
			tok->intval = sym->constval.intnum;
		}
		else if (sym->basicdt == 1) {
			tok->datatype = REAL;
			tok->realval = sym->constval.realnum;
		}

	}
	else {
	
		tok->symentry = sym;
		typ = sym->datatype;
		tok->symtype = typ;

		if (typ->kind == BASICTYPE || typ->kind == POINTERSYM) {
			tok->datatype = typ->basicdt;
		}

	}
	
	if (DEBUG & DB_FINDID) {
		printf(" Finished findid().\n");
		dbugprint1tok(tok);
	}	

	return tok;
}

/* findtype looks up a type name in the symbol table, puts the pointer
   to its type into tok->symtype, returns tok. */
TOKEN findtype(TOKEN tok) {

	if (DEBUG & DB_FINDTYPE) {
		printf("(%d)\n", debug_call_num++);
		printf("In findtype(), from %s\n", last_method);
		dbugprint1arg(tok);
		last_method = "findtype()";
	}
	
	SYMBOL sym, typ;
//	sym = searchins(tok->stringval);	// triggers segfault
	sym = searchst(tok->stringval);

	if (!sym) {
		printf(" Error: type \"%s\" not found in symbol table, findtype().\n", tok->stringval);
		return NULL;
	}

	typ = sym->datatype;
	int kind = sym->kind;

	/* Arg represents symbol of basic datatype (INTEGER, REAL, STRINGTYPE, BOOLETYPE, POINTER) */
	if (kind == BASICTYPE) {
		tok->datatype = sym->basicdt;
		tok->symtype = sym;
	}
	else {
		tok->symtype = typ;
	}

	if (DEBUG & DB_FINDTYPE) {
		printf(" Finished findtype().\n");
		dbugprint1tok(tok);
	}

	return tok;
}

/* Gets and returns the last TOKEN (in)directly
   connected via ->link to TOKEN tok. Mostly used 
   to handle elimination of nested progns. */
TOKEN get_last_link(TOKEN tok) {
	if (!tok) {
		return NULL;
	}

	TOKEN curr = tok;
	TOKEN curr_link = curr->link;
	while (curr_link) {
		curr = curr_link;
		curr_link = curr_link->link;
	}

	return curr;
}

/* Gets and returns the last TOKEN (in)directly
   connected via ->operands to TOKEN tok. */
TOKEN get_last_operand(TOKEN tok) {
	if (!tok) {
		return NULL;
	}

	TOKEN curr = tok;
	TOKEN curr_operand = curr->operands;
	while (curr_operand) {
		curr = curr_operand;
		curr_operand = curr_operand->operands;
	}

	return curr;	
}

/* instconst installs a constant in the symbol table */
void instconst(TOKEN idtok, TOKEN consttok) {

	if (DEBUG & DB_INSTCONST) {
		printf("(%d)\n", debug_call_num++);
		printf("In instconstant(), from %s\n", last_method);
		dbugprint2args(idtok, consttok);		
		last_method = "instconst()";
	}

	SYMBOL sym;

	sym = insertsym(idtok->stringval);
	sym->kind = CONSTSYM;
	sym->basicdt = consttok->datatype;

	if (sym->basicdt == INTEGER) {		// INTEGER
		sym->constval.intnum = consttok->intval;
		sym->size = basicsizes[INTEGER];	// 4
	}
	else if (sym->basicdt == REAL) {	// REAL
		sym->constval.realnum = consttok->realval;
		sym->size = basicsizes[REAL];	// 8
	}
	else if (sym->basicdt == STRINGTYPE) {
		strncpy(sym->constval.stringconst, consttok->stringval, 16);
		sym->size = basicsizes[STRINGTYPE];
	}

	if (DEBUG & DB_INSTCONST) {
		printf(" Finished instconstant().\n");
		dbugprint2toks(idtok, consttok);
	}

}

/* instdotdot installs a .. subrange in the symbol table.
   dottok is a (now) unused token that is recycled. */
TOKEN instdotdot(TOKEN lowtok, TOKEN dottok, TOKEN hightok) {
	if (DEBUG & DB_INSTDOTDOT) {
		printf("(%d)\n", debug_call_num++);
		printf("In instdotdot(), from %s\n", last_method);
		dbugprint3args(lowtok, dottok, hightok);	
		last_method = "instdotdot()";	
	}

	TOKEN out = makesubrange(dottok, lowtok->intval, hightok->intval);

	if (DEBUG & DB_INSTDOTDOT) {
		printf(" Finished instdotdot().\n");
		dbugprint1tok(out);
		last_method = "instdotdot()";	
	}

	return out;
}

/* instenum installs an enumerated subrange in the symbol table,
   e.g., type color = (red, white, blue)
   by calling makesubrange and returning the token it returns. */
TOKEN instenum(TOKEN idlist) {
	if (DEBUG & DB_INSTENUM) {
		printf("(%d)\n", debug_call_num++);
		printf("In instenum(), from %s\n", last_method);
		dbugprint1arg(idlist);
		last_method = "instenum()";
	}

	int total_size = 0;
	TOKEN temp = idlist;
	while (temp) {
		instconst(temp, makeintc(total_size));
		total_size++;
		temp = temp->link;
	}

	TOKEN subrange_tok = makesubrange(idlist, 0, (total_size - 1));

	if (DEBUG & DB_INSTENUM) {
		printf(" Finished instenum().\n");
		dbugprint1tok(subrange_tok);
		last_method = "instenum()";
	}

	return subrange_tok;
}

/* instlabel installs a user label into the label table */
void instlabel (TOKEN num) {

	// DO NOT CALL THIS METHOD FOR COMPILER-GENERATED LABELS

	if (DEBUG & DB_INSTLABEL) {
		printf("(%d)\n", debug_call_num++);
		printf("In dolabel(), from %s\n", last_method);
		dbugprint1arg(num);
		last_method = "instlabel()";
	}
	
//	insert_label(labelnumber++, num->intval);
	insert_label(labelnumber++, num);

	if (DEBUG & DB_INSTLABEL) {
		printf(" Finished dolabel().\n");
	}
}

/* instvars will install variables in symbol table.
   typetok is a token containing symbol table pointer for type.

   Note that initsyms() is already called in main().

   Adapted from Prof. Novak's class notes with permission. */
void instvars(TOKEN idlist, TOKEN typetok) {

	if (DEBUG & DB_INSTVARS) {
		printf("(%d)\n", debug_call_num++);
		printf("In instvars(), from %s\n", last_method);
		printf(" typetok: ");
		ppexpr(typetok);
		dbugprint1tok(typetok);
		printf(" Installing...\n");
		last_method = "instvars()";
	}

	SYMBOL sym, typesym;
	int align;

	typesym = typetok->symtype;
	align = alignsize(typesym);

	while (idlist != NULL) {
		sym = insertsym(idlist->stringval);
		sym->kind = VARSYM;
		sym->offset = wordaddress(blockoffs[blocknumber], align);
		sym->size = typesym->size;
		blockoffs[blocknumber] = sym->offset + sym->size;
		sym->datatype = typesym;
		sym->basicdt = typesym->basicdt;

		if (typesym->datatype != NULL && typesym->datatype->kind == ARRAYSYM) {
			SYMBOL arr_type = typesym->datatype;
			while (arr_type && arr_type->kind == ARRAYSYM) {
				arr_type = arr_type->datatype;
			}
			if (arr_type->kind == BASICTYPE) {
				sym->basicdt = arr_type->basicdt;
			}
		}

		if (DEBUG & DB_INSTVARS) {
			printf(" ");
			dbugprinttok(idlist);
		}
		
		idlist = idlist->link;
	}

	if (DEBUG & DB_INSTVARS) {
		printf("\n");
	}
}

/* makearef makes an array reference operation.
   off is be an integer constant token
   tok (if not NULL) is a (now) unused token that is recycled. */
TOKEN makearef(TOKEN var, TOKEN off, TOKEN tok) {
	if (DEBUG & DB_MAKEAREF) {
		printf("(%d)\n", debug_call_num++);
		printf("In makearef(), from %s\n", last_method);
		dbugprint3args(var, off, tok);
		last_method = "makearef()";
	}

	TOKEN aref = makeop(AREFOP);
	aref->operands = var;
	var->link = off;

	if (DEBUG & DB_MAKEAREF) {
		printf(" Finished makearef().\n");
		dbugprint1tok(aref);
		last_method = "makearef()";
	}	
	
	return aref;
}

/* makefix forces the item tok to be integer, by truncating a constant
   or by inserting a FIXOP operator */
TOKEN makefix(TOKEN tok) {

	if (DEBUG & DB_MAKEFIX) {
		printf("(%d)\n", debug_call_num++);
		printf("In makefix(), from %s\n", last_method);
		last_method = "makefix()";
		dbugprint1arg(tok);
		last_method = "makefix()";
	}

	TOKEN out = makeop(FIXOP);	// create FIXOP TOKEN
	if (!out) {
		printf(" Failed to alloc TOKEN, makefix().\n");
		return NULL;
	}

	out->operands = tok;
	out->link = NULL;

	if (DEBUG & DB_MAKEFIX) {
		printf(" Finished makefix().\n");
		dbugprint1tok(out);
		last_method = "makefix()";
	}

	return out;
}

/* makefloat forces the item tok to be floating, by floating a constant
   or by inserting a FLOATOP operator */
TOKEN makefloat(TOKEN tok) {

	if (DEBUG & DB_MAKEFLOAT) {
		printf("(%d)\n", debug_call_num++);
		printf("In makefloat(), from %s\n", last_method);
		dbugprint1arg(tok);
		last_method = "makefloat()";
	}

	TOKEN out;

	if (NUM_COERCE_IMPLICIT && tok->tokentype == NUMBERTOK) {
		/* e.g., floating 34 prints "3.400000e+01" to console */
		out = tok;
		out->datatype = REAL;
		out->realval = out->intval;
		out->intval = INT_MIN;
	}
	else {
		/* e.g., floating 34 prints "(float 34)" to console */
		out = makeop(FLOATOP);
		if (!out) {
			printf(" Failed to alloc TOKEN, makefloat().\n");
			return NULL;
		}

		out->operands = tok;
		out->link = NULL;	
	}

	if (DEBUG & DB_MAKEFLOAT) {
		printf(" Finished makefloat().\n");
		dbugprint1tok(out);
		last_method = "makefloat()";
	}

	return out;
}

/* makefor makes structures for a for statement. sign == 1 for regular
   for-loop, -1 for downto for-loop. tok, tokb and tokc are (now) unused
   tokens that are recycled. */
TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, 
			TOKEN endexpr, TOKEN tokc, TOKEN statement) {

	if (DEBUG & DB_MAKEFOR) {
		printf("(%d)\n", debug_call_num++);
		printf("In makefor(), from %s\n", last_method);
		dbugprint6args(tok, asg, tokb, endexpr, tokc, statement);	
		last_method = "makefor()";	
	}

	TOKEN for_asg_progn_tok = makepnb(talloc(), asg);
	TOKEN label_tok = makelabel();
	
	TOKEN stop_op_tok = makeop(LEOP);
	TOKEN do_progn_tok = makepnb(talloc(), statement);
	TOKEN ifop_tok = makeif(makeop(IFOP), stop_op_tok, do_progn_tok, NULL);

	TOKEN loop_stop_tok = copytok(asg->operands); // the counter var, eg "i" in trivb.pas
	TOKEN stmt_incr_tok = makeloopincr(asg->operands, sign);
	TOKEN goto_tok;

	if (!for_asg_progn_tok || !label_tok || !ifop_tok || !stop_op_tok ||
		!do_progn_tok || !loop_stop_tok || !stmt_incr_tok) {
		printf(" Failed to alloc TOKEN(s), makefor().\n");
		return NULL;
	}

	goto_tok = makegoto(label_tok->operands->intval);	// TODO: not null-checked

	if (sign == -1) {
		stop_op_tok->whichval = GEOP;	// "downto"
	}

	/* Link all the tokens together. */
	asg->link = label_tok;
	label_tok->link = ifop_tok;
	stop_op_tok->operands = loop_stop_tok;
	loop_stop_tok->link = endexpr;

	/* Handle elimination of nested progns */
	if (do_progn_tok->whichval != PROGNOP) {
		do_progn_tok->operands = statement;
		statement->link = stmt_incr_tok;
	}
	else {	// do_progn_tok == statement
		get_last_link(do_progn_tok->operands)->link = stmt_incr_tok;
	}
	stmt_incr_tok->link = goto_tok;
	
	if (DEBUG & DB_MAKEFOR) {
		printf(" Finished makefor().\n");
		dbugprint1tok(for_asg_progn_tok);
		last_method = "makefor()";	
	}

	return for_asg_progn_tok;
}
			
/* makefuncall makes a FUNCALL operator and links it to the fn and args.
   tok is a (now) unused token that is recycled. */
TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args) {

	if (DEBUG & DB_MAKEFUNCALL) {
		printf("(%d)\n", debug_call_num++);
		printf("In makefuncall(), from %s\n", last_method);
		dbugprint3args(tok, fn, args);
		last_method = "makefuncall()";
	}

	TOKEN funcall_tok;

	if (strcmp(fn->stringval, "new") != 0) {

		funcall_tok = makeop(FUNCALLOP);		// 24
		if (!funcall_tok) {
			printf(" Failed to allocate TOKEN, makefuncall().\n");	// according to the Prof, print message and coredump
			return NULL;
		}

		SYMBOL this_fxn = searchst(fn->stringval);
		if (!this_fxn) {
			printf(" Failed to find function with name \"%s\" in symbol table.\n", fn->stringval);
			return NULL;
		}
		
		funcall_tok->datatype = this_fxn->datatype->basicdt;

		/* Check for type compatibility between the write functions and
		   the arguments. Correct if necessary. */
		if (strcmp(fn->stringval, "write") == 0 || strcmp(fn->stringval, "writeln") == 0) {
			fn = write_fxn_args_type_check(fn, args);
			if (!fn) {
				return NULL;
			}
		}

		/* (+ i j) => +->operands = i and i->link = j; (funcall_tok fn args) */
		funcall_tok->operands = fn;
		fn->link = args;
	}
	else {
		/* For whenever new() is called */

		funcall_tok = makeop(ASSIGNOP);
		TOKEN funcall = makeop(FUNCALLOP);

		SYMBOL this_type = searchst(args->stringval);

		if (!this_type) {
			printf(" Error: type \"%s\" not found in symbol table, findtype().\n", args->stringval);
			return NULL;
		}

		funcall_tok->operands = args;
		args->link = funcall;
		funcall->operands = fn;
		fn->link = makeintc(this_type->datatype->datatype->datatype->size);

	}

	if (DEBUG & DB_MAKEFUNCALL) {
		printf(" Finished makefuncall().\n");
		dbugprint3toks(funcall_tok, funcall_tok->operands, funcall_tok->operands->link);
//		ppexpr(funcall_tok);
		last_method = "makefuncall()";
	}

	return funcall_tok;
}

/* makegoto makes a GOTO operator to go to the specified label.
   The label number is put into a number token. */
TOKEN makegoto(int label) {

	if (DEBUG & DB_MAKEGOTO) {
		printf("(%d)\n", debug_call_num++);
		printf("In makegoto(), from %s\n", last_method);
		if (DB_PRINT_ARGS) {
			printf(" Arguments:\n  %d\n\n", label);
		}
		last_method = "makegoto()";
	}

	if (label < 0) {
		printf(" Warning: label number is negative (%d), makegoto().\n", label);
	}

	TOKEN goto_tok = makeop(GOTOOP);
	TOKEN goto_num_tok = makeintc(label);
	if (!goto_tok || !goto_num_tok) {
		printf(" Failed to alloc TOKEN, makegoto().\n");
		return NULL;
	}

	goto_tok->operands = goto_num_tok;	// operand together

	if (DEBUG & DB_MAKEGOTO) {
		printf(" Finished makegoto().\n");
		dbugprint1tok(goto_tok);
		last_method = "makegoto()";
	}

	return goto_tok;
}

/* makeif makes an IF operator and links it to its arguments.
   tok is a (now) unused token that is recycled to become an IFOP operator */
TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart) {

	if (DEBUG & DB_MAKEIF) {
		printf("(%d)\n", debug_call_num++);
		printf("In makeif(), from %s\n", last_method);
		dbugprint4args(tok, exp, thenpart, elsepart);	
		last_method = "makeif()";	
	}
	
	tok->tokentype = OPERATOR;	/* Make it look like an operator. */
	tok->whichval = IFOP;
	
	if (elsepart != NULL) {
		elsepart->link = NULL;
	}

	thenpart->link = elsepart;
	exp->link = thenpart;
	tok->operands = exp;

	if (DEBUG & DB_MAKEIF) {
		printf(" Finished makeif().\n");
		dbugprint1tok(tok);
	}

	return tok;
}

/* makeintc makes a new token with num as its value */
TOKEN makeintc(int num) {

	if (DEBUG & DB_MAKEINTC) {
		printf("(%d)\n", debug_call_num++);
		printf("In makeintc(), from %s\n", last_method);
		printf(" Arguments:\n  %d\n\n", num);
		last_method = "makeintc()";
	} 

	TOKEN out = talloc();
	if (!out) {
		printf(" Failed to alloc TOKEN, makeintc().\n");
		return NULL;
	}

	out->tokentype = NUMBERTOK;
	out->datatype = INTEGER;
	out->intval = num;

	if (DEBUG & DB_MAKEINTC) {
		printf(" Finished makeintc().\n");
		dbugprint1tok(out);
	}

	return out;
}

/* makelabel makes a new label, using labelnumber++ */
TOKEN makelabel() {

	// DO NOT CALL FOR USER LABELS

	if (DEBUG & DB_MAKELABEL) {
		printf("(%d)\n", debug_call_num++);
		printf("In makelabel(), from %s\n\n", last_method);
		last_method = "makelabel()";
	}

	TOKEN label_tok = makeop(LABELOP);
	TOKEN label_num_tok = makeintc(labelnumber++);	// increment it after creation
	
	if (!label_tok || !label_num_tok) {
		printf(" Failed to alloc TOKEN(s), makelabel().\n");
		return NULL;
	}

	label_tok->operands = label_num_tok;	// operand together

	if (DEBUG & DB_MAKELABEL) {
		printf(" Finished makelabel().\n");
		dbugprint1tok(label_tok);
		last_method = "makelabel()";
	}

	return label_tok;
}

/* A helper method used to create the TOKENs required to increment
   the counter var in a for-loop.

   Returned TOKENs are of the form "(:= i (+ i 1))".  */
TOKEN makeloopincr(TOKEN var, int incr_amt) {
	// if in makefor(), send in asg->operands

	TOKEN assignop = makeop(ASSIGNOP);
	TOKEN var_cpy = copytok(var);
	TOKEN plusop = makeplus(copytok(var), makeintc(incr_amt), NULL);	// PLUSOP operand "var" link amt

	assignop->operands = var_cpy;
	var_cpy->link = plusop;

	return assignop;
}

/* makeop makes a new operator token with operator number opnum.
   Example:  makeop(FLOATOP)  */
TOKEN makeop(int opnum) {

	if (DEBUG & DB_MAKEOP) {
		printf("(%d)\n", debug_call_num++);
		printf("In makeop(), from %s\n", last_method);
		if (DB_PRINT_ARGS) {
			printf(" Arguments:\n  %d\n\n", opnum);	
		}
		last_method = "makeop()";
	}

	if (opnum < 0) {
		printf(" Warning: opnum is negative (%d), makeop().\n", opnum);
	}

	TOKEN out = talloc();
	if (!out) {
		printf(" Failed to alloc TOKEN, makeop().\n");
		return NULL;
	}

	out->tokentype = OPERATOR;
	out->whichval = opnum;

	if (DEBUG & DB_MAKEOP) {
		printf(" Finished makeop().\n");
		dbugprint1tok(out);
	}

	return out;
}

/* makeplus makes a + operator.
   tok (if not NULL) is a (now) unused token that is recycled. */
TOKEN makeplus(TOKEN lhs, TOKEN rhs, TOKEN tok) {

	if (DEBUG & DB_MAKEPLUS) {
		printf("(%d)\n", debug_call_num++);
		printf("In makeplus(), from %s\n", last_method);
		dbugprint3args(lhs, rhs, tok);		
		last_method = "makeplus()";
	}

	TOKEN out = makeop(PLUSOP);
	if (lhs && rhs) {
		out->operands = lhs;
		lhs->link = rhs;
		rhs->link = NULL;
	}
	
	if (DEBUG & DB_MAKEPLUS) {
		printf(" Finished makeplus().\n");
		dbugprint1tok(out);
		last_method = "makeplus()";
	}

	return out;
}

/* Make a * operator TOKEN. Sets operands and
   fields if not NULL and returns this, otherwise
   just returns a * OPERATOR TOKEN. */
TOKEN maketimes(TOKEN lhs, TOKEN rhs, TOKEN tok) {

	TOKEN out = makeop(TIMESOP);
	if (lhs && rhs) {
		out->operands = lhs;
		lhs->link = rhs;
		rhs->link = NULL;
	}

	return out;
}

/* makepnb is like makeprogn, except that if statements is already a progn,
   it just returns statements.  This is optional. */
TOKEN makepnb(TOKEN tok, TOKEN statements) {

	if (statements->whichval == PROGNOP && ELIM_NESTED_PROGN) {
		if (DEBUG & DB_MAKEPNB) {
			printf("(%d)\n", debug_call_num++);
			printf("In makepnb(), from %s\n", last_method);
			dbugprint2args(tok, statements);
			printf(" Finished makepnb().\n");
			dbugprint1tok(statements);
		}
		return statements;
	}
	if (DEBUG & DB_MAKEPNB) {
		printf("(%d)\n", debug_call_num++);
		printf("In makepnb(), from %s; transferring to makeprogn()...\n", last_method);
	}
	return (makeprogn(tok, statements));
}

/* makeprogn makes a PROGN operator and links it to the list of statements.
   tok is a (now) unused token that is recycled. */
TOKEN makeprogn(TOKEN tok, TOKEN statements) {

	if (DEBUG & DB_MAKEPROGN) {
		printf("(%d)\n", debug_call_num++);
		printf("In makeprogn(), from %s\n", last_method);
		dbugprint2args(tok, statements);
		last_method = "makeprogn()";
	}

	tok->tokentype = OPERATOR;		// 0
	tok->whichval = PROGNOP;		// 22
	tok->operands = statements;

	if (DEBUG & DB_MAKEPROGN) {
		printf(" Finished makeprogn().\n");
		dbugprint2toks(tok, statements);
	}

	return tok;
}

/* makeprogram makes the tree structures for the top-level program */
TOKEN makeprogram(TOKEN name, TOKEN args, TOKEN statements) {

	if (DEBUG & DB_MAKEPROGRAM) {
		printf("(%d)\n", debug_call_num++);
		printf("In makeprogram(), from %s\n", last_method);
		dbugprint3args(name, args, statements);
		last_method = "makeprogram()";
	}

	TOKEN program_start = makeop(PROGRAMOP);		// 26
	TOKEN progn_start = makepnb(talloc(), args);	// set []->operands to args
	
	if (!program_start || !progn_start) {
		printf(" Failed to alloc TOKEN, makeprogram().\n");	// according to the Prof, print message and coredump
		return NULL;
	}

	/* Create the head of the tree (this is stored in parseresult). */
	program_start->operands = name;
	progn_start->link = statements;
	name->link = progn_start;

	if (DEBUG & DB_MAKEPROGRAM) {
		printf(" Finished makeprogram().\n");
		dbugprint1tok(program_start);
		last_method = "makeprogram()";
	}

	return program_start;
}

/* Not really much use for this except
   in get_offset() */
TOKEN makerealtok(float num) {
	TOKEN out = talloc();
	if (!out) {
		printf(" Failed to alloc TOKEN, makerealtok().\n");
		return NULL;
	}

	out->tokentype = NUMBERTOK;
	out->datatype = REAL;
	out->realval = num;

	return out;
}

/* makerepeat makes structures for a repeat statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr) {

	if (DEBUG & DB_MAKEREPEAT) {
		printf("(%d)\n", debug_call_num++);
		printf("In makerepeat(), from %s\n", last_method);
		dbugprint4args(tok, statements, tokb, expr);
		last_method = "makerepeat()";
	}

	TOKEN label_tok = makelabel();
	TOKEN goto_tok = makegoto(label_tok->operands->intval);
	TOKEN rpt_progn_tok = makepnb(talloc(), label_tok);	// operand label_tok to rpt_progn_tok
	TOKEN do_progn_tok = makeop(PROGNOP);
	TOKEN ifop_tok = makeif(makeop(IFOP), expr, do_progn_tok, NULL);

	if (!label_tok || !goto_tok || !rpt_progn_tok ||
		!do_progn_tok ||!ifop_tok) {
		printf(" Failed to alloc TOKEN(s), makerepeat().\n");
		return NULL;
	}

	/* Link TOKENs together */
	label_tok->link = statements;
	do_progn_tok->link = goto_tok;

	/* Handle elimination of nested progns */
	get_last_link(statements)->link = ifop_tok;

	if (DEBUG & DB_MAKEREPEAT) {
		printf(" Finished makerepeat().\n");
		dbugprint1tok(rpt_progn_tok);
		last_method = "makerepeat()";
	}

	return rpt_progn_tok;
}

/* makewhile makes structures for a while statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement) {

	if (DEBUG & DB_MAKEWHILE) {
		printf("(%d)\n", debug_call_num++);
		printf("In makewhile(), from %s\n", last_method);
		dbugprint4args(tok, expr, tokb, statement);
		last_method = "makewhile()";
	}

	if (expr->operands->link && expr->operands->link->whichval == (NIL - RESERVED_BIAS)) {
		expr->operands->link->tokentype = NUMBERTOK;
		expr->operands->link->datatype = INTEGER;
		expr->operands->link->whichval = 0;
	}

	TOKEN label_tok = makelabel();
	TOKEN goto_tok = makegoto(label_tok->operands->intval);
	TOKEN while_progn_tok = makepnb(talloc(), label_tok);	// operand label_tok to while_progn_tok
	TOKEN do_progn_tok = makepnb(talloc(), statement);		// operand statement to do_progn_tok
	TOKEN ifop_tok = makeif(makeop(IFOP), expr, do_progn_tok, NULL);

	if (!label_tok || !goto_tok || !while_progn_tok ||
		!do_progn_tok ||!ifop_tok) {
		printf(" Failed to alloc TOKEN(s), makewhile().\n");
		return NULL;
	}

	label_tok->link = ifop_tok;

	/* Handle elimination of nested progns */
	if (do_progn_tok->whichval != PROGNOP) {
		do_progn_tok->operands = statement;
		statement->link = goto_tok;
	}
	else {	// do_progn_tok == statement
		get_last_link(do_progn_tok->operands)->link = goto_tok;
	}

	if (DEBUG & DB_MAKEWHILE) {
		printf(" Finished makewhile().\n");
		dbugprint1tok(while_progn_tok);
		last_method = "makewhile()";
	}

	return while_progn_tok;
}

/* mulint multiplies expression exp by integer n */
TOKEN mulint(TOKEN exp, int n) {
	if (!exp) {
		return NULL;
	}

	if (exp->datatype == INTEGER) {

		int a = exp->intval;
		int val = a * n;
		
		if (DEBUG & DB_MULINT) {
			printf("(%d)\n", debug_call_num++);
			printf("In mulint(), from %s\n Multiplying %d to %d\n", last_method, n, a);
			last_method = "mulint()";
		}

		if (a != 0 && (a * n) / a != n) {
			printf(" Integer overflow detected, mulint()\n");
			printf(" Cannot multiply %d to %d\n", n, a);
		}
		else {
			exp->intval = val;
		}

		if (DEBUG & DB_MULINT) {
			printf(" New value of exp: %d\n", exp->intval);
			dbugprint1tok(exp);
		}

	}
	else if (exp->datatype == REAL) {

		if (DEBUG & DB_MULINT) {
			printf("In mulint()\n Multiplying %d to %f\n", n, exp->realval);
		}
	
		double val = exp->realval * n;

		if ((val > FLT_MAX || val < FLT_MIN)) {
			printf(" Floating number out of range, mulint()\n");
			printf(" Cannot multiply %d to %f\n", n, exp->realval);
		}
		else {
			exp->realval = val;
		}

		if (DEBUG & DB_MULINT) {
			printf(" New value of exp: %f\n", exp->realval);
			dbugprint1tok(exp);
		}

	}

	return exp;
}

/* searchins will search for symbol, inserting it if not present. */
SYMBOL searchinsst(char name[]) {
	return (searchins(name));
}

/* settoktype sets up the type fields of token tok.
   typ = type pointer, ent = symbol table entry of the variable  */
void settoktype(TOKEN tok, SYMBOL typ, SYMBOL ent) {

	if (DEBUG & DB_SETTOKTYPE) {
		printf("(%d)\n", debug_call_num++);
		printf("In settoktype(), from %s\n", last_method);
		dbugprint3args(tok, typ, ent);
		last_method = "settoktype()";
	}

	if (!tok || !typ || !ent) {
		// something;
	}

	tok->symtype = typ;
	tok->symentry = ent;

	if (DEBUG & DB_SETTOKTYPE) {
		printf(" Finished settoktype().\n\n");
	}
}

/* unaryop links a unary operator op to one operand, lhs. +/-/NOT */
TOKEN unaryop(TOKEN op, TOKEN lhs) {

	if (DEBUG & DB_UNARYOP) {
		printf("(%d)\n", debug_call_num++);
		printf("In unaryop(), from %s\n", last_method);
		dbugprint2args(op, lhs);
		last_method = "unaryop()";
	}

	op->operands = lhs;
	lhs->link = NULL;

	if (DEBUG & DB_UNARYOP) {
		printf(" Finished unaryop().\n");
		dbugprint2toks(op, lhs);
	}

	return op;
}

/* wordaddress pads the offset n to be a multiple of wordsize.
   wordsize should be 4 for integer, 8 for real and pointers,
   16 for records and arrays */
int wordaddress(int n, int wordsize) { 
	return ((n + wordsize - 1) / wordsize) * wordsize;
}

// TODO: assumes fn is always a write() or writeln() function
// TODO: does not do cross-conversions (e.g., send in writelnf() to convert to writelni())
// TODO: identifier datatypes?
/* Check for type compatibility between the write functions and
   the arguments. Correct if necessary. */
TOKEN write_fxn_args_type_check(TOKEN fn, TOKEN args) {

	if (args->datatype == STRINGTYPE) {
		return fn;
	}

	TOKEN out = NULL;

	SYMBOL fn_sym = searchst(fn->stringval);
	if (!fn_sym) {
		printf(" Error: function \"%s\" is not defined.\n", fn->stringval);
		return out;
	}

	int fn_arg_type = fn_sym->datatype->link->basicdt;
	int args_type = args->datatype;

	if (args_type == STRINGTYPE) {
		out = fn;
	}
	else {

		int replace_index = 5;
		if (strcmp(fn->stringval, "writeln") == 0) {
			replace_index = 7;
		}

		if (strcmp(fn->stringval, "write") == 0) {

			if (args_type == INTEGER) {
				fn->stringval[replace_index] = 'i';
				fn->stringval[replace_index + 1] = '\0';
				out = fn;
			}
			else if (args_type == REAL) {
				fn->stringval[replace_index] = 'f';
				fn->stringval[replace_index + 1] = '\0';
				out = fn;				
			}

		}
		else if (strcmp(fn->stringval, "writeln") == 0) {

			if (args_type == INTEGER) {
				fn->stringval[replace_index] = 'i';
				fn->stringval[replace_index + 1] = '\0';
				out = fn;
			}
			else if (args_type == REAL) {
				fn->stringval[replace_index] = 'f';
				fn->stringval[replace_index + 1] = '\0';
				out = fn;
			}

		}
	}

	return out;
}

yyerror(s) char *s; {
	fputs(s, stderr);
	putc('\n', stderr);
}

int main(int argc, char **argv) {
	int res;
	initsyms();
	res = yyparse();

	if (!DEBUG_MASTER_SWITCH && !GEN_OUTPUT) {
		/* Set DEBUG_MASTER_SWITCH and GEN_OUTPUT to 0 */
		printst();
		printf("yyparse result = %8d\n", res);
		ppexpr(parseresult);
	}
	else if (DEBUG & DB_PARSERES && !GEN_OUTPUT) {
		/* Set DEBUG_MASTER_SWITCH to 1 and GEN_OUTPUT to 0; set DB_PRINT_ARGS to 1 if desired */
		printf("Done.\n\n");

		printst();

		printf("--------------------------------------------------------------------\n\n");
		printf("yyparse result = %8d\n\n", res);
		printf("parseresult:\n");
		dbugprinttok(parseresult);
		printf("\n");
		ppexpr(parseresult);	/* Pretty-print the result tree */
		printf("\n");
		printf("--------------------------------------------------------------------\n");
	}
	else {
		/* Set GEN_OUTPUT to 1 (everything else is irrelevant) */
//		ppexpr(parseresult);
//		system("testparser");
		gencode(parseresult, blockoffs[blocknumber], labelnumber);
	}

	destroy_toklist();		/* Free all tokens allocated during program runtime (including lex) */
	destroy_symlist();		/* Free all symbols allocated during program runtime */
	destroy_user_labels();	/* Free all user labels allocated during program runtime */

	return 0;
}




// DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED

// TOKEN get_offset(TOKEN var, TOKEN field) {
	
// 	TOKEN offset = makeintc(-1);

// 	TOKEN root_name = get_last_operand(var);
// 	TOKEN last_offset = get_last_link(var->operands);

// 	if (var->whichval != AREFOP) {
// 		SYMBOL found = NULL;

// 		SYMBOL varsym = searchst(root_name->stringval);
// 		if (varsym) {
// 			SYMBOL temp = varsym;
// 			while (temp) {
// 				if (temp->datatype && temp->datatype->kind == BASICTYPE) {
// 					break;
// 				}
// 				temp = temp->datatype;
// 			}
// 			while (temp && !found) {
// 				if (strcmp(temp->namestring, field->stringval) == 0) {
// 					found = temp;
// 				}
// 				else {
// 					temp = temp->link;
// 				}
// 			}
// 			if (found) {
// 				offset->whichval = found->offset;
// 				return offset;
// 			}
// 		}

// 	}
// 	else {
// 		SYMBOL found = NULL;

// 		SYMBOL varsym = searchst(root_name->stringval);
// 		if (varsym) {
// 			SYMBOL temp = varsym;
// 			while (temp) {
// 				if (temp->datatype && temp->datatype->kind == BASICTYPE) {
// 					break;
// 				}
// 				temp = temp->datatype;
// 			}
// 			while (temp && !found) {
// 				if (temp->offset == last_offset->whichval) {
// 					found = temp;
// 				}
// 				else {
// 					temp = temp->link;
// 				}
// 			}
// 			if (found) {
// 				SYMBOL found_cpy = found;
// 				SYMBOL blah = searchst(found->datatype->namestring);
// 				found = NULL;
// 				while (blah) {
// 					if (blah->datatype && blah->datatype->kind == BASICTYPE) {
// 						break;
// 					}
// 					blah = blah->datatype;
// 				}
// 				while (blah && !found) {
					
// 					if (strcmp(blah->namestring, field->stringval) == 0) {
// 						found = blah;
// 					}
// 					else {
// 						blah = blah->link;
// 					}
// 				}
// 				if (found) {
// 					offset->whichval = last_offset->whichval + found->offset;
// 				}				
// 			}
// 		}		
// 	}

// 	return offset;
// }

// PARTIALLY WORKING
// TOO MANY LOGICAL FLAWS TO BE CURRENTLY VIABLE
// TOKEN std_fxn_args_type_check(TOKEN fn, TOKEN args) {

// 	SYMBOL fn_sym = searchst(fn->stringval);
// 	if (!fn_sym) {
// 		printf(" Error: function \"%s\" is not defined.\n", fn->stringval);
// 		return NULL;
// 	}
// /* The following defines are commented out, but may be needed.
// #define INTEGER    0
// #define REAL       1
// #define STRINGTYPE 2
// #define BOOLETYPE  3
// #define POINTER    4
//     */
// 	int fn_arg_type = fn_sym->datatype->link->basicdt;
// 	int args_type = args->datatype;

// 	if (args_type == fn_arg_type) {
// 		return fn;
// 	}
// 	else {

// 		if (strcmp(fn->stringval, "write") == 0 || strcmp(fn->stringval, "writeln") == 0) {

// 			int replacement_index = 5;
// 			if (strcmp(fn->stringval, "writeln") == 0) {
// 				replacement_index = 7;
// 			}

// 			if (args_type == INTEGER) {
// 				fn->stringval[replacement_index] = 'i';
// 				fn->stringval[replacement_index + 1] = '\0';
// 				return fn;
// 			}
// 			else if (args_type == REAL) {
// 				fn->stringval[replacement_index] = 'f';
// 				fn->stringval[replacement_index + 1] = '\0';
// 				return fn;
// 			}
// 		}
// 	}

// 	printf(" Error: function \"%s\" with argument type %d cannot accept arguments of type %d.\n", fn->stringval, fn_arg_type, args_type);

// 	return NULL;
// }
