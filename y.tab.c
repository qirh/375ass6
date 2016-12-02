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

       /* To use:
                     make pars1y              has 1 shift/reduce conflict
                     pars1y                   execute the parser
                     i:=j .
                     ^D                       control-D to end input

                     pars1y                   execute the parser
                     begin i:=j; if i+j then x:=a+b*c else x:=a*b+c; k:=i end.
                     ^D

                     pars1y                   execute the parser
                     if x+y then if y+z then i:=j else k:=2.
                     ^D

           You may copy pars1.y to be parse.y and extend it for your
           assignment.  Then use   make parser   as above.
        */

        /* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
           the IF statement, but Yacc's default resolves it in the right way.*/

#include <stdio.h>
#include <ctype.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"
#include <string.h>


        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;



#line 130 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
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

#line 300 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   278

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

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
static const yytype_uint8 yyrline[] =
{
       0,    83,    83,    86,    87,    88,    89,    91,    92,    94,
      95,    96,    97,    99,   100,   102,   104,   105,   110,   111,
     112,   113,   114,   116,   117,   118,   120,   121,   123,   125,
     127,   128,   130,   131,   133,   135,   136,   137,   139,   140,
     142,   143,   145,   147,   148,   149,   151,   152,   154,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   167,
     168,   170,   171,   173,   174,   176,   178,   179,   181,   182,
     183,   185,   186,   187,   188,   190,   191,   193,   194,   195,
     196,   197,   198,   199,   201,   202,   204,   205,   206,   207,
     208,   209,   210,   212,   213,   215,   216
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
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
  "variable", "id_list", "type", "num_list", "fields", "field_list",
  "constant", "simple_type", "simple_type_list", "block", "cdef",
  "cdef_list", "cblock", "tdef", "tdef_list", "tblock", "lblock", "vdef",
  "vdef_list", "vblock", "funcall", "statement", "statement_list",
  "endpart", "endif", "assignment", "expr_list", "expression",
  "simple_expression", "term", "factor", "args", "compare_op", "sign",
  "times_op", YY_NULLPTR
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

#define YYPACT_NINF -152

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-152)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -41,    26,    43,    18,  -152,    49,    30,    36,    49,    60,
    -152,    56,    28,    66,    75,    80,    49,  -152,  -152,  -152,
      73,  -152,    61,    79,    28,   127,   128,    54,    28,    54,
      57,  -152,    -3,  -152,   123,   111,   -19,   115,   124,   141,
     131,   -12,   139,   143,   136,  -152,    54,    28,    -3,  -152,
     117,  -152,   146,  -152,  -152,  -152,    22,    54,  -152,   137,
    -152,  -152,   132,    71,    96,  -152,   113,   145,   119,   177,
      54,  -152,   172,    54,    28,  -152,  -152,   219,    66,  -152,
      75,   -15,   148,    80,  -152,   148,    49,  -152,   149,   224,
     150,  -152,  -152,    54,    54,  -152,   137,   205,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,    28,    54,    54,   121,
    -152,  -152,   121,   146,  -152,  -152,    96,    29,    28,    54,
      28,   254,  -152,   151,   239,    -3,  -152,  -152,  -152,  -152,
    -152,  -152,   153,   183,    49,   164,    49,  -152,  -152,  -152,
    -152,  -152,  -152,    54,  -152,   191,  -152,   156,    71,    71,
      96,  -152,  -152,  -152,  -152,   254,  -152,  -152,    54,  -152,
     175,  -152,   167,    23,   181,   173,   169,  -152,  -152,    28,
      28,  -152,  -152,  -152,   185,   182,   148,    49,  -152,  -152,
    -152,    23,   179,  -152,  -152,  -152,   148,  -152
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     8,     0,     0,     0,
       7,     0,     0,     0,     0,     0,     0,    47,    41,    33,
       0,    39,     3,     0,     0,     0,     0,     0,     0,     0,
       0,    52,     0,    51,     0,     0,     0,    14,     0,     0,
      36,     0,     0,    44,     0,     2,     0,     0,     0,     3,
       0,    58,     3,    20,    19,    93,    94,     0,    83,    80,
      81,    82,     0,    70,    72,    76,     0,    60,     0,     0,
       0,     5,     0,     0,     0,    62,    28,     0,    31,    32,
       0,     0,     0,    37,    38,     0,    45,    46,     0,    67,
       0,    50,    49,     0,     0,    79,    78,     0,    94,    86,
      89,    87,    90,    91,    88,    92,     0,     0,     0,     0,
      95,    96,     0,     3,    20,    19,    73,     0,     0,     0,
       0,    65,     4,     0,    67,     0,    18,    29,    30,    13,
      40,    23,     0,     0,     0,     0,     0,    34,     9,    35,
      42,    43,    48,     0,    57,     0,    77,    64,    68,    69,
      71,    75,    22,    21,    59,    56,    55,     6,     0,    61,
       0,    11,     0,     0,     0,    17,     0,    66,    84,     0,
       0,    53,    25,    24,    27,     0,     0,     0,    12,    54,
      63,     0,     0,    15,    16,    26,     0,    10
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,  -152,   -11,    -5,   -83,   152,  -152,    64,   165,  -151,
      52,   199,  -152,   166,   176,  -152,   188,   211,  -152,  -152,
     170,   217,    -8,    -6,   144,   -40,  -152,   234,   -64,   -22,
      15,   -55,   160,   130,  -152,   -13,  -152
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    59,    42,   137,    38,   165,   166,    60,   138,
     175,    17,    35,    36,    18,    40,    41,    19,    20,    43,
      44,    21,    61,    67,    68,    76,   171,    33,    88,   124,
      63,    64,    65,    90,   107,    66,   112
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       7,    30,   140,    10,    31,    62,    32,    69,    92,   123,
       1,   116,   174,    30,    30,    12,    31,    30,    48,    12,
      31,    13,    12,    74,    89,    49,   131,    95,   132,     3,
     174,    22,   152,    23,   153,    97,    30,    75,    15,    31,
      16,    91,    15,     4,    16,    96,     5,    16,   121,   108,
     109,   134,     6,   117,   150,     8,   108,    52,    53,    54,
      55,    56,    24,    30,   117,     9,    31,    70,   125,    34,
      25,   145,    26,    27,    71,    72,   108,    55,    98,   167,
      37,    28,    57,    39,   108,   159,    11,    73,    29,    46,
      12,    45,    13,   183,   167,    30,   117,   155,    31,   117,
     147,    58,    14,   187,   110,   111,    47,    30,   108,    30,
      31,   108,    31,    15,   156,    16,   113,   114,   115,    55,
      56,    89,   148,   149,    52,   114,    54,    55,    56,   162,
      49,   164,   108,    51,    77,   109,   109,    78,    55,    98,
      80,    57,   108,    99,   100,   101,   102,   103,   104,    57,
      81,   131,    82,   132,    71,    72,   105,    83,    30,    30,
      58,    31,    31,   179,   180,   133,    85,    73,    58,    86,
      12,   118,   164,    93,    94,   122,   134,   119,   142,   144,
     172,   135,   157,    55,    98,   160,   161,   106,    99,   100,
     101,   102,   103,   104,   163,   170,   173,    55,    98,   177,
     136,   105,    99,   100,   101,   102,   103,   104,   176,   178,
     181,    55,    98,   182,   120,   105,    99,   100,   101,   102,
     103,   104,   126,   114,    54,    55,    98,   186,   169,   105,
      55,    98,   129,   185,   146,    99,   100,   101,   102,   103,
     104,   184,   127,    87,   128,    55,    98,    79,   105,   143,
      99,   100,   101,   102,   103,   104,   141,   130,    84,    50,
      55,    98,   154,   105,   158,    99,   100,   101,   102,   103,
     104,   139,   151,   168,     0,     0,     0,     0,   105
};

