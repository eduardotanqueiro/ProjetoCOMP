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
    //  Ricardo Silva - 2020
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
#line 78 "jucompiler.y"

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
  YYSYMBOL_Expr = 70                       /* Expr  */
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
#define YYLAST   594

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

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
       0,    87,    87,    90,    91,    92,    93,    97,   100,   101,
     103,   104,   108,   109,   110,   112,   113,   114,   115,   118,
     119,   121,   122,   125,   127,   128,   129,   132,   134,   135,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   170,   171,   174,   175,   176,   180,   181,   185,   187,
     188,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218
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
  "MethodInvocation", "CommaExprRep", "Assignment", "ParseArgs", "Expr", YY_NULLPTR
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
     -27,    21,    28,    22,   -47,    37,    14,    37,     2,    59,
      37,    37,   -47,   -47,    19,   -47,   -47,   -47,   -47,   -47,
     -47,    71,    89,    76,    77,    60,    13,   -47,    56,    95,
      80,    84,    85,    50,    33,   -47,    83,    88,    98,   202,
     100,   120,    97,    13,    13,    99,   101,   103,   -47,   106,
     125,   107,   126,   -47,   108,   -47,   -47,   234,   166,    33,
     111,   234,   209,     4,    -6,   -47,   -47,   -47,   177,   234,
     234,   234,   -47,   -47,   -47,   -47,   249,   234,   126,   -47,
     -47,   -47,   -47,   -47,   -47,   110,   129,   -47,   -47,   -47,
     445,   114,   -47,   277,   -47,   -47,   305,   116,   333,   118,
     128,   -47,   134,   361,    29,   -47,    29,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     -47,   234,   234,   234,   389,   137,   146,     5,   -47,   -47,
     234,   145,    46,   144,   153,   -47,   234,   -47,   -47,   498,
     -47,   -47,   547,   560,   560,   560,   560,    29,   -47,   547,
     473,    29,   219,   219,   523,    46,   -47,   -47,   173,   277,
     -47,   138,   -47,   -47,   417,   -47,   129,   -47,    46,   157,
     -47,   -47,   -47
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
       0,     0,     0,     0,    55,    57,    58,    59,     0,     0,
       0,     0,    33,    52,    53,    54,     0,     0,    11,    23,
      25,    24,    36,    37,    38,     0,    22,    16,    10,    15,
      48,     0,    43,    47,    41,    28,     0,     0,     0,     0,
       0,    56,     0,     0,    60,    61,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,     0,     0,     0,     0,     0,     0,     0,    19,    45,
       0,     0,     0,     0,     0,    50,     0,    79,    51,    68,
      65,    66,    73,    74,    75,    76,    77,    64,    67,    78,
      69,    63,    71,    72,    70,     0,    27,    20,     0,    47,
      44,    30,    35,    34,     0,    31,    22,    46,     0,     0,
      21,    29,    49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -47,   -47,    73,   -47,   -47,   -46,    -3,   -47,   159,    24,
     -47,    27,   -47,   -33,   133,   -26,    35,   -24,   -22,    43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    10,    11,    31,    41,    23,    51,   128,
      27,    42,    43,    44,    60,    73,   131,    74,    75,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    59,    46,    57,    47,    99,    88,   100,    45,     1,
      46,    22,    47,    58,    32,    18,    33,    45,    45,    46,
      46,    47,    47,    18,     3,    50,    59,    50,     4,    18,
      34,   101,   125,    45,    32,    46,    33,    47,     6,     5,
     108,   -26,   109,    19,    35,    12,    20,    32,    14,    33,
      34,    19,   116,    36,    20,    37,    38,    19,    39,    57,
      20,   -42,    40,    34,    35,    -6,    18,    21,     7,    58,
      80,    81,    29,    36,    24,    37,    38,    35,    39,    30,
      13,     8,    40,    16,    17,    48,    36,    15,    37,    38,
      18,    39,    25,    26,    19,    40,    28,    20,    52,   161,
      90,    93,    61,    49,    96,    98,    45,    62,    46,    53,
      47,   103,   104,   105,   106,    55,    56,    63,    19,    77,
     124,    20,   165,    78,   158,    79,    85,    49,    86,    45,
      82,    46,    83,    47,    84,   171,    87,    89,    29,    95,
     126,   127,    45,   129,    46,   133,    47,   135,   136,   157,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   137,   152,   153,   154,    91,   156,    64,
      65,    66,    67,   159,   160,   162,   166,   168,   102,   164,
      64,    65,    66,    67,   163,    68,   172,     0,    69,    54,
     170,    70,    94,    71,   167,    92,    68,     0,     0,    69,
       0,     0,    70,     0,    71,    64,    65,    66,    67,    38,
       0,     0,    64,    65,    66,    67,    97,     0,     0,     0,
      38,    68,     0,     0,    69,     0,     0,    70,    68,    71,
     108,    69,   109,    72,    70,     0,    71,    64,    65,    66,
      67,   115,   116,     0,     0,    38,   119,     0,     0,     0,
       0,     0,    38,    68,     0,     0,    69,   107,     0,    70,
     108,    71,   109,   110,   111,   112,     0,   113,     0,     0,
     114,   115,   116,   117,     0,   118,   119,    38,     0,     0,
     120,     0,   121,   122,   123,   107,     0,     0,   108,   130,
     109,   110,   111,   112,     0,   113,     0,     0,   114,   115,
     116,   117,     0,   118,   119,     0,     0,     0,     0,     0,
     121,   122,   123,   107,     0,     0,   108,     0,   109,   110,
     111,   112,     0,   113,     0,     0,   114,   115,   116,   117,
       0,   118,   119,     0,   132,     0,     0,     0,   121,   122,
     123,   107,     0,     0,   108,     0,   109,   110,   111,   112,
       0,   113,     0,     0,   114,   115,   116,   117,     0,   118,
     119,     0,   134,     0,     0,     0,   121,   122,   123,   107,
       0,     0,   108,     0,   109,   110,   111,   112,     0,   113,
       0,     0,   114,   115,   116,   117,     0,   118,   119,     0,
     138,     0,     0,     0,   121,   122,   123,   107,     0,     0,
     108,     0,   109,   110,   111,   112,     0,   113,     0,     0,
     114,   115,   116,   117,     0,   118,   119,     0,   155,     0,
       0,     0,   121,   122,   123,   107,     0,     0,   108,     0,
     109,   110,   111,   112,     0,   113,     0,     0,   114,   115,
     116,   117,     0,   118,   119,     0,     0,   169,     0,     0,
     121,   122,   123,   107,     0,     0,   108,     0,   109,   110,
     111,   112,     0,   113,     0,     0,   114,   115,   116,   117,
       0,   118,   119,     0,     0,     0,     0,     0,   121,   122,
     123,   107,     0,     0,   108,     0,   109,   110,   111,   112,
       0,   113,     0,     0,   114,   115,   116,   117,     0,     0,
     119,     0,     0,     0,     0,     0,   121,   122,   123,   108,
       0,   109,   110,   111,   112,     0,   113,     0,     0,   114,
     115,   116,   117,     0,     0,   119,     0,     0,     0,     0,
       0,   121,   122,   123,   108,     0,   109,   110,   111,   112,
       0,   113,     0,     0,   114,   115,   116,   117,     0,     0,
     119,     0,     0,     0,     0,     0,   121,   122,   108,     0,
     109,     0,   111,   112,     0,   113,     0,     0,   114,   115,
     116,   108,     0,   109,   119,     0,     0,     0,     0,     0,
     121,   122,   115,   116,     0,     0,     0,   119,     0,     0,
       0,     0,     0,   121,   122
};

