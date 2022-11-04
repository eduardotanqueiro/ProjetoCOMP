%{
    //  Eduardo Carneiro - 2020240332
    //  Ricardo Silva - 2020
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "functions.h"
#include "symtab.h"
#include "y.tab.h"
#define NSYMS 100

symtab tab[NSYMS];

void varlist();

symtab *symlook(char *varname);
int yylex (void);
void yyerror(char* s);
is_program* myprogram;

extern int line_num;
extern int col_num;
extern int flag_tree;
%}

/* --------------------------------------------------- */
%token <id> ID
%token <id> INTLIT
%token <id> REALLIT
%token <id> BOOLLIT
%token <id> STRLIT

%token AND ASSIGN BOOL STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR CLASS DOTLENGTH DOUBLE ELSE IF INT PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE RESERVED



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

// EBNF, com a qual [...] significa “opcional” e {...} significa “zero ou mais repetições”

Program:  CLASS ID LBRACE MethodFieldSemicolonRep RBRACE {printf("program\n");$$=myprogram=insert_program($2,$4);}


MethodFieldSemicolonRep: MethodDecl MethodFieldSemicolonRep {printf("method dcl prog\n");$$=insert_methoddecl_methodfield($1,$2);}
                       | FieldDecl MethodFieldSemicolonRep  {printf("field decl prog\n");$$=insert_fielddecl_methodfield($1,$2);}
                       | SEMICOLON MethodFieldSemicolonRep  {printf("semicolon \n");$$=insert_semicolon_methodfield($2);}
                       |                                    {printf("method dcl prog rep empty \n");$$=NULL;}
                       ;


MethodDecl: PUBLIC STATIC MethodHeader MethodBody {printf("method dcl solo\n");$$=insert_methoddecl($3,$4);}


FieldDecl: PUBLIC STATIC Type ID CommaIdRep SEMICOLON {printf("field decl solo \n");$$=insert_fielddecl($3,$4,$5);}
        | error SEMICOLON {$$=NULL;printf("fielddecl error \n");flag_tree=0;}

CommaIdRep: COMMA ID CommaIdRep {printf("commma id rep \n");$$=insert_comma_id_rep($2,$3);}
          |                     {printf("comma id rep empty \n");$$=NULL;}
          ;


Type: BOOL  {printf("bool \n");$$=insert_type("BOOL");}
    | INT {printf("int \n");$$=insert_type("INT");}
    | DOUBLE {printf("double \n");$$=insert_type("DOUBLE");}

MethodHeader: Type ID LPAR FormalParams RPAR    {printf("method header full \n");$$=insert_methodheader($1,$2,$4);}
            | VOID ID LPAR FormalParams RPAR    {printf("method header void params \n");$$=insert_methodheader(NULL,$2,$4);}
            | Type ID LPAR RPAR                 {printf("method header type no params \n");$$=insert_methodheader($1,$2,NULL);}
            | VOID ID LPAR RPAR                 {printf("method header void no params \n");$$=insert_methodheader(NULL,$2,NULL);}


FormalParams: Type ID CommaTypeIdRep {printf("formalsparams type \n");$$=insert_params($1,$2,$3);}
            | STRING LSQ RSQ ID {printf("formalparams string \n");$$=insert_string($4);}

CommaTypeIdRep: COMMA Type ID CommaTypeIdRep {printf("commatypeidrep \n");$$=insert_commatype_id_rep($2,$3,$4);}
          |                              {printf("commatypeidrep empty \n");$$=NULL;}   
          ;


MethodBody: LBRACE StatementVarRep RBRACE {printf("methodbody \n");$$=insert_methodbody($2);}

StatementVarRep: Statement StatementVarRep {printf("statementvarrep stat \n");$$=insert_statementvar_rep($1,$2);}
               | VarDecl StatementVarRep   {printf("statementvarrep vardecl \n");$$=insert_vardecl_statement($1,$2);}
               |                           {printf("statementvarrep empty \n");$$=NULL;}
               ;

VarDecl: Type ID CommaIdRep SEMICOLON {printf("vardecl solo \n");$$=insert_vardecl($1,$2,$3);}

Statement: LBRACE StatementRep RBRACE                 {printf("statement block\n");$$=insert_statement_brace($2);}
         | IF LPAR Expr RPAR Statement ELSE Statement {printf("statement if full\n");$$=insert_if_statement($3,$5,$7);}
         | IF LPAR Expr RPAR Statement                {printf("statement if solo\n");$$=insert_if_statement($3,$5,NULL);}
         | WHILE LPAR Expr RPAR Statement             {printf("statement while\n");$$=insert_while_statement($3,$5);}
         | RETURN Expr SEMICOLON                      {printf("statement return expr\n");$$=insert_return_statement($2);}
         | RETURN SEMICOLON                           {printf("statement return\n");$$=insert_return_statement(NULL);}
         | PRINT LPAR Expr RPAR SEMICOLON             {printf("statement print expr\n");$$=insert_print_expr_statement($3);}
         | PRINT LPAR STRLIT RPAR SEMICOLON           {printf("statement print str\n");$$=insert_print_string_statement($3);}
         | MethodInvocation SEMICOLON                 {printf("statement MI\n");$$=insert_method_statement($1);}
         | Assignment SEMICOLON                       {printf("statement agn\n");$$=insert_assign_statement($1);}
         | ParseArgs SEMICOLON                        {printf("statement pa\n");$$=insert_parseargs_statement($1);}
         | SEMICOLON                                  {printf("statement semicolon\n");$$=NULL;}
         | error SEMICOLON                            {$$=NULL;printf("statement error\n");flag_tree=0;}

StatementRep: Statement StatementRep {printf("statementrep \n");$$=insert_statement_rep($1,$2);}
            |                        {printf("statement rep empty \n");$$=NULL;}
            ;

MethodInvocation: ID LPAR RPAR                   {printf("methodinvocation \n");$$=insert_methodinvocation($1,NULL,NULL);}
                | ID LPAR Expr CommaExprRep RPAR {printf("methodinvocation \n");$$=insert_methodinvocation($1,$3,$4);}
                | ID LPAR error RPAR    {$$=NULL;printf("methodinvocation \n");flag_tree=0;}



CommaExprRep: COMMA Expr CommaExprRep {printf("commaexprrep \n");$$=insert_comma_expr_rep($2,$3);}
            |                         {printf("commmaexprrep empty \n");$$=NULL;}
            ;


Assignment: ID ASSIGN Expr {printf("assign \n");$$=insert_assign($1,$3);}

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR {printf("parseargs full \n");$$=insert_parse_args($3,$5);}
        | PARSEINT LPAR error RPAR  {$$=NULL;printf("parseargs error \n");flag_tree=0;}

Expr: LPAR Expr RPAR        {printf("expr brace\n");$$=insert_expr_brace($2);}
    | MethodInvocation      {printf("expr MI\n");$$=insert_expr_methodinvocation($1);}
    | Assignment            {printf("expr agn\n");$$=insert_expr_assign($1);}
    | ParseArgs             {printf("expr pa\n");$$=insert_expr_parseargs($1);}
    | ID                    {printf("expr id\n");$$=insert_expr_id($1);}
    | ID DOTLENGTH          {printf("expr dotlenght\n");$$=insert_expr_dotlenght($1);}
    | INTLIT                {printf("expr intlit\n");$$=insert_expr_intlit($1);}
    | REALLIT               {printf("expr reallit\n");$$=insert_expr_reallit($1);}
    | BOOLLIT               {printf("expr boollit\n");$$=insert_expr_boollit($1);}
    | MINUS Expr            {printf("expr self minus\n");$$=insert_expr_minus_expr($2);}
    | NOT Expr              {printf("expr self not\n");$$=insert_expr_not_expr($2);}
    | PLUS Expr             {printf("expr self plus\n");$$=insert_expr_plus_expr($2);}
    | Expr PLUS Expr        {printf("expr plus\n");$$=insert_expr_op($1,"PLUS",$3);}
    | Expr MINUS Expr       {printf("expr MINUS\n");$$=insert_expr_op($1,"MINUS",$3);}
    | Expr STAR Expr        {printf("expr STAR\n");$$=insert_expr_op($1,"STAR",$3);}
    | Expr DIV Expr         {printf("expr DIV\n");$$=insert_expr_op($1,"DIV",$3);}
    | Expr MOD Expr         {printf("expr MOD\n");$$=insert_expr_op($1,"MOD",$3);}
    | Expr AND Expr         {printf("expr AND\n");$$=insert_expr_op($1,"AND",$3);}
    | Expr OR Expr          {printf("expr OR\n");$$=insert_expr_op($1,"OR",$3);}
    | Expr XOR Expr         {printf("expr XOR\n");$$=insert_expr_op($1,"XOR",$3);}
    | Expr LSHIFT Expr      {printf("expr LSHIFT\n");$$=insert_expr_op($1,"LSHIFT",$3);}
    | Expr RSHIFT Expr      {printf("expr RSHIFT\n");$$=insert_expr_op($1,"RSHIFT",$3);}
    | Expr EQ Expr          {printf("expr EQ\n");$$=insert_expr_op($1,"EQ",$3);}
    | Expr GE Expr          {printf("expr GE\n");$$=insert_expr_op($1,"GE",$3);}
    | Expr GT Expr          {printf("expr GT\n");$$=insert_expr_op($1,"GT",$3);}
    | Expr LE Expr          {printf("expr LE\n");$$=insert_expr_op($1,"LE",$3);}
    | Expr LT Expr          {printf("expr LT\n");$$=insert_expr_op($1,"LT",$3);}
    | Expr NE Expr          {printf("expr NE\n");$$=insert_expr_op($1,"NE",$3);}
    | LPAR error RPAR       {$$=NULL;printf("expr error\n");flag_tree=0;}

%%

void yyerror (char *s) { 
    /* printf ("Line %d, col %d: %s: %s\n", line_num, col_num, s, yytext ); */
    printf( "yy error: %s\n", s);
}