%{
    //  Eduardo Carneiro - 2020240332
    //  Ricardo Silva - 2020227184
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "symbol_table.h"


int yylex (void);
extern void yyerror(char* s);
no* raiz;
no* tmp;



extern int line_num, col_num;
extern int flag_tree;
%}

/* --------------------------------------------------- */
%token <info> ID
%token <info> INTLIT
%token <info> REALLIT
%token <info> BOOLLIT
%token <info> STRLIT
%token <info> PLUS AND ASSIGN STAR DIV EQ GE GT LE LT MINUS MOD NE NOT OR PRINT DOTLENGTH LSHIFT RSHIFT PARSEINT

%token BOOL COMMA LBRACE LPAR LSQ RBRACE RPAR RSQ SEMICOLON ARROW XOR CLASS DOUBLE ELSE IF INT PUBLIC RETURN STATIC STRING VOID WHILE RESERVED



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
    info* info;
    no* node;
}

%%


Program:  CLASS ID LBRACE MethodFieldSemicolonRep RBRACE {$$=raiz=criar_no("Program",gen_token("",line_num, col_num)); $$->filho = criar_no("Id",$2); adicionar_irmao($$->filho, $4);}


MethodFieldSemicolonRep: MethodDecl MethodFieldSemicolonRep {$$=$1; adicionar_irmao($$,$2);}
                       | FieldDecl MethodFieldSemicolonRep  {if($1!=NULL){$$=$1; adicionar_irmao($$,$2);}else $$=$2;} //Verificação pois o fielddecl pode ser null, e não podemos adicionar irmaos a um nó NULL
                       | SEMICOLON MethodFieldSemicolonRep  {$$=$2;}
                       |                                    {$$=NULL;}
                       ;


MethodDecl: PUBLIC STATIC MethodHeader MethodBody {$$= criar_no("MethodDecl",gen_token("",line_num, col_num)); $$->filho=$3; adicionar_irmao($3,$4);}


FieldDecl: PUBLIC STATIC Type ID CommaIdRep SEMICOLON {$$=criar_no("FieldDecl",gen_token("",line_num, col_num)); $$->filho=$3; 
                                                                                    adicionar_irmao($3,criar_no("Id",$4)); 
                                                                                    if($5!=NULL){ //Verificar se há argumentos e, se sim, ir criar um nó fielddecl para cada arguento
                                                                                        tmp = $5; 
                                                                                        while(tmp != NULL){ 
                                                                                            no* tmp1 = criar_no("FieldDecl",gen_token("",line_num, col_num));
                                                                                            no* tmp2 = criar_no($3->tipo,$3->info); 
                                                                                            tmp1->filho= tmp2; 
                                                                                            adicionar_irmao(tmp2,criar_no("Id",tmp->info)); 
                                                                                            adicionar_irmao($$,tmp1); 
                                                                                            tmp = tmp->irmao;
                                                                                        } 
                                                                                    };}
        | error SEMICOLON                             {$$=NULL;flag_tree=0;}

CommaIdRep: COMMA ID CommaIdRep {$$=criar_no("Id",$2); adicionar_irmao($$,$3);}
          |                     {$$=NULL;}
          ;


Type: BOOL   {$$=criar_no("Bool",gen_token("",line_num, col_num));}
    | INT    {$$=criar_no("Int",gen_token("",line_num, col_num));}
    | DOUBLE {$$=criar_no("Double",gen_token("",line_num, col_num));}

MethodHeader: Type ID LPAR FormalParams RPAR    {$$=criar_no("MethodHeader",gen_token("",line_num, col_num)); $$->filho=$1; //Cria-se o nó methodheader, adiciona-se filhos o type e o ID, cria-se o methodparams e colocam-se os formalparams como filhos do methodparams
                                                                                 adicionar_irmao($1, criar_no("Id",$2)); 
                                                                                 adicionar_irmao($1, criar_no("MethodParams",gen_token("",line_num, col_num))); 
                                                                                 $1->irmao->irmao->filho=$4;}

            | VOID ID LPAR FormalParams RPAR    {$$=criar_no("MethodHeader",gen_token("",line_num, col_num)); $$->filho=criar_no("Void",gen_token("",line_num, col_num)); 
                                                                                 adicionar_irmao($$->filho, criar_no("Id",$2)); 
                                                                                 adicionar_irmao($$->filho,criar_no("MethodParams",gen_token("",line_num, col_num))); 
                                                                                 $$->filho->irmao->irmao->filho=$4;}

            | Type ID LPAR RPAR                 {$$=criar_no("MethodHeader",gen_token("",line_num, col_num)); $$->filho=$1; 
                                                                                 adicionar_irmao($1, criar_no("Id",$2)); 
                                                                                 adicionar_irmao($1, criar_no("MethodParams",gen_token("",line_num, col_num)));}

            | VOID ID LPAR RPAR                 {$$=criar_no("MethodHeader",gen_token("",line_num, col_num)); $$->filho=criar_no("Void",gen_token("",line_num, col_num)); 
                                                                                 adicionar_irmao($$->filho, criar_no("Id",$2)); 
                                                                                 adicionar_irmao($$->filho,criar_no("MethodParams",gen_token("",line_num, col_num)));}