static const yytype_int16 yycheck[] =
{
      26,    34,    26,     9,    26,     1,    52,     3,    34,    36,
      34,    14,    34,    19,     1,    10,     3,    43,    44,    43,
      44,    43,    44,    10,     3,    28,    59,    30,     0,    10,
      17,    37,    78,    59,     1,    59,     3,    59,     1,    17,
      11,    28,    13,    38,    31,    31,    41,     1,    46,     3,
      17,    38,    23,    40,    41,    42,    43,    38,    45,     9,
      41,    28,    49,    17,    31,    28,    10,    48,    31,    19,
      43,    44,    12,    40,     3,    42,    43,    31,    45,    19,
       7,    44,    49,    10,    11,    29,    40,    28,    42,    43,
      10,    45,     3,    17,    38,    49,    19,    41,     3,   132,
      57,    58,    19,    47,    61,    62,   132,    19,   132,    29,
     132,    68,    69,    70,    71,    31,    31,    19,    38,    19,
      77,    41,   155,     3,   127,    28,    20,    47,     3,   155,
      31,   155,    31,   155,    31,   168,    29,    29,    12,    28,
      30,    12,   168,    29,   168,    29,   168,    29,    20,     3,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    29,   121,   122,   123,     1,    31,     3,
       4,     5,     6,   130,    29,    31,     3,    39,     1,   136,
       3,     4,     5,     6,    31,    19,    29,    -1,    22,    30,
     166,    25,    59,    27,   159,    29,    19,    -1,    -1,    22,
      -1,    -1,    25,    -1,    27,     3,     4,     5,     6,    43,
      -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      43,    19,    -1,    -1,    22,    -1,    -1,    25,    19,    27,
      11,    22,    13,    31,    25,    -1,    27,     3,     4,     5,
       6,    22,    23,    -1,    -1,    43,    27,    -1,    -1,    -1,
      -1,    -1,    43,    19,    -1,    -1,    22,     8,    -1,    25,
      11,    27,    13,    14,    15,    16,    -1,    18,    -1,    -1,
      21,    22,    23,    24,    -1,    26,    27,    43,    -1,    -1,
      31,    -1,    33,    34,    35,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    -1,    18,    -1,    -1,    21,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,     8,    -1,    -1,    11,    -1,    13,    14,
      15,    16,    -1,    18,    -1,    -1,    21,    22,    23,    24,
      -1,    26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,
      35,     8,    -1,    -1,    11,    -1,    13,    14,    15,    16,
      -1,    18,    -1,    -1,    21,    22,    23,    24,    -1,    26,
      27,    -1,    29,    -1,    -1,    -1,    33,    34,    35,     8,
      -1,    -1,    11,    -1,    13,    14,    15,    16,    -1,    18,
      -1,    -1,    21,    22,    23,    24,    -1,    26,    27,    -1,
      29,    -1,    -1,    -1,    33,    34,    35,     8,    -1,    -1,
      11,    -1,    13,    14,    15,    16,    -1,    18,    -1,    -1,
      21,    22,    23,    24,    -1,    26,    27,    -1,    29,    -1,
      -1,    -1,    33,    34,    35,     8,    -1,    -1,    11,    -1,
      13,    14,    15,    16,    -1,    18,    -1,    -1,    21,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,    35,     8,    -1,    -1,    11,    -1,    13,    14,
      15,    16,    -1,    18,    -1,    -1,    21,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,     8,    -1,    -1,    11,    -1,    13,    14,    15,    16,
      -1,    18,    -1,    -1,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    11,
      -1,    13,    14,    15,    16,    -1,    18,    -1,    -1,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    11,    -1,    13,    14,    15,    16,
      -1,    18,    -1,    -1,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    11,    -1,
      13,    -1,    15,    16,    -1,    18,    -1,    -1,    21,    22,
      23,    11,    -1,    13,    27,    -1,    -1,    -1,    -1,    -1,
      33,    34,    22,    23,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    33,    34
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
      25,    27,    31,    66,    68,    69,    70,    19,     3,    28,
      62,    62,    31,    31,    31,    20,     3,    29,    56,    29,
      70,     1,    29,    70,    65,    28,    70,     7,    70,     1,
       3,    37,     1,    70,    70,    70,    70,     8,    11,    13,
      14,    15,    16,    18,    21,    22,    23,    24,    26,    27,
      31,    33,    34,    35,    70,    56,    30,    12,    60,    29,
      12,    67,    29,    29,    29,    29,    20,    29,    29,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    29,    31,     3,    57,    70,
      29,    64,    31,    31,    70,    64,     3,    67,    39,    30,
      60,    64,    29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    57,    58,    58,    58,    58,    59,
      59,    60,    60,    61,    62,    62,    62,    63,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    65,    65,    66,    66,    66,    67,    67,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     2,     2,     0,     4,     6,     2,
       3,     0,     1,     1,     1,     5,     5,     4,     4,     3,
       4,     4,     0,     3,     2,     2,     0,     4,     3,     7,
       5,     5,     3,     2,     5,     5,     2,     2,     2,     1,
       2,     2,     0,     3,     5,     4,     3,     0,     3,     7,
       4,     3,     1,     1,     1,     1,     2,     1,     1,     1,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3
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
#line 87 "jucompiler.y"
                                                         {if(DEBUG)printf("program\n");(yyval.node)=raiz=criar_no("Program",""); (yyval.node)->filho = criar_no("Id",(yyvsp[-3].id)); adicionar_irmao((yyval.node)->filho, (yyvsp[-1].node));}
#line 1496 "y.tab.c"
    break;

  case 3: /* MethodFieldSemicolonRep: MethodDecl MethodFieldSemicolonRep  */
#line 90 "jucompiler.y"
                                                            {if(DEBUG)printf("method dcl prog\n");(yyval.node)=(yyvsp[-1].node); adicionar_irmao((yyval.node),(yyvsp[0].node));}
#line 1502 "y.tab.c"
    break;

  case 4: /* MethodFieldSemicolonRep: FieldDecl MethodFieldSemicolonRep  */
#line 91 "jucompiler.y"
                                                            {if(DEBUG)printf("field decl prog\n"); if((yyvsp[-1].node)!=NULL){(yyval.node)=(yyvsp[-1].node); adicionar_irmao((yyval.node),(yyvsp[0].node));}else (yyval.node)=(yyvsp[0].node);}
#line 1508 "y.tab.c"
    break;

  case 5: /* MethodFieldSemicolonRep: SEMICOLON MethodFieldSemicolonRep  */
#line 92 "jucompiler.y"
                                                            {if(DEBUG)printf("semicolon \n");(yyval.node)=(yyvsp[0].node);}
#line 1514 "y.tab.c"
    break;

  case 6: /* MethodFieldSemicolonRep: %empty  */
#line 93 "jucompiler.y"
                                                            {if(DEBUG)printf("method dcl prog rep empty \n");(yyval.node)=NULL;}
#line 1520 "y.tab.c"
    break;

  case 7: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 97 "jucompiler.y"
                                                  {if(DEBUG)printf("method dcl solo\n");(yyval.node)= criar_no("MethodDecl",""), (yyval.node)->filho=(yyvsp[-1].node); adicionar_irmao((yyvsp[-1].node),(yyvsp[0].node));}
#line 1526 "y.tab.c"
    break;

  case 8: /* FieldDecl: PUBLIC STATIC Type ID CommaIdRep SEMICOLON  */
#line 100 "jucompiler.y"
                                                      {if(DEBUG)printf("field decl solo \n");(yyval.node)=criar_no("FieldDecl",""), (yyval.node)->filho=(yyvsp[-3].node); adicionar_irmao((yyvsp[-3].node),criar_no("Id",(yyvsp[-2].id))); if((yyvsp[-1].node)!=NULL){tmp = (yyvsp[-1].node); while(tmp != NULL){ no* tmp1 = criar_no("FieldDecl","");no* tmp2 = criar_no((yyvsp[-3].node)->tipo,(yyvsp[-3].node)->val); tmp1->filho= tmp2; adicionar_irmao(tmp2,criar_no("Id",tmp->val)); adicionar_irmao((yyval.node),tmp1); tmp = tmp->irmao;} } ;}
#line 1532 "y.tab.c"
    break;

  case 9: /* FieldDecl: error SEMICOLON  */
#line 101 "jucompiler.y"
                          {(yyval.node)=NULL;if(DEBUG)printf("fielddecl error \n");flag_tree=0;}
#line 1538 "y.tab.c"
    break;

  case 10: /* CommaIdRep: COMMA ID CommaIdRep  */
#line 103 "jucompiler.y"
                                {if(DEBUG)printf("commma id rep \n");(yyval.node)=criar_no("Id",(yyvsp[-1].id)); adicionar_irmao((yyval.node),(yyvsp[0].node));}
#line 1544 "y.tab.c"
    break;

  case 11: /* CommaIdRep: %empty  */
#line 104 "jucompiler.y"
                                {if(DEBUG)printf("comma id rep empty \n");(yyval.node)=NULL;}
#line 1550 "y.tab.c"
    break;

  case 12: /* Type: BOOL  */
#line 108 "jucompiler.y"
            {if(DEBUG)printf("bool \n");(yyval.node)=criar_no("Bool","");}
#line 1556 "y.tab.c"
    break;

  case 13: /* Type: INT  */
#line 109 "jucompiler.y"
          {if(DEBUG)printf("int \n");(yyval.node)=criar_no("Int","");}
#line 1562 "y.tab.c"
    break;

  case 14: /* Type: DOUBLE  */
#line 110 "jucompiler.y"
             {if(DEBUG)printf("double \n");(yyval.node)=criar_no("Double","");}
#line 1568 "y.tab.c"
    break;

  case 15: /* MethodHeader: Type ID LPAR FormalParams RPAR  */
#line 112 "jucompiler.y"
                                                {if(DEBUG)printf("method header full \n");(yyval.node)=criar_no("MethodHeader",""); (yyval.node)->filho=(yyvsp[-4].node); adicionar_irmao((yyvsp[-4].node), criar_no("Id",(yyvsp[-3].id))); adicionar_irmao((yyvsp[-4].node), criar_no("MethodParams","")); (yyvsp[-4].node)->irmao->irmao->filho=(yyvsp[-1].node);}
#line 1574 "y.tab.c"
    break;

  case 16: /* MethodHeader: VOID ID LPAR FormalParams RPAR  */
#line 113 "jucompiler.y"
                                                {if(DEBUG)printf("method header void params \n");(yyval.node)=criar_no("MethodHeader",""); (yyval.node)->filho=criar_no("Void",""); adicionar_irmao((yyval.node)->filho, criar_no("Id",(yyvsp[-3].id))); adicionar_irmao((yyval.node)->filho,criar_no("MethodParams","")); (yyval.node)->filho->irmao->irmao->filho=(yyvsp[-1].node);}
#line 1580 "y.tab.c"
    break;

  case 17: /* MethodHeader: Type ID LPAR RPAR  */
#line 114 "jucompiler.y"
                                                {if(DEBUG)printf("method header type no params \n");(yyval.node)=criar_no("MethodHeader",""); (yyval.node)->filho=(yyvsp[-3].node); adicionar_irmao((yyvsp[-3].node), criar_no("Id",(yyvsp[-2].id))); adicionar_irmao((yyvsp[-3].node), criar_no("MethodParams",""));}
#line 1586 "y.tab.c"
    break;

  case 18: /* MethodHeader: VOID ID LPAR RPAR  */
#line 115 "jucompiler.y"
                                                {if(DEBUG)printf("method header void no params \n");(yyval.node)=criar_no("MethodHeader",""); (yyval.node)->filho=criar_no("Void",""); adicionar_irmao((yyval.node)->filho, criar_no("Id",(yyvsp[-2].id))); adicionar_irmao((yyval.node)->filho,criar_no("MethodParams",""));}
#line 1592 "y.tab.c"
    break;

  case 19: /* FormalParams: Type ID CommaTypeIdRep  */
#line 118 "jucompiler.y"
                                     {if(DEBUG)printf("formalsparams type \n");(yyval.node)=criar_no("ParamDecl",""); (yyval.node)->filho=(yyvsp[-2].node);adicionar_irmao((yyvsp[-2].node), criar_no("Id",(yyvsp[-1].id)));adicionar_irmao((yyval.node),(yyvsp[0].node));}
#line 1598 "y.tab.c"
    break;

  case 20: /* FormalParams: STRING LSQ RSQ ID  */
#line 119 "jucompiler.y"
                                {if(DEBUG)printf("formalparams string \n");(yyval.node)=criar_no("ParamDecl",""); (yyval.node)->filho=criar_no("StringArray",""); adicionar_irmao((yyval.node)->filho, criar_no("Id",(yyvsp[0].id)));}
#line 1604 "y.tab.c"
    break;

  case 21: /* CommaTypeIdRep: COMMA Type ID CommaTypeIdRep  */
#line 121 "jucompiler.y"
                                             {if(DEBUG)printf("commatypeidrep \n"); (yyval.node) = criar_no("ParamDecl",""); (yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node),criar_no("Id",(yyvsp[-1].id))); adicionar_irmao((yyval.node),(yyvsp[0].node));}
