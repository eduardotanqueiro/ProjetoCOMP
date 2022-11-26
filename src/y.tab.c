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
#line 1 "jucompiler.y"

    //  Eduardo Carneiro - 2020240332
    //  Ricardo Silva - 2020227184
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "symbol_table.h"


int yylex (void);
extern void yyerror(char* s);
no* raiz;
no* tmp;



extern int line_num, col_num;
extern int flag_tree;

#line 92 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    ID = 258,                      /* ID  */
    INTLIT = 259,                  /* INTLIT  */
    REALLIT = 260,                 /* REALLIT  */
    BOOLLIT = 261,                 /* BOOLLIT  */
    STRLIT = 262,                  /* STRLIT  */
    PLUS = 263,                    /* PLUS  */
    AND = 264,                     /* AND  */
    ASSIGN = 265,                  /* ASSIGN  */
    STAR = 266,                    /* STAR  */
    DIV = 267,                     /* DIV  */
    EQ = 268,                      /* EQ  */
    GE = 269,                      /* GE  */
    GT = 270,                      /* GT  */
    LE = 271,                      /* LE  */
    LT = 272,                      /* LT  */
    MINUS = 273,                   /* MINUS  */
    MOD = 274,                     /* MOD  */
    NE = 275,                      /* NE  */
    NOT = 276,                     /* NOT  */
    OR = 277,                      /* OR  */
    PRINT = 278,                   /* PRINT  */
    DOTLENGTH = 279,               /* DOTLENGTH  */
    BOOL = 280,                    /* BOOL  */
    COMMA = 281,                   /* COMMA  */
    LBRACE = 282,                  /* LBRACE  */
    LPAR = 283,                    /* LPAR  */
    LSQ = 284,                     /* LSQ  */
    RBRACE = 285,                  /* RBRACE  */
    RPAR = 286,                    /* RPAR  */
    RSQ = 287,                     /* RSQ  */
    SEMICOLON = 288,               /* SEMICOLON  */
    ARROW = 289,                   /* ARROW  */
    LSHIFT = 290,                  /* LSHIFT  */
    RSHIFT = 291,                  /* RSHIFT  */
    XOR = 292,                     /* XOR  */
    CLASS = 293,                   /* CLASS  */
    DOUBLE = 294,                  /* DOUBLE  */
    ELSE = 295,                    /* ELSE  */
    IF = 296,                      /* IF  */
    INT = 297,                     /* INT  */
    PARSEINT = 298,                /* PARSEINT  */
    PUBLIC = 299,                  /* PUBLIC  */
    RETURN = 300,                  /* RETURN  */
    STATIC = 301,                  /* STATIC  */
    STRING = 302,                  /* STRING  */
    VOID = 303,                    /* VOID  */
    WHILE = 304,                   /* WHILE  */
    RESERVED = 305                 /* RESERVED  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define INTLIT 259
#define REALLIT 260
#define BOOLLIT 261
#define STRLIT 262
#define PLUS 263
#define AND 264
#define ASSIGN 265
#define STAR 266
#define DIV 267
#define EQ 268
#define GE 269
#define GT 270
#define LE 271
#define LT 272
#define MINUS 273
#define MOD 274
#define NE 275
#define NOT 276
#define OR 277
#define PRINT 278
#define DOTLENGTH 279
#define BOOL 280
#define COMMA 281
#define LBRACE 282
#define LPAR 283
#define LSQ 284
#define RBRACE 285
#define RPAR 286
#define RSQ 287
#define SEMICOLON 288
#define ARROW 289
#define LSHIFT 290
#define RSHIFT 291
#define XOR 292
#define CLASS 293
#define DOUBLE 294
#define ELSE 295
#define IF 296
#define INT 297
#define PARSEINT 298
#define PUBLIC 299
#define RETURN 300
#define STATIC 301
#define STRING 302
#define VOID 303
#define WHILE 304
#define RESERVED 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 75 "jucompiler.y"

    info* info;
    no* node;

#line 250 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INTLIT = 4,                     /* INTLIT  */
  YYSYMBOL_REALLIT = 5,                    /* REALLIT  */
  YYSYMBOL_BOOLLIT = 6,                    /* BOOLLIT  */
  YYSYMBOL_STRLIT = 7,                     /* STRLIT  */
  YYSYMBOL_PLUS = 8,                       /* PLUS  */
  YYSYMBOL_AND = 9,                        /* AND  */
  YYSYMBOL_ASSIGN = 10,                    /* ASSIGN  */
  YYSYMBOL_STAR = 11,                      /* STAR  */
  YYSYMBOL_DIV = 12,                       /* DIV  */
  YYSYMBOL_EQ = 13,                        /* EQ  */
  YYSYMBOL_GE = 14,                        /* GE  */
  YYSYMBOL_GT = 15,                        /* GT  */
  YYSYMBOL_LE = 16,                        /* LE  */
  YYSYMBOL_LT = 17,                        /* LT  */
  YYSYMBOL_MINUS = 18,                     /* MINUS  */
  YYSYMBOL_MOD = 19,                       /* MOD  */
  YYSYMBOL_NE = 20,                        /* NE  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_OR = 22,                        /* OR  */
  YYSYMBOL_PRINT = 23,                     /* PRINT  */
  YYSYMBOL_DOTLENGTH = 24,                 /* DOTLENGTH  */
  YYSYMBOL_BOOL = 25,                      /* BOOL  */
  YYSYMBOL_COMMA = 26,                     /* COMMA  */
  YYSYMBOL_LBRACE = 27,                    /* LBRACE  */
  YYSYMBOL_LPAR = 28,                      /* LPAR  */
  YYSYMBOL_LSQ = 29,                       /* LSQ  */
  YYSYMBOL_RBRACE = 30,                    /* RBRACE  */
  YYSYMBOL_RPAR = 31,                      /* RPAR  */
  YYSYMBOL_RSQ = 32,                       /* RSQ  */
  YYSYMBOL_SEMICOLON = 33,                 /* SEMICOLON  */
  YYSYMBOL_ARROW = 34,                     /* ARROW  */
  YYSYMBOL_LSHIFT = 35,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 36,                    /* RSHIFT  */
  YYSYMBOL_XOR = 37,                       /* XOR  */
  YYSYMBOL_CLASS = 38,                     /* CLASS  */
  YYSYMBOL_DOUBLE = 39,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 40,                      /* ELSE  */
  YYSYMBOL_IF = 41,                        /* IF  */
  YYSYMBOL_INT = 42,                       /* INT  */
  YYSYMBOL_PARSEINT = 43,                  /* PARSEINT  */
  YYSYMBOL_PUBLIC = 44,                    /* PUBLIC  */
  YYSYMBOL_RETURN = 45,                    /* RETURN  */
  YYSYMBOL_STATIC = 46,                    /* STATIC  */
  YYSYMBOL_STRING = 47,                    /* STRING  */
  YYSYMBOL_VOID = 48,                      /* VOID  */
  YYSYMBOL_WHILE = 49,                     /* WHILE  */
  YYSYMBOL_RESERVED = 50,                  /* RESERVED  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_Program = 52,                   /* Program  */
  YYSYMBOL_MethodFieldSemicolonRep = 53,   /* MethodFieldSemicolonRep  */
  YYSYMBOL_MethodDecl = 54,                /* MethodDecl  */
  YYSYMBOL_FieldDecl = 55,                 /* FieldDecl  */
  YYSYMBOL_CommaIdRep = 56,                /* CommaIdRep  */
  YYSYMBOL_Type = 57,                      /* Type  */
  YYSYMBOL_MethodHeader = 58,              /* MethodHeader  */
  YYSYMBOL_FormalParams = 59,              /* FormalParams  */
  YYSYMBOL_CommaTypeIdRep = 60,            /* CommaTypeIdRep  */
  YYSYMBOL_MethodBody = 61,                /* MethodBody  */
  YYSYMBOL_StatementVarRep = 62,           /* StatementVarRep  */
  YYSYMBOL_VarDecl = 63,                   /* VarDecl  */
  YYSYMBOL_Statement = 64,                 /* Statement  */
  YYSYMBOL_StatementRep = 65,              /* StatementRep  */
  YYSYMBOL_MethodInvocation = 66,          /* MethodInvocation  */
  YYSYMBOL_CommaExprRep = 67,              /* CommaExprRep  */
  YYSYMBOL_Assignment = 68,                /* Assignment  */
  YYSYMBOL_ParseArgs = 69,                 /* ParseArgs  */
  YYSYMBOL_Expr = 70,                      /* Expr  */
  YYSYMBOL_ExprOp = 71                     /* ExprOp  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   381

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    86,    87,    88,    89,    93,    96,   109,
     111,   112,   116,   117,   118,   120,   125,   130,   134,   139,
     140,   142,   143,   146,   148,   149,   150,   153,   166,   167,
     222,   247,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   275,   280,   283,   285,   291,   295,   301,   305,   307,
     308,   311,   312,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INTLIT",
  "REALLIT", "BOOLLIT", "STRLIT", "PLUS", "AND", "ASSIGN", "STAR", "DIV",
  "EQ", "GE", "GT", "LE", "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PRINT",
  "DOTLENGTH", "BOOL", "COMMA", "LBRACE", "LPAR", "LSQ", "RBRACE", "RPAR",
  "RSQ", "SEMICOLON", "ARROW", "LSHIFT", "RSHIFT", "XOR", "CLASS",
  "DOUBLE", "ELSE", "IF", "INT", "PARSEINT", "PUBLIC", "RETURN", "STATIC",
  "STRING", "VOID", "WHILE", "RESERVED", "$accept", "Program",
  "MethodFieldSemicolonRep", "MethodDecl", "FieldDecl", "CommaIdRep",
  "Type", "MethodHeader", "FormalParams", "CommaTypeIdRep", "MethodBody",
  "StatementVarRep", "VarDecl", "Statement", "StatementRep",
  "MethodInvocation", "CommaExprRep", "Assignment", "ParseArgs", "Expr",
  "ExprOp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-47)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-43)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -33,     7,    27,    10,   -47,     2,    11,     2,     4,    66,
       2,     2,   -47,   -47,    14,   -47,   -47,   -47,   -47,   -47,
     -47,    96,    98,    81,    83,    29,   124,   -47,    95,   106,
     334,    84,    86,    21,    90,   129,   -47,   110,   111,   178,
     112,   121,   113,   124,   124,   108,   117,   125,   -47,   116,
     157,   130,   138,   -47,   137,   -47,   -47,    79,    85,   212,
     129,   141,    79,    91,    19,   -47,   -47,   -47,   220,   220,
     220,   186,   -47,   -47,   -47,   -47,   143,   253,    79,   138,
     -47,   -47,   -47,   -47,   -47,   -47,   145,   154,   -47,   -47,
     -47,   -47,   167,   -47,   162,   169,   171,   -47,   -47,   172,
     174,   179,   -47,   -12,   -47,   -47,   -47,   181,   182,   -47,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   191,   176,   207,    56,
     -47,   -47,    79,   196,   198,   201,   152,   -47,    79,   -47,
     -47,    -4,   296,   -47,   -47,   339,   224,   224,   224,   224,
      -4,   -47,   339,   283,    40,    40,   326,   152,   -47,   -47,
     234,   162,   -47,   -47,   -47,   199,   213,   -47,   154,   -47,
     152,   215,   -47,   -47,   -47
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     9,     5,     0,     2,     3,     4,    12,    14,
      13,     0,     0,     0,     0,    11,     0,     7,     0,     0,
       0,     0,     0,     0,     0,     0,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,    11,    17,     0,     8,    40,     0,     0,     0,
       0,     0,     0,     0,    56,    58,    59,    60,     0,     0,
       0,     0,    33,    54,    52,    55,     0,    51,     0,    11,
      23,    25,    24,    36,    37,    38,     0,    22,    16,    10,
      15,    48,     0,    43,    47,     0,     0,    41,    28,     0,
       0,     0,    57,    56,    63,    61,    62,     0,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    45,     0,     0,     0,     0,     0,    50,     0,    80,
      53,    64,    69,    66,    67,    74,    75,    76,    77,    78,
      65,    68,    79,    70,    72,    73,    71,     0,    27,    20,
       0,    47,    44,    35,    34,    30,     0,    31,    22,    46,
       0,     0,    21,    29,    49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -47,   -47,    53,   -47,   -47,   -46,     0,   -47,   214,    82,
     -47,    61,   -47,   -34,   187,   -26,    88,   -24,   -22,   -17,
     -45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    10,    11,    31,    41,    23,    51,   130,
      27,    42,    43,    44,    61,    73,   133,    74,    75,    76,
      77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    60,    46,     6,    47,     1,    89,   112,   113,    45,
       3,    46,   102,    47,    22,   120,    58,    45,    45,    46,
      46,    47,    47,   104,   105,   106,    60,     4,    50,    57,
      50,    57,    -6,   127,    45,     7,    46,     5,    47,    18,
      91,    94,    96,   102,    12,    99,     8,    58,   110,    58,
      14,   112,   113,    19,   108,    29,    20,    30,   119,   120,
      13,   126,    21,    16,    17,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,    18,    64,    65,    66,    67,    92,    68,    64,    65,
      66,    67,   100,    68,   101,    19,    15,    69,    20,    24,
      70,    25,   165,    69,    81,    82,    70,    71,    26,    52,
      45,    28,    46,    71,    47,   161,    93,    55,    59,    56,
      18,   166,    38,   167,    79,    32,    48,    33,    38,   160,
      32,    45,    33,    46,    19,    47,   173,    20,    62,    63,
      78,    83,    49,    80,    45,    86,    46,    34,    47,    18,
      84,    35,    34,    32,   -26,    33,    35,    36,    85,   -42,
      87,    88,    36,    19,    29,    37,    20,    38,    90,    39,
      37,    98,    38,    40,    39,    34,   109,   128,    40,    35,
     129,    64,    65,    66,    67,    36,    68,   107,   132,    64,
      65,    66,    67,    37,    68,    38,    69,    39,   131,    70,
     134,    40,   135,   136,    69,   137,    71,    70,   138,   158,
     159,    72,   139,   140,    71,    64,    65,    66,    67,    95,
      68,    38,   157,   103,    65,    66,    67,   162,    68,    38,
      69,   163,   110,    70,   164,   112,   113,   168,    69,   170,
      71,    70,   119,   120,    54,   171,   174,    97,    71,   169,
     172,     0,     0,     0,     0,    38,     0,     0,     0,   123,
     124,   110,   111,    38,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,     0,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,   124,
     125,   110,   111,     0,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   110,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   123,   124,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,   124,   125,   110,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   110,     0,     0,
     112,   113,     0,   115,   116,   117,   118,   119,   120,    18,
       0,   123,   124,     0,     0,    53,     0,     0,     0,     0,
       0,     0,     0,    19,   123,   124,    20,     0,     0,     0,
       0,    49
};

static const yytype_int16 yycheck[] =
{
      26,    35,    26,     1,    26,    38,    52,    11,    12,    35,
       3,    35,    24,    35,    14,    19,    28,    43,    44,    43,
      44,    43,    44,    68,    69,    70,    60,     0,    28,    10,
      30,    10,    30,    79,    60,    33,    60,    27,    60,    25,
      57,    58,    59,    24,    33,    62,    44,    28,     8,    28,
      46,    11,    12,    39,    71,    26,    42,    28,    18,    19,
       7,    78,    48,    10,    11,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    25,     3,     4,     5,     6,     1,     8,     3,     4,
       5,     6,     1,     8,     3,    39,    30,    18,    42,     3,
      21,     3,   136,    18,    43,    44,    21,    28,    27,     3,
     136,    28,   136,    28,   136,   132,    31,    33,    28,    33,
      25,   138,    43,   157,     3,     1,    31,     3,    43,   129,
       1,   157,     3,   157,    39,   157,   170,    42,    28,    28,
      28,    33,    47,    30,   170,    29,   170,    23,   170,    25,
      33,    27,    23,     1,    30,     3,    27,    33,    33,    30,
       3,    31,    33,    39,    26,    41,    42,    43,    31,    45,
      41,    30,    43,    49,    45,    23,    33,    32,    49,    27,
      26,     3,     4,     5,     6,    33,     8,     1,    26,     3,
       4,     5,     6,    41,     8,    43,    18,    45,    31,    21,
      31,    49,    31,    31,    18,    31,    28,    21,    29,    33,
       3,    33,    31,    31,    28,     3,     4,     5,     6,     7,
       8,    43,    31,     3,     4,     5,     6,    31,     8,    43,
      18,    33,     8,    21,    33,    11,    12,     3,    18,    40,
      28,    21,    18,    19,    30,    32,    31,    60,    28,   161,
     168,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    35,
      36,     8,     9,    43,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,     8,     9,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     8,    -1,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,     8,    -1,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     8,    -1,    -1,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    25,
      -1,    35,    36,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    35,    36,    42,    -1,    -1,    -1,
      -1,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    52,     3,     0,    27,     1,    33,    44,    53,
      54,    55,    33,    53,    46,    30,    53,    53,    25,    39,
      42,    48,    57,    58,     3,     3,    27,    61,    28,    26,
      28,    56,     1,     3,    23,    27,    33,    41,    43,    45,
      49,    57,    62,    63,    64,    66,    68,    69,    31,    47,
      57,    59,     3,    31,    59,    33,    33,    10,    28,    28,
      64,    65,    28,    28,     3,     4,     5,     6,     8,    18,
      21,    28,    33,    66,    68,    69,    70,    71,    28,     3,
      30,    62,    62,    33,    33,    33,    29,     3,    31,    56,
      31,    70,     1,    31,    70,     7,    70,    65,    30,    70,
       1,     3,    24,     3,    71,    71,    71,     1,    70,    33,
       8,     9,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    22,    35,    36,    37,    70,    56,    32,    26,
      60,    31,    26,    67,    31,    31,    31,    31,    29,    31,
      31,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    31,    33,     3,
      57,    70,    31,    33,    33,    64,    70,    64,     3,    67,
      40,    32,    60,    64,    31
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    57,    58,    58,    58,    58,    59,
      59,    60,    60,    61,    62,    62,    62,    63,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    65,    65,    66,    66,    66,    67,    67,    68,    69,
      69,    70,    70,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     2,     2,     0,     4,     6,     2,
       3,     0,     1,     1,     1,     5,     5,     4,     4,     3,
       4,     4,     0,     3,     2,     2,     0,     4,     3,     7,
       5,     5,     3,     2,     5,     5,     2,     2,     2,     1,
       2,     2,     0,     3,     5,     4,     3,     0,     3,     7,
       4,     1,     1,     3,     1,     1,     1,     2,     1,     1,
       1,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3
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
  case 2: /* Program: CLASS ID LBRACE MethodFieldSemicolonRep RBRACE  */
