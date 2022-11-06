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
#include "symtab.h"
#define NSYMS 100
#define DEBUG 0

symtab tab[NSYMS];

void varlist();

symtab *symlook(char *varname);
int yylex (void);
extern void yyerror(char* s);
no* raiz;
no* tmp;

extern int line_num;
extern int col_num;
extern int flag_tree;

#line 97 "y.tab.c"

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
    AND = 263,                     /* AND  */
    ASSIGN = 264,                  /* ASSIGN  */
    BOOL = 265,                    /* BOOL  */
    STAR = 266,                    /* STAR  */
    COMMA = 267,                   /* COMMA  */
    DIV = 268,                     /* DIV  */
    EQ = 269,                      /* EQ  */
    GE = 270,                      /* GE  */
    GT = 271,                      /* GT  */
    LBRACE = 272,                  /* LBRACE  */
    LE = 273,                      /* LE  */
    LPAR = 274,                    /* LPAR  */
    LSQ = 275,                     /* LSQ  */
    LT = 276,                      /* LT  */
    MINUS = 277,                   /* MINUS  */
    MOD = 278,                     /* MOD  */
    NE = 279,                      /* NE  */
    NOT = 280,                     /* NOT  */
    OR = 281,                      /* OR  */
    PLUS = 282,                    /* PLUS  */
    RBRACE = 283,                  /* RBRACE  */
    RPAR = 284,                    /* RPAR  */
    RSQ = 285,                     /* RSQ  */
    SEMICOLON = 286,               /* SEMICOLON  */
    ARROW = 287,                   /* ARROW  */
    LSHIFT = 288,                  /* LSHIFT  */
    RSHIFT = 289,                  /* RSHIFT  */
    XOR = 290,                     /* XOR  */
    CLASS = 291,                   /* CLASS  */
    DOTLENGTH = 292,               /* DOTLENGTH  */
    DOUBLE = 293,                  /* DOUBLE  */
    ELSE = 294,                    /* ELSE  */
    IF = 295,                      /* IF  */
    INT = 296,                     /* INT  */
    PRINT = 297,                   /* PRINT  */
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
#define AND 263
#define ASSIGN 264
#define BOOL 265
#define STAR 266
#define COMMA 267
#define DIV 268
#define EQ 269
#define GE 270
#define GT 271
#define LBRACE 272
#define LE 273
#define LPAR 274
#define LSQ 275
#define LT 276
#define MINUS 277
#define MOD 278
#define NE 279
#define NOT 280
#define OR 281
#define PLUS 282
#define RBRACE 283
#define RPAR 284
#define RSQ 285
#define SEMICOLON 286
#define ARROW 287
#define LSHIFT 288
#define RSHIFT 289
#define XOR 290
#define CLASS 291
#define DOTLENGTH 292
#define DOUBLE 293
#define ELSE 294
#define IF 295
#define INT 296
#define PRINT 297
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
#line 79 "jucompiler.y"

    char* id;
    no* node;