#line 1610 "y.tab.c"
    break;

  case 22: /* CommaTypeIdRep: %empty  */
#line 122 "jucompiler.y"
                                             {if(DEBUG)printf("commatypeidrep empty \n");(yyval.node)=NULL;}
#line 1616 "y.tab.c"
    break;

  case 23: /* MethodBody: LBRACE StatementVarRep RBRACE  */
#line 125 "jucompiler.y"
                                          {if(DEBUG)printf("methodbody \n");(yyval.node)=criar_no("MethodBody","");(yyval.node)->filho=(yyvsp[-1].node);}
#line 1622 "y.tab.c"
    break;

  case 24: /* StatementVarRep: Statement StatementVarRep  */
#line 127 "jucompiler.y"
                                           {if(DEBUG)printf("statementvarrep stat \n"); if((yyvsp[-1].node) != NULL){(yyval.node)=(yyvsp[-1].node); adicionar_irmao((yyval.node),(yyvsp[0].node));}else (yyval.node)=(yyvsp[0].node);}
#line 1628 "y.tab.c"
    break;

  case 25: /* StatementVarRep: VarDecl StatementVarRep  */
#line 128 "jucompiler.y"
                                           {if(DEBUG)printf("statementvarrep vardecl \n");(yyval.node)=(yyvsp[-1].node); adicionar_irmao((yyval.node),(yyvsp[0].node));}