FormalParams: Type ID CommaTypeIdRep {$$=criar_no("ParamDecl",gen_token("",line_num, col_num)); $$->filho=$1;adicionar_irmao($1, criar_no("Id",$2));adicionar_irmao($$,$3);}
            | STRING LSQ RSQ ID      {$$=criar_no("ParamDecl",gen_token("",line_num, col_num)); $$->filho=criar_no("StringArray",gen_token("",line_num, col_num)); adicionar_irmao($$->filho, criar_no("Id",$4));}

CommaTypeIdRep: COMMA Type ID CommaTypeIdRep {$$ = criar_no("ParamDecl",gen_token("",line_num, col_num)); $$->filho=$2; adicionar_irmao($2,criar_no("Id",$3)); adicionar_irmao($$,$4);}
              |                              {$$=NULL;}
              ;

MethodBody: LBRACE StatementVarRep RBRACE {$$=criar_no("MethodBody",gen_token("",line_num, col_num));$$->filho=$2;}

StatementVarRep: Statement StatementVarRep {if($1 != NULL){$$=$1; adicionar_irmao($$,$2);}else $$=$2;} //Verificamos se o Statement é NULL, se não for metemos como filho e adicionamos o Rep como filho, se não o filho fica o Rep
               | VarDecl StatementVarRep   {$$=$1; adicionar_irmao($$,$2);}
               |                           {$$=NULL;}
               ;

VarDecl: Type ID CommaIdRep SEMICOLON {$$=criar_no("VarDecl",gen_token("",line_num, col_num)); $$->filho=$1; 
                                                                  adicionar_irmao($1, criar_no("Id",$2)); 
                                                                  if($3!=NULL){ //Verificamos se existe mais do que uma declaração de variável, se sim cria-se um nó irmao do tipo VarDecl para cada variável
                                                                    tmp = $3; 
                                                                    while(tmp != NULL){ 
                                                                        no* tmp1 = criar_no("VarDecl",gen_token("",line_num, col_num));
                                                                        no* tmp2 = criar_no($1->tipo,$1->info); 
                                                                        tmp1->filho= tmp2; 
                                                                        adicionar_irmao(tmp2,criar_no("Id",tmp->info)); 
                                                                        adicionar_irmao($$,tmp1); tmp = tmp->irmao;
                                                                    } 
                                                                  } ;}

Statement: LBRACE StatementRep RBRACE                 {if( contador_irmaos($2)>1){$$=criar_no("Block",gen_token("",line_num, col_num));$$->filho=$2;}else{$$=$2;}} //Verificar se o statementRep tem mais 2 ou mais statements, de modo a criar o block
         | IF LPAR Expr RPAR Statement ELSE Statement {$$=criar_no("If",gen_token("",line_num, col_num));                                           
                                                        if($3 != NULL){  //Verificamos se o Expr não é NULL
                                                            $$->filho=$3; 
                                                            tmp = criar_no("Block",gen_token("",line_num, col_num));
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
                                                                    no* tmp_aux = criar_no("Block",gen_token("",line_num, col_num));
                                                                    adicionar_irmao(tmp, tmp_aux);
                                                                    tmp_aux->filho = $7;
                                                                }
                                                            }
                                                        }else{

                                                            tmp = criar_no("Block",gen_token("",line_num, col_num)); //A mesma lógica de cima, mas deste modo a ignorar o Expr
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
                                                                    no* tmp_aux = criar_no("Block",gen_token("",line_num, col_num));
                                                                    adicionar_irmao(tmp, tmp_aux);
                                                                    tmp_aux->filho = $7;
                                                                }
                                                            }   
                                                                
                                                                
                                                        }}

         | IF LPAR Expr RPAR Statement                {$$=criar_no("If",gen_token("",line_num, col_num)); //Mesma lógica aplicada ao outro IF
                                                        tmp = criar_no("Block",gen_token("",line_num, col_num));
                                                    
                                                        if($3!=NULL){ //Verificar se o Expr não é NULL, verificar o nr de statements no statement de modo a criar ou não o block
                                                            $$->filho=$3;
                                                            if($5 != NULL && contador_irmaos($5) < 2 ){
                                                                adicionar_irmao($3,$5); 
                                                                adicionar_irmao($5, tmp);}
                                                            else{
                                                                adicionar_irmao($3,tmp); 
                                                                tmp->filho = $5; 
                                                                adicionar_irmao(tmp,criar_no("Block",gen_token("",line_num, col_num)));
                                                                }
                                                        }else{

                                                            if($5 != NULL && contador_irmaos($5) < 2 ){
                                                                $$->filho = $5; 
                                                                adicionar_irmao($5, tmp);}
                                                            else{
                                                                $$->filho = tmp; 
                                                                tmp->filho = $5; 
                                                                adicionar_irmao(tmp,criar_no("Block",gen_token("",line_num, col_num)));
                                                            }
                                                        }}

         | WHILE LPAR Expr RPAR Statement             {$$=criar_no("While",gen_token("",line_num, col_num)); //Mesma lógica aplicada aos IFs
                                                        if($3!=NULL){  //Verificar se o Expr não é NULL, verificar o nr de statements no statement de modo a criar ou não o block
                                                            $$->filho=$3; 
                                                            if($5 != NULL && contador_irmaos($5) < 2){
                                                                adicionar_irmao($3,$5);}
                                                            else{
                                                                tmp = criar_no("Block",gen_token("",line_num, col_num)); 
                                                                adicionar_irmao($3,tmp); 
                                                                tmp->filho = $5;} 
                                                        }
                                                        else{
                                                            if($5 != NULL && contador_irmaos($5) < 2){
                                                                $$->filho=$5;}
                                                            else{
                                                                tmp = criar_no("Block",gen_token("",line_num, col_num)); 
                                                                $$->filho = tmp; 
                                                                tmp->filho = $5;} 
                                                        } }
         | RETURN Expr SEMICOLON                      {$$=criar_no("Return",gen_token("",line_num, col_num)); $$->filho=$2;}
         | RETURN SEMICOLON                           {$$=criar_no("Return",gen_token("",line_num, col_num));}
         | PRINT LPAR Expr RPAR SEMICOLON             {$$=criar_no("Print",$1);$$->filho=$3;}
         | PRINT LPAR STRLIT RPAR SEMICOLON           {$$=criar_no("Print",$1);$$->filho=criar_no("StrLit",$3);}
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