#line 255 "y.tab.c"

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
  YYSYMBOL_AND = 8,                        /* AND  */
  YYSYMBOL_ASSIGN = 9,                     /* ASSIGN  */
  YYSYMBOL_BOOL = 10,                      /* BOOL  */
  YYSYMBOL_STAR = 11,                      /* STAR  */
  YYSYMBOL_COMMA = 12,                     /* COMMA  */
  YYSYMBOL_DIV = 13,                       /* DIV  */
  YYSYMBOL_EQ = 14,                        /* EQ  */
  YYSYMBOL_GE = 15,                        /* GE  */
  YYSYMBOL_GT = 16,                        /* GT  */
  YYSYMBOL_LBRACE = 17,                    /* LBRACE  */
  YYSYMBOL_LE = 18,                        /* LE  */
  YYSYMBOL_LPAR = 19,                      /* LPAR  */
  YYSYMBOL_LSQ = 20,                       /* LSQ  */
  YYSYMBOL_LT = 21,                        /* LT  */
  YYSYMBOL_MINUS = 22,                     /* MINUS  */
  YYSYMBOL_MOD = 23,                       /* MOD  */
  YYSYMBOL_NE = 24,                        /* NE  */
  YYSYMBOL_NOT = 25,                       /* NOT  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_PLUS = 27,                      /* PLUS  */
  YYSYMBOL_RBRACE = 28,                    /* RBRACE  */
  YYSYMBOL_RPAR = 29,                      /* RPAR  */
  YYSYMBOL_RSQ = 30,                       /* RSQ  */
  YYSYMBOL_SEMICOLON = 31,                 /* SEMICOLON  */
  YYSYMBOL_ARROW = 32,                     /* ARROW  */
  YYSYMBOL_LSHIFT = 33,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 34,                    /* RSHIFT  */
  YYSYMBOL_XOR = 35,                       /* XOR  */
  YYSYMBOL_CLASS = 36,                     /* CLASS  */
  YYSYMBOL_DOTLENGTH = 37,                 /* DOTLENGTH  */
  YYSYMBOL_DOUBLE = 38,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 39,                      /* ELSE  */
  YYSYMBOL_IF = 40,                        /* IF  */
  YYSYMBOL_INT = 41,                       /* INT  */
  YYSYMBOL_PRINT = 42,                     /* PRINT  */
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
#define YYLAST   417

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
static const yytype_uint8 yyrline[] =
{
       0,    88,    88,    91,    92,    93,    94,    98,   101,   102,
     104,   105,   109,   110,   111,   113,   114,   115,   116,   119,
     120,   122,   123,   126,   128,   129,   130,   133,   135,   136,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   171,   172,   175,   176,   177,   181,   182,   186,   188,
     189,   192,   193,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223
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
  "REALLIT", "BOOLLIT", "STRLIT", "AND", "ASSIGN", "BOOL", "STAR", "COMMA",
  "DIV", "EQ", "GE", "GT", "LBRACE", "LE", "LPAR", "LSQ", "LT", "MINUS",
  "MOD", "NE", "NOT", "OR", "PLUS", "RBRACE", "RPAR", "RSQ", "SEMICOLON",
  "ARROW", "LSHIFT", "RSHIFT", "XOR", "CLASS", "DOTLENGTH", "DOUBLE",
  "ELSE", "IF", "INT", "PRINT", "PARSEINT", "PUBLIC", "RETURN", "STATIC",
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

#define YYPACT_NINF (-48)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-43)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -30,    42,    51,    36,   -48,    13,    25,    13,    15,    57,
      13,    13,   -48,   -48,    14,   -48,   -48,   -48,   -48,   -48,
     -48,    62,    83,    72,    73,    35,    87,   -48,    58,    91,
     223,    64,    67,     4,   137,   -48,    81,    90,    92,   203,
      95,   103,    88,    87,    87,    86,    89,   108,   -48,   101,
     119,    94,   122,   -48,   112,   -48,   -48,   235,   169,   137,
     114,   235,   210,     6,    27,   -48,   -48,   -48,   199,   244,
     244,   244,   -48,   -48,   -48,   -48,   116,   268,   235,   122,
     -48,   -48,   -48,   -48,   -48,   -48,   113,   133,   -48,   -48,
     -48,   -48,   120,   -48,   138,   -48,   -48,   123,   126,   127,
     128,   139,   -48,   129,   131,    21,   -48,   -48,    37,   -48,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   132,   135,   159,    -7,
     -48,   -48,   235,   134,   150,   140,   145,   -48,   235,   -48,
     -48,   321,   -48,   -48,   370,   383,   383,   383,   383,    37,
     -48,   370,   296,    37,    80,    80,   346,   150,   -48,   -48,
     161,   138,   -48,   130,   -48,   -48,   148,   -48,   133,   -48,
     150,   154,   -48,   -48,   -48
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     9,     5,     0,     2,     3,     4,    12,    14,
      13,     0,     0,     0,     0,    11,     0,     7,     0,     0,
       0,     0,     0,     0,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,    11,    17,     0,     8,    40,     0,     0,     0,
       0,     0,     0,     0,    56,    58,    59,    60,     0,     0,
       0,     0,    33,    54,    52,    55,     0,    51,     0,    11,
      23,    25,    24,    36,    37,    38,     0,    22,    16,    10,
      15,    48,     0,    43,    47,    41,    28,     0,     0,     0,
       0,     0,    57,     0,     0,    56,    61,    62,    63,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    45,     0,     0,     0,     0,     0,    50,     0,    80,
      53,    69,    66,    67,    74,    75,    76,    77,    78,    65,
      68,    79,    70,    64,    72,    73,    71,     0,    27,    20,
       0,    47,    44,    30,    35,    34,     0,    31,    22,    46,
       0,     0,    21,    29,    49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -48,   -48,    56,   -48,   -48,   -47,    -3,   -48,   155,    16,
     -48,   -28,   -48,   -33,   142,   -26,    26,   -24,   -22,   -19,
     -41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    10,    11,    31,    41,    23,    51,   130,
      27,    42,    43,    44,    60,    73,   133,    74,    75,    76,
      77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    59,    46,    18,    47,    89,     1,   100,    45,   101,
      46,    22,    47,    57,     6,    81,    82,    45,    45,    46,
      46,    47,    47,    58,    18,    50,    59,    50,   106,   107,
     108,    19,   127,    45,    20,    46,    57,    47,    91,    94,
      58,    -6,    97,    99,     7,     3,    58,    29,   111,   104,
     112,     4,    19,     5,    30,    20,    12,     8,   102,   126,
     119,    14,    21,    13,   102,    24,    16,    17,    18,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    15,    25,    48,    32,    26,
      33,   111,    28,   112,    52,    55,    19,    18,    56,    20,
      61,   163,   118,   119,    34,    49,    79,   122,    45,    62,
      46,    63,    47,   161,    78,   -26,    80,    83,    35,   166,
      84,    86,    87,    88,   167,    19,   160,    36,    20,    37,
      38,    45,    39,    46,    29,    47,    40,   173,    32,    85,
      33,    90,    96,   128,    45,   129,    46,   109,    47,   131,
     132,    32,   134,    33,    34,   135,   136,   137,   139,   138,
     140,   157,   159,   162,   168,   -42,   158,    34,    35,   170,
      92,   164,    64,    65,    66,    67,   165,    36,   171,    37,
      38,    35,    39,   174,   172,    54,    40,   169,    68,     0,
      36,    69,    37,    38,    70,    39,    71,     0,    93,    40,
     103,    95,    64,    65,    66,    67,    64,    65,    66,    67,
       0,     0,    38,    64,    65,    66,    67,    98,    68,     0,
       0,    69,    68,     0,    70,    69,    71,     0,    70,    68,
      71,     0,    69,    18,    72,    70,     0,    71,    64,    65,
      66,    67,    38,     0,     0,     0,    38,   105,    65,    66,
      67,     0,    53,    38,    68,     0,     0,    69,     0,     0,
      70,    19,    71,    68,    20,     0,    69,     0,     0,    70,
      49,    71,     0,     0,     0,     0,   110,     0,    38,   111,
       0,   112,   113,   114,   115,     0,   116,    38,     0,   117,
     118,   119,   120,     0,   121,   122,     0,     0,     0,     0,
       0,   123,   124,   125,   110,     0,     0,   111,     0,   112,
     113,   114,   115,     0,   116,     0,     0,   117,   118,   119,
     120,     0,     0,   122,     0,     0,     0,     0,     0,   123,
     124,   125,   111,     0,   112,   113,   114,   115,     0,   116,
       0,     0,   117,   118,   119,   120,     0,     0,   122,     0,
       0,     0,     0,     0,   123,   124,   125,   111,     0,   112,
     113,   114,   115,     0,   116,     0,     0,   117,   118,   119,
     120,     0,     0,   122,     0,     0,     0,     0,     0,   123,
     124,   111,     0,   112,     0,   114,   115,     0,   116,     0,
       0,   117,   118,   119,   111,     0,   112,   122,     0,     0,
       0,     0,     0,   123,   124,   118,   119,     0,     0,     0,
     122,     0,     0,     0,     0,     0,   123,   124
};