#line 1634 "y.tab.c"
    break;

  case 26: /* StatementVarRep: %empty  */
#line 129 "jucompiler.y"
                                           {if(DEBUG)printf("statementvarrep empty \n");(yyval.node)=NULL;}
#line 1640 "y.tab.c"
    break;

  case 27: /* VarDecl: Type ID CommaIdRep SEMICOLON  */
#line 132 "jucompiler.y"
                                      {if(DEBUG)printf("vardecl solo \n");(yyval.node)=criar_no("VarDecl",""); (yyval.node)->filho=(yyvsp[-3].node); adicionar_irmao((yyvsp[-3].node), criar_no("Id",(yyvsp[-2].id))); if((yyvsp[-1].node)!=NULL){tmp = (yyvsp[-1].node); while(tmp != NULL){ no* tmp1 = criar_no("VarDecl","");no* tmp2 = criar_no((yyvsp[-3].node)->tipo,(yyvsp[-3].node)->val); tmp1->filho= tmp2; adicionar_irmao(tmp2,criar_no("Id",tmp->val)); adicionar_irmao((yyval.node),tmp1); tmp = tmp->irmao;} } ;}
#line 1646 "y.tab.c"
    break;

  case 28: /* Statement: LBRACE StatementRep RBRACE  */
#line 134 "jucompiler.y"
                                                      {if(DEBUG)printf("statement block\n");if( contador_irmaos((yyvsp[-1].node))>1){(yyval.node)=criar_no("Block","");(yyval.node)->filho=(yyvsp[-1].node);}else{(yyval.node)=(yyvsp[-1].node);}}
