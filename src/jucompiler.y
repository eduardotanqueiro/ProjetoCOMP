%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "symtab.h"
#define NSYMS 100

symtab tab[NSYMS];

void varlist();

symtab *symlook(char *varname);
int yylex (void);
void yyerror(char* s);
is_program* myprogram;

%}

/* --------------------------------------------------- */

%token AND ASSIGN BOOL STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR CLASS DOTLENGHT DOUBLE ELSE IF INT PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE RESERVED ID INTLIT STRLIT REALLIT BOOLLIT

/* --------------------------------------------------- */

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
%nonassoc ELSE

/* --------------------------------------------------- */

%type<ip>Program
%type<imfr>MethodFieldSemicolonRep
%type<imd>MethodDecl
%type<ifd>FieldDecl
%type<icir>CommaIdRep
%type<it>Type
%type<imh>MethodHeader
%type<ifp>FormalParams
%type<ictir>CommaTypeIdRep
%type<imb>MethodBody
%type<isvr>StatementVarRep
%type<ivd>VarDecl
%type<is>Statement
%type<isr>StatementRep
%type<imi>MethodInvocation
%type<icer>CommaExprRep
%type<ia>Assignment
%type<ipa>ParseArgs
%type<ie>Expr

/* --------------------------------------------------- */

%union{
    char* id;
    is_program* ip;
    is_methodfield_rep* imfr;
    is_methoddecl* imd;
    is_fielddecl* ifd;
    is_commaid_rep* icir;
    is_type* it;
    is_methodheader* imh;
    is_formalparams* ifp;
    is_commatypeid_rep* ictir;
    is_methodbody* imb;
    is_statementvar_rep* isvr;
    is_vardecl* ivd;
    is_statement* is;
    is_statement_rep* isr;
    is_methodinvocation* imi;
    is_commaexpr_rep* icer;
    is_assign* ia;
    is_parseargs* ipa;
    is_expr* ie;
}

%%

Program:  CLASS ID LBRACE MethodFieldSemicolonRep RBRACE {$$=myprogram=insert_program($2,$4);}


MethodFieldSemicolonRep: MethodDecl MethodFieldSemicolonRep {$$=insert_methoddecl_methodfield($1,$2);}
                       | FieldDecl MethodFieldSemicolonRep  {$$=insert_fielddecl_methodfield($1,$2);}
                       | SEMICOLON MethodFieldSemicolonRep  {$$=insert_semicolon_methodfield($2);}
                       |                                    {$$=NULL;}
                       ;


MethodDecl: PUBLIC STATIC MethodHeader MethodBody {$$=insert_methoddecl($3,$4);}


FieldDecl: PUBLIC STATIC Type ID CommaIdRep SEMICOLON {$$=insert_fielddecl($3,$4,$5);}

CommaIdRep: COMMA ID CommaIdRep {$$=insert_comma_id_rep($2,$3);}
          |                     {$$=NULL;}
          ;


Type: BOOL  {;} //TODO ?!?!?!?!?!?!?!?!?!?
    | INT {;}
    | DOUBLE {;}

MethodHeader: Type ID LPAR FormalParams RPAR    {$$=insert_methodheader($1,$2,$4);}
            | VOID ID LPAR FormalParams RPAR    {$$=insert_methodheader(d_void,$1,$4);}
            | Type ID LPAR RPAR                 {$$=insert_methodheader($1,$2,d_none);}
            | VOID ID LPAR RPAR                 {$$=insert_methodheader(d_void,$2,d_none);}


FormalParams: Type ID CommaTypeIdRep {$$=insert_params($1,$2,$3);}
            | STRING LSQ RSQ ID {$$=insert_string($4);}

CommaTypeIdRep: COMMA Type ID CommaIdRep {$$=insert_commatype_id_rep($2,$3,$4);}
          |                              {$$=NULL;}   
          ;


MethodBody: LBRACE StatementVarRep RBRACE {$$=insert_methodbody($2);}

StatementVarRep: Statement StatementVarRep {$$=insert_statementvar_rep($1,$2);}
               | VarDecl StatementVarRep   {$$=insert_vardecl_statement($1,$2);}
               |                           {$$=NULL;}
               ;