static const yytype_int16 yycheck[] =
{
      26,    34,    26,    10,    26,    52,    36,     1,    34,     3,
      34,    14,    34,     9,     1,    43,    44,    43,    44,    43,
      44,    43,    44,    19,    10,    28,    59,    30,    69,    70,
      71,    38,    79,    59,    41,    59,     9,    59,    57,    58,
      19,    28,    61,    62,    31,     3,    19,    12,    11,    68,
      13,     0,    38,    17,    19,    41,    31,    44,    37,    78,
      23,    46,    48,     7,    37,     3,    10,    11,    10,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    28,     3,    29,     1,    17,
       3,    11,    19,    13,     3,    31,    38,    10,    31,    41,
      19,   134,    22,    23,    17,    47,     3,    27,   134,    19,
     134,    19,   134,   132,    19,    28,    28,    31,    31,   138,
      31,    20,     3,    29,   157,    38,   129,    40,    41,    42,
      43,   157,    45,   157,    12,   157,    49,   170,     1,    31,
       3,    29,    28,    30,   170,    12,   170,    31,   170,    29,
      12,     1,    29,     3,    17,    29,    29,    29,    29,    20,
      29,    29,     3,    29,     3,    28,    31,    17,    31,    39,
       1,    31,     3,     4,     5,     6,    31,    40,    30,    42,
      43,    31,    45,    29,   168,    30,    49,   161,    19,    -1,
      40,    22,    42,    43,    25,    45,    27,    -1,    29,    49,
       1,    59,     3,     4,     5,     6,     3,     4,     5,     6,
      -1,    -1,    43,     3,     4,     5,     6,     7,    19,    -1,
      -1,    22,    19,    -1,    25,    22,    27,    -1,    25,    19,
      27,    -1,    22,    10,    31,    25,    -1,    27,     3,     4,
       5,     6,    43,    -1,    -1,    -1,    43,     3,     4,     5,
       6,    -1,    29,    43,    19,    -1,    -1,    22,    -1,    -1,
      25,    38,    27,    19,    41,    -1,    22,    -1,    -1,    25,
      47,    27,    -1,    -1,    -1,    -1,     8,    -1,    43,    11,
      -1,    13,    14,    15,    16,    -1,    18,    43,    -1,    21,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,     8,    -1,    -1,    11,    -1,    13,
      14,    15,    16,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    11,    -1,    13,    14,    15,    16,    -1,    18,
      -1,    -1,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    11,    -1,    13,
      14,    15,    16,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    33,
      34,    11,    -1,    13,    -1,    15,    16,    -1,    18,    -1,
      -1,    21,    22,    23,    11,    -1,    13,    27,    -1,    -1,
      -1,    -1,    -1,    33,    34,    22,    23,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    52,     3,     0,    17,     1,    31,    44,    53,
      54,    55,    31,    53,    46,    28,    53,    53,    10,    38,
      41,    48,    57,    58,     3,     3,    17,    61,    19,    12,
      19,    56,     1,     3,    17,    31,    40,    42,    43,    45,
      49,    57,    62,    63,    64,    66,    68,    69,    29,    47,
      57,    59,     3,    29,    59,    31,    31,     9,    19,    64,
      65,    19,    19,    19,     3,     4,     5,     6,    19,    22,
      25,    27,    31,    66,    68,    69,    70,    71,    19,     3,
      28,    62,    62,    31,    31,    31,    20,     3,    29,    56,
      29,    70,     1,    29,    70,    65,    28,    70,     7,    70,
       1,     3,    37,     1,    70,     3,    71,    71,    71,    31,
       8,    11,    13,    14,    15,    16,    18,    21,    22,    23,
      24,    26,    27,    33,    34,    35,    70,    56,    30,    12,
      60,    29,    12,    67,    29,    29,    29,    29,    20,    29,
      29,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    29,    31,     3,
      57,    70,    29,    64,    31,    31,    70,    64,     3,    67,
      39,    30,    60,    64,    29
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
#line 88 "jucompiler.y"
                                                         {if(DEBUG)printf("program\n");(yyval.node)=raiz=criar_no("Program",""); (yyval.node)->filho = criar_no("Id",(yyvsp[-3].id)); adicionar_irmao((yyval.node)->filho, (yyvsp[-1].node));}
#line 1467 "y.tab.c"
    break;

  case 3: /* MethodFieldSemicolonRep: MethodDecl MethodFieldSemicolonRep  */
#line 91 "jucompiler.y"
                                                            {if(DEBUG)printf("method dcl prog\n");(yyval.node)=(yyvsp[-1].node); adicionar_irmao((yyval.node),(yyvsp[0].node));}
#line 1473 "y.tab.c"
    break;

  case 4: /* MethodFieldSemicolonRep: FieldDecl MethodFieldSemicolonRep  */
#line 92 "jucompiler.y"
                                                            {if(DEBUG)printf("field decl prog\n"); if((yyvsp[-1].node)!=NULL){(yyval.node)=(yyvsp[-1].node); adicionar_irmao((yyval.node),(yyvsp[0].node));}else (yyval.node)=(yyvsp[0].node);}
#line 1479 "y.tab.c"
    break;

  case 5: /* MethodFieldSemicolonRep: SEMICOLON MethodFieldSemicolonRep  */
#line 93 "jucompiler.y"
                                                            {if(DEBUG)printf("semicolon \n");(yyval.node)=(yyvsp[0].node);}
#line 1485 "y.tab.c"
    break;

  case 6: /* MethodFieldSemicolonRep: %empty  */
#line 94 "jucompiler.y"
                                                            {if(DEBUG)printf("method dcl prog rep empty \n");(yyval.node)=NULL;}
#line 1491 "y.tab.c"
    break;

  case 7: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 98 "jucompiler.y"
                                                  {if(DEBUG)printf("method dcl solo\n");(yyval.node)= criar_no("MethodDecl",""), (yyval.node)->filho=(yyvsp[-1].node); adicionar_irmao((yyvsp[-1].node),(yyvsp[0].node));}
#line 1497 "y.tab.c"
    break;

  case 8: /* FieldDecl: PUBLIC STATIC Type ID CommaIdRep SEMICOLON  */
#line 101 "jucompiler.y"
                                                      {if(DEBUG)printf("field decl solo \n");(yyval.node)=criar_no("FieldDecl",""), (yyval.node)->filho=(yyvsp[-3].node); adicionar_irmao((yyvsp[-3].node),criar_no("Id",(yyvsp[-2].id))); if((yyvsp[-1].node)!=NULL){tmp = (yyvsp[-1].node); while(tmp != NULL){ no* tmp1 = criar_no("FieldDecl","");no* tmp2 = criar_no((yyvsp[-3].node)->tipo,(yyvsp[-3].node)->val); tmp1->filho= tmp2; adicionar_irmao(tmp2,criar_no("Id",tmp->val)); adicionar_irmao((yyval.node),tmp1); tmp = tmp->irmao;} } ;}
#line 1503 "y.tab.c"
    break;

  case 9: /* FieldDecl: error SEMICOLON  */
#line 102 "jucompiler.y"
                          {(yyval.node)=NULL;if(DEBUG)printf("fielddecl error \n");flag_tree=0;}
#line 1509 "y.tab.c"
    break;

  case 10: /* CommaIdRep: COMMA ID CommaIdRep  */
#line 104 "jucompiler.y"
                                {if(DEBUG)printf("commma id rep \n");(yyval.node)=criar_no("Id",(yyvsp[-1].id)); adicionar_irmao((yyval.node),(yyvsp[0].node));}
#line 1515 "y.tab.c"
    break;

  case 11: /* CommaIdRep: %empty  */
#line 105 "jucompiler.y"
                                {if(DEBUG)printf("comma id rep empty \n");(yyval.node)=NULL;}
#line 1521 "y.tab.c"
    break;

  case 12: /* Type: BOOL  */
#line 109 "jucompiler.y"
            {if(DEBUG)printf("bool \n");(yyval.node)=criar_no("Bool","");}
#line 1527 "y.tab.c"
    break;

  case 13: /* Type: INT  */
#line 110 "jucompiler.y"
          {if(DEBUG)printf("int \n");(yyval.node)=criar_no("Int","");}
#line 1533 "y.tab.c"
    break;

  case 14: /* Type: DOUBLE  */
#line 111 "jucompiler.y"
             {if(DEBUG)printf("double \n");(yyval.node)=criar_no("Double","");}
#line 1539 "y.tab.c"
    break;

  case 15: /* MethodHeader: Type ID LPAR FormalParams RPAR  */
#line 113 "jucompiler.y"
                                                {if(DEBUG)printf("method header full \n");(yyval.node)=criar_no("MethodHeader",""); (yyval.node)->filho=(yyvsp[-4].node); adicionar_irmao((yyvsp[-4].node), criar_no("Id",(yyvsp[-3].id))); adicionar_irmao((yyvsp[-4].node), criar_no("MethodParams","")); (yyvsp[-4].node)->irmao->irmao->filho=(yyvsp[-1].node);}
#line 1545 "y.tab.c"
    break;

  case 16: /* MethodHeader: VOID ID LPAR FormalParams RPAR  */
#line 114 "jucompiler.y"
                                                {if(DEBUG)printf("method header void params \n");(yyval.node)=criar_no("MethodHeader",""); (yyval.node)->filho=criar_no("Void",""); adicionar_irmao((yyval.node)->filho, criar_no("Id",(yyvsp[-3].id))); adicionar_irmao((yyval.node)->filho,criar_no("MethodParams","")); (yyval.node)->filho->irmao->irmao->filho=(yyvsp[-1].node);}
#line 1551 "y.tab.c"
    break;

  case 17: /* MethodHeader: Type ID LPAR RPAR  */
#line 115 "jucompiler.y"
                                                {if(DEBUG)printf("method header type no params \n");(yyval.node)=criar_no("MethodHeader",""); (yyval.node)->filho=(yyvsp[-3].node); adicionar_irmao((yyvsp[-3].node), criar_no("Id",(yyvsp[-2].id))); adicionar_irmao((yyvsp[-3].node), criar_no("MethodParams",""));}
#line 1557 "y.tab.c"
    break;

  case 18: /* MethodHeader: VOID ID LPAR RPAR  */
#line 116 "jucompiler.y"
                                                {if(DEBUG)printf("method header void no params \n");(yyval.node)=criar_no("MethodHeader",""); (yyval.node)->filho=criar_no("Void",""); adicionar_irmao((yyval.node)->filho, criar_no("Id",(yyvsp[-2].id))); adicionar_irmao((yyval.node)->filho,criar_no("MethodParams",""));}
#line 1563 "y.tab.c"
    break;

  case 19: /* FormalParams: Type ID CommaTypeIdRep  */
#line 119 "jucompiler.y"
                                     {if(DEBUG)printf("formalsparams type \n");(yyval.node)=criar_no("ParamDecl",""); (yyval.node)->filho=(yyvsp[-2].node);adicionar_irmao((yyvsp[-2].node), criar_no("Id",(yyvsp[-1].id)));adicionar_irmao((yyval.node),(yyvsp[0].node));}
#line 1569 "y.tab.c"
    break;

  case 20: /* FormalParams: STRING LSQ RSQ ID  */
#line 120 "jucompiler.y"
                                {if(DEBUG)printf("formalparams string \n");(yyval.node)=criar_no("ParamDecl",""); (yyval.node)->filho=criar_no("StringArray",""); adicionar_irmao((yyval.node)->filho, criar_no("Id",(yyvsp[0].id)));}
#line 1575 "y.tab.c"
    break;

  case 21: /* CommaTypeIdRep: COMMA Type ID CommaTypeIdRep  */
#line 122 "jucompiler.y"
                                             {if(DEBUG)printf("commatypeidrep \n"); (yyval.node) = criar_no("ParamDecl",""); (yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node),criar_no("Id",(yyvsp[-1].id))); adicionar_irmao((yyval.node),(yyvsp[0].node));}