#line 1652 "y.tab.c"
    break;

  case 29: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 135 "jucompiler.y"
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
#line 1680 "y.tab.c"
    break;

  case 30: /* Statement: IF LPAR Expr RPAR Statement  */
#line 158 "jucompiler.y"
                                                      {if(DEBUG)printf("statement if solo\n");(yyval.node)=criar_no("If",""); (yyval.node)->filho=(yyvsp[-2].node);tmp = criar_no("Block","");if((yyvsp[0].node) != NULL && contador_irmaos((yyvsp[0].node)) == 1 ){adicionar_irmao((yyvsp[-2].node),(yyvsp[0].node)); adicionar_irmao((yyvsp[0].node), tmp);}else{adicionar_irmao((yyvsp[-2].node),tmp); tmp->filho = (yyvsp[0].node); adicionar_irmao(tmp,criar_no("Block",""));}}
#line 1686 "y.tab.c"
    break;

  case 31: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 159 "jucompiler.y"
                                                      {if(DEBUG)printf("statement while\n");(yyval.node)=criar_no("While",""); (yyval.node)->filho=(yyvsp[-2].node); if((yyvsp[0].node) != NULL && contador_irmaos((yyvsp[0].node)) < 2){adicionar_irmao((yyvsp[-2].node),(yyvsp[0].node));}else{tmp = criar_no("Block",""); adicionar_irmao((yyvsp[-2].node),tmp); tmp->filho = (yyvsp[0].node);} }