VarDecl: Type ID CommaIdRep SEMICOLON {$$=insert_vardecl($1,$2,$3);}

Statement: LBRACE StatementRep RBRACE                 {$$=insert_statement_brace($2);}
         | IF LPAR Expr RPAR Statement ELSE Statement {$$=insert_if_statement($3,$5,$7);}
         | IF LPAR Expr RPAR Statement                {$$=insert_if_statement($3,$5,d_none);}
         | WHILE LPAR Expr RPAR Statement             {$$=insert_while_statement($3,$5);}
         | RETURN Expr SEMICOLON;                     {$$=insert_return_statement($2);}
         | RETURN SEMICOLON;                          {$$=insert_return_statement(d_none);}
         | PRINT LPAR Expr RPAR SEMICOLON;            {$$=insert_print_expr_statement($3);}
         | PRINT LPAR STRLIT RPAR SEMICOLON;          {$$=insert_print_string_statement($3);}
         | MethodInvocation SEMICOLON                 {$$=insert_method_statement($1);}
         | Assignment SEMICOLON                       {$$=insert_assign_statement($1);}
         | ParseArgs SEMICOLON                        {$$=insert_parseargs_statement($1);}
         | SEMICOLON                                  {;} //TODO ????????!?!?!?!?!?

StatementRep: Statement StatementRep {$$=insert_statement_rep($1,$2);}
            |                        {$$=NULL;}
            ;

MethodInvocation: ID LPAR RPAR                   {$$=insert_methodinvocation(d_none,d_none);}
                | ID LPAR Expr CommaExprRep RPAR {$$=insert_mehthodinvocation($3,$4);}



CommaExprRep: COMMA Expr CommaExprRep {$$=insert_comma_expr_rep($2,$3);}
            |                         {$$=NULL;}
            ;


Assignment: ID ASSIGN Expr {$$=insert_assign($1,$3);}

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR {$$=insert_parse_args($3,$5);}

Expr: LPAR Expr RPAR {$$=insert_expr_brace($2);}
    | MethodInvocation {$$=insert_expr_methodinvocation($1);}
    | Assignment {$$=insert_expr_assign($1);}
    | ParseArgs {$$=insert_expr_parseargs($1);}
    | ID {$$=insert_expr_id($1,d_none);}
    | ID DOTLENGHT {$$=insert_expr_id($1,$2);}
    | INTLIT {$$=insert_intlit($1);}
    | REALLIT {$$=insert_reallit($1);}
    | BOOLLIT {$$=insert_boollit($1);}
    | MINUS Expr {$$=insert_minus_expr($2);}
    | NOT Expr {$$=insert_not_expr($2);}
    | PLUS Expr {$$=insert_plus_expr($2);}
    | Expr PLUS Expr  {$$=insert_expr_op($1,$2,$3);}
    | Expr MINUS Expr {$$=insert_expr_op($1,$2,$3);}
    | Expr STAR Expr {$$=insert_expr_op($1,$2,$3);}
    | Expr DIV Expr {$$=insert_expr_op($1,$2,$3);}
    | Expr MOD Expr {$$=insert_expr_op($1,$2,$3);}
    | Expr AND Expr {$$=insert_expr_op($1,$2,$3);}
    | Expr OR Expr {$$=insert_expr_op($1,$2,$3);}
    | Expr XOR Expr {$$=insert_expr_op($1,$2,$3);}
    | Expr LSHIFT Expr {$$=insert_expr_op($1,$2,$3);}
    | Expr RSHIFT Expr {$$=insert_expr_op($1,$2,$3);}
    | Expr EQ Expr {$$=insert_expr_op($1,$2,$3);}
    | Expr GE Expr {$$=insert_expr_op($1,$2,$3);}
    | Expr GT Expr {$$=insert_expr_op($1,$2,$3);}
    | Expr LE Expr {$$=insert_expr_op($1,$2,$3);}
    | Expr LT Expr {$$=insert_expr_op($1,$2,$3);}
    | Expr NE Expr {$$=insert_expr_op($1,$2,$3);}

%%

void yyerror (char *s) { 
    printf ("Line␣%d,␣col␣%d:␣%s:␣%s\n", <num linha >, <num coluna >, s, yytext );
}