#line 83 "jucompiler.y"
                                                         {(yyval.node)=raiz=criar_no("Program",gen_token("",line_num, col_num)); (yyval.node)->filho = criar_no("Id",(yyvsp[-3].info)); adicionar_irmao((yyval.node)->filho, (yyvsp[-1].node));}
#line 1456 "y.tab.c"
    break;

  case 3: /* MethodFieldSemicolonRep: MethodDecl MethodFieldSemicolonRep  */
#line 86 "jucompiler.y"
                                                            {(yyval.node)=(yyvsp[-1].node); adicionar_irmao((yyval.node),(yyvsp[0].node));}
#line 1462 "y.tab.c"
    break;

  case 4: /* MethodFieldSemicolonRep: FieldDecl MethodFieldSemicolonRep  */
#line 87 "jucompiler.y"
                                                            {if((yyvsp[-1].node)!=NULL){(yyval.node)=(yyvsp[-1].node); adicionar_irmao((yyval.node),(yyvsp[0].node));}else (yyval.node)=(yyvsp[0].node);}
#line 1468 "y.tab.c"
    break;

  case 5: /* MethodFieldSemicolonRep: SEMICOLON MethodFieldSemicolonRep  */
#line 88 "jucompiler.y"
                                                            {(yyval.node)=(yyvsp[0].node);}