#line 1692 "y.tab.c"
    break;

  case 32: /* Statement: RETURN Expr SEMICOLON  */
#line 160 "jucompiler.y"
                                                      {if(DEBUG)printf("statement return expr\n");(yyval.node)=criar_no("Return",""); (yyval.node)->filho=(yyvsp[-1].node);}
#line 1698 "y.tab.c"
    break;

  case 33: /* Statement: RETURN SEMICOLON  */
#line 161 "jucompiler.y"
                                                      {if(DEBUG)printf("statement return\n");(yyval.node)=criar_no("Return","");}
#line 1704 "y.tab.c"
    break;

  case 34: /* Statement: PRINT LPAR Expr RPAR SEMICOLON  */
#line 162 "jucompiler.y"
                                                      {if(DEBUG)printf("statement print expr\n");(yyval.node)=criar_no("Print","");(yyval.node)->filho=(yyvsp[-2].node);}
#line 1710 "y.tab.c"
    break;

  case 35: /* Statement: PRINT LPAR STRLIT RPAR SEMICOLON  */
#line 163 "jucompiler.y"
                                                      {if(DEBUG)printf("statement print str\n");(yyval.node)=criar_no("Print","");(yyval.node)->filho=criar_no("StrLit",(yyvsp[-2].id));}
#line 1716 "y.tab.c"
    break;

  case 36: /* Statement: MethodInvocation SEMICOLON  */
#line 164 "jucompiler.y"
                                                      {if(DEBUG)printf("statement MI\n");(yyval.node)=(yyvsp[-1].node);}
#line 1722 "y.tab.c"
    break;

  case 37: /* Statement: Assignment SEMICOLON  */
#line 165 "jucompiler.y"
                                                      {if(DEBUG)printf("statement agn\n");(yyval.node)=(yyvsp[-1].node);}
#line 1728 "y.tab.c"
    break;

  case 38: /* Statement: ParseArgs SEMICOLON  */
#line 166 "jucompiler.y"
                                                      {if(DEBUG)printf("statement pa\n");(yyval.node)=(yyvsp[-1].node);}
#line 1734 "y.tab.c"
    break;

  case 39: /* Statement: SEMICOLON  */
#line 167 "jucompiler.y"
                                                      {if(DEBUG)printf("statement semicolon\n");(yyval.node)=NULL;}
#line 1740 "y.tab.c"
    break;

  case 40: /* Statement: error SEMICOLON  */
#line 168 "jucompiler.y"
                                                      {(yyval.node)=NULL;if(DEBUG)printf("statement error\n");flag_tree=0;}
#line 1746 "y.tab.c"
    break;

  case 41: /* StatementRep: Statement StatementRep  */
#line 170 "jucompiler.y"
                                     {if(DEBUG)printf("statementrep \n"); if((yyvsp[-1].node)!=NULL){(yyval.node)=(yyvsp[-1].node);adicionar_irmao((yyval.node),(yyvsp[0].node));} else { (yyval.node)=(yyvsp[0].node);}}
#line 1752 "y.tab.c"
    break;

  case 42: /* StatementRep: %empty  */
#line 171 "jucompiler.y"
                                     {if(DEBUG)printf("statement rep empty \n");(yyval.node)=NULL;}
#line 1758 "y.tab.c"
    break;

  case 43: /* MethodInvocation: ID LPAR RPAR  */
#line 174 "jucompiler.y"
                                                 {if(DEBUG)printf("methodinvocation \n");(yyval.node)=criar_no("Call",""); (yyval.node)->filho = criar_no("Id",(yyvsp[-2].id));}
#line 1764 "y.tab.c"
    break;

  case 44: /* MethodInvocation: ID LPAR Expr CommaExprRep RPAR  */
