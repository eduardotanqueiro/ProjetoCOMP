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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symtab.h"
#define NSYMS 100

symtab tab[NSYMS];

void varlist();

symtab *symlook(char *varname);
int yylex (void);
void yyerror(char* s);

#line 87 "y.tab.c"

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
    AND = 258,                     /* AND  */
    ASSIGN = 259,                  /* ASSIGN  */
    BOOL = 260,                    /* BOOL  */
    STAR = 261,                    /* STAR  */
    COMMA = 262,                   /* COMMA  */
    DIV = 263,                     /* DIV  */
    EQ = 264,                      /* EQ  */
    GE = 265,                      /* GE  */
    GT = 266,                      /* GT  */
    LBRACE = 267,                  /* LBRACE  */
    LE = 268,                      /* LE  */
    LPAR = 269,                    /* LPAR  */
    LSQ = 270,                     /* LSQ  */
    LT = 271,                      /* LT  */
    MINUS = 272,                   /* MINUS  */
    MOD = 273,                     /* MOD  */
    NE = 274,                      /* NE  */
    NOT = 275,                     /* NOT  */
    OR = 276,                      /* OR  */
    PLUS = 277,                    /* PLUS  */
    RBRACE = 278,                  /* RBRACE  */
    RPAR = 279,                    /* RPAR  */
    RSQ = 280,                     /* RSQ  */
    SEMICOLON = 281,               /* SEMICOLON  */
    ARROW = 282,                   /* ARROW  */
    LSHIFT = 283,                  /* LSHIFT  */
    RSHIFT = 284,                  /* RSHIFT  */
    XOR = 285,                     /* XOR  */
    CLASS = 286,                   /* CLASS  */
    DOTLENGHT = 287,               /* DOTLENGHT  */
    DOUBLE = 288,                  /* DOUBLE  */
    ELSE = 289,                    /* ELSE  */
    IF = 290,                      /* IF  */
    INT = 291,                     /* INT  */
    PRINT = 292,                   /* PRINT  */
    PARSEINT = 293,                /* PARSEINT  */
    PUBLIC = 294,                  /* PUBLIC  */
    RETURN = 295,                  /* RETURN  */
    STATIC = 296,                  /* STATIC  */
    STRING = 297,                  /* STRING  */
    VOID = 298,                    /* VOID  */
    WHILE = 299,                   /* WHILE  */
    RESERVED = 300,                /* RESERVED  */
    ID = 301,                      /* ID  */
    INTLIT = 302,                  /* INTLIT  */
    STRLIT = 303,                  /* STRLIT  */
    REALLIT = 304,                 /* REALLIT  */
    BOOLLIT = 305                  /* BOOLLIT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define AND 258
#define ASSIGN 259
#define BOOL 260
#define STAR 261
#define COMMA 262
#define DIV 263
#define EQ 264
#define GE 265
#define GT 266
#define LBRACE 267
#define LE 268
#define LPAR 269
#define LSQ 270
#define LT 271
#define MINUS 272
#define MOD 273
#define NE 274
#define NOT 275
#define OR 276
#define PLUS 277
#define RBRACE 278
#define RPAR 279
#define RSQ 280
#define SEMICOLON 281
#define ARROW 282
#define LSHIFT 283
#define RSHIFT 284
#define XOR 285
#define CLASS 286
#define DOTLENGHT 287
#define DOUBLE 288
#define ELSE 289
#define IF 290
#define INT 291
#define PRINT 292
#define PARSEINT 293
#define PUBLIC 294
#define RETURN 295
#define STATIC 296
#define STRING 297
#define VOID 298
#define WHILE 299
#define RESERVED 300
#define ID 301
#define INTLIT 302
#define STRLIT 303
#define REALLIT 304
#define BOOLLIT 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 79 "jucompiler.y"

    int num;
    double real;
    char* id;

#line 246 "y.tab.c"

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
  YYSYMBOL_AND = 3,                        /* AND  */
  YYSYMBOL_ASSIGN = 4,                     /* ASSIGN  */
  YYSYMBOL_BOOL = 5,                       /* BOOL  */
  YYSYMBOL_STAR = 6,                       /* STAR  */
  YYSYMBOL_COMMA = 7,                      /* COMMA  */
  YYSYMBOL_DIV = 8,                        /* DIV  */
  YYSYMBOL_EQ = 9,                         /* EQ  */
  YYSYMBOL_GE = 10,                        /* GE  */
  YYSYMBOL_GT = 11,                        /* GT  */
  YYSYMBOL_LBRACE = 12,                    /* LBRACE  */
  YYSYMBOL_LE = 13,                        /* LE  */
  YYSYMBOL_LPAR = 14,                      /* LPAR  */
  YYSYMBOL_LSQ = 15,                       /* LSQ  */
  YYSYMBOL_LT = 16,                        /* LT  */
  YYSYMBOL_MINUS = 17,                     /* MINUS  */
  YYSYMBOL_MOD = 18,                       /* MOD  */
  YYSYMBOL_NE = 19,                        /* NE  */
  YYSYMBOL_NOT = 20,                       /* NOT  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_PLUS = 22,                      /* PLUS  */
  YYSYMBOL_RBRACE = 23,                    /* RBRACE  */
  YYSYMBOL_RPAR = 24,                      /* RPAR  */
  YYSYMBOL_RSQ = 25,                       /* RSQ  */
  YYSYMBOL_SEMICOLON = 26,                 /* SEMICOLON  */
  YYSYMBOL_ARROW = 27,                     /* ARROW  */
  YYSYMBOL_LSHIFT = 28,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 29,                    /* RSHIFT  */
  YYSYMBOL_XOR = 30,                       /* XOR  */
  YYSYMBOL_CLASS = 31,                     /* CLASS  */
  YYSYMBOL_DOTLENGHT = 32,                 /* DOTLENGHT  */
  YYSYMBOL_DOUBLE = 33,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 34,                      /* ELSE  */
  YYSYMBOL_IF = 35,                        /* IF  */
  YYSYMBOL_INT = 36,                       /* INT  */
  YYSYMBOL_PRINT = 37,                     /* PRINT  */
  YYSYMBOL_PARSEINT = 38,                  /* PARSEINT  */
  YYSYMBOL_PUBLIC = 39,                    /* PUBLIC  */
  YYSYMBOL_RETURN = 40,                    /* RETURN  */
  YYSYMBOL_STATIC = 41,                    /* STATIC  */
  YYSYMBOL_STRING = 42,                    /* STRING  */
  YYSYMBOL_VOID = 43,                      /* VOID  */
  YYSYMBOL_WHILE = 44,                     /* WHILE  */
  YYSYMBOL_RESERVED = 45,                  /* RESERVED  */
  YYSYMBOL_ID = 46,                        /* ID  */
  YYSYMBOL_INTLIT = 47,                    /* INTLIT  */
  YYSYMBOL_STRLIT = 48,                    /* STRLIT  */
  YYSYMBOL_REALLIT = 49,                   /* REALLIT  */
  YYSYMBOL_BOOLLIT = 50,                   /* BOOLLIT  */
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
#define YYLAST   499

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

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
       0,    87,    87,    90,    91,    92,    93,    97,   100,   102,
     103,   107,   108,   109,   111,   112,   113,   114,   117,   118,
     120,   121,   125,   127,   128,   129,   132,   134,   135,   136,
     137,   138,   139,   140,   141,   143,   144,   147,   148,   152,
     153,   157,   159,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188
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
  "\"end of file\"", "error", "\"invalid token\"", "AND", "ASSIGN",
  "BOOL", "STAR", "COMMA", "DIV", "EQ", "GE", "GT", "LBRACE", "LE", "LPAR",
  "LSQ", "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PLUS", "RBRACE", "RPAR",
  "RSQ", "SEMICOLON", "ARROW", "LSHIFT", "RSHIFT", "XOR", "CLASS",
  "DOTLENGHT", "DOUBLE", "ELSE", "IF", "INT", "PRINT", "PARSEINT",
  "PUBLIC", "RETURN", "STATIC", "STRING", "VOID", "WHILE", "RESERVED",
  "ID", "INTLIT", "STRLIT", "REALLIT", "BOOLLIT", "$accept", "Program",
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

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -22,   -31,    20,    13,   -47,   -12,   -12,    -7,    50,   -12,
     -12,   -47,    31,   -47,   -47,   -47,   -47,   -47,   -47,     9,
      29,    64,    65,    21,    26,   -47,    36,    35,    66,    56,
      89,    69,    70,    71,    72,    43,    77,    26,    26,   -47,
      79,    46,    82,   104,   -47,    88,   -47,    89,    91,   130,
      93,   130,   130,   130,   130,   -47,   105,    73,   -47,   -47,
     -47,   -47,   -47,   -47,   175,   130,   104,   -47,   -47,   -47,
      98,   120,   -47,   -47,   -47,   -47,   -47,   203,   111,   231,
     259,     5,   -47,     5,    90,   130,   108,   -47,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   -47,   130,   130,   130,   287,   119,   102,    32,   -47,
      89,   127,   133,   -47,   141,   371,   -47,   315,   396,   -47,
     -47,   470,     4,     4,     4,     4,     5,   -47,   470,   421,
       5,   143,   143,   446,    89,   -47,   -47,   116,   129,   -47,
     -47,   130,   130,   140,   -47,   104,    89,   343,   315,   -47,
     -47,   -47,   142,   -47,   -47
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     6,     6,     0,     0,     6,
       6,     5,     0,     2,     3,     4,    11,    13,    12,     0,
       0,     0,     0,    10,    25,     7,     0,     0,     0,     0,
      36,     0,     0,     0,     0,     0,     0,    25,    25,    17,
       0,     0,     0,    10,    16,     0,     8,    36,     0,     0,
       0,     0,     0,     0,     0,    32,     0,    47,    49,    50,
      51,    44,    45,    46,     0,     0,    10,    22,    24,    23,
       0,    21,    15,     9,    14,    35,    27,     0,     0,     0,
       0,    52,    53,    54,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,    43,     0,    41,    37,    40,    60,    57,
      58,    65,    66,    67,    68,    69,    56,    59,    70,    61,
      55,    63,    64,    62,     0,    26,    19,     0,    29,    34,
      33,     0,     0,     0,    30,    10,     0,     0,    40,    38,
      20,    28,     0,    39,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -47,   -47,   128,   -47,   -47,   -42,   -10,   -47,   139,   -47,
     -47,    -8,   -47,   -30,   122,   -47,    22,   -47,   -47,   -46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     8,     9,    10,    29,    35,    21,    42,   109,
      25,    36,    37,    38,    48,    61,   143,    62,    63,    64
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      47,    73,    20,    77,    79,    80,    81,    82,    83,     1,
      89,    89,    90,    90,     6,     3,    41,    47,    41,   105,
       4,    96,    97,    97,   106,     5,   100,     7,    27,    68,
      69,    16,   102,   103,    12,    28,    16,    16,    30,   115,
     117,    16,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    22,   131,   132,   133,    17,
      39,    31,    18,    32,    17,    17,    33,    18,    18,    17,
      34,    16,    18,    13,    19,    23,    24,    85,    40,    26,
     138,    43,    46,    49,    50,    51,    65,    86,    52,    66,
      44,    53,    71,    54,    70,   147,   148,    55,   137,    17,
      67,    30,    18,   150,   144,    87,    72,    51,    40,    56,
      52,    27,    74,    53,    76,    54,   151,    57,    58,    84,
      59,    60,    51,   107,    31,    52,    32,   108,    53,    33,
      54,    56,   116,    34,    11,   111,   114,    14,    15,    57,
      58,    78,    59,    60,    51,   135,    56,    52,   136,    89,
      53,    90,    54,   139,    57,    58,   141,    59,    60,   140,
      96,    97,   145,   146,   149,   100,   154,    45,    56,    75,
     153,     0,     0,     0,     0,     0,    57,    58,    88,    59,
      60,    89,     0,    90,    91,    92,    93,     0,    94,     0,
       0,    95,    96,    97,    98,     0,    99,   100,     0,     0,
       0,   101,     0,   102,   103,   104,    88,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,    95,
      96,    97,    98,     0,    99,   100,     0,   110,     0,     0,
       0,   102,   103,   104,    88,     0,     0,    89,     0,    90,
      91,    92,    93,     0,    94,     0,     0,    95,    96,    97,
      98,     0,    99,   100,     0,   112,     0,     0,     0,   102,
     103,   104,    88,     0,     0,    89,     0,    90,    91,    92,
      93,     0,    94,     0,     0,    95,    96,    97,    98,     0,
      99,   100,     0,   113,     0,     0,     0,   102,   103,   104,
      88,     0,     0,    89,     0,    90,    91,    92,    93,     0,
      94,     0,     0,    95,    96,    97,    98,     0,    99,   100,
       0,   134,     0,     0,     0,   102,   103,   104,    88,     0,
       0,    89,   142,    90,    91,    92,    93,     0,    94,     0,
       0,    95,    96,    97,    98,     0,    99,   100,     0,     0,
       0,     0,     0,   102,   103,   104,    88,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,    95,
      96,    97,    98,     0,    99,   100,     0,     0,   152,     0,
       0,   102,   103,   104,    88,     0,     0,    89,     0,    90,
      91,    92,    93,     0,    94,     0,     0,    95,    96,    97,
      98,     0,    99,   100,     0,     0,     0,     0,     0,   102,
     103,   104,    89,     0,    90,    91,    92,    93,     0,    94,
       0,     0,    95,    96,    97,    98,     0,    99,   100,     0,
       0,     0,     0,     0,   102,   103,   104,    89,     0,    90,
      91,    92,    93,     0,    94,     0,     0,    95,    96,    97,
      98,     0,     0,   100,     0,     0,     0,     0,     0,   102,
     103,   104,    89,     0,    90,    91,    92,    93,     0,    94,
       0,     0,    95,    96,    97,    98,     0,     0,   100,     0,
       0,     0,     0,     0,   102,   103,    89,     0,    90,     0,
      92,    93,     0,    94,     0,     0,    95,    96,    97,     0,
       0,     0,   100,     0,     0,     0,     0,     0,   102,   103
};