#line 1474 "y.tab.c"
    break;

  case 6: /* MethodFieldSemicolonRep: %empty  */
#line 89 "jucompiler.y"
                                                            {(yyval.node)=NULL;}
#line 1480 "y.tab.c"
    break;

  case 7: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 93 "jucompiler.y"
                                                  {(yyval.node)= criar_no("MethodDecl",gen_token("",line_num, col_num)); (yyval.node)->filho=(yyvsp[-1].node); adicionar_irmao((yyvsp[-1].node),(yyvsp[0].node));}
#line 1486 "y.tab.c"
    break;

  case 8: /* FieldDecl: PUBLIC STATIC Type ID CommaIdRep SEMICOLON  */
#line 96 "jucompiler.y"
                                                      {(yyval.node)=criar_no("FieldDecl",gen_token("",line_num, col_num)); (yyval.node)->filho=(yyvsp[-3].node); 
                                                                                    adicionar_irmao((yyvsp[-3].node),criar_no("Id",(yyvsp[-2].info))); 
                                                                                    if((yyvsp[-1].node)!=NULL){ //Verificar se há argumentos e, se sim, ir criar um nó fielddecl para cada arguento
                                                                                        tmp = (yyvsp[-1].node); 
                                                                                        while(tmp != NULL){ 
                                                                                            no* tmp1 = criar_no("FieldDecl",gen_token("",line_num, col_num));
                                                                                            no* tmp2 = criar_no((yyvsp[-3].node)->tipo,(yyvsp[-3].node)->info); 
                                                                                            tmp1->filho= tmp2; 
                                                                                            adicionar_irmao(tmp2,criar_no("Id",tmp->info)); 
                                                                                            adicionar_irmao((yyval.node),tmp1); 
                                                                                            tmp = tmp->irmao;
                                                                                        } 
                                                                                    };}
#line 1504 "y.tab.c"
    break;

  case 9: /* FieldDecl: error SEMICOLON  */
#line 109 "jucompiler.y"
                                                      {(yyval.node)=NULL;flag_tree=0;}
#line 1510 "y.tab.c"
    break;

  case 10: /* CommaIdRep: COMMA ID CommaIdRep  */
#line 111 "jucompiler.y"
                                {(yyval.node)=criar_no("Id",(yyvsp[-1].info)); adicionar_irmao((yyval.node),(yyvsp[0].node));}
#line 1516 "y.tab.c"
    break;

  case 11: /* CommaIdRep: %empty  */
#line 112 "jucompiler.y"
                                {(yyval.node)=NULL;}
#line 1522 "y.tab.c"
    break;

  case 12: /* Type: BOOL  */
#line 116 "jucompiler.y"
             {(yyval.node)=criar_no("Bool",gen_token("",line_num, col_num));}
#line 1528 "y.tab.c"
    break;

  case 13: /* Type: INT  */
#line 117 "jucompiler.y"
             {(yyval.node)=criar_no("Int",gen_token("",line_num, col_num));}
#line 1534 "y.tab.c"
    break;

  case 14: /* Type: DOUBLE  */
#line 118 "jucompiler.y"
             {(yyval.node)=criar_no("Double",gen_token("",line_num, col_num));}
#line 1540 "y.tab.c"
    break;

  case 15: /* MethodHeader: Type ID LPAR FormalParams RPAR  */
#line 120 "jucompiler.y"
                                                {(yyval.node)=criar_no("MethodHeader",gen_token("",line_num, col_num)); (yyval.node)->filho=(yyvsp[-4].node); //Cria-se o nó methodheader, adiciona-se filhos o type e o ID, cria-se o methodparams e colocam-se os formalparams como filhos do methodparams
                                                                                 adicionar_irmao((yyvsp[-4].node), criar_no("Id",(yyvsp[-3].info))); 
                                                                                 adicionar_irmao((yyvsp[-4].node), criar_no("MethodParams",gen_token("",line_num, col_num))); 
                                                                                 (yyvsp[-4].node)->irmao->irmao->filho=(yyvsp[-1].node);}
#line 1549 "y.tab.c"
    break;

  case 16: /* MethodHeader: VOID ID LPAR FormalParams RPAR  */
#line 125 "jucompiler.y"
                                                {(yyval.node)=criar_no("MethodHeader",gen_token("",line_num, col_num)); (yyval.node)->filho=criar_no("Void",gen_token("",line_num, col_num)); 
                                                                                 adicionar_irmao((yyval.node)->filho, criar_no("Id",(yyvsp[-3].info))); 
                                                                                 adicionar_irmao((yyval.node)->filho,criar_no("MethodParams",gen_token("",line_num, col_num))); 
                                                                                 (yyval.node)->filho->irmao->irmao->filho=(yyvsp[-1].node);}