#line 175 "jucompiler.y"
                                                 {if(DEBUG)printf("methodinvocation \n");(yyval.node)=criar_no("Call",""); (yyval.node)->filho = criar_no("Id",(yyvsp[-4].id)); adicionar_irmao((yyval.node)->filho,(yyvsp[-2].node)); adicionar_irmao((yyvsp[-2].node),(yyvsp[-1].node));}
#line 1770 "y.tab.c"
    break;

  case 45: /* MethodInvocation: ID LPAR error RPAR  */
#line 176 "jucompiler.y"
                                        {(yyval.node)=NULL;if(DEBUG)printf("methodinvocation \n");flag_tree=0;}
#line 1776 "y.tab.c"
    break;

  case 46: /* CommaExprRep: COMMA Expr CommaExprRep  */
#line 180 "jucompiler.y"
                                      {if(DEBUG)printf("commaexprrep \n");if((yyvsp[-1].node)!=NULL){(yyval.node)=(yyvsp[-1].node);adicionar_irmao((yyval.node),(yyvsp[0].node));}else (yyval.node)=(yyvsp[-1].node);}
#line 1782 "y.tab.c"
    break;

  case 47: /* CommaExprRep: %empty  */
#line 181 "jucompiler.y"
                                      {if(DEBUG)printf("commmaexprrep empty \n");(yyval.node)=NULL;}
#line 1788 "y.tab.c"
    break;

  case 48: /* Assignment: ID ASSIGN Expr  */
#line 185 "jucompiler.y"
                           {if(DEBUG)printf("assign \n");(yyval.node)=criar_no("Assign","");(yyval.node)->filho=criar_no("Id",(yyvsp[-2].id)); adicionar_irmao((yyval.node)->filho,(yyvsp[0].node));}
#line 1794 "y.tab.c"
    break;

  case 49: /* ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR  */
#line 187 "jucompiler.y"
                                              {if(DEBUG)printf("parseargs full \n");(yyval.node)=criar_no("ParseArgs",""); (yyval.node)->filho=criar_no("Id",(yyvsp[-4].id)); adicionar_irmao((yyval.node)->filho,(yyvsp[-2].node));}
#line 1800 "y.tab.c"
    break;

  case 50: /* ParseArgs: PARSEINT LPAR error RPAR  */
#line 188 "jucompiler.y"
                                    {(yyval.node)=NULL;if(DEBUG)printf("parseargs error \n");flag_tree=0;}
#line 1806 "y.tab.c"
    break;

  case 51: /* Expr: LPAR Expr RPAR  */
#line 190 "jucompiler.y"
                            {if(DEBUG)printf("expr brace\n");(yyval.node)=(yyvsp[-1].node);}
#line 1812 "y.tab.c"
    break;

  case 52: /* Expr: MethodInvocation  */
#line 191 "jucompiler.y"
                            {if(DEBUG)printf("expr MI\n");(yyval.node)=(yyvsp[0].node);}
#line 1818 "y.tab.c"
    break;

  case 53: /* Expr: Assignment  */
#line 192 "jucompiler.y"
                            {if(DEBUG)printf("expr agn\n");(yyval.node)=(yyvsp[0].node);}
#line 1824 "y.tab.c"
    break;

  case 54: /* Expr: ParseArgs  */
#line 193 "jucompiler.y"
                            {if(DEBUG)printf("expr pa\n");(yyval.node)=(yyvsp[0].node);}
#line 1830 "y.tab.c"
    break;

  case 55: /* Expr: ID  */
#line 194 "jucompiler.y"
                            {if(DEBUG)printf("expr id\n");(yyval.node)=criar_no("Id",(yyvsp[0].id));}
#line 1836 "y.tab.c"
    break;

  case 56: /* Expr: ID DOTLENGTH  */
#line 195 "jucompiler.y"
                            {if(DEBUG)printf("expr dotlenght\n");(yyval.node)=criar_no("Length",""); (yyval.node)->filho = criar_no("Id",(yyvsp[-1].id));}
#line 1842 "y.tab.c"
    break;

  case 57: /* Expr: INTLIT  */
#line 196 "jucompiler.y"
                            {if(DEBUG)printf("expr intlit\n");(yyval.node)=criar_no("DecLit",(yyvsp[0].id));}
#line 1848 "y.tab.c"
    break;

  case 58: /* Expr: REALLIT  */
#line 197 "jucompiler.y"
                            {if(DEBUG)printf("expr reallit\n");(yyval.node)=criar_no("RealLit",(yyvsp[0].id));}
#line 1854 "y.tab.c"
    break;

  case 59: /* Expr: BOOLLIT  */
#line 198 "jucompiler.y"
                            {if(DEBUG)printf("expr boollit\n");(yyval.node)=criar_no("BoolLit",(yyvsp[0].id));}
#line 1860 "y.tab.c"
    break;

  case 60: /* Expr: MINUS Expr  */
#line 199 "jucompiler.y"
                            {if(DEBUG)printf("expr self minus\n");(yyval.node)=criar_no("Minus",""); (yyval.node)->filho=(yyvsp[0].node);}