#line 1581 "y.tab.c"
    break;

  case 22: /* CommaTypeIdRep: %empty  */
#line 123 "jucompiler.y"
                                             {if(DEBUG)printf("commatypeidrep empty \n");(yyval.node)=NULL;}
#line 1587 "y.tab.c"
    break;

  case 23: /* MethodBody: LBRACE StatementVarRep RBRACE  */
#line 126 "jucompiler.y"
                                          {if(DEBUG)printf("methodbody \n");(yyval.node)=criar_no("MethodBody","");(yyval.node)->filho=(yyvsp[-1].node);}
#line 1593 "y.tab.c"
    break;

  case 24: /* StatementVarRep: Statement StatementVarRep  */
#line 128 "jucompiler.y"
                                           {if(DEBUG)printf("statementvarrep stat \n"); if((yyvsp[-1].node) != NULL){(yyval.node)=(yyvsp[-1].node); adicionar_irmao((yyval.node),(yyvsp[0].node));}else (yyval.node)=(yyvsp[0].node);}
#line 1599 "y.tab.c"
    break;

  case 25: /* StatementVarRep: VarDecl StatementVarRep  */
#line 129 "jucompiler.y"
                                           {if(DEBUG)printf("statementvarrep vardecl \n");(yyval.node)=(yyvsp[-1].node); adicionar_irmao((yyval.node),(yyvsp[0].node));}