#line 1558 "y.tab.c"
    break;

  case 17: /* MethodHeader: Type ID LPAR RPAR  */
#line 130 "jucompiler.y"
                                                {(yyval.node)=criar_no("MethodHeader",gen_token("",line_num, col_num)); (yyval.node)->filho=(yyvsp[-3].node); 
                                                                                 adicionar_irmao((yyvsp[-3].node), criar_no("Id",(yyvsp[-2].info))); 
                                                                                 adicionar_irmao((yyvsp[-3].node), criar_no("MethodParams",gen_token("",line_num, col_num)));}
#line 1566 "y.tab.c"
    break;

  case 18: /* MethodHeader: VOID ID LPAR RPAR  */
#line 134 "jucompiler.y"
                                                {(yyval.node)=criar_no("MethodHeader",gen_token("",line_num, col_num)); (yyval.node)->filho=criar_no("Void",gen_token("",line_num, col_num)); 
                                                                                 adicionar_irmao((yyval.node)->filho, criar_no("Id",(yyvsp[-2].info))); 
                                                                                 adicionar_irmao((yyval.node)->filho,criar_no("MethodParams",gen_token("",line_num, col_num)));}
#line 1574 "y.tab.c"
    break;

  case 19: /* FormalParams: Type ID CommaTypeIdRep  */
#line 139 "jucompiler.y"
                                     {(yyval.node)=criar_no("ParamDecl",gen_token("",line_num, col_num)); (yyval.node)->filho=(yyvsp[-2].node);adicionar_irmao((yyvsp[-2].node), criar_no("Id",(yyvsp[-1].info)));adicionar_irmao((yyval.node),(yyvsp[0].node));}
#line 1580 "y.tab.c"
    break;

  case 20: /* FormalParams: STRING LSQ RSQ ID  */
#line 140 "jucompiler.y"
                                     {(yyval.node)=criar_no("ParamDecl",gen_token("",line_num, col_num)); (yyval.node)->filho=criar_no("StringArray",gen_token("",line_num, col_num)); adicionar_irmao((yyval.node)->filho, criar_no("Id",(yyvsp[0].info)));}
#line 1586 "y.tab.c"
    break;

  case 21: /* CommaTypeIdRep: COMMA Type ID CommaTypeIdRep  */
#line 142 "jucompiler.y"
                                             {(yyval.node) = criar_no("ParamDecl",gen_token("",line_num, col_num)); (yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node),criar_no("Id",(yyvsp[-1].info))); adicionar_irmao((yyval.node),(yyvsp[0].node));}
#line 1592 "y.tab.c"
    break;

  case 22: /* CommaTypeIdRep: %empty  */
#line 143 "jucompiler.y"
                                             {(yyval.node)=NULL;}
#line 1598 "y.tab.c"
    break;

  case 23: /* MethodBody: LBRACE StatementVarRep RBRACE  */
#line 146 "jucompiler.y"
                                          {(yyval.node)=criar_no("MethodBody",gen_token("",line_num, col_num));(yyval.node)->filho=(yyvsp[-1].node);}
#line 1604 "y.tab.c"
    break;

  case 24: /* StatementVarRep: Statement StatementVarRep  */
#line 148 "jucompiler.y"
                                           {if((yyvsp[-1].node) != NULL){(yyval.node)=(yyvsp[-1].node); adicionar_irmao((yyval.node),(yyvsp[0].node));}else (yyval.node)=(yyvsp[0].node);}
#line 1610 "y.tab.c"
    break;

  case 25: /* StatementVarRep: VarDecl StatementVarRep  */
#line 149 "jucompiler.y"
                                           {(yyval.node)=(yyvsp[-1].node); adicionar_irmao((yyval.node),(yyvsp[0].node));}
#line 1616 "y.tab.c"
    break;

  case 26: /* StatementVarRep: %empty  */
#line 150 "jucompiler.y"
                                           {(yyval.node)=NULL;}
#line 1622 "y.tab.c"
    break;

  case 27: /* VarDecl: Type ID CommaIdRep SEMICOLON  */
#line 153 "jucompiler.y"
                                      {(yyval.node)=criar_no("VarDecl",gen_token("",line_num, col_num)); (yyval.node)->filho=(yyvsp[-3].node); 
                                                                  adicionar_irmao((yyvsp[-3].node), criar_no("Id",(yyvsp[-2].info))); 
                                                                  if((yyvsp[-1].node)!=NULL){ //Verificamos se existe mais do que uma declaração de variável, se sim cria-se um nó irmao do tipo VarDecl para cada variável
                                                                    tmp = (yyvsp[-1].node); 
                                                                    while(tmp != NULL){ 
                                                                        no* tmp1 = criar_no("VarDecl",gen_token("",line_num, col_num));
                                                                        no* tmp2 = criar_no((yyvsp[-3].node)->tipo,(yyvsp[-3].node)->info); 
                                                                        tmp1->filho= tmp2; 
                                                                        adicionar_irmao(tmp2,criar_no("Id",tmp->info)); 
                                                                        adicionar_irmao((yyval.node),tmp1); tmp = tmp->irmao;
                                                                    } 
                                                                  } ;}
#line 1639 "y.tab.c"
    break;

  case 28: /* Statement: LBRACE StatementRep RBRACE  */
#line 166 "jucompiler.y"
                                                      {if( contador_irmaos((yyvsp[-1].node))>1){(yyval.node)=criar_no("Block",gen_token("",line_num, col_num));(yyval.node)->filho=(yyvsp[-1].node);}else{(yyval.node)=(yyvsp[-1].node);}}