static const yytype_int16 yycheck[] =
{
       5,    12,    85,     8,    12,    27,    12,    29,    48,    73,
      51,    66,   163,    24,    25,    34,    24,    28,    24,    34,
      28,    36,    34,    26,    46,     3,     3,     5,     5,     3,
     181,     3,     3,     5,     5,    57,    47,    40,    57,    47,
      59,    47,    57,     0,    59,    56,    28,    59,    70,    62,
      63,    28,     3,    66,   109,    25,    69,     3,     4,     5,
       6,     7,    34,    74,    77,    29,    74,    10,    74,     3,
      42,    93,    44,    45,    17,    18,    89,     6,     7,   143,
       5,    53,    28,     3,    97,   125,    26,    30,    60,    28,
      34,    18,    36,   176,   158,   106,   109,   119,   106,   112,
     106,    47,    46,   186,     8,     9,    27,   118,   121,   120,
     118,   124,   120,    57,   120,    59,     3,     4,     5,     6,
       7,   143,   107,   108,     3,     4,     5,     6,     7,   134,
       3,   136,   145,     5,    11,   148,   149,    26,     6,     7,
      25,    28,   155,    11,    12,    13,    14,    15,    16,    28,
      26,     3,    11,     5,    17,    18,    24,    26,   169,   170,
      47,   169,   170,   169,   170,    17,    27,    30,    47,    26,
      34,    26,   177,    56,    28,     3,    28,    58,    29,    29,
       5,    33,    31,     6,     7,    32,     3,    55,    11,    12,
      13,    14,    15,    16,    30,    39,    29,     6,     7,    26,
      52,    24,    11,    12,    13,    14,    15,    16,    27,    40,
      25,     6,     7,    31,    37,    24,    11,    12,    13,    14,
      15,    16,     3,     4,     5,     6,     7,    48,    37,    24,
       6,     7,    80,   181,    29,    11,    12,    13,    14,    15,
      16,   177,    77,    44,    78,     6,     7,    36,    24,    25,
      11,    12,    13,    14,    15,    16,    86,    81,    41,    25,
       6,     7,   118,    24,    25,    11,    12,    13,    14,    15,
      16,    83,   112,   143,    -1,    -1,    -1,    -1,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    63,     3,     0,    28,     3,    65,    25,    29,
      65,    26,    34,    36,    46,    57,    59,    73,    76,    79,
      80,    83,     3,     5,    34,    42,    44,    45,    53,    60,
      64,    84,    85,    89,     3,    74,    75,     5,    67,     3,
      77,    78,    65,    81,    82,    18,    28,    27,    85,     3,
      89,     5,     3,     4,     5,     6,     7,    28,    47,    64,
      70,    84,    91,    92,    93,    94,    97,    85,    86,    91,
      10,    17,    18,    30,    26,    40,    87,    11,    26,    79,
      25,    26,    11,    26,    83,    27,    26,    73,    90,    91,
      95,    85,    87,    56,    28,     5,    64,    91,     7,    11,
      12,    13,    14,    15,    16,    24,    55,    96,    97,    97,
       8,     9,    98,     3,     4,     5,    93,    97,    26,    58,
      37,    91,     3,    90,    91,    85,     3,    70,    75,    67,
      76,     3,     5,    17,    28,    33,    52,    66,    71,    78,
      66,    82,    29,    25,    29,    91,    29,    85,    92,    92,
      93,    94,     3,     5,    86,    91,    85,    31,    25,    87,
      32,     3,    65,    30,    65,    68,    69,    90,    95,    37,
      39,    88,     5,    29,    71,    72,    27,    26,    40,    85,
      85,    25,    31,    66,    69,    72,    48,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    64,    64,    65,    65,    66,
      66,    66,    66,    67,    67,    68,    69,    69,    70,    70,
      70,    70,    70,    71,    71,    71,    72,    72,    73,    74,
      75,    75,    76,    76,    77,    78,    78,    78,    79,    79,
      80,    80,    81,    82,    82,    82,    83,    83,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    86,
      86,    87,    87,    88,    88,    89,    90,    90,    91,    91,
      91,    92,    92,    92,    92,    93,    93,    94,    94,    94,
      94,    94,    94,    94,    95,    95,    96,    96,    96,    96,
      96,    96,    96,    97,    97,    98,    98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     1,     3,     2,     4,     3,     1,     1,
       6,     2,     3,     3,     1,     3,     3,     1,     1,     1,
       1,     2,     2,     1,     3,     3,     3,     1,     3,     3,
       3,     2,     3,     1,     3,     3,     1,     2,     3,     1,
       4,     1,     3,     3,     1,     2,     3,     1,     4,     3,
       3,     1,     1,     5,     6,     4,     4,     4,     2,     3,
       1,     3,     1,     2,     0,     3,     3,     1,     3,     3,
       1,     3,     1,     2,     1,     3,     1,     3,     2,     2,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
#line 84 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 program\n" ); parseresult = makeprogram((yyvsp[-6]), (yyvsp[-4]), (yyvsp[-1])); }
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 86 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 variable\n" ); (yyval) = findid((yyvsp[0])); }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 87 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 variable\n" ); (yyval) = reducedot((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 88 "parse.y" /* yacc.c:1646  */
    { printdebug( "3 variable\n" ); (yyval) = dopoint((yyvsp[-1]), (yyvsp[0])); }
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 89 "parse.y" /* yacc.c:1646  */
    { printdebug( "4 variable\n" ); (yyval) = arrayref((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 91 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 id_list\n" ); (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 92 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 id_list\n" ); (yyval) = cons((yyvsp[0]), NULL); }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 94 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 type\n" ); }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 95 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 type\n" ); (yyval) = instarray((yyvsp[-3]), (yyvsp[0])); }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 96 "parse.y" /* yacc.c:1646  */
    { printdebug( "3 type\n" ); (yyval) = instpoint((yyvsp[-1]), (yyvsp[0]));; }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 97 "parse.y" /* yacc.c:1646  */
    { printdebug( "4 type\n" ); (yyval) = instrec((yyvsp[-2]), (yyvsp[-1])); }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 99 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 num_list\n" ); instlabel((yyvsp[-2])); }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 100 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 num_list\n" ); instlabel((yyvsp[0])); }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 102 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 fields\n" ); (yyval) = instfields((yyvsp[-2]), (yyvsp[0])); }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 104 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 field_list\n" ); (yyval) = nconc((yyvsp[-2]), (yyvsp[0])); }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 105 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 field_list\n" ); }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 110 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 constant\n" ); }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 111 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 constant\n" ); }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 112 "parse.y" /* yacc.c:1646  */
    { printdebug( "3 constant\n" ); }
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 113 "parse.y" /* yacc.c:1646  */
    { printdebug( "4 constant\n" ); }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 114 "parse.y" /* yacc.c:1646  */
    { printdebug( "5 constant\n" ); }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 116 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 simple_type\n" ); (yyval) = findtype((yyvsp[0])); }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 117 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 simple_type\n" ); (yyval) = instenum((yyvsp[-1])); }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 118 "parse.y" /* yacc.c:1646  */
    { printdebug( "3 simple_type\n" ); (yyval) = makesubrange((yyvsp[-1]), (yyvsp[-2])->intval, (yyvsp[0])->intval);; }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 120 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 simple_type_list\n" ); (yyval) = cons((yyvsp[0]), (yyvsp[-2])); }
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 121 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 simple_type_list\n" ); }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 123 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 block\n" ); (yyval) = makeprogn((yyvsp[-2]), cons((yyvsp[-1]), (yyvsp[0])));  }
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 125 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 cdef\n" ); instconst((yyvsp[-2]), (yyvsp[0])); }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 127 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 cdef_list\n" ); cons((yyvsp[-2]), (yyvsp[0])); }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 128 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 cdef_list\n" ); cons((yyvsp[-1]), NULL); }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 130 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 cblock\n" ); (yyval) = (yyvsp[0]); }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 131 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 cblock\n" ); }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 133 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 tdef\n" ); insttype((yyvsp[-2]), (yyvsp[0])); }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 135 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 tdef_list\n" ); }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 136 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 tdef_list\n" ); }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 137 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 tdef_list\n" ); }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 139 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 tblock\n" ); (yyval) = (yyvsp[0]); }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 140 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 tblock\n" ); }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 142 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 lblock\n" ); (yyval) = (yyvsp[0]); }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 143 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 lblock\n" ); }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 145 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 vdef\n" ); instvars((yyvsp[-2]), (yyvsp[0])); }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 147 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 vdef_list\n" ); cons((yyvsp[-2]), (yyvsp[0])); }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 148 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 vdef_list\n" ); }
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 149 "parse.y" /* yacc.c:1646  */
    { printdebug( "3 vdef_list\n" ); }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 151 "parse.y" /* yacc.c:1646  */
    { printdebug( "*******1 vblock\n" ); (yyval) = (yyvsp[0]); }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 152 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 vblock\n" ); }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 154 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 funcall\n" ); (yyval) = makefuncall(talloc(), (yyvsp[-3]), (yyvsp[-1])); }
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 156 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 statement\n" ); (yyval) = makeprogn((yyvsp[-2]), cons((yyvsp[-1]), (yyvsp[0]))); }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 157 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 statement\n" ); (yyval) = dolabel((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 158 "parse.y" /* yacc.c:1646  */
    { printdebug( "3 statement\n" ); }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 159 "parse.y" /* yacc.c:1646  */
    { printdebug( "4 statement\n" ); }
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 160 "parse.y" /* yacc.c:1646  */
    { printdebug( "5 statement\n" ); (yyval) = makeif((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-1]), (yyvsp[0])); }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 161 "parse.y" /* yacc.c:1646  */
    { printdebug( "6 statement\n" ); (yyval) = makefor(1, (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 162 "parse.y" /* yacc.c:1646  */
    { printdebug( "7 statement\n" ); (yyval) = makewhile((yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0])); }
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 163 "parse.y" /* yacc.c:1646  */
    { printdebug( "8 statement\n" ); (yyval) = makerepeat((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 164 "parse.y" /* yacc.c:1646  */
    { printdebug( "9 statement\n" ); (yyval) = makefuncall((yyvsp[-2]), (yyvsp[-3]), (yyvsp[-1])); }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 165 "parse.y" /* yacc.c:1646  */
    { printdebug( "A statement\n" ); }
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 167 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 statement_list\n" ); (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 168 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 statement_list\n" ); }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 170 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 endpart\n" ); (yyval) = cons((yyvsp[-1]), (yyvsp[0])); }
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 171 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 endpart\n" ); (yyval) = NULL; }
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 173 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 endif\n" ); (yyval) = (yyvsp[0]); }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 174 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 endif\n" ); (yyval) = NULL; }
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 176 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 assignment\n" ); (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 178 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 expr_list\n" ); (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 179 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 expr_list\n" ); }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 181 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 expression\n" ); (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 182 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 expression\n" ); (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 183 "parse.y" /* yacc.c:1646  */
    { printdebug( "3 expression\n" ); }
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 185 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 simple_expression\n" ); (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 186 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 simple_expression\n" ); }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 187 "parse.y" /* yacc.c:1646  */
    { printdebug( "3 simple_expression\n" ); (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 188 "parse.y" /* yacc.c:1646  */
    { printdebug( "4 simple_expression\n" ); }
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 190 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 term\n" ); (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 191 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 term\n" ); }
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 193 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 factor\n" ); (yyval) = (yyvsp[-1]); }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 194 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 factor FUNCTION\n" ); (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 195 "parse.y" /* yacc.c:1646  */
    { printdebug( "3 factor FUNCTION\n" ); (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 196 "parse.y" /* yacc.c:1646  */
    { printdebug( "4 factor\n" ); }
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 197 "parse.y" /* yacc.c:1646  */
    { printdebug( "5 factor\n" ); }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 198 "parse.y" /* yacc.c:1646  */
    { printdebug( "6 factor\n" ); }
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 199 "parse.y" /* yacc.c:1646  */
    { printdebug( "7 factor\n" ); (yyval) = convertnil((yyvsp[0])); }
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 201 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 args\n" ); (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 202 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 args\n" ); (yyval) = cons((yyvsp[0]), NULL); }
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 204 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 compare_op\n" ); }
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 205 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 compare_op\n" ); }
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 206 "parse.y" /* yacc.c:1646  */
    { printdebug( "3 compare_op\n" ); }
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 207 "parse.y" /* yacc.c:1646  */
    { printdebug( "4 compare_op\n" ); }
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 208 "parse.y" /* yacc.c:1646  */
    { printdebug( "5 compare_op\n" ); }
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 209 "parse.y" /* yacc.c:1646  */
    { printdebug( "6 compare_op\n" ); }
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 210 "parse.y" /* yacc.c:1646  */
    { printdebug( "7 compare_op\n" ); }
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 212 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 sign\n" ); }
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 213 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 sign\n" ); }
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 215 "parse.y" /* yacc.c:1646  */
    { printdebug( "1 times_op\n" ); }
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 216 "parse.y" /* yacc.c:1646  */
    { printdebug( "2 times_op\n" ); }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2099 "y.tab.c" /* yacc.c:1646  */
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
#line 218 "parse.y" /* yacc.c:1906  */


/* You should add your own debugging flags below, and add debugging
   printouts to your programs.

   You will want to change DEBUG to turn off printouts once things
   are working.
  */

#define DEBUG 0
typedef enum {false, true} bool;
int labels[50];          //max labels
int labelnumber = 0;  /* sequential counter for internal label numbers */

   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */

TOKEN cons(TOKEN item, TOKEN list) {
  
  printdebug( "cons()\n" );
  item->link = list;
  if( DEBUG ) {
    printdebug( "cons\n" );
    dbugprinttok(item);
    dbugprinttok(list);
  };
  printdebug( "cons() ends \n\n" );
  return item;

}

TOKEN unaryop(TOKEN op, TOKEN lhs) {
  
  printdebug( "unaryop()\n" );
  op->operands = lhs;
  lhs->link = NULL;
  
  printdebug( "unaryop() ends \n\n" );
  return op;

}
TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs) { 
  
  printdebug( "binop()\n" );
  op->operands = lhs;          /* link operands to operator       */
  lhs->link = rhs;             /* link second operand to first    */
  rhs->link = NULL;            /* terminate operand list          */
  if( DEBUG ){ 
    dbugprinttok(op);
    dbugprinttok(lhs);
    dbugprinttok(rhs);
  }
  printdebug( "binop() ends \n\n" );
  return op;

}
TOKEN findid(TOKEN tok){
  
  printdebug( "findid()\n" );
  SYMBOL sym, typ;
  sym = searchst(tok->stringval);

  if(sym->kind != CONSTSYM){ //from project 3
    tok->symentry = sym;
    typ = sym->datatype;
    tok->symtype = typ;

    if (typ->kind == BASICTYPE || typ->kind == POINTERSYM)
      tok->datatype = typ->basicdt;
  }
  else { //sym->kind == CONSTSYM
    tok->tokentype = NUMBERTOK;

    if(sym->basicdt ==0){           //INTEGER
      tok->datatype = INTEGER;
      tok->intval = sym->constval.intnum;
    }
    else if (sym->basicdt == 1) {     //REAL
      tok->datatype = REAL;
      tok->realval = sym->constval.realnum;
    }
  }
  if (DEBUG) { 
    dbugprinttok(tok);
  }

  printdebug( "findid() ends \n\n" );
  return tok;

}
void instvars(TOKEN id_list, TOKEN typetok) {
 
  printdebug( "instvars() \n" );

  SYMBOL sym, typesym;
  typesym = typetok->symtype;

  int align = 0;
  if (typesym->size > 4)
    align = 16;
  else
    align = alignsize(typesym);

  while (id_list != NULL) {
    sym = insertsym(id_list->stringval);
    sym->kind = VARSYM;
    sym->offset = wordaddress(blockoffs[blocknumber], align);
    sym->size = typesym->size;
    blockoffs[blocknumber] = sym->offset + sym->size;
    sym->datatype = typesym;
    sym->basicdt = typesym->basicdt;
    id_list = id_list->link;
  }
  printdebug( "instvars() ends \n\n" );

}
void instconst(TOKEN idtok, TOKEN consttok) {
  
  printdebug( "instconst()\n" );

  SYMBOL sym, typesym;
  
  sym = insertsym(idtok->stringval);
  sym->kind = CONSTSYM;

  sym->basicdt = consttok->datatype;

  //INTEGER
  if(sym->basicdt == 0){
    sym->size = 4;
    sym->constval.intnum = consttok-> intval;
  }
  //REAL
  else if (sym->basicdt == 1){  
    sym->size = 8;
    sym->constval.realnum = consttok-> realval;
  }

  if (DEBUG) { 
    dbugprinttok(idtok);
    dbugprinttok(consttok);
  }
  printdebug( "instconst() ends \n\n" );

}
TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart) {
  
  printdebug( "makeif()\n" );
  tok->tokentype = OPERATOR;
  tok->whichval = IFOP;
  if (elsepart != NULL) elsepart->link = NULL;
  thenpart->link = elsepart;
  exp->link = thenpart;
  tok->operands = exp;
  if (DEBUG) {
    dbugprinttok(tok);
    dbugprinttok(exp);
    dbugprinttok(thenpart);
    dbugprinttok(elsepart);
  };
  printdebug( "makeif() ends \n\n" );
  return tok;

}
TOKEN makeprogn(TOKEN tok, TOKEN statements) {
 
  printdebug( "makeprogn()\n" );
  tok->tokentype = OPERATOR;
  tok->whichval = PROGNOP;
  tok->operands = statements;
  if (DEBUG) {
    printdebug( "makeprogn\n" );
    dbugprinttok(tok);
    dbugprinttok(statements);
    ppexpr(tok);
  };
  printdebug( "makeprogn() ends \n\n" );
  return tok;

}
TOKEN makelabel() {
  
  printdebug( "makelabel()\n" );
  TOKEN tok = talloc();
  tok->tokentype = OPERATOR;
  tok->whichval = LABELOP;
  tok->operands = makeintc(labelnumber);
  labelnumber += 1;
  
  printdebug( "makelabel() ends \n\n" );
  return tok;

}
TOKEN makegoto(int label) {
 
  printdebug( "makegoto()\n" );
  TOKEN gotoTok = talloc();
  gotoTok->tokentype = OPERATOR;
  gotoTok->whichval = GOTOOP;
  gotoTok->operands = makeintc(labelnumber - 1);
  
  printdebug( "makegoto() ends \n\n" );
  return gotoTok;

}
TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args) {
  
  printdebug( "makefuncall() with args\n" );
  if( DEBUG )
    ppexpr(args);

  tok->tokentype = OPERATOR;
  tok->whichval = FUNCALLOP;

  fn->link = args;
  tok->operands = fn;

  printdebug( "makefuncall() ends \n\n" );
  return tok;

}
TOKEN makeintc(int num) {
  
  printdebug( "makeintc()\n" );
  
  TOKEN tmp = talloc();
  tmp->tokentype = NUMBERTOK;
  tmp->datatype = INTEGER;
  tmp->intval = num;
  
  printdebug( "makeintc() ends \n\n" );
  return tmp;

}
TOKEN makeprogram(TOKEN name, TOKEN args, TOKEN statements) {
 
  printdebug( "makeprogram()" );
  if( DEBUG ){
    printf(" with args:\n\t" );
    ppexpr(args);
  }
  else
    printdebug( "\n" );

  TOKEN program = talloc();
  TOKEN tmpArgs = talloc();
  program->tokentype = OPERATOR;
  program->whichval = PROGRAMOP;
  program->operands = name;
  
  tmpArgs->tokentype = OPERATOR;
  tmpArgs->whichval = PROGNOP;
  name->link = tmpArgs;

  tmpArgs->operands = args;
  tmpArgs->link = statements;
  
  printdebug( "makeprogram() ends \n\n" );
  return program;

}
TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr, TOKEN tokc, TOKEN statement) {

  printdebug( "makefor() \n\t" );

  tok->tokentype = OPERATOR;
  tok->whichval = PROGNOP;
  tok->operands = asg;

  tokb->tokentype = OPERATOR;
  tokb->whichval = LABELOP;
  asg->link=tokb;
  
  TOKEN tok1 = talloc();
  tok1->tokentype = NUMBERTOK;
  tok1->datatype = INTEGER;
  labelnumber+=1;
  tok1->intval = labelnumber; 
  
  tokb->operands = tok1;
  tokc->tokentype = OPERATOR;
  tokc->whichval = IFOP;
  tokb->link = tokc;
  
  TOKEN tok2 = talloc();
  tok2->tokentype = OPERATOR;
  tok2->whichval = LEOP;
  tokc->operands = tok2;

  TOKEN tok3 = talloc();
  tok3->tokentype = asg->operands->tokentype;
  strcpy (tok3->stringval,asg->operands->stringval);
  tok3->link = endexpr;
  tok2->operands = tok3;
  
  TOKEN tok4 = talloc();
  tok4->tokentype = OPERATOR;
  tok4->whichval = PROGNOP;
  tok2->link = tok4;
  tok4->operands = statement;

  TOKEN tok5 = talloc();
  tok5->tokentype = OPERATOR;
  tok5->whichval = ASSIGNOP;
  statement->link = tok5;

  TOKEN tok6 = talloc();
  tok6->tokentype = asg->operands->tokentype;
  strcpy (tok6->stringval,asg->operands->stringval);
  tok5->operands = tok6;
  
  TOKEN tok7 = talloc();
  tok7->tokentype = OPERATOR;
  tok7->whichval = PLUSOP;
  tok6->link = tok7;

  TOKEN tok8 = talloc();
  tok8->tokentype = asg->operands->tokentype;
  strcpy (tok8->stringval,asg->operands->stringval);
  tok7->operands = tok8;

  TOKEN tok9 = talloc();
  tok9->tokentype = NUMBERTOK;
  tok9->datatype = INTEGER;
  tok9->intval = 1;
  tok8->link = tok9;

  TOKEN tokA = talloc();
  tokA->tokentype = OPERATOR;
  tokA->whichval = GOTOOP;
  tok5->link = tokA;

  TOKEN tokB = talloc();
  tokB->tokentype = NUMBERTOK;
  tokB->datatype = INTEGER;
  tokB->intval = labelnumber;
  tokA->operands = tokB;
  
  if (DEBUG){ 
    printdebug( "makefor\n" );
    dbugprinttok(tok);
    dbugprinttok(asg);
    dbugprinttok(tokb);
    dbugprinttok(endexpr);
    dbugprinttok(tokc);
    dbugprinttok(statement);
    ppexpr(tok);
  }
   
  printdebug( "makefor() ends \n\n" );
  return tok;

}
TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokxzczxv, TOKEN expr) {
 
  printdebug( "makerepeat() \n" );

  TOKEN tok1 = talloc();
  tok1->tokentype = OPERATOR;
  tok1->whichval = PROGNOP;
  
  TOKEN tok2 = talloc();
  tok2->tokentype = OPERATOR;
  tok2->whichval = LABELOP;
  
  TOKEN tok3 = talloc();    //int
  tok3->tokentype = NUMBERTOK;
  tok3->datatype = INTEGER;
  int lbl = labelnumber++;
  tok3->intval = lbl;
  
  tok1->operands = tok2;
  tok2->operands = tok3;
  tok2->link= statements; 

  if( DEBUG ){
    printdebug( "tok1: \n\t" );
    ppexpr(tok1);
  }
  
  TOKEN tok4 = talloc();
  tok4->tokentype = OPERATOR;
  tok4->whichval = IFOP;
  statements->link = tok4;  
  tok4->operands = expr;
  
  TOKEN tok5 = talloc();
  tok5->tokentype = OPERATOR;
  tok5->whichval = PROGNOP;
  expr->link = tok5;
  

  TOKEN tok6 = talloc();
  tok6->tokentype = OPERATOR;
  tok6->whichval = GOTOOP;
  tok5->link = tok6;
  

  TOKEN tok7 = talloc();
  tok7->tokentype = NUMBERTOK;
  tok7->datatype = INTEGER;
  tok7->intval = lbl;
  tok6->operands = tok7;

  if(DEBUG){
    printdebug( "tok1: \n\t" );
    ppexpr(tok1);
  }
  printdebug( "makerepeat() ends \n\n" );
  return tok1;

}
TOKEN findtype(TOKEN tok) {
 
  printdebug( "findtype() \n" );

  SYMBOL sym;
  sym = searchst(tok->stringval); 
  
  if(sym->kind == TYPESYM){
    printdebug( "TYPESYM \n" );
    tok->symtype = sym->datatype;
  }
  else if(sym->kind == BASICTYPE ) {
    printdebug( "BASICTYPE \n" );
    tok->symtype = sym; 
    tok->datatype = sym->basicdt;    
  }
  else
    printdebug( "findtype() ERROR \n" );
  

  printdebug( "findtype() ends \n\n" );
  return tok;

}