#line 1605 "y.tab.c"
    break;

  case 26: /* StatementVarRep: %empty  */
#line 130 "jucompiler.y"
                                           {if(DEBUG)printf("statementvarrep empty \n");(yyval.node)=NULL;}
#line 1611 "y.tab.c"
    break;

  case 27: /* VarDecl: Type ID CommaIdRep SEMICOLON  */
#line 133 "jucompiler.y"
                                      {if(DEBUG)printf("vardecl solo \n");(yyval.node)=criar_no("VarDecl",""); (yyval.node)->filho=(yyvsp[-3].node); adicionar_irmao((yyvsp[-3].node), criar_no("Id",(yyvsp[-2].id))); if((yyvsp[-1].node)!=NULL){tmp = (yyvsp[-1].node); while(tmp != NULL){ no* tmp1 = criar_no("VarDecl","");no* tmp2 = criar_no((yyvsp[-3].node)->tipo,(yyvsp[-3].node)->val); tmp1->filho= tmp2; adicionar_irmao(tmp2,criar_no("Id",tmp->val)); adicionar_irmao((yyval.node),tmp1); tmp = tmp->irmao;} } ;}
#line 1617 "y.tab.c"
    break;

  case 28: /* Statement: LBRACE StatementRep RBRACE  */
#line 135 "jucompiler.y"
                                                      {if(DEBUG)printf("statement block\n");if( contador_irmaos((yyvsp[-1].node))>1){(yyval.node)=criar_no("Block","");(yyval.node)->filho=(yyvsp[-1].node);}else{(yyval.node)=(yyvsp[-1].node);}}