#line 1645 "y.tab.c"
    break;

  case 29: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 167 "jucompiler.y"
                                                      {(yyval.node)=criar_no("If",gen_token("",line_num, col_num));                                           
                                                        if((yyvsp[-4].node) != NULL){  //Verificamos se o Expr não é NULL
                                                            (yyval.node)->filho=(yyvsp[-4].node); 
                                                            tmp = criar_no("Block",gen_token("",line_num, col_num));
                                                            if ((yyvsp[-2].node) != NULL && contador_irmaos((yyvsp[-2].node)) < 2) { //Verificar se o Statement não é NULL e se tem menos de 2 statements
                                                                adicionar_irmao((yyvsp[-4].node), (yyvsp[-2].node));
                                                                if ((yyvsp[0].node) != NULL && contador_irmaos((yyvsp[0].node)) < 2) { //A mesma verificação de cima
                                                                    adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));
                                                                }
                                                                else {
                                                                    adicionar_irmao((yyvsp[-2].node), tmp);
                                                                    tmp->filho = (yyvsp[0].node);
                                                                }
                                                            }
                                                            else {
                                                                adicionar_irmao((yyvsp[-4].node), tmp);
                                                                tmp->filho = (yyvsp[-2].node);
                                                                if ((yyvsp[0].node) != NULL && contador_irmaos((yyvsp[0].node)) < 2 ) { //Verificar se o Statement não é NULL e se tem menos de 2 statements
                                                                    adicionar_irmao(tmp, (yyvsp[0].node));
                                                                }
                                                                else {
                                                                    no* tmp_aux = criar_no("Block",gen_token("",line_num, col_num));
                                                                    adicionar_irmao(tmp, tmp_aux);
                                                                    tmp_aux->filho = (yyvsp[0].node);
                                                                }
                                                            }
                                                        }else{

                                                            tmp = criar_no("Block",gen_token("",line_num, col_num)); //A mesma lógica de cima, mas deste modo a ignorar o Expr
                                                            if ((yyvsp[-2].node) != NULL && contador_irmaos((yyvsp[-2].node)) < 2) {
                                                                (yyval.node)->filho = (yyvsp[-2].node);
                                                                if ((yyvsp[0].node) != NULL && contador_irmaos((yyvsp[0].node)) < 2) {
                                                                    adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));
                                                                }
                                                                else {
                                                                    adicionar_irmao((yyvsp[-2].node), tmp);
                                                                    tmp->filho = (yyvsp[0].node);
                                                                }
                                                            }
                                                            else {
                                                                (yyval.node)->filho = tmp;
                                                                tmp->filho = (yyvsp[-2].node);
                                                                if ((yyvsp[0].node) != NULL && contador_irmaos((yyvsp[0].node)) < 2) {
                                                                    adicionar_irmao(tmp, (yyvsp[0].node));
                                                                }
                                                                else {
                                                                    no* tmp_aux = criar_no("Block",gen_token("",line_num, col_num));
                                                                    adicionar_irmao(tmp, tmp_aux);
                                                                    tmp_aux->filho = (yyvsp[0].node);
                                                                }
                                                            }   
                                                                
                                                                
                                                        }}
#line 1704 "y.tab.c"
    break;

  case 30: /* Statement: IF LPAR Expr RPAR Statement  */
#line 222 "jucompiler.y"
                                                      {(yyval.node)=criar_no("If",gen_token("",line_num, col_num)); //Mesma lógica aplicada ao outro IF
                                                        tmp = criar_no("Block",gen_token("",line_num, col_num));
                                                    
                                                        if((yyvsp[-2].node)!=NULL){ //Verificar se o Expr não é NULL, verificar o nr de statements no statement de modo a criar ou não o block
                                                            (yyval.node)->filho=(yyvsp[-2].node);
                                                            if((yyvsp[0].node) != NULL && contador_irmaos((yyvsp[0].node)) < 2 ){
                                                                adicionar_irmao((yyvsp[-2].node),(yyvsp[0].node)); 
                                                                adicionar_irmao((yyvsp[0].node), tmp);}
                                                            else{
                                                                adicionar_irmao((yyvsp[-2].node),tmp); 
                                                                tmp->filho = (yyvsp[0].node); 
                                                                adicionar_irmao(tmp,criar_no("Block",gen_token("",line_num, col_num)));
                                                                }
                                                        }else{

                                                            if((yyvsp[0].node) != NULL && contador_irmaos((yyvsp[0].node)) < 2 ){
                                                                (yyval.node)->filho = (yyvsp[0].node); 
                                                                adicionar_irmao((yyvsp[0].node), tmp);}
                                                            else{
                                                                (yyval.node)->filho = tmp; 
                                                                tmp->filho = (yyvsp[0].node); 
                                                                adicionar_irmao(tmp,criar_no("Block",gen_token("",line_num, col_num)));
                                                            }
                                                        }}
#line 1733 "y.tab.c"
    break;

  case 31: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 247 "jucompiler.y"
                                                      {(yyval.node)=criar_no("While",gen_token("",line_num, col_num)); //Mesma lógica aplicada aos IFs
                                                        if((yyvsp[-2].node)!=NULL){  //Verificar se o Expr não é NULL, verificar o nr de statements no statement de modo a criar ou não o block
                                                            (yyval.node)->filho=(yyvsp[-2].node); 
                                                            if((yyvsp[0].node) != NULL && contador_irmaos((yyvsp[0].node)) < 2){
                                                                adicionar_irmao((yyvsp[-2].node),(yyvsp[0].node));}
                                                            else{
                                                                tmp = criar_no("Block",gen_token("",line_num, col_num)); 
                                                                adicionar_irmao((yyvsp[-2].node),tmp); 
                                                                tmp->filho = (yyvsp[0].node);} 
                                                        }
                                                        else{
                                                            if((yyvsp[0].node) != NULL && contador_irmaos((yyvsp[0].node)) < 2){
                                                                (yyval.node)->filho=(yyvsp[0].node);}
                                                            else{
                                                                tmp = criar_no("Block",gen_token("",line_num, col_num)); 
                                                                (yyval.node)->filho = tmp; 
                                                                tmp->filho = (yyvsp[0].node);} 
                                                        } }
#line 1756 "y.tab.c"
    break;

  case 32: /* Statement: RETURN Expr SEMICOLON  */
#line 265 "jucompiler.y"
                                                      {(yyval.node)=criar_no("Return",gen_token("",line_num, col_num)); (yyval.node)->filho=(yyvsp[-1].node);}
#line 1762 "y.tab.c"
    break;

  case 33: /* Statement: RETURN SEMICOLON  */