/*
  *
  *
  *     ASSIGNMENT 5
  *
  *
*/

TOKEN nconc(TOKEN lista, TOKEN listb) {
  
  printdebug( "nconc() \n" );
  TOKEN tmp = lista;
  while( tmp->link )
    tmp = tmp->link;
  tmp->link = listb;

  printdebug( "nconc() ends \n\n" );
  return lista;
  
}
TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement) {
  
  printdebug( "makewhile() \n" );
  TOKEN labeltok = talloc();
  labeltok->tokentype = OPERATOR;
  labeltok->whichval = LABELOP;

  TOKEN numtok = talloc();
  numtok->tokentype = NUMBERTOK;
  numtok->intval = labelnumber++;
  labeltok->operands = numtok;

  TOKEN progntok = makeprogn(tok, labeltok);

  TOKEN iftok = talloc();
  iftok->tokentype = OPERATOR;
  iftok->whichval = IFOP;

  TOKEN iftest = unaryop(iftok, expr);
  labeltok->link = iftok;
  iftest->operands->link = statement;

  TOKEN tmp = statement->operands;
  while(tmp->link)
    tmp = tmp->link;
  
  TOKEN gototok = talloc();
  gototok->tokentype = OPERATOR;
  gototok->whichval = GOTOOP;

  TOKEN gotonum = copytok(numtok);
  tmp->link = unaryop(gototok, gotonum);

  printdebug( "makewhile() ends \n\n" );
  return progntok;

}
TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field) {
  
  printdebug( "reducedot() \n" );
  SYMBOL record = var->symtype;
  bool p = false;
  
  if (record->kind == POINTERSYM) {
    record = record->datatype;
    record = stype(record);
    p = true;
  }

  int oldoff = 0;
  bool reuse = false;

  if (!p && var->tokentype == OPERATOR && var->operands->link->tokentype == NUMBERTOK && var->whichval == AREFOP) {
    dot = var;
    oldoff = var->operands->link->intval;
    reuse = true;
  }
  else 
    dot = createtok(OPERATOR,AREFOP);
  
  record = record->datatype;

  while ( record != NULL && strcmp(field->stringval, record->namestring) ) 
    record = record->link;
  
  dot->datatype = record->basicdt;
  int off = record->offset + oldoff;

  if( !p && off == 0 )
    return var;

  if ( !reuse )
    dot->operands = var;

  dot->operands->link = makeintc(off);
  dot->symtype = stype(record->datatype);
    
  printdebug( "reducedot() ends \n\n" );
  return dot;

}
TOKEN arrayref(TOKEN arr, TOKEN tok, TOKEN subs, TOKEN tokb) {
  
  printdebug( "arrayref() \n" );
  int index = 0;
  int offset = 0;
  SYMBOL array = arr->symtype;
  TOKEN offsetTok = NULL;
  TOKEN last = NULL;

  while(subs != NULL) {
    TOKEN link = subs->link;
    int size = array->datatype->size;

    TOKEN mult = binop( createtok(OPERATOR,TIMESOP), makeintc(size), subs );
    TOKEN add = binop( createtok(OPERATOR,PLUSOP), makeintc(-size * array->lowbound), mult );

    if(offsetTok != NULL) {
      TOKEN addlast = binop(createtok(OPERATOR,PLUSOP), offsetTok, add);
      offsetTok = addlast;
    }
    else
      offsetTok = add;
    
    array = array->datatype;
    subs = link;
  }

  TOKEN ret = createtok( OPERATOR,AREFOP );
  array = stype( array );
  ret->operands = arr;
  ret->operands->link = offsetTok;
  ret->symtype = array;

  printdebug( "arrayref() ends \n\n" );
  return ret;

}
SYMBOL stype(SYMBOL sym) {
  
  printdebug( "stype() \n" );
  while(sym->kind == TYPESYM)
    sym = sym->datatype;
  
  printdebug( "stype() ends \n\n" );
  return sym;

}
TOKEN copytok(TOKEN tok) {

  printdebug( "copytok() \n" );
  TOKEN ret = talloc();
  *ret = *tok;
  ret->operands = NULL;
  ret->link = NULL;

  printdebug( "copytok() ends \n\n" );
  return ret;

}
TOKEN createtok(int what, int which) {
  
  printdebug( "createtok() \n" );
  TOKEN ret = talloc();
  ret->tokentype = what;
  ret->whichval = which;
  printdebug( "createtok() ends \n\n" );
  return ret;

}
TOKEN instrec(TOKEN rectok, TOKEN argstok) {
  
  printdebug( "instrec() \n" );
  
  SYMBOL tmptab[50];
  TOKEN tmp = argstok;
  
  while(tmp)
    tmp = tmp->link;
  
  SYMBOL tmptable[50];              
  SYMBOL record = makesym( "record" );
  record->kind = RECORDSYM;
  int size = 0;
  
  SYMBOL sym, typesym; 
  int align;
  
  tmp = argstok;
  SYMBOL first;
  typesym = tmp->symtype;
  align = alignsize(typesym);
  int index = 0;
  
  while(tmp) {
    sym = makesym(tmp->stringval);
    if( index == 0 )
      first = sym;
    sym->datatype = tmp->symtype;
    sym->offset += size;
    sym->size = tmp->symtype->size;

    if( (size % 8 != 0) && (tmp->symtype->size == 8) )
      size += 4;
    
    size += tmp->symtype->size;
    tmptab[index] = sym;    
    tmp = tmp->link;
  
    index++;
  }
  
  int i;
  for(i = 0; i < index - 1; i++){
    tmptab[i]->link = tmptab[i+1];
  }
  
  record->datatype = first;
  record->size = size;
  
  rectok->symtype = record;     
  printdebug( "instrec() ends \n\n" );
  return rectok;

}
TOKEN dopoint(TOKEN var, TOKEN tok) {
  
  printdebug( "dopoint() \n" );
  SYMBOL sym = var->symtype;

  tok = createtok(OPERATOR,POINTEROP);
  tok->operands = var;
  sym = stype(sym);
  tok->symtype = sym;

  printdebug( "dopoint() ends \n\n" );
  return tok;

}
TOKEN instfields(TOKEN idlist, TOKEN typetok) {
  
  printdebug( "instfields() \n" );
  TOKEN tmp = idlist;

  while(tmp){
    tmp->symtype = typetok->symtype;
    tmp = tmp->link;
  }
  
//  printf("%s\n", typetok->symtype->namestring);
  printdebug( "instfields() ends \n\n" );
  return idlist;

}
void insttype(TOKEN typename, TOKEN typetok) {
  
  printdebug( "insttype() \n" );

  SYMBOL tmp = searchst(typename->stringval);
  if(tmp) {
    printdebug( " yes!\n" );
    tmp->kind = TYPESYM;
    tmp->datatype = typetok->symtype;
    tmp->size = typetok->symtype->size;
    tmp->basicdt = typetok->symtype->basicdt;
  }
  else {
    printdebug( " no\n" );
    SYMBOL typesym = insertsym(typename->stringval);
    typesym->kind = TYPESYM;
    typesym->datatype = typetok->symtype;
    typesym->size = typetok->symtype->size;
    typesym->basicdt = typetok->symtype->basicdt;
  }

  printdebug( "insttype() ends \n\n" );

}
TOKEN instpoint(TOKEN tok, TOKEN typename) {
  
  printdebug( "instpoint() \n" );
  
  SYMBOL tsym = searchst(typename->stringval);
  if(DEBUG)
    printf("%s\n", typename->stringval);
  SYMBOL tmp = insertsym(typename->stringval);
  tmp->kind = TYPESYM;
  
  
  SYMBOL pointersym = makesym(typename->stringval);   
  pointersym->kind = POINTERSYM;
  pointersym->datatype = tmp;
  pointersym->size = basicsizes[POINTER];
  pointersym->basicdt = POINTER;
  
  if(DEBUG)
    printf("POINTER = %d\n", POINTER);
  
  tok->symtype = pointersym;
  
  if(DEBUG)
    printf("%d\n", tok->symtype->size);

  printdebug( "instpoint() ends \n\n" );
  return tok;

}
TOKEN instenum(TOKEN idlist) {

  printdebug( "instenum() \n" );
  int low = 0, high = 0;
  TOKEN tmp = idlist;
  
  while(tmp){
    tmp = tmp->link;
    high++;
  }
  
  TOKEN subrange = makesubrange(copytok(idlist), low, high - 1);
  
  tmp = idlist;
  TOKEN number = copytok(idlist);
  number->tokentype = NUMBERTOK;
  number->datatype = INTEGER;

  int i;
  for(i = 0; i < high; i++){
    number->intval = i;
    instconst(tmp, number);
    number = copytok(number);
    tmp = tmp->link;
  }
  printdebug( "instenum() ends \n\n" );
  return subrange;

}
TOKEN makesubrange(TOKEN tok, int low, int high){

  printdebug( "makesubrange() \n" );
  SYMBOL subrange = makesym("subrange" );
  subrange->kind = SUBRANGE;
  subrange->highbound = high;
  subrange->lowbound = low;
  subrange->basicdt = INTEGER;
  subrange->size = basicsizes[INTEGER];
  tok->symtype = subrange;
  tok->tokentype = NUMBERTOK;
  printdebug( "makesubrange() ends \n\n" );
  return tok;

}
TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement){
  
  printdebug( "dolabel() \n" );
  TOKEN progn = makeprogn(tok, statement);
  TOKEN label = talloc();
  label->tokentype = OPERATOR;
  label->whichval = LABELOP;
  label->operands = labeltok;

  int i = 0;
  while(labels[i] != labeltok->intval)
    i++;
  labeltok->intval = i;
  progn->operands = label;
  label->link = statement;
  printdebug( "dolabel() ends \n\n" );
  return progn;

}
void  instlabel (TOKEN num) {

  printdebug( "instlabel() \n" );
  labels[labelnumber++] = num->intval;
  
  int i;
  for(i = 0; i < labelnumber; i++)
    printf("%d\n", labels[i]);
  
  printdebug( "instlabel() ends \n\n" );

}
TOKEN instarray(TOKEN simpletypes, TOKEN typetok) {

  printdebug( "instarray() \n" );
  SYMBOL sym = instarrayhelper(simpletypes, typetok);

  TOKEN ret = talloc();
  ret->symtype = sym;
  printdebug( "instarray() ends \n\n" );
  return ret;

}
SYMBOL instarrayhelper(TOKEN simpletypes, TOKEN typetok) {
  
  printdebug( "instarrayhelper() \n" );
  if(simpletypes == NULL) 
    return typetok->symtype;

  SYMBOL sym = symalloc();
  SYMBOL simplesym = simpletypes->symtype;
  sym->kind = ARRAYSYM;

  if(simplesym->datatype != NULL) {
    sym->lowbound = simplesym->datatype->lowbound;
    sym->highbound = simplesym->datatype->highbound;
  }

  sym->datatype = instarrayhelper(simpletypes->link, typetok);
  sym->size = (sym->highbound - sym->lowbound + 1)*sym->datatype->size;
  printdebug( "instarrayhelper() ends \n\n" );
  return sym;

}
TOKEN convertnil(TOKEN nil) {

  printdebug( "convertnil() \n" );
  TOKEN zero = talloc();
  zero->tokentype = NUMBERTOK;
  zero->datatype = POINTER;
  zero->intval = 0;
  printdebug( "convertnil() ends \n\n" );
  return zero;

}

/*
  *
  *
  *     ORIGINAL CODE
  *
  *
*/

void printdebug (char arr[]) {
  
  char array[sizeof(arr) + 1];
  int i;
  for (i = 0; i < sizeof(arr); i++)
    array[i] = arr[i];
  array[sizeof(arr)] = '\0';

  if (DEBUG)
    printf("%s", arr);
  
}
int wordaddress(int n, int wordsize) {
  return ((n + wordsize - 1) / wordsize) * wordsize;
}
yyerror(s) char * s; {
  extern int yylineno;  // defined and maintained in lex
  extern char *yytext;  // defined and maintained in lex
  fprintf(stderr, "ERROR: %s at symbol '%s' on line %d\n", s, yytext, yylineno);
  fputs(s, stderr);
  putc('\n', stderr);
}
main() {
  int res;
  initsyms();
  res = yyparse();
  printst();
  printf("yyparse result = %8d\n", res);
  if (DEBUG) 
    dbugprinttok(parseresult);
  ppexpr(parseresult); /* Pretty-print the result tree */
}
