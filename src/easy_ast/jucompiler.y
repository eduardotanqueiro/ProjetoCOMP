%{
    //  Eduardo Carneiro - 2020240332
    //  Ricardo Silva - 2020227184
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"
#define NSYMS 100
#define DEBUG 0

int yylex (void);
extern void yyerror(char* s);
no* raiz;
no* tmp;

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
%left OR
%left AND
%left XOR
%left EQ NE
%left GE GT LT LE
%left LSHIFT RSHIFT
%left MINUS PLUS  
%left STAR DIV MOD
%right NOT
%left LPAR RPAR LSQ RSQ

%right ELSE

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
%type<node>ExprOp

/* --------------------------------------------------- */

%union{
    char* id;
    no* node;
}

%%

// EBNF, com a qual [...] significa “opcional” e {...} significa “zero ou mais repetições”

Program:  CLASS ID LBRACE MethodFieldSemicolonRep RBRACE {if(DEBUG)printf("program\n");$$=raiz=criar_no("Program",""); $$->filho = criar_no("Id",$2); adicionar_irmao($$->filho, $4);}


MethodFieldSemicolonRep: MethodDecl MethodFieldSemicolonRep {if(DEBUG)printf("method dcl prog\n");$$=$1; adicionar_irmao($$,$2);}
                       | FieldDecl MethodFieldSemicolonRep  {if(DEBUG)printf("field decl prog\n"); if($1!=NULL){$$=$1; adicionar_irmao($$,$2);}else $$=$2;} //Verificação pois o fielddecl pode ser null
                       | SEMICOLON MethodFieldSemicolonRep  {if(DEBUG)printf("semicolon \n");$$=$2;}
                       |                                    {if(DEBUG)printf("method dcl prog rep empty \n");$$=NULL;}
                       ;


MethodDecl: PUBLIC STATIC MethodHeader MethodBody {if(DEBUG)printf("method dcl solo\n");$$= criar_no("MethodDecl",""), $$->filho=$3; adicionar_irmao($3,$4);}


FieldDecl: PUBLIC STATIC Type ID CommaIdRep SEMICOLON {if(DEBUG)printf("field decl solo \n");$$=criar_no("FieldDecl",""), $$->filho=$3; adicionar_irmao($3,criar_no("Id",$4)); if($5!=NULL){tmp = $5; while(tmp != NULL){ no* tmp1 = criar_no("FieldDecl","");no* tmp2 = criar_no($3->tipo,$3->val); tmp1->filho= tmp2; adicionar_irmao(tmp2,criar_no("Id",tmp->val)); adicionar_irmao($$,tmp1); tmp = tmp->irmao;} } ;}
        | error SEMICOLON {$$=NULL;if(DEBUG)printf("fielddecl error \n");flag_tree=0;}

CommaIdRep: COMMA ID CommaIdRep {if(DEBUG)printf("commma id rep \n");$$=criar_no("Id",$2); adicionar_irmao($$,$3);}
          |                     {if(DEBUG)printf("comma id rep empty \n");$$=NULL;}
          ;


Type: BOOL  {if(DEBUG)printf("bool \n");$$=criar_no("Bool","");}
    | INT {if(DEBUG)printf("int \n");$$=criar_no("Int","");}
    | DOUBLE {if(DEBUG)printf("double \n");$$=criar_no("Double","");}

MethodHeader: Type ID LPAR FormalParams RPAR    {if(DEBUG)printf("method header full \n");$$=criar_no("MethodHeader",""); $$->filho=$1; adicionar_irmao($1, criar_no("Id",$2)); adicionar_irmao($1, criar_no("MethodParams","")); $1->irmao->irmao->filho=$4;}
            | VOID ID LPAR FormalParams RPAR    {if(DEBUG)printf("method header void params \n");$$=criar_no("MethodHeader",""); $$->filho=criar_no("Void",""); adicionar_irmao($$->filho, criar_no("Id",$2)); adicionar_irmao($$->filho,criar_no("MethodParams","")); $$->filho->irmao->irmao->filho=$4;}
            | Type ID LPAR RPAR                 {if(DEBUG)printf("method header type no params \n");$$=criar_no("MethodHeader",""); $$->filho=$1; adicionar_irmao($1, criar_no("Id",$2)); adicionar_irmao($1, criar_no("MethodParams",""));}
            | VOID ID LPAR RPAR                 {if(DEBUG)printf("method header void no params \n");$$=criar_no("MethodHeader",""); $$->filho=criar_no("Void",""); adicionar_irmao($$->filho, criar_no("Id",$2)); adicionar_irmao($$->filho,criar_no("MethodParams",""));}


FormalParams: Type ID CommaTypeIdRep {if(DEBUG)printf("formalsparams type \n");$$=criar_no("ParamDecl",""); $$->filho=$1;adicionar_irmao($1, criar_no("Id",$2));adicionar_irmao($$,$3);}
            | STRING LSQ RSQ ID {if(DEBUG)printf("formalparams string \n");$$=criar_no("ParamDecl",""); $$->filho=criar_no("StringArray",""); adicionar_irmao($$->filho, criar_no("Id",$4));}

CommaTypeIdRep: COMMA Type ID CommaTypeIdRep {if(DEBUG)printf("commatypeidrep \n"); $$ = criar_no("ParamDecl",""); $$->filho=$2; adicionar_irmao($2,criar_no("Id",$3)); adicionar_irmao($$,$4);}
              |                              {if(DEBUG)printf("commatypeidrep empty \n");$$=NULL;}
              ;

MethodBody: LBRACE StatementVarRep RBRACE {if(DEBUG)printf("methodbody \n");$$=criar_no("MethodBody","");$$->filho=$2;}

StatementVarRep: Statement StatementVarRep {if(DEBUG)printf("statementvarrep stat \n"); if($1 != NULL){$$=$1; adicionar_irmao($$,$2);}else $$=$2;}
               | VarDecl StatementVarRep   {if(DEBUG)printf("statementvarrep vardecl \n");$$=$1; adicionar_irmao($$,$2);}
               |                           {if(DEBUG)printf("statementvarrep empty \n");$$=NULL;}
               ;

VarDecl: Type ID CommaIdRep SEMICOLON {if(DEBUG)printf("vardecl solo \n");$$=criar_no("VarDecl",""); $$->filho=$1; adicionar_irmao($1, criar_no("Id",$2)); if($3!=NULL){tmp = $3; while(tmp != NULL){ no* tmp1 = criar_no("VarDecl","");no* tmp2 = criar_no($1->tipo,$1->val); tmp1->filho= tmp2; adicionar_irmao(tmp2,criar_no("Id",tmp->val)); adicionar_irmao($$,tmp1); tmp = tmp->irmao;} } ;}

Statement: LBRACE StatementRep RBRACE                 {if(DEBUG)printf("statement block\n");if( contador_irmaos($2)>1){$$=criar_no("Block","");$$->filho=$2;}else{$$=$2;}} //TODO block checking
         | IF LPAR Expr RPAR Statement ELSE Statement {if(DEBUG)printf("statement if full\n");$$=criar_no("If",""); $$->filho=$3; tmp = criar_no("Block","");
                                                                                                                        if ($5 != NULL && contador_irmaos($5) == 1) {
                                                                                                                            adicionar_irmao($3, $5);
                                                                                                                            if ($7 != NULL && contador_irmaos($7) == 1) {
                                                                                                                                adicionar_irmao($5, $7);
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                adicionar_irmao($5, tmp);
                                                                                                                                tmp->filho = $7;
                                                                                                                            }
                                                                                                                        }
                                                                                                                        else {
                                                                                                                            adicionar_irmao($3, tmp);
                                                                                                                            tmp->filho = $5;
                                                                                                                            if ($7 != NULL && contador_irmaos($7) == 1 ) {
                                                                                                                                adicionar_irmao(tmp, $7);
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                no* tmp_aux = criar_no("Block","");
                                                                                                                                adicionar_irmao(tmp, tmp_aux);
                                                                                                                                tmp_aux->filho = $7;
                                                                                                                            }
                                                                                                                        }} //TODO block
         | IF LPAR Expr RPAR Statement                {if(DEBUG)printf("statement if solo\n");$$=criar_no("If",""); $$->filho=$3;tmp = criar_no("Block","");if($5 != NULL && contador_irmaos($5) == 1 ){adicionar_irmao($3,$5); adicionar_irmao($5, tmp);}else{adicionar_irmao($3,tmp); tmp->filho = $5; adicionar_irmao(tmp,criar_no("Block",""));}} ///TODO block
         | WHILE LPAR Expr RPAR Statement             {if(DEBUG)printf("statement while\n");$$=criar_no("While",""); $$->filho=$3; if($5 != NULL && contador_irmaos($5) < 2){adicionar_irmao($3,$5);}else{tmp = criar_no("Block",""); adicionar_irmao($3,tmp); tmp->filho = $5;} } //TODO block
         | RETURN Expr SEMICOLON                      {if(DEBUG)printf("statement return expr\n");$$=criar_no("Return",""); $$->filho=$2;}
         | RETURN SEMICOLON                           {if(DEBUG)printf("statement return\n");$$=criar_no("Return","");}
         | PRINT LPAR Expr RPAR SEMICOLON             {if(DEBUG)printf("statement print expr\n");$$=criar_no("Print","");$$->filho=$3;}
         | PRINT LPAR STRLIT RPAR SEMICOLON           {if(DEBUG)printf("statement print str\n");$$=criar_no("Print","");$$->filho=criar_no("StrLit",$3);}
         | MethodInvocation SEMICOLON                 {if(DEBUG)printf("statement MI\n");$$=$1;}
         | Assignment SEMICOLON                       {if(DEBUG)printf("statement agn\n");$$=$1;}
         | ParseArgs SEMICOLON                        {if(DEBUG)printf("statement pa\n");$$=$1;}
         | SEMICOLON                                  {if(DEBUG)printf("statement semicolon\n");$$=NULL;}
         | error SEMICOLON                            {$$=NULL;if(DEBUG)printf("statement error\n");flag_tree=0;}

StatementRep: Statement StatementRep {if(DEBUG)printf("statementrep \n"); if($1!=NULL){$$=$1;adicionar_irmao($$,$2);} else { $$=$2;}} //TODO ?!??!?!?
            |                        {if(DEBUG)printf("statement rep empty \n");$$=NULL;}
            ;

MethodInvocation: ID LPAR RPAR                   {if(DEBUG)printf("methodinvocation \n");$$=criar_no("Call",""); $$->filho = criar_no("Id",$1);}
                | ID LPAR Expr CommaExprRep RPAR {if(DEBUG)printf("methodinvocation \n");$$=criar_no("Call",""); $$->filho = criar_no("Id",$1); adicionar_irmao($$->filho,$3); adicionar_irmao($3,$4);}
                | ID LPAR error RPAR    {$$=NULL;if(DEBUG)printf("methodinvocation \n");flag_tree=0;}



CommaExprRep: COMMA Expr CommaExprRep {if(DEBUG)printf("commaexprrep \n");if($2!=NULL){$$=$2;adicionar_irmao($$,$3);}else $$=$2;}
            |                         {if(DEBUG)printf("commmaexprrep empty \n");$$=NULL;}
            ;


Assignment: ID ASSIGN Expr {if(DEBUG)printf("assign \n");$$=criar_no("Assign","");$$->filho=criar_no("Id",$1); adicionar_irmao($$->filho,$3);}

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR {if(DEBUG)printf("parseargs full \n");$$=criar_no("ParseArgs",""); $$->filho=criar_no("Id",$3); adicionar_irmao($$->filho,$5);}
        | PARSEINT LPAR error RPAR  {$$=NULL;if(DEBUG)printf("parseargs error \n");flag_tree=0;}


Expr: ExprOp                {$$=$1;}//PARA NÃO SE PODER DAR DOIS ASSIGNS SEGUIDOS!!
    | Assignment            {$$=$1;}


ExprOp: LPAR Expr RPAR        {if(DEBUG)printf("ExprOp brace\n");$$=$2;}
    | MethodInvocation      {if(DEBUG)printf("ExprOp MI\n");$$=$1;}
    | ParseArgs             {if(DEBUG)printf("ExprOp pa\n");$$=$1;}
    | ID                    {if(DEBUG)printf("ExprOp id\n");$$=criar_no("Id",$1);}
    | ID DOTLENGTH          {if(DEBUG)printf("ExprOp dotlenght\n");$$=criar_no("Length",""); $$->filho = criar_no("Id",$1);}
    | INTLIT                {if(DEBUG)printf("ExprOp intlit\n");$$=criar_no("DecLit",$1);}
    | REALLIT               {if(DEBUG)printf("ExprOp reallit\n");$$=criar_no("RealLit",$1);}
    | BOOLLIT               {if(DEBUG)printf("ExprOp boollit\n");$$=criar_no("BoolLit",$1);}
    | MINUS ExprOp %prec NOT    {if(DEBUG)printf("ExprOp self minus\n");$$=criar_no("Minus",""); $$->filho=$2;} // DAR A MESMA PRECEDENCIA AO MINUS QUE O NOT, POIS NESTE CASO O MINUS IGUALA-SE AO NOT
    | NOT ExprOp                {if(DEBUG)printf("ExprOp self not\n");$$=criar_no("Not",""); $$->filho=$2;}
    | PLUS ExprOp %prec NOT    {if(DEBUG)printf("ExprOp self plus\n");$$=criar_no("Plus",""); $$->filho=$2;}
    | ExprOp PLUS ExprOp        {if(DEBUG)printf("ExprOp plus\n");$$=criar_no("Add",""); $$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp MINUS ExprOp       {if(DEBUG)printf("ExprOp MINUS\n");$$=criar_no("Sub","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp STAR ExprOp        {if(DEBUG)printf("ExprOp STAR\n");$$=criar_no("Mul","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp DIV ExprOp         {if(DEBUG)printf("ExprOp DIV\n");$$=criar_no("Div","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp MOD ExprOp         {if(DEBUG)printf("ExprOp MOD\n");$$=criar_no("Mod","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp AND ExprOp         {if(DEBUG)printf("ExprOp AND\n");$$=criar_no("And","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp OR ExprOp          {if(DEBUG)printf("ExprOp OR\n");$$=criar_no("Or","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp XOR ExprOp         {if(DEBUG)printf("ExprOp XOR\n");$$=criar_no("Xor","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp LSHIFT ExprOp      {if(DEBUG)printf("ExprOp LSHIFT\n");$$=criar_no("Lshift","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp RSHIFT ExprOp      {if(DEBUG)printf("ExprOp RSHIFT\n");$$=criar_no("Rshift","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp EQ ExprOp          {if(DEBUG)printf("ExprOp EQ\n");$$=criar_no("Eq","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp GE ExprOp          {if(DEBUG)printf("ExprOp GE\n");$$=criar_no("Ge","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp GT ExprOp          {if(DEBUG)printf("ExprOp GT\n");$$=criar_no("Gt","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp LE ExprOp          {if(DEBUG)printf("ExprOp LE\n");$$=criar_no("Le","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp LT ExprOp          {if(DEBUG)printf("ExprOp LT\n");$$=criar_no("Lt","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp NE ExprOp          {if(DEBUG)printf("ExprOp NE\n");$$=criar_no("Ne","");$$->filho=$1; adicionar_irmao($1, $3);}
    | LPAR error RPAR       {$$=NULL;if(DEBUG)printf("ExprOp error\n");flag_tree=0;}

%%