static const yytype_int16 yycheck[] =
{
      30,    43,    12,    49,    50,    51,    52,    53,    54,    31,
       6,     6,     8,     8,    26,    46,    26,    47,    28,    65,
       0,    17,    18,    18,    66,    12,    22,    39,     7,    37,
      38,     5,    28,    29,    41,    14,     5,     5,    12,    85,
      86,     5,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    46,   102,   103,   104,    33,
      24,    35,    36,    37,    33,    33,    40,    36,    36,    33,
      44,     5,    36,    23,    43,    46,    12,     4,    42,    14,
     110,    46,    26,    14,    14,    14,    14,    14,    17,    46,
      24,    20,    46,    22,    15,   141,   142,    26,   108,    33,
      23,    12,    36,   145,   134,    32,    24,    14,    42,    38,
      17,     7,    24,    20,    23,    22,   146,    46,    47,    14,
      49,    50,    14,    25,    35,    17,    37,     7,    20,    40,
      22,    38,    24,    44,     6,    24,    46,     9,    10,    46,
      47,    48,    49,    50,    14,    26,    38,    17,    46,     6,
      20,     8,    22,    26,    46,    47,    15,    49,    50,    26,
      17,    18,    46,    34,    24,    22,    24,    28,    38,    47,
     148,    -1,    -1,    -1,    -1,    -1,    46,    47,     3,    49,
      50,     6,    -1,     8,     9,    10,    11,    -1,    13,    -1,
      -1,    16,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    26,    -1,    28,    29,    30,     3,    -1,    -1,     6,
      -1,     8,     9,    10,    11,    -1,    13,    -1,    -1,    16,
      17,    18,    19,    -1,    21,    22,    -1,    24,    -1,    -1,
      -1,    28,    29,    30,     3,    -1,    -1,     6,    -1,     8,
       9,    10,    11,    -1,    13,    -1,    -1,    16,    17,    18,
      19,    -1,    21,    22,    -1,    24,    -1,    -1,    -1,    28,
      29,    30,     3,    -1,    -1,     6,    -1,     8,     9,    10,
      11,    -1,    13,    -1,    -1,    16,    17,    18,    19,    -1,
      21,    22,    -1,    24,    -1,    -1,    -1,    28,    29,    30,
       3,    -1,    -1,     6,    -1,     8,     9,    10,    11,    -1,
      13,    -1,    -1,    16,    17,    18,    19,    -1,    21,    22,
      -1,    24,    -1,    -1,    -1,    28,    29,    30,     3,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    -1,
      -1,    16,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,     3,    -1,    -1,     6,
      -1,     8,     9,    10,    11,    -1,    13,    -1,    -1,    16,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    25,    -1,
      -1,    28,    29,    30,     3,    -1,    -1,     6,    -1,     8,
       9,    10,    11,    -1,    13,    -1,    -1,    16,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,     6,    -1,     8,     9,    10,    11,    -1,    13,
      -1,    -1,    16,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    -1,    28,    29,    30,     6,    -1,     8,
       9,    10,    11,    -1,    13,    -1,    -1,    16,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,     6,    -1,     8,     9,    10,    11,    -1,    13,
      -1,    -1,    16,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    28,    29,     6,    -1,     8,    -1,
      10,    11,    -1,    13,    -1,    -1,    16,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    31,    52,    46,     0,    12,    26,    39,    53,    54,
      55,    53,    41,    23,    53,    53,     5,    33,    36,    43,
      57,    58,    46,    46,    12,    61,    14,     7,    14,    56,
      12,    35,    37,    40,    44,    57,    62,    63,    64,    24,
      42,    57,    59,    46,    24,    59,    26,    64,    65,    14,
      14,    14,    17,    20,    22,    26,    38,    46,    47,    49,
      50,    66,    68,    69,    70,    14,    46,    23,    62,    62,
      15,    46,    24,    56,    24,    65,    23,    70,    48,    70,
      70,    70,    70,    70,    14,     4,    14,    32,     3,     6,
       8,     9,    10,    11,    13,    16,    17,    18,    19,    21,
      22,    26,    28,    29,    30,    70,    56,    25,     7,    60,
      24,    24,    24,    24,    46,    70,    24,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    24,    26,    46,    57,    64,    26,
      26,    15,     7,    67,    64,    46,    34,    70,    70,    24,
      56,    64,    25,    67,    24
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    55,    56,
      56,    57,    57,    57,    58,    58,    58,    58,    59,    59,
      60,    60,    61,    62,    62,    62,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    65,    65,    66,    66,    67,
      67,    68,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     2,     2,     0,     4,     6,     3,
       0,     1,     1,     1,     5,     5,     4,     4,     3,     4,
       4,     0,     3,     2,     2,     0,     4,     3,     7,     5,
       5,     3,     2,     5,     5,     2,     0,     3,     5,     3,
       0,     3,     7,     3,     1,     1,     1,     1,     2,     1,
       1,     1,     2,     2,     2,     3,     3,     3,     3,     3,
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
#line 87 "jucompiler.y"
                                                         {;}
#line 1461 "y.tab.c"
    break;

  case 3: /* MethodFieldSemicolonRep: MethodDecl MethodFieldSemicolonRep  */
#line 90 "jucompiler.y"
                                                            {;}
#line 1467 "y.tab.c"
    break;

  case 4: /* MethodFieldSemicolonRep: FieldDecl MethodFieldSemicolonRep  */
#line 91 "jucompiler.y"
                                                           {;}
#line 1473 "y.tab.c"
    break;

  case 5: /* MethodFieldSemicolonRep: SEMICOLON MethodFieldSemicolonRep  */
#line 92 "jucompiler.y"
                                                           {;}
#line 1479 "y.tab.c"
    break;

  case 7: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 97 "jucompiler.y"
                                                  {;}
#line 1485 "y.tab.c"
    break;

  case 8: /* FieldDecl: PUBLIC STATIC Type ID CommaIdRep SEMICOLON  */
#line 100 "jucompiler.y"
                                                      {;}
#line 1491 "y.tab.c"
    break;

  case 9: /* CommaIdRep: COMMA ID CommaIdRep  */
#line 102 "jucompiler.y"
                                {;}
#line 1497 "y.tab.c"
    break;

  case 11: /* Type: BOOL  */
#line 107 "jucompiler.y"
            {;}
#line 1503 "y.tab.c"
    break;

  case 12: /* Type: INT  */
#line 108 "jucompiler.y"
          {;}
#line 1509 "y.tab.c"
    break;

  case 13: /* Type: DOUBLE  */
#line 109 "jucompiler.y"
             {;}
#line 1515 "y.tab.c"
    break;

  case 18: /* FormalParams: Type ID CommaTypeIdRep  */
#line 117 "jucompiler.y"
                                     {;}
#line 1521 "y.tab.c"
    break;

  case 19: /* FormalParams: STRING LSQ RSQ ID  */
#line 118 "jucompiler.y"
                                {;}
#line 1527 "y.tab.c"
    break;

  case 20: /* CommaTypeIdRep: COMMA Type ID CommaIdRep  */
#line 120 "jucompiler.y"
                                         {;}
#line 1533 "y.tab.c"
    break;

  case 22: /* MethodBody: LBRACE StatementVarRep RBRACE  */
#line 125 "jucompiler.y"
                                          {;}
#line 1539 "y.tab.c"
    break;

  case 23: /* StatementVarRep: Statement StatementVarRep  */
#line 127 "jucompiler.y"
                                           {;}
#line 1545 "y.tab.c"
    break;

  case 24: /* StatementVarRep: VarDecl StatementVarRep  */
#line 128 "jucompiler.y"
                                         {;}
#line 1551 "y.tab.c"
    break;

  case 26: /* VarDecl: Type ID CommaIdRep SEMICOLON  */
#line 132 "jucompiler.y"
                                     {;}
#line 1557 "y.tab.c"
    break;

  case 27: /* Statement: LBRACE StatementRep RBRACE  */
#line 134 "jucompiler.y"
                                      {;}
#line 1563 "y.tab.c"
    break;

  case 28: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 135 "jucompiler.y"
                                                     {;}
#line 1569 "y.tab.c"
    break;

  case 29: /* Statement: IF LPAR Expr RPAR Statement  */
#line 136 "jucompiler.y"
                                       {;}
#line 1575 "y.tab.c"
    break;

  case 30: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 137 "jucompiler.y"
                                          {;}
#line 1581 "y.tab.c"
    break;

  case 35: /* StatementRep: Statement StatementRep  */
#line 143 "jucompiler.y"
                                     {;}
#line 1587 "y.tab.c"
    break;

  case 37: /* MethodInvocation: ID LPAR RPAR  */
#line 147 "jucompiler.y"
                               {;}
#line 1593 "y.tab.c"
    break;

  case 38: /* MethodInvocation: ID LPAR Expr CommaExprRep RPAR  */
#line 148 "jucompiler.y"
                                                 {;}
#line 1599 "y.tab.c"
    break;

  case 39: /* CommaExprRep: COMMA Expr CommaExprRep  */
#line 152 "jucompiler.y"
                                      {;}
#line 1605 "y.tab.c"
    break;

  case 41: /* Assignment: ID ASSIGN Expr  */
#line 157 "jucompiler.y"
                           {;}
#line 1611 "y.tab.c"
    break;

  case 42: /* ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR  */
#line 159 "jucompiler.y"
                                              {;}
#line 1617 "y.tab.c"
    break;

  case 43: /* Expr: LPAR Expr RPAR  */
#line 161 "jucompiler.y"
                     {;}
#line 1623 "y.tab.c"
    break;

  case 44: /* Expr: MethodInvocation  */
#line 162 "jucompiler.y"
                       {;}
#line 1629 "y.tab.c"
    break;

  case 45: /* Expr: Assignment  */
#line 163 "jucompiler.y"
                 {;}
#line 1635 "y.tab.c"
    break;

  case 46: /* Expr: ParseArgs  */
#line 164 "jucompiler.y"
                {;}
#line 1641 "y.tab.c"
    break;

  case 47: /* Expr: ID  */
#line 165 "jucompiler.y"
         {;}
#line 1647 "y.tab.c"
    break;

  case 48: /* Expr: ID DOTLENGHT  */
#line 166 "jucompiler.y"
                   {;}
#line 1653 "y.tab.c"
    break;

  case 49: /* Expr: INTLIT  */
#line 167 "jucompiler.y"
             {;}
#line 1659 "y.tab.c"
    break;

  case 50: /* Expr: REALLIT  */
#line 168 "jucompiler.y"
              {;}
#line 1665 "y.tab.c"
    break;

  case 51: /* Expr: BOOLLIT  */
#line 169 "jucompiler.y"
              {;}
#line 1671 "y.tab.c"
    break;

  case 52: /* Expr: MINUS Expr  */
#line 170 "jucompiler.y"
                 {;}
#line 1677 "y.tab.c"
    break;

  case 53: /* Expr: NOT Expr  */
#line 171 "jucompiler.y"
               {;}
#line 1683 "y.tab.c"
    break;

  case 54: /* Expr: PLUS Expr  */
#line 172 "jucompiler.y"
                {;}
#line 1689 "y.tab.c"
    break;

  case 55: /* Expr: Expr PLUS Expr  */
#line 173 "jucompiler.y"
                      {;}
#line 1695 "y.tab.c"
    break;

  case 56: /* Expr: Expr MINUS Expr  */
#line 174 "jucompiler.y"
                      {;}
#line 1701 "y.tab.c"
    break;

  case 57: /* Expr: Expr STAR Expr  */
#line 175 "jucompiler.y"
                     {;}
#line 1707 "y.tab.c"
    break;

  case 58: /* Expr: Expr DIV Expr  */
#line 176 "jucompiler.y"
                    {;}
#line 1713 "y.tab.c"
    break;

  case 59: /* Expr: Expr MOD Expr  */
#line 177 "jucompiler.y"
                    {;}
#line 1719 "y.tab.c"
    break;

  case 60: /* Expr: Expr AND Expr  */
#line 178 "jucompiler.y"
                    {;}
#line 1725 "y.tab.c"
    break;

  case 61: /* Expr: Expr OR Expr  */
#line 179 "jucompiler.y"
                   {;}
#line 1731 "y.tab.c"
    break;

  case 62: /* Expr: Expr XOR Expr  */
#line 180 "jucompiler.y"
                    {;}
#line 1737 "y.tab.c"
    break;

  case 63: /* Expr: Expr LSHIFT Expr  */
#line 181 "jucompiler.y"
                       {;}
#line 1743 "y.tab.c"
    break;

  case 64: /* Expr: Expr RSHIFT Expr  */
#line 182 "jucompiler.y"
                       {;}
#line 1749 "y.tab.c"
    break;

  case 65: /* Expr: Expr EQ Expr  */
#line 183 "jucompiler.y"
                   {;}
#line 1755 "y.tab.c"
    break;

  case 66: /* Expr: Expr GE Expr  */
#line 184 "jucompiler.y"
                   {;}
#line 1761 "y.tab.c"
    break;

  case 67: /* Expr: Expr GT Expr  */
#line 185 "jucompiler.y"
                   {;}
#line 1767 "y.tab.c"
    break;

  case 68: /* Expr: Expr LE Expr  */
#line 186 "jucompiler.y"
                   {;}
#line 1773 "y.tab.c"
    break;

  case 69: /* Expr: Expr LT Expr  */
#line 187 "jucompiler.y"
                   {;}
#line 1779 "y.tab.c"
    break;

  case 70: /* Expr: Expr NE Expr  */
#line 188 "jucompiler.y"
                   {;}
#line 1785 "y.tab.c"
    break;


#line 1789 "y.tab.c"

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

#line 190 "jucompiler.y"


void yyerror (char *s) { 
    printf ("Line␣%d,␣col␣%d:␣%s:␣%s\n", <num linha >, <num coluna >, s, yytext );
}