#line 266 "jucompiler.y"
                                                      {(yyval.node)=criar_no("Return",gen_token("",line_num, col_num));}
#line 1768 "y.tab.c"
    break;

  case 34: /* Statement: PRINT LPAR Expr RPAR SEMICOLON  */
#line 267 "jucompiler.y"
                                                      {(yyval.node)=criar_no("Print",(yyvsp[-4].info));(yyval.node)->filho=(yyvsp[-2].node);}
#line 1774 "y.tab.c"
    break;

  case 35: /* Statement: PRINT LPAR STRLIT RPAR SEMICOLON  */
#line 268 "jucompiler.y"
                                                      {(yyval.node)=criar_no("Print",(yyvsp[-4].info));(yyval.node)->filho=criar_no("StrLit",(yyvsp[-2].info));}
#line 1780 "y.tab.c"
    break;

  case 36: /* Statement: MethodInvocation SEMICOLON  */
#line 269 "jucompiler.y"
                                                      {(yyval.node)=(yyvsp[-1].node);}
#line 1786 "y.tab.c"
    break;

  case 37: /* Statement: Assignment SEMICOLON  */
#line 270 "jucompiler.y"
                                                      {(yyval.node)=(yyvsp[-1].node);}
#line 1792 "y.tab.c"
    break;

  case 38: /* Statement: ParseArgs SEMICOLON  */
#line 271 "jucompiler.y"
                                                      {(yyval.node)=(yyvsp[-1].node);}
#line 1798 "y.tab.c"
    break;

  case 39: /* Statement: SEMICOLON  */
#line 272 "jucompiler.y"
                                                      {(yyval.node)=NULL;}
#line 1804 "y.tab.c"
    break;

  case 40: /* Statement: error SEMICOLON  */
#line 273 "jucompiler.y"
                                                      {(yyval.node)=NULL;flag_tree=0;}
#line 1810 "y.tab.c"
    break;

  case 41: /* StatementRep: Statement StatementRep  */
#line 275 "jucompiler.y"
                                     {if((yyvsp[-1].node)!=NULL){ //Verificar se o statement não é NULL
                                        (yyval.node)=(yyvsp[-1].node);
                                        adicionar_irmao((yyval.node),(yyvsp[0].node));} 
                                    else { (yyval.node)=(yyvsp[0].node);}}
#line 1819 "y.tab.c"
    break;

  case 42: /* StatementRep: %empty  */
#line 280 "jucompiler.y"
                                     {(yyval.node)=NULL;}
#line 1825 "y.tab.c"
    break;

  case 43: /* MethodInvocation: ID LPAR RPAR  */
#line 283 "jucompiler.y"
                                                 {(yyval.node)=criar_no("Call",gen_token("",line_num, col_num)); (yyval.node)->filho = criar_no("Id",(yyvsp[-2].info));}
#line 1831 "y.tab.c"
    break;

  case 44: /* MethodInvocation: ID LPAR Expr CommaExprRep RPAR  */
#line 285 "jucompiler.y"
                                                 {(yyval.node)=criar_no("Call",gen_token("",line_num, col_num)); (yyval.node)->filho = criar_no("Id",(yyvsp[-4].info)); //Verificar se o Expr não é NULL para adicionar os irmãos
                                                                          if((yyvsp[-2].node) != NULL){
                                                                            adicionar_irmao((yyval.node)->filho,(yyvsp[-2].node)); 
                                                                            adicionar_irmao((yyvsp[-2].node),(yyvsp[-1].node));
                                                                          }else 
                                                                            adicionar_irmao((yyval.node)->filho,(yyvsp[-1].node));}
#line 1842 "y.tab.c"
    break;

  case 45: /* MethodInvocation: ID LPAR error RPAR  */
#line 291 "jucompiler.y"
                                        {(yyval.node)=NULL;flag_tree=0;}
#line 1848 "y.tab.c"
    break;

  case 46: /* CommaExprRep: COMMA Expr CommaExprRep  */
#line 295 "jucompiler.y"
                                      {if((yyvsp[-1].node)!=NULL){ //Verificar se Expr não é NULL
                                        (yyval.node)=(yyvsp[-1].node);
                                        adicionar_irmao((yyval.node),(yyvsp[0].node));
                                       }else 
                                        (yyval.node)=(yyvsp[-1].node);}
#line 1858 "y.tab.c"
    break;

  case 47: /* CommaExprRep: %empty  */
#line 301 "jucompiler.y"
                                      {(yyval.node)=NULL;}
#line 1864 "y.tab.c"
    break;

  case 48: /* Assignment: ID ASSIGN Expr  */
#line 305 "jucompiler.y"
                           {(yyval.node)=criar_no("Assign",(yyvsp[-1].info));(yyval.node)->filho=criar_no("Id",(yyvsp[-2].info)); adicionar_irmao((yyval.node)->filho,(yyvsp[0].node));}
#line 1870 "y.tab.c"
    break;

  case 49: /* ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR  */
#line 307 "jucompiler.y"
                                              {(yyval.node)=criar_no("ParseArgs",gen_token("",line_num, col_num)); (yyval.node)->filho=criar_no("Id",(yyvsp[-4].info)); adicionar_irmao((yyval.node)->filho,(yyvsp[-2].node));}
#line 1876 "y.tab.c"
    break;

  case 50: /* ParseArgs: PARSEINT LPAR error RPAR  */
#line 308 "jucompiler.y"
                                              {(yyval.node)=NULL;flag_tree=0;}
#line 1882 "y.tab.c"
    break;

  case 51: /* Expr: ExprOp  */
#line 311 "jucompiler.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 1888 "y.tab.c"
    break;

  case 52: /* Expr: Assignment  */
#line 312 "jucompiler.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 1894 "y.tab.c"
    break;

  case 53: /* ExprOp: LPAR Expr RPAR  */
#line 315 "jucompiler.y"
                                {(yyval.node)=(yyvsp[-1].node);}
#line 1900 "y.tab.c"
    break;

  case 54: /* ExprOp: MethodInvocation  */
#line 316 "jucompiler.y"
                                {(yyval.node)=(yyvsp[0].node);}
#line 1906 "y.tab.c"
    break;

  case 55: /* ExprOp: ParseArgs  */