#line 1866 "y.tab.c"
    break;

  case 61: /* Expr: NOT Expr  */
#line 200 "jucompiler.y"
                            {if(DEBUG)printf("expr self not\n");(yyval.node)=criar_no("Not",""); (yyval.node)->filho=(yyvsp[0].node);}
#line 1872 "y.tab.c"
    break;

  case 62: /* Expr: PLUS Expr  */
#line 201 "jucompiler.y"
                            {if(DEBUG)printf("expr self plus\n");(yyval.node)=criar_no("Plus",""); (yyval.node)->filho=(yyvsp[0].node);}
#line 1878 "y.tab.c"
    break;

  case 63: /* Expr: Expr PLUS Expr  */
#line 202 "jucompiler.y"
                            {if(DEBUG)printf("expr plus\n");(yyval.node)=criar_no("Add",""); (yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1884 "y.tab.c"
    break;

  case 64: /* Expr: Expr MINUS Expr  */
#line 203 "jucompiler.y"
                            {if(DEBUG)printf("expr MINUS\n");(yyval.node)=criar_no("Sub","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1890 "y.tab.c"
    break;

  case 65: /* Expr: Expr STAR Expr  */
#line 204 "jucompiler.y"
                            {if(DEBUG)printf("expr STAR\n");(yyval.node)=criar_no("Mul","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1896 "y.tab.c"
    break;

  case 66: /* Expr: Expr DIV Expr  */
#line 205 "jucompiler.y"
                            {if(DEBUG)printf("expr DIV\n");(yyval.node)=criar_no("Div","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1902 "y.tab.c"
    break;

  case 67: /* Expr: Expr MOD Expr  */
#line 206 "jucompiler.y"
                            {if(DEBUG)printf("expr MOD\n");(yyval.node)=criar_no("Mod","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1908 "y.tab.c"
    break;

  case 68: /* Expr: Expr AND Expr  */
#line 207 "jucompiler.y"
                            {if(DEBUG)printf("expr AND\n");(yyval.node)=criar_no("And","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1914 "y.tab.c"
    break;

  case 69: /* Expr: Expr OR Expr  */
#line 208 "jucompiler.y"
                            {if(DEBUG)printf("expr OR\n");(yyval.node)=criar_no("Or","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1920 "y.tab.c"
    break;

  case 70: /* Expr: Expr XOR Expr  */
#line 209 "jucompiler.y"
                            {if(DEBUG)printf("expr XOR\n");(yyval.node)=criar_no("Xor","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1926 "y.tab.c"
    break;

  case 71: /* Expr: Expr LSHIFT Expr  */
#line 210 "jucompiler.y"
                            {if(DEBUG)printf("expr LSHIFT\n");(yyval.node)=criar_no("Lshift","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1932 "y.tab.c"
    break;

  case 72: /* Expr: Expr RSHIFT Expr  */
#line 211 "jucompiler.y"
                            {if(DEBUG)printf("expr RSHIFT\n");(yyval.node)=criar_no("Rshift","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1938 "y.tab.c"
    break;

  case 73: /* Expr: Expr EQ Expr  */
#line 212 "jucompiler.y"
                            {if(DEBUG)printf("expr EQ\n");(yyval.node)=criar_no("Eq","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1944 "y.tab.c"
    break;

  case 74: /* Expr: Expr GE Expr  */
#line 213 "jucompiler.y"
                            {if(DEBUG)printf("expr GE\n");(yyval.node)=criar_no("Ge","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1950 "y.tab.c"
    break;

  case 75: /* Expr: Expr GT Expr  */
#line 214 "jucompiler.y"
                            {if(DEBUG)printf("expr GT\n");(yyval.node)=criar_no("Gt","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1956 "y.tab.c"
    break;

  case 76: /* Expr: Expr LE Expr  */
#line 215 "jucompiler.y"
                            {if(DEBUG)printf("expr LE\n");(yyval.node)=criar_no("Le","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1962 "y.tab.c"
    break;

  case 77: /* Expr: Expr LT Expr  */
#line 216 "jucompiler.y"
                            {if(DEBUG)printf("expr LT\n");(yyval.node)=criar_no("Lt","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1968 "y.tab.c"
    break;

  case 78: /* Expr: Expr NE Expr  */
#line 217 "jucompiler.y"
                            {if(DEBUG)printf("expr NE\n");(yyval.node)=criar_no("Ne","");(yyval.node)->filho=(yyvsp[-2].node); adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 1974 "y.tab.c"
    break;

  case 79: /* Expr: LPAR error RPAR  */
#line 218 "jucompiler.y"
                            {(yyval.node)=NULL;if(DEBUG)printf("expr error\n");flag_tree=0;}
#line 1980 "y.tab.c"
    break;


#line 1984 "y.tab.c"

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

#line 220 "jucompiler.y"

