/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
    LSHIFT = 280,                  /* LSHIFT  */
    RSHIFT = 281,                  /* RSHIFT  */
    PARSEINT = 282,                /* PARSEINT  */
    BOOL = 283,                    /* BOOL  */
    COMMA = 284,                   /* COMMA  */
    LBRACE = 285,                  /* LBRACE  */
    LPAR = 286,                    /* LPAR  */
    LSQ = 287,                     /* LSQ  */
    RBRACE = 288,                  /* RBRACE  */
    RPAR = 289,                    /* RPAR  */
    RSQ = 290,                     /* RSQ  */
    SEMICOLON = 291,               /* SEMICOLON  */
    ARROW = 292,                   /* ARROW  */
    XOR = 293,                     /* XOR  */
    CLASS = 294,                   /* CLASS  */
    DOUBLE = 295,                  /* DOUBLE  */
    ELSE = 296,                    /* ELSE  */
    IF = 297,                      /* IF  */
    INT = 298,                     /* INT  */
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
#define LSHIFT 280
#define RSHIFT 281
#define PARSEINT 282
#define BOOL 283
#define COMMA 284
#define LBRACE 285
#define LPAR 286
#define LSQ 287
#define RBRACE 288
#define RPAR 289
#define RSQ 290
#define SEMICOLON 291
#define ARROW 292
#define XOR 293
#define CLASS 294
#define DOUBLE 295
#define ELSE 296
#define IF 297
#define INT 298
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

#line 172 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