#line 317 "jucompiler.y"
                                {(yyval.node)=(yyvsp[0].node);}
#line 1912 "y.tab.c"
    break;

  case 56: /* ExprOp: ID  */
#line 318 "jucompiler.y"
                                {(yyval.node)=criar_no("Id",(yyvsp[0].info));}
#line 1918 "y.tab.c"
    break;

  case 57: /* ExprOp: ID DOTLENGTH  */
#line 319 "jucompiler.y"
                                {(yyval.node)=criar_no("Length",(yyvsp[0].info)); (yyval.node)->filho = criar_no("Id",(yyvsp[-1].info));}
#line 1924 "y.tab.c"
    break;

  case 58: /* ExprOp: INTLIT  */
#line 320 "jucompiler.y"
                                {(yyval.node)=criar_no("DecLit",(yyvsp[0].info));}
#line 1930 "y.tab.c"
    break;

  case 59: /* ExprOp: REALLIT  */
#line 321 "jucompiler.y"
                                {(yyval.node)=criar_no("RealLit",(yyvsp[0].info));}
#line 1936 "y.tab.c"
    break;

  case 60: /* ExprOp: BOOLLIT  */
#line 322 "jucompiler.y"
                                {(yyval.node)=criar_no("BoolLit",(yyvsp[0].info));}
#line 1942 "y.tab.c"
    break;

  case 61: /* ExprOp: MINUS ExprOp  */
#line 323 "jucompiler.y"
                                {;(yyval.node)=criar_no("Minus",(yyvsp[-1].info)); (yyval.node)->filho=(yyvsp[0].node);}
#line 1948 "y.tab.c"
    break;

  case 62: /* ExprOp: NOT ExprOp  */
#line 324 "jucompiler.y"
                                {;(yyval.node)=criar_no("Not",(yyvsp[-1].info)); (yyval.node)->filho=(yyvsp[0].node);}
#line 1954 "y.tab.c"
    break;

  case 63: /* ExprOp: PLUS ExprOp  */
#line 325 "jucompiler.y"
                                {;(yyval.node)=criar_no("Plus",(yyvsp[-1].info)); (yyval.node)->filho=(yyvsp[0].node);}
#line 1960 "y.tab.c"
    break;

  case 64: /* ExprOp: ExprOp PLUS ExprOp  */
#line 326 "jucompiler.y"
                                {(yyval.node)=criar_no("Add",(yyvsp[-1].info)); (yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1966 "y.tab.c"
    break;

  case 65: /* ExprOp: ExprOp MINUS ExprOp  */
#line 327 "jucompiler.y"
                                {(yyval.node)=criar_no("Sub",(yyvsp[-1].info));(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1972 "y.tab.c"
    break;

  case 66: /* ExprOp: ExprOp STAR ExprOp  */
#line 328 "jucompiler.y"
                                {(yyval.node)=criar_no("Mul",(yyvsp[-1].info));(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1978 "y.tab.c"
    break;

  case 67: /* ExprOp: ExprOp DIV ExprOp  */
#line 329 "jucompiler.y"
                                {(yyval.node)=criar_no("Div",(yyvsp[-1].info));(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1984 "y.tab.c"
    break;

  case 68: /* ExprOp: ExprOp MOD ExprOp  */
#line 330 "jucompiler.y"
                                {(yyval.node)=criar_no("Mod",(yyvsp[-1].info));(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1990 "y.tab.c"
    break;

  case 69: /* ExprOp: ExprOp AND ExprOp  */
#line 331 "jucompiler.y"
                                {(yyval.node)=criar_no("And",(yyvsp[-1].info));(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1996 "y.tab.c"
    break;

  case 70: /* ExprOp: ExprOp OR ExprOp  */
#line 332 "jucompiler.y"
                                {(yyval.node)=criar_no("Or",(yyvsp[-1].info));(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2002 "y.tab.c"
    break;

  case 71: /* ExprOp: ExprOp XOR ExprOp  */
#line 333 "jucompiler.y"
                                {(yyval.node)=criar_no("Xor",gen_token("",line_num, col_num));(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2008 "y.tab.c"
    break;

  case 72: /* ExprOp: ExprOp LSHIFT ExprOp  */
#line 334 "jucompiler.y"
                                {(yyval.node)=criar_no("Lshift",gen_token("",line_num, col_num));(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2014 "y.tab.c"
    break;

  case 73: /* ExprOp: ExprOp RSHIFT ExprOp  */
#line 335 "jucompiler.y"
                                {(yyval.node)=criar_no("Rshift",gen_token("",line_num, col_num));(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2020 "y.tab.c"
    break;

  case 74: /* ExprOp: ExprOp EQ ExprOp  */
#line 336 "jucompiler.y"
                                {(yyval.node)=criar_no("Eq",(yyvsp[-1].info));(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2026 "y.tab.c"
    break;

  case 75: /* ExprOp: ExprOp GE ExprOp  */
#line 337 "jucompiler.y"
                                {(yyval.node)=criar_no("Ge",(yyvsp[-1].info));(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2032 "y.tab.c"
    break;

  case 76: /* ExprOp: ExprOp GT ExprOp  */
#line 338 "jucompiler.y"
                                {(yyval.node)=criar_no("Gt",(yyvsp[-1].info));(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2038 "y.tab.c"
    break;

  case 77: /* ExprOp: ExprOp LE ExprOp  */
#line 339 "jucompiler.y"
                                {(yyval.node)=criar_no("Le",(yyvsp[-1].info));(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2044 "y.tab.c"
    break;

  case 78: /* ExprOp: ExprOp LT ExprOp  */
#line 340 "jucompiler.y"
                                {(yyval.node)=criar_no("Lt",(yyvsp[-1].info));(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2050 "y.tab.c"
    break;

  case 79: /* ExprOp: ExprOp NE ExprOp  */
#line 341 "jucompiler.y"
                                {(yyval.node)=criar_no("Ne",(yyvsp[-1].info));(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2056 "y.tab.c"
    break;

  case 80: /* ExprOp: LPAR error RPAR  */
#line 342 "jucompiler.y"
                                {(yyval.node)=NULL;flag_tree=0;}
#line 2062 "y.tab.c"
    break;


#line 2066 "y.tab.c"

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

#line 344 "jucompiler.y"