#line 1623 "y.tab.c"
    break;

  case 29: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 136 "jucompiler.y"
                                                      {if(DEBUG)printf("statement if full\n");(yyval.node)=criar_no("If",""); (yyval.node)->filho=(yyvsp[-4].node); tmp = criar_no("Block","");
                                                                                                                        if ((yyvsp[-2].node) != NULL && contador_irmaos((yyvsp[-2].node)) == 1) {
                                                                                                                            adicionar_irmao((yyvsp[-4].node), (yyvsp[-2].node));
                                                                                                                            if ((yyvsp[0].node) != NULL && contador_irmaos((yyvsp[0].node)) == 1) {
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
                                                                                                                            if ((yyvsp[0].node) != NULL && contador_irmaos((yyvsp[0].node)) == 1 ) {
                                                                                                                                adicionar_irmao(tmp, (yyvsp[0].node));
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                no* tmp_aux = criar_no("Block","");
                                                                                                                                adicionar_irmao(tmp, tmp_aux);
                                                                                                                                tmp_aux->filho = (yyvsp[0].node);
                                                                                                                            }
                                                                                                                        }}
#line 1651 "y.tab.c"
    break;

  case 30: /* Statement: IF LPAR Expr RPAR Statement  */
#line 159 "jucompiler.y"
                                                      {if(DEBUG)printf("statement if solo\n");(yyval.node)=criar_no("If",""); (yyval.node)->filho=(yyvsp[-2].node);tmp = criar_no("Block","");if((yyvsp[0].node) != NULL && contador_irmaos((yyvsp[0].node)) == 1 ){adicionar_irmao((yyvsp[-2].node),(yyvsp[0].node)); adicionar_irmao((yyvsp[0].node), tmp);}else{adicionar_irmao((yyvsp[-2].node),tmp); tmp->filho = (yyvsp[0].node); adicionar_irmao(tmp,criar_no("Block",""));}}
#line 1657 "y.tab.c"
    break;

  case 31: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 160 "jucompiler.y"
                                                      {if(DEBUG)printf("statement while\n");(yyval.node)=criar_no("While",""); (yyval.node)->filho=(yyvsp[-2].node); if((yyvsp[0].node) != NULL && contador_irmaos((yyvsp[0].node)) < 2){adicionar_irmao((yyvsp[-2].node),(yyvsp[0].node));}else{tmp = criar_no("Block",""); adicionar_irmao((yyvsp[-2].node),tmp); tmp->filho = (yyvsp[0].node);} }
#line 1663 "y.tab.c"
    break;

  case 32: /* Statement: RETURN Expr SEMICOLON  */
#line 161 "jucompiler.y"
                                                      {if(DEBUG)printf("statement return expr\n");(yyval.node)=criar_no("Return",""); (yyval.node)->filho=(yyvsp[-1].node);}
#line 1669 "y.tab.c"
    break;

  case 33: /* Statement: RETURN SEMICOLON  */
#line 162 "jucompiler.y"
                                                      {if(DEBUG)printf("statement return\n");(yyval.node)=criar_no("Return","");}
#line 1675 "y.tab.c"
    break;

  case 34: /* Statement: PRINT LPAR Expr RPAR SEMICOLON  */
#line 163 "jucompiler.y"
                                                      {if(DEBUG)printf("statement print expr\n");(yyval.node)=criar_no("Print","");(yyval.node)->filho=(yyvsp[-2].node);}
#line 1681 "y.tab.c"
    break;

  case 35: /* Statement: PRINT LPAR STRLIT RPAR SEMICOLON  */
#line 164 "jucompiler.y"
                                                      {if(DEBUG)printf("statement print str\n");(yyval.node)=criar_no("Print","");(yyval.node)->filho=criar_no("StrLit",(yyvsp[-2].id));}
#line 1687 "y.tab.c"
    break;

  case 36: /* Statement: MethodInvocation SEMICOLON  */
#line 165 "jucompiler.y"
                                                      {if(DEBUG)printf("statement MI\n");(yyval.node)=(yyvsp[-1].node);}
#line 1693 "y.tab.c"
    break;

  case 37: /* Statement: Assignment SEMICOLON  */
#line 166 "jucompiler.y"
                                                      {if(DEBUG)printf("statement agn\n");(yyval.node)=(yyvsp[-1].node);}
#line 1699 "y.tab.c"
    break;

  case 38: /* Statement: ParseArgs SEMICOLON  */
#line 167 "jucompiler.y"
                                                      {if(DEBUG)printf("statement pa\n");(yyval.node)=(yyvsp[-1].node);}
#line 1705 "y.tab.c"
    break;

  case 39: /* Statement: SEMICOLON  */
#line 168 "jucompiler.y"
                                                      {if(DEBUG)printf("statement semicolon\n");(yyval.node)=NULL;}
#line 1711 "y.tab.c"
    break;

  case 40: /* Statement: error SEMICOLON  */
#line 169 "jucompiler.y"
                                                      {(yyval.node)=NULL;if(DEBUG)printf("statement error\n");flag_tree=0;}
#line 1717 "y.tab.c"
    break;

  case 41: /* StatementRep: Statement StatementRep  */
#line 171 "jucompiler.y"
                                     {if(DEBUG)printf("statementrep \n"); if((yyvsp[-1].node)!=NULL){(yyval.node)=(yyvsp[-1].node);adicionar_irmao((yyval.node),(yyvsp[0].node));} else { (yyval.node)=(yyvsp[0].node);}}
#line 1723 "y.tab.c"
    break;

  case 42: /* StatementRep: %empty  */
#line 172 "jucompiler.y"
                                     {if(DEBUG)printf("statement rep empty \n");(yyval.node)=NULL;}
#line 1729 "y.tab.c"
    break;

  case 43: /* MethodInvocation: ID LPAR RPAR  */
#line 175 "jucompiler.y"
                                                 {if(DEBUG)printf("methodinvocation \n");(yyval.node)=criar_no("Call",""); (yyval.node)->filho = criar_no("Id",(yyvsp[-2].id));}
#line 1735 "y.tab.c"
    break;

  case 44: /* MethodInvocation: ID LPAR Expr CommaExprRep RPAR  */
#line 176 "jucompiler.y"
                                                 {if(DEBUG)printf("methodinvocation \n");(yyval.node)=criar_no("Call",""); (yyval.node)->filho = criar_no("Id",(yyvsp[-4].id)); adicionar_irmao((yyval.node)->filho,(yyvsp[-2].node)); adicionar_irmao((yyvsp[-2].node),(yyvsp[-1].node));}
#line 1741 "y.tab.c"
    break;

  case 45: /* MethodInvocation: ID LPAR error RPAR  */
#line 177 "jucompiler.y"
                                        {(yyval.node)=NULL;if(DEBUG)printf("methodinvocation \n");flag_tree=0;}
#line 1747 "y.tab.c"
    break;

  case 46: /* CommaExprRep: COMMA Expr CommaExprRep  */
#line 181 "jucompiler.y"
                                      {if(DEBUG)printf("commaexprrep \n");if((yyvsp[-1].node)!=NULL){(yyval.node)=(yyvsp[-1].node);adicionar_irmao((yyval.node),(yyvsp[0].node));}else (yyval.node)=(yyvsp[-1].node);}
#line 1753 "y.tab.c"
    break;

  case 47: /* CommaExprRep: %empty  */
#line 182 "jucompiler.y"
                                      {if(DEBUG)printf("commmaexprrep empty \n");(yyval.node)=NULL;}
#line 1759 "y.tab.c"
    break;

  case 48: /* Assignment: ID ASSIGN Expr  */
#line 186 "jucompiler.y"
                           {if(DEBUG)printf("assign \n");(yyval.node)=criar_no("Assign","");(yyval.node)->filho=criar_no("Id",(yyvsp[-2].id)); adicionar_irmao((yyval.node)->filho,(yyvsp[0].node));}
#line 1765 "y.tab.c"
    break;

  case 49: /* ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR  */
#line 188 "jucompiler.y"
                                              {if(DEBUG)printf("parseargs full \n");(yyval.node)=criar_no("ParseArgs",""); (yyval.node)->filho=criar_no("Id",(yyvsp[-4].id)); adicionar_irmao((yyval.node)->filho,(yyvsp[-2].node));}
#line 1771 "y.tab.c"
    break;

  case 50: /* ParseArgs: PARSEINT LPAR error RPAR  */
#line 189 "jucompiler.y"
                                    {(yyval.node)=NULL;if(DEBUG)printf("parseargs error \n");flag_tree=0;}
#line 1777 "y.tab.c"
    break;

  case 51: /* Expr: ExprOp  */
#line 192 "jucompiler.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 1783 "y.tab.c"
    break;

  case 52: /* Expr: Assignment  */
#line 193 "jucompiler.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 1789 "y.tab.c"
    break;

  case 53: /* ExprOp: LPAR Expr RPAR  */
#line 196 "jucompiler.y"
                              {if(DEBUG)printf("ExprOp brace\n");(yyval.node)=(yyvsp[-1].node);}
#line 1795 "y.tab.c"
    break;

  case 54: /* ExprOp: MethodInvocation  */
#line 197 "jucompiler.y"
                            {if(DEBUG)printf("ExprOp MI\n");(yyval.node)=(yyvsp[0].node);}
#line 1801 "y.tab.c"
    break;

  case 55: /* ExprOp: ParseArgs  */
#line 198 "jucompiler.y"
                            {if(DEBUG)printf("ExprOp pa\n");(yyval.node)=(yyvsp[0].node);}
#line 1807 "y.tab.c"
    break;

  case 56: /* ExprOp: ID  */
#line 199 "jucompiler.y"
                            {if(DEBUG)printf("ExprOp id\n");(yyval.node)=criar_no("Id",(yyvsp[0].id));}
#line 1813 "y.tab.c"
    break;

  case 57: /* ExprOp: ID DOTLENGTH  */
#line 200 "jucompiler.y"
                            {if(DEBUG)printf("ExprOp dotlenght\n");(yyval.node)=criar_no("Length",""); (yyval.node)->filho = criar_no("Id",(yyvsp[-1].id));}
#line 1819 "y.tab.c"
    break;

  case 58: /* ExprOp: INTLIT  */
#line 201 "jucompiler.y"
                            {if(DEBUG)printf("ExprOp intlit\n");(yyval.node)=criar_no("DecLit",(yyvsp[0].id));}
#line 1825 "y.tab.c"
    break;

  case 59: /* ExprOp: REALLIT  */
#line 202 "jucompiler.y"
                            {if(DEBUG)printf("ExprOp reallit\n");(yyval.node)=criar_no("RealLit",(yyvsp[0].id));}
#line 1831 "y.tab.c"
    break;

  case 60: /* ExprOp: BOOLLIT  */
#line 203 "jucompiler.y"
                            {if(DEBUG)printf("ExprOp boollit\n");(yyval.node)=criar_no("BoolLit",(yyvsp[0].id));}
#line 1837 "y.tab.c"
    break;

  case 61: /* ExprOp: MINUS ExprOp  */
#line 204 "jucompiler.y"
                                       {if(DEBUG)printf("ExprOp self minus\n");(yyval.node)=criar_no("Minus",""); (yyval.node)->filho=(yyvsp[0].node);}
#line 1843 "y.tab.c"
    break;

  case 62: /* ExprOp: NOT ExprOp  */
#line 205 "jucompiler.y"
                              {if(DEBUG)printf("ExprOp self not\n");(yyval.node)=criar_no("Not",""); (yyval.node)->filho=(yyvsp[0].node);}
#line 1849 "y.tab.c"
    break;

  case 63: /* ExprOp: PLUS ExprOp  */
#line 206 "jucompiler.y"
                              {if(DEBUG)printf("ExprOp self plus\n");(yyval.node)=criar_no("Plus",""); (yyval.node)->filho=(yyvsp[0].node);}
#line 1855 "y.tab.c"
    break;

  case 64: /* ExprOp: ExprOp PLUS ExprOp  */
#line 207 "jucompiler.y"
                                {if(DEBUG)printf("ExprOp plus\n");(yyval.node)=criar_no("Add",""); (yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1861 "y.tab.c"
    break;

  case 65: /* ExprOp: ExprOp MINUS ExprOp  */
#line 208 "jucompiler.y"
                                {if(DEBUG)printf("ExprOp MINUS\n");(yyval.node)=criar_no("Sub","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1867 "y.tab.c"
    break;

  case 66: /* ExprOp: ExprOp STAR ExprOp  */
#line 209 "jucompiler.y"
                                {if(DEBUG)printf("ExprOp STAR\n");(yyval.node)=criar_no("Mul","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1873 "y.tab.c"
    break;

  case 67: /* ExprOp: ExprOp DIV ExprOp  */
#line 210 "jucompiler.y"
                                {if(DEBUG)printf("ExprOp DIV\n");(yyval.node)=criar_no("Div","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1879 "y.tab.c"
    break;

  case 68: /* ExprOp: ExprOp MOD ExprOp  */
#line 211 "jucompiler.y"
                                {if(DEBUG)printf("ExprOp MOD\n");(yyval.node)=criar_no("Mod","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1885 "y.tab.c"
    break;

  case 69: /* ExprOp: ExprOp AND ExprOp  */
#line 212 "jucompiler.y"
                                {if(DEBUG)printf("ExprOp AND\n");(yyval.node)=criar_no("And","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1891 "y.tab.c"
    break;

  case 70: /* ExprOp: ExprOp OR ExprOp  */
#line 213 "jucompiler.y"
                                {if(DEBUG)printf("ExprOp OR\n");(yyval.node)=criar_no("Or","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1897 "y.tab.c"
    break;

  case 71: /* ExprOp: ExprOp XOR ExprOp  */
#line 214 "jucompiler.y"
                                {if(DEBUG)printf("ExprOp XOR\n");(yyval.node)=criar_no("Xor","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1903 "y.tab.c"
    break;

  case 72: /* ExprOp: ExprOp LSHIFT ExprOp  */
#line 215 "jucompiler.y"
                                {if(DEBUG)printf("ExprOp LSHIFT\n");(yyval.node)=criar_no("Lshift","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1909 "y.tab.c"
    break;

  case 73: /* ExprOp: ExprOp RSHIFT ExprOp  */
#line 216 "jucompiler.y"
                                {if(DEBUG)printf("ExprOp RSHIFT\n");(yyval.node)=criar_no("Rshift","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1915 "y.tab.c"
    break;

  case 74: /* ExprOp: ExprOp EQ ExprOp  */
#line 217 "jucompiler.y"
                                {if(DEBUG)printf("ExprOp EQ\n");(yyval.node)=criar_no("Eq","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1921 "y.tab.c"
    break;

  case 75: /* ExprOp: ExprOp GE ExprOp  */
#line 218 "jucompiler.y"
                                {if(DEBUG)printf("ExprOp GE\n");(yyval.node)=criar_no("Ge","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1927 "y.tab.c"
    break;

  case 76: /* ExprOp: ExprOp GT ExprOp  */
#line 219 "jucompiler.y"
                                {if(DEBUG)printf("ExprOp GT\n");(yyval.node)=criar_no("Gt","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1933 "y.tab.c"
    break;

  case 77: /* ExprOp: ExprOp LE ExprOp  */
#line 220 "jucompiler.y"
                                {if(DEBUG)printf("ExprOp LE\n");(yyval.node)=criar_no("Le","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1939 "y.tab.c"
    break;

  case 78: /* ExprOp: ExprOp LT ExprOp  */
#line 221 "jucompiler.y"
                                {if(DEBUG)printf("ExprOp LT\n");(yyval.node)=criar_no("Lt","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1945 "y.tab.c"
    break;

  case 79: /* ExprOp: ExprOp NE ExprOp  */
#line 222 "jucompiler.y"
                                {if(DEBUG)printf("ExprOp NE\n");(yyval.node)=criar_no("Ne","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1951 "y.tab.c"
    break;

  case 80: /* ExprOp: LPAR error RPAR  */
#line 223 "jucompiler.y"
                            {(yyval.node)=NULL;if(DEBUG)printf("ExprOp error\n");flag_tree=0;}
#line 1957 "y.tab.c"
    break;


#line 1961 "y.tab.c"

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

#line 227 "jucompiler.y"