MethodInvocation: ID LPAR RPAR                   {$$=criar_no("Call",gen_token("",line_num, col_num)); $$->filho = criar_no("Id",$1);}

                | ID LPAR Expr CommaExprRep RPAR {$$=criar_no("Call",gen_token("",line_num, col_num)); $$->filho = criar_no("Id",$1); //Verificar se o Expr não é NULL para adicionar os irmãos
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


Assignment: ID ASSIGN Expr {$$=criar_no("Assign",$2);$$->filho=criar_no("Id",$1); adicionar_irmao($$->filho,$3);}

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR {$$=criar_no("ParseArgs",$1); $$->filho=criar_no("Id",$3); adicionar_irmao($$->filho,$5);}
        |  PARSEINT LPAR error RPAR           {$$=NULL;flag_tree=0;}


Expr: ExprOp                {$$=$1;}//PARA NÃO SE PODER DAR DOIS ASSIGNS SEGUIDOS!!
    | Assignment            {$$=$1;}


ExprOp: LPAR Expr RPAR          {$$=$2;}
    | MethodInvocation          {$$=$1;}
    | ParseArgs                 {$$=$1;}
    | ID                        {$$=criar_no("Id",$1);}
    | ID DOTLENGTH              {$$=criar_no("Length",$2); $$->filho = criar_no("Id",$1);}
    | INTLIT                    {$$=criar_no("DecLit",$1);}
    | REALLIT                   {$$=criar_no("RealLit",$1);}
    | BOOLLIT                   {$$=criar_no("BoolLit",$1);}
    | MINUS ExprOp %prec NOT    {;$$=criar_no("Minus",$1); $$->filho=$2;} // DAR A MESMA PRECEDENCIA AO MINUS QUE O NOT, POIS NESTE CASO O MINUS IGUALA-SE AO NOT
    | NOT ExprOp                {;$$=criar_no("Not",$1); $$->filho=$2;}
    | PLUS ExprOp %prec NOT     {;$$=criar_no("Plus",$1); $$->filho=$2;} // DAR A MESMA PRECEDENCIA AO MINUS QUE O NOT, POIS NESTE CASO O MINUS IGUALA-SE AO NOT
    | ExprOp PLUS ExprOp        {$$=criar_no("Add",$2); $$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp MINUS ExprOp       {$$=criar_no("Sub",$2);$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp STAR ExprOp        {$$=criar_no("Mul",$2);$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp DIV ExprOp         {$$=criar_no("Div",$2);$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp MOD ExprOp         {$$=criar_no("Mod",$2);$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp AND ExprOp         {$$=criar_no("And",$2);$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp OR ExprOp          {$$=criar_no("Or",$2);$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp XOR ExprOp         {$$=criar_no("Xor",gen_token("",line_num, col_num));$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp LSHIFT ExprOp      {$$=criar_no("Lshift",$2);$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp RSHIFT ExprOp      {$$=criar_no("Rshift",$2);$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp EQ ExprOp          {$$=criar_no("Eq",$2);$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp GE ExprOp          {$$=criar_no("Ge",$2);$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp GT ExprOp          {$$=criar_no("Gt",$2);$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp LE ExprOp          {$$=criar_no("Le",$2);$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp LT ExprOp          {$$=criar_no("Lt",$2);$$->filho=$1; adicionar_irmao($1, $3);}
    | ExprOp NE ExprOp          {$$=criar_no("Ne",$2);$$->filho=$1; adicionar_irmao($1, $3);}
    | LPAR error RPAR           {$$=NULL;flag_tree=0;}

%%
