%{
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
%}

%token AND
%token ASSIGN
%token BOOL
%token STAR
%token COMMA
%token DIV
%token EQ
%token GE
%token GT
%token LBRACE
%token LE
%token LPAR
%token LSQ
%token LT
%token MINUS
%token MOD
%token NE
%token NOT
%token OR
%token PLUS
%token RBRACE
%token RPAR
%token RSQ
%token SEMICOLON
%token ARROW
%token LSHIFT
%token RSHIFT
%token XOR
%token CLASS
%token DOTLENGHT
%token DOUBLE
%token ELSE
%token IF
%token INT
%token PRINT
%token PARSEINT
%token PUBLIC
%token RETURN
%token STATIC
%token STRING
%token VOID
%token WHILE
%token RESERVED
%token ID
%token INTLIT
%token STRLIT
%token REALLIT
%token BOOLLIT

%right ASSIGN
%left AND
%left OR
%left XOR
%left EQ NE
%left GE GT LT LE
%left LSHIFT RSHIFT
%left PLUS MINUS 
%left STAR DIV MOD
%right NOT
%left LPAR RPAR

%union{
    int num;
    double real;
    char* id;
}

%%

Program:  CLASS ID LBRACE MethodFieldSemicolonRep RBRACE {;}


MethodFieldSemicolonRep: MethodDecl MethodFieldSemicolonRep {;}
                       | FieldDecl MethodFieldSemicolonRep {;}
                       | SEMICOLON MethodFieldSemicolonRep {;}
                       |
                       ;


MethodDecl: PUBLIC STATIC MethodHeader MethodBody {;}


FieldDecl: PUBLIC STATIC Type ID CommaIdRep SEMICOLON {;}

CommaIdRep: COMMA ID CommaIdRep {;}
          |
          ;


Type: BOOL  {;}
    | INT {;}
    | DOUBLE {;}

MethodHeader: Type ID LPAR FormalParams RPAR
            | VOID ID LPAR FormalParams RPAR
            | Type ID LPAR RPAR
            | VOID ID LPAR RPAR


FormalParams: Type ID CommaTypeIdRep {;}
            | STRING LSQ RSQ ID {;}

CommaTypeIdRep: COMMA Type ID CommaIdRep {;}
          |
          ;


MethodBody: LBRACE StatementVarRep RBRACE {;}

StatementVarRep: Statement StatementVarRep {;}
               | VarDecl StatementVarRep {;}
               |
               ;

VarDecl: Type ID CommaIdRep SEMICOLON{;}

Statement: LBRACE StatementRep RBRACE {;}
         | IF LPAR Expr RPAR Statement {;}
         | IF LPAR Expr RPAR Statement ELSE Statement{;}
         | WHILE LPAR Expr RPAR Statement {;}
         | RETURN Expr SEMICOLON;
         | RETURN SEMICOLON;
         | PRINT LPAR Expr RPAR SEMICOLON;
         | PRINT LPAR STRLIT RPAR SEMICOLON;

StatementRep: Statement StatementRep {;}
            |
            ;

MethodInvocation: ID LPAR RPAR {;}
                | ID LPAR Expr CommaExprRep RPAR {;}



CommaExprRep: COMMA Expr CommaExprRep {;}
            |
            ;


Assignment: ID ASSIGN Expr {;}

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR {;}

Expr: LPAR Expr RPAR {;}
    | MethodInvocation {;}
    | Assignment {;}
    | ParseArgs {;}
    | ID {;}
    | ID DOTLENGHT {;}
    | INTLIT {;}
    | REALLIT {;}
    | BOOLLIT {;}
    | MINUS Expr {;}
    | NOT Expr {;}
    | PLUS Expr {;}
    | Expr PLUS Expr  {;}
    | Expr MINUS Expr {;}
    | Expr STAR Expr {;}
    | Expr DIV Expr {;}
    | Expr MOD Expr {;}
    | Expr AND Expr {;}
    | Expr OR Expr {;}
    | Expr XOR Expr {;}
    | Expr LSHIFT Expr {;}
    | Expr RSHIFT Expr {;}
    | Expr EQ Expr {;}
    | Expr GE Expr {;}
    | Expr GT Expr {;}
    | Expr LE Expr {;}
    | Expr LT Expr {;}
    | Expr NE Expr {;}

%%

void yyerror (char *s) { 
    printf ("Line␣%d,␣col␣%d:␣%s:␣%s\n", <num linha >, <num coluna >, s, yytext );
}