%{
    //  Eduardo Carneiro - 2020240332
    //  Ricardo Silva - 2020227184
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol_table.h"
#include "ast.h"
#define NSYMS 100
#define DEBUG 0

int yylex (void);
extern void yyerror(char* s);
no* raiz;
no* tmp;

extern int flag_tree;

table_class* class_table;
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


Program:  CLASS ID LBRACE MethodFieldSemicolonRep RBRACE {$$=raiz=criar_no("Program",""); $$->filho = criar_no("Id",$2); adicionar_irmao($$->filho, $4);}


MethodFieldSemicolonRep: MethodDecl MethodFieldSemicolonRep {$$=$1; adicionar_irmao($$,$2);}
                       | FieldDecl MethodFieldSemicolonRep  {if($1!=NULL){$$=$1; adicionar_irmao($$,$2);}else $$=$2;} //Verificação pois o fielddecl pode ser null, e não podemos adicionar irmaos a um nó NULL
                       | SEMICOLON MethodFieldSemicolonRep  {$$=$2;}
                       |                                    {$$=NULL;}
                       ;


MethodDecl: PUBLIC STATIC MethodHeader MethodBody {$$= criar_no("MethodDecl",""); $$->filho=$3; adicionar_irmao($3,$4);}


FieldDecl: PUBLIC STATIC Type ID CommaIdRep SEMICOLON {$$=criar_no("FieldDecl",""); $$->filho=$3; 
                                                                                    adicionar_irmao($3,criar_no("Id",$4)); 
                                                                                    if($5!=NULL){ //Verificar se há argumentos e, se sim, ir criar um nó fielddecl para cada arguento
                                                                                        tmp = $5; 
                                                                                        while(tmp != NULL){ 
                                                                                            no* tmp1 = criar_no("FieldDecl","");
                                                                                            no* tmp2 = criar_no($3->tipo,$3->val); 
                                                                                            tmp1->filho= tmp2; 
                                                                                            adicionar_irmao(tmp2,criar_no("Id",tmp->val)); 
                                                                                            adicionar_irmao($$,tmp1); 
                                                                                            tmp = tmp->irmao;
                                                                                        } 
                                                                                    };}
        | error SEMICOLON                             {$$=NULL;flag_tree=0;}

CommaIdRep: COMMA ID CommaIdRep {$$=criar_no("Id",$2); adicionar_irmao($$,$3);}
          |                     {$$=NULL;}
          ;


Type: BOOL   {$$=criar_no("Bool","");}
    | INT    {$$=criar_no("Int","");}
    | DOUBLE {$$=criar_no("Double","");}

MethodHeader: Type ID LPAR FormalParams RPAR    {$$=criar_no("MethodHeader",""); $$->filho=$1; //Cria-se o nó methodheader, adiciona-se filhos o type e o ID, cria-se o methodparams e colocam-se os formalparams como filhos do methodparams
                                                                                 adicionar_irmao($1, criar_no("Id",$2)); 
                                                                                 adicionar_irmao($1, criar_no("MethodParams","")); 
                                                                                 $1->irmao->irmao->filho=$4;}

            | VOID ID LPAR FormalParams RPAR    {$$=criar_no("MethodHeader",""); $$->filho=criar_no("Void",""); 
                                                                                 adicionar_irmao($$->filho, criar_no("Id",$2)); 
                                                                                 adicionar_irmao($$->filho,criar_no("MethodParams","")); 
                                                                                 $$->filho->irmao->irmao->filho=$4;}

            | Type ID LPAR RPAR                 {$$=criar_no("MethodHeader",""); $$->filho=$1; 
                                                                                 adicionar_irmao($1, criar_no("Id",$2)); 
                                                                                 adicionar_irmao($1, criar_no("MethodParams",""));}

            | VOID ID LPAR RPAR                 {$$=criar_no("MethodHeader",""); $$->filho=criar_no("Void",""); 
                                                                                 adicionar_irmao($$->filho, criar_no("Id",$2)); 
                                                                                 adicionar_irmao($$->filho,criar_no("MethodParams",""));}


FormalParams: Type ID CommaTypeIdRep {$$=criar_no("ParamDecl",""); $$->filho=$1;adicionar_irmao($1, criar_no("Id",$2));adicionar_irmao($$,$3);}
            | STRING LSQ RSQ ID      {$$=criar_no("ParamDecl",""); $$->filho=criar_no("StringArray",""); adicionar_irmao($$->filho, criar_no("Id",$4));}

CommaTypeIdRep: COMMA Type ID CommaTypeIdRep {$$ = criar_no("ParamDecl",""); $$->filho=$2; adicionar_irmao($2,criar_no("Id",$3)); adicionar_irmao($$,$4);}
              |                              {$$=NULL;}
              ;

MethodBody: LBRACE StatementVarRep RBRACE {$$=criar_no("MethodBody","");$$->filho=$2;}

StatementVarRep: Statement StatementVarRep {if($1 != NULL){$$=$1; adicionar_irmao($$,$2);}else $$=$2;} //Verificamos se o Statement é NULL, se não for metemos como filho e adicionamos o Rep como filho, se não o filho fica o Rep
               | VarDecl StatementVarRep   {$$=$1; adicionar_irmao($$,$2);}
               |                           {$$=NULL;}
               ;

VarDecl: Type ID CommaIdRep SEMICOLON {$$=criar_no("VarDecl",""); $$->filho=$1; 
                                                                  adicionar_irmao($1, criar_no("Id",$2)); 
                                                                  if($3!=NULL){ //Verificamos se existe mais do que uma declaração de variável, se sim cria-se um nó irmao do tipo VarDecl para cada variável
                                                                    tmp = $3; 
                                                                    while(tmp != NULL){ 
                                                                        no* tmp1 = criar_no("VarDecl","");
                                                                        no* tmp2 = criar_no($1->tipo,$1->val); 
                                                                        tmp1->filho= tmp2; 
                                                                        adicionar_irmao(tmp2,criar_no("Id",tmp->val)); 
                                                                        adicionar_irmao($$,tmp1); tmp = tmp->irmao;
                                                                    } 
                                                                  } ;}

Statement: LBRACE StatementRep RBRACE                 {if( contador_irmaos($2)>1){$$=criar_no("Block","");$$->filho=$2;}else{$$=$2;}} //Verificar se o statementRep tem mais 2 ou mais statements, de modo a criar o block
         | IF LPAR Expr RPAR Statement ELSE Statement {$$=criar_no("If","");                                           
                                                        if($3 != NULL){  //Verificamos se o Expr não é NULL
                                                            $$->filho=$3; 
                                                            tmp = criar_no("Block","");
                                                            if ($5 != NULL && contador_irmaos($5) < 2) { //Verificar se o Statement não é NULL e se tem menos de 2 statements
                                                                adicionar_irmao($3, $5);
                                                                if ($7 != NULL && contador_irmaos($7) < 2) { //A mesma verificação de cima
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
                                                                if ($7 != NULL && contador_irmaos($7) < 2 ) { //Verificar se o Statement não é NULL e se tem menos de 2 statements
                                                                    adicionar_irmao(tmp, $7);
                                                                }
                                                                else {
                                                                    no* tmp_aux = criar_no("Block","");
                                                                    adicionar_irmao(tmp, tmp_aux);
                                                                    tmp_aux->filho = $7;
                                                                }
                                                            }
                                                        }else{

                                                            tmp = criar_no("Block",""); //A mesma lógica de cima, mas deste modo a ignorar o Expr
                                                            if ($5 != NULL && contador_irmaos($5) < 2) {
                                                                $$->filho = $5;
                                                                if ($7 != NULL && contador_irmaos($7) < 2) {
                                                                    adicionar_irmao($5, $7);
                                                                }
                                                                else {
                                                                    adicionar_irmao($5, tmp);
                                                                    tmp->filho = $7;
                                                                }
                                                            }
                                                            else {
                                                                $$->filho = tmp;
                                                                tmp->filho = $5;
                                                                if ($7 != NULL && contador_irmaos($7) < 2) {
                                                                    adicionar_irmao(tmp, $7);
                                                                }
                                                                else {
                                                                    no* tmp_aux = criar_no("Block","");
                                                                    adicionar_irmao(tmp, tmp_aux);
                                                                    tmp_aux->filho = $7;
                                                                }
                                                            }   
                                                                
                                                                
                                                        }}

         | IF LPAR Expr RPAR Statement                {$$=criar_no("If",""); //Mesma lógica aplicada ao outro IF
                                                        tmp = criar_no("Block","");
                                                    
                                                        if($3!=NULL){ //Verificar se o Expr não é NULL, verificar o nr de statements no statement de modo a criar ou não o block
                                                            $$->filho=$3;
                                                            if($5 != NULL && contador_irmaos($5) < 2 ){
                                                                adicionar_irmao($3,$5); 
                                                                adicionar_irmao($5, tmp);}
                                                            else{
                                                                adicionar_irmao($3,tmp); 
                                                                tmp->filho = $5; 
                                                                adicionar_irmao(tmp,criar_no("Block",""));
                                                                }
                                                        }else{

                                                            if($5 != NULL && contador_irmaos($5) < 2 ){
                                                                $$->filho = $5; 
                                                                adicionar_irmao($5, tmp);}
                                                            else{
                                                                $$->filho = tmp; 
                                                                tmp->filho = $5; 
                                                                adicionar_irmao(tmp,criar_no("Block",""));
                                                            }
                                                        }}

         | WHILE LPAR Expr RPAR Statement             {$$=criar_no("While",""); //Mesma lógica aplicada aos IFs
                                                        if($3!=NULL){  //Verificar se o Expr não é NULL, verificar o nr de statements no statement de modo a criar ou não o block
                                                            $$->filho=$3; 
                                                            if($5 != NULL && contador_irmaos($5) < 2){
                                                                adicionar_irmao($3,$5);}
                                                            else{
                                                                tmp = criar_no("Block",""); 
                                                                adicionar_irmao($3,tmp); 
                                                                tmp->filho = $5;} 
                                                        }
                                                        else{
                                                            if($5 != NULL && contador_irmaos($5) < 2){
                                                                $$->filho=$5;}
                                                            else{
                                                                tmp = criar_no("Block",""); 
                                                                $$->filho = tmp; 
                                                                tmp->filho = $5;} 
                                                        } }
         | RETURN Expr SEMICOLON                      {$$=criar_no("Return",""); $$->filho=$2;}
         | RETURN SEMICOLON                           {$$=criar_no("Return","");}
         | PRINT LPAR Expr RPAR SEMICOLON             {$$=criar_no("Print","");$$->filho=$3;}
         | PRINT LPAR STRLIT RPAR SEMICOLON           {$$=criar_no("Print","");$$->filho=criar_no("StrLit",$3);}
         | MethodInvocation SEMICOLON                 {$$=$1;}
         | Assignment SEMICOLON                       {$$=$1;}
         | ParseArgs SEMICOLON                        {$$=$1;}
         | SEMICOLON                                  {$$=NULL;}
         | error SEMICOLON                            {$$=NULL;flag_tree=0;} // Colocar a flag para dar print à tree a false

StatementRep: Statement StatementRep {if($1!=NULL){ //Verificar se o statement não é NULL
                                        $$=$1;
                                        adicionar_irmao($$,$2);} 
                                    else { $$=$2;}} 

            |                        {$$=NULL;}
            ;

MethodInvocation: ID LPAR RPAR                   {$$=criar_no("Call",""); $$->filho = criar_no("Id",$1);}

                | ID LPAR Expr CommaExprRep RPAR {$$=criar_no("Call",""); $$->filho = criar_no("Id",$1); //Verificar se o Expr não é NULL para adicionar os irmãos
                                                                          if($3 != NULL){
                                                                            adicionar_irmao($$->filho,$3); 
                                                                            adicionar_irmao($3,$4);
                                                                          }else 
                                                                            adicionar_irmao($$->filho,$4);}
                | ID LPAR error RPAR    {$$=NULL;flag_tree=0;}



CommaExprRep: COMMA Expr CommaExprRep {if($2!=NULL){ //Verificar se Expr não é NULL
                                        $$=$2;
                                        adicionar_irmao($$,$3);
                                       }else 
                                        $$=$2;}

            |                         {$$=NULL;}
            ;


Assignment: ID ASSIGN Expr {$$=criar_no("Assign","");$$->filho=criar_no("Id",$1); adicionar_irmao($$->filho,$3);}

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR {$$=criar_no("ParseArgs",""); $$->filho=criar_no("Id",$3); adicionar_irmao($$->filho,$5);}
        |  PARSEINT LPAR error RPAR           {$$=NULL;flag_tree=0;}


Expr: ExprOp                {$$=$1;}//PARA NÃO SE PODER DAR DOIS ASSIGNS SEGUIDOS!!
    | Assignment            {$$=$1;}


ExprOp: LPAR Expr RPAR          {$$=$2;}
    | MethodInvocation          {$$=$1;}
    | ParseArgs                 {$$=$1;}
    | ID                        {$$=criar_no("Id",$1);}
    | ID DOTLENGTH              {$$=criar_no("Length",""); $$->filho = criar_no("Id",$1);}
    | INTLIT                    {$$=criar_no("DecLit",$1);}
    | REALLIT                   {$$=criar_no("RealLit",$1);}
    | BOOLLIT                   {$$=criar_no("BoolLit",$1);}
    | MINUS ExprOp %prec NOT    {;$$=criar_no("Minus",""); $$->filho=$2;} // DAR A MESMA PRECEDENCIA AO MINUS QUE O NOT, POIS NESTE CASO O MINUS IGUALA-SE AO NOT
    | NOT ExprOp                {;$$=criar_no("Not",""); $$->filho=$2;}
    | PLUS ExprOp %prec NOT     {;$$=criar_no("Plus",""); $$->filho=$2;} // DAR A MESMA PRECEDENCIA AO MINUS QUE O NOT, POIS NESTE CASO O MINUS IGUALA-SE AO NOT
    | ExprOp PLUS ExprOp        {$$=criar_no("Add",""); $$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp MINUS ExprOp       {$$=criar_no("Sub","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp STAR ExprOp        {$$=criar_no("Mul","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp DIV ExprOp         {$$=criar_no("Div","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp MOD ExprOp         {$$=criar_no("Mod","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp AND ExprOp         {$$=criar_no("And","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp OR ExprOp          {$$=criar_no("Or","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp XOR ExprOp         {$$=criar_no("Xor","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp LSHIFT ExprOp      {$$=criar_no("Lshift","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp RSHIFT ExprOp      {$$=criar_no("Rshift","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp EQ ExprOp          {$$=criar_no("Eq","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp GE ExprOp          {$$=criar_no("Ge","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp GT ExprOp          {$$=criar_no("Gt","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp LE ExprOp          {$$=criar_no("Le","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp LT ExprOp          {$$=criar_no("Lt","");$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp NE ExprOp          {$$=criar_no("Ne","");$$->filho=$1; adicionar_irmao($1, $3);}
    | LPAR error RPAR           {$$=NULL;flag_tree=0;}

%%
