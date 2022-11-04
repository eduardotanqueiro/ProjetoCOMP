%{
    //  Eduardo Carneiro - 2020240332
    //  Ricardo Silva - 2020
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "functions.h"
#include "symtab.h"
#include "y.tab.h"
#define NSYMS 100

symtab tab[NSYMS];

void varlist();

symtab *symlook(char *varname);
int yylex (void);
void yyerror(char* s);
no* raiz;

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

%type<node>Program
%type<node>MethodFieldSemicolonRep
%type<node>MethodDecl
%type<node>FieldDecl
%type<node>CommaIdRep
%type<node>Type
%type<node>MethodHeader
%type<node>FormalParams
%type<node>CommaTypeIdRep
%type<node>MethodBody
%type<node>StatementVarRep
%type<node>VarDecl
%type<node>Statement
%type<node>StatementRep
%type<node>MethodInvocation
%type<node>CommaExprRep
%type<node>Assignment
%type<node>ParseArgs
%type<node>Expr

/* --------------------------------------------------- */

%union{
    char* id;
    no* node;

}

%%

// EBNF, com a qual [...] significa “opcional” e {...} significa “zero ou mais repetições”

Program:  CLASS ID LBRACE MethodFieldSemicolonRep RBRACE {printf("program\n");$$=raiz=criar_no("Program","");
                                                          raiz->filho=$4;
                                                         }


MethodFieldSemicolonRep: MethodDecl MethodFieldSemicolonRep {printf("method dcl prog\n");$$=$1; adicionar_irmao($$,$2);}
                       | FieldDecl MethodFieldSemicolonRep  {printf("field decl prog\n");$$=$1; adicionar_irmao($$,$2);}
                       | SEMICOLON MethodFieldSemicolonRep  {printf("semicolon \n");$$=$2;}
                       |                                    {printf("method dcl prog rep empty \n");$$=NULL;}
                       ;


MethodDecl: PUBLIC STATIC MethodHeader MethodBody {printf("method dcl solo\n");$$= criar_no("MethodDecl",""), $$->filho=$3; adicionar_irmao($3,$4);}


FieldDecl: PUBLIC STATIC Type ID CommaIdRep SEMICOLON {printf("field decl solo \n");$$=criar_no("FieldDecl",""), $$->irmao=$3; adicionar_irmao($3,criar_node("Id",$4)); adicionar_irmao($3->irmao,$5);}
        | error SEMICOLON {$$=NULL;printf("fielddecl error \n");flag_tree=0;}

CommaIdRep: COMMA ID CommaIdRep {printf("commma id rep \n");$$=criar_no("Id",$2); adicionar_irmao($$,$3);}
          |                     {printf("comma id rep empty \n");$$=NULL;}
          ;


Type: BOOL  {printf("bool \n");$$=criar_no("Bool","");}
    | INT {printf("int \n");$$=criar_no("Int","");}
    | DOUBLE {printf("double \n");$$=criar_no("Double","");}

MethodHeader: Type ID LPAR FormalParams RPAR    {printf("method header full \n");$$=criar_no("MethodHeader",""); $$->filho=$1; adicionar_irmao($1, criar_no("Id",$2)); adicionar_irmao($1->irmao,$4);}
            | VOID ID LPAR FormalParams RPAR    {printf("method header void params \n");$$=criar_no("MethodHeader",""); $$->filho=criar_no("Void",""); adicionar_irmao($$->filho, criar_no("Id",$2)); adicionar_irmao($$->filho->irmao,$4);}
            | Type ID LPAR RPAR                 {printf("method header type no params \n");$$=criar_no("MethodHeader",""); $$->filho=$1; adicionar_irmao($1, criar_no("Id",$2));}
            | VOID ID LPAR RPAR                 {printf("method header void no params \n");$$=criar_no("MethodHeader",""); $$->filho=criar_no("Void",""); adicionar_irmao($$->filho, criar_no("Id",$2));}


FormalParams: Type ID CommaTypeIdRep {printf("formalsparams type \n");$$=criar_no("ParamDecl",""); $$->filho=$1;adicionar_irmao($1, criar_no("Id",$2));adicionar_irmao($1->irmao,$3);}
            | STRING LSQ RSQ ID {printf("formalparams string \n");$$=criar_no("ParamDecl",""); $$->filho=criar_no("StringArray",""); adicionar_irmao($$->filho, criar_no("Id",$4));}

CommaTypeIdRep: COMMA Type ID CommaTypeIdRep {printf("commatypeidrep \n");$$=insert_commatype_id_rep($2,$3,$4);}
          |                              {printf("commatypeidrep empty \n");$$=NULL;}   
          ;

MethodBody: LBRACE StatementVarRep RBRACE {printf("methodbody \n");$$=criar_no("MethodBody","");$$->filho=$2;}

StatementVarRep: Statement StatementVarRep {printf("statementvarrep stat \n");$$=$1; adicionar_irmao($$,$2);}
               | VarDecl StatementVarRep   {printf("statementvarrep vardecl \n");$$=$1; adicionar_irmao($$,$2);}
               |                           {printf("statementvarrep empty \n");$$=NULL;}
               ;

VarDecl: Type ID CommaIdRep SEMICOLON {printf("vardecl solo \n");$$=criar_no("VarDecl",""); $$->filho=$1; adicionar_irmao($1, criar_no("Id",$2)); adicionar_irmao($1->irmao,$3);}

Statement: LBRACE StatementRep RBRACE                 {printf("statement block\n");$$=$2;} //TODO block checking
         | IF LPAR Expr RPAR Statement ELSE Statement {printf("statement if full\n");$$=criar_no("If",""); $$->filho=$3; adicionar_irmao($3, $5); adicionar_irmao($5, $7)} //TODO block
         | IF LPAR Expr RPAR Statement                {printf("statement if solo\n");$$=insert_if_statement($3,$5,NULL);} ///TODO block
         | WHILE LPAR Expr RPAR Statement             {printf("statement while\n");$$=insert_while_statement($3,$5);} //TODO block
         | RETURN Expr SEMICOLON                      {printf("statement return expr\n");$$=criar_no("Return",""); $$->filho=$2;}
         | RETURN SEMICOLON                           {printf("statement return\n");$$=criar_no("Return","");}
         | PRINT LPAR Expr RPAR SEMICOLON             {printf("statement print expr\n");$$=criar_no("Print","");$$->filho=$3;}
         | PRINT LPAR STRLIT RPAR SEMICOLON           {printf("statement print str\n");$$=criar_no("Print",criar_no("StrLit",$3));$$->filho=$3;}
         | MethodInvocation SEMICOLON                 {printf("statement MI\n");$$=$1;}
         | Assignment SEMICOLON                       {printf("statement agn\n");$$=$1;}
         | ParseArgs SEMICOLON                        {printf("statement pa\n");$$=$1;}
         | SEMICOLON                                  {printf("statement semicolon\n");$$=NULL;} //TODO ?!?!?!?
         | error SEMICOLON                            {$$=NULL;printf("statement error\n");flag_tree=0;}

StatementRep: Statement StatementRep {printf("statementrep \n"); if($1!=NULL){$$=$1;adicionar_irmao($$,$2)} else { $$=$2;}} //TODO ?!??!?!?
            |                        {printf("statement rep empty \n");$$=NULL;}
            ;

MethodInvocation: ID LPAR RPAR                   {printf("methodinvocation \n");$$=criar_no("Call",""); $$->filho = criar_no("Id",$1);}
                | ID LPAR Expr CommaExprRep RPAR {printf("methodinvocation \n");$$=criar_no("Call",""); $$->filho = criar_no("Id",$1); adicionar_irmao($1,$3); adicionar_irmao($3,$4);}
                | ID LPAR error RPAR    {$$=NULL;printf("methodinvocation \n");flag_tree=0;}



CommaExprRep: COMMA Expr CommaExprRep {printf("commaexprrep \n");$$=$2;adicionar_irmao($$,$3);}
            |                         {printf("commmaexprrep empty \n");$$=NULL;}
            ;


Assignment: ID ASSIGN Expr {printf("assign \n");$$=criar_no("Assign");$$->filho=criar_no("Id",$1); adicionar_irmao($$->filho,$3);}

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR {printf("parseargs full \n");$$=criar_no("ParseArgs"); $$->filho=criar_no("Id",$3); adicionar_irmao($$->filho,$5);}
        | PARSEINT LPAR error RPAR  {$$=NULL;printf("parseargs error \n");flag_tree=0;}

//TODO
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