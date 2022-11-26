%{
    //  Eduardo Carneiro - 2020240332
    //  Ricardo Silva - 2020227184
    #include "ast.h"
    #include "y.tab.h"
    #include "symbol_table.h"   

    //ast
    extern no* raiz;

    //tabela simbolos
    tab_element* symtab;

    int line_num = 1;
    int col_num = 1;
    int start_comment = 1;
    int comment_line = 1;
    int comment_col = 1;
    int start_string = 1;
    int flag_tokens_lex = 0;
    int flag_tree=0;
    int flag_syntactic = 1;
    int flag_lexical=1;
    int flag_semantic=0;
%}

expoente [eE]["+"-]?[0-9]([0-9_]*[0-9])?
newline (\r?\n)|\r
reserved_words private|protected|abstract|extends|final|implements|interface|native|new|strictfp|synchronized|transient|volatile|break|case|continue|default|do|for|instanceof|switch|assert|catch|finally|throw|throws|try|import|package|byte|char|float|short|super|this|const|goto|enum|long
scape \\[fnrt\\\"]

%X _STRING COMMENT1 COMMENT2 STRING_ERROR

%%

"//"                {col_num += yyleng;BEGIN COMMENT1;}
<COMMENT1>{newline} {line_num++;col_num = 1;BEGIN 0;}
<COMMENT1>. {col_num+=yyleng;}

"/*"             {comment_line = line_num; comment_col = col_num + yyleng;BEGIN COMMENT2;}
<COMMENT2>"*/"             {line_num = comment_line; col_num = comment_col + yyleng;BEGIN 0;}
<COMMENT2>{newline}              {comment_line++;comment_col = 1;}
<COMMENT2><<EOF>>               {comment_col+=yyleng;printf("Line %d, col %d: unterminated comment\n",line_num,col_num);line_num = comment_line;col_num=comment_col;yyterminate();}
<COMMENT2>.               {comment_col+=yyleng;}



true|false  {if(flag_tokens_lex) printf("BOOLLIT(%s)\n",yytext);yylval.info = gen_token(yytext,line_num,col_num); col_num+=yyleng; return BOOLLIT;}

"&""&"  {if(flag_tokens_lex) printf("AND\n");yylval.info = gen_token("", line_num,col_num);col_num+=yyleng; return AND;}

"=" {if(flag_tokens_lex) printf("ASSIGN\n"); yylval.info = gen_token("", line_num,col_num); col_num+=yyleng; return ASSIGN;}

"*" {if(flag_tokens_lex) printf("STAR\n");yylval.info = gen_token("", line_num,col_num);col_num+=yyleng; return STAR;}

"," {if(flag_tokens_lex) printf("COMMA\n");col_num+=yyleng; return COMMA;}

"/" {if(flag_tokens_lex) printf("DIV\n");yylval.info = gen_token("", line_num,col_num);col_num+=yyleng; return DIV;}

"=""=" {if(flag_tokens_lex) printf("EQ\n"); yylval.info = gen_token("", line_num,col_num); col_num+=yyleng; return EQ;}

">=" {if(flag_tokens_lex) printf("GE\n"); yylval.info = gen_token("", line_num,col_num);col_num+=yyleng; return GE;}

">" {if(flag_tokens_lex) printf("GT\n"); yylval.info = gen_token("", line_num,col_num);col_num+=yyleng; return GT;}

"{" {if(flag_tokens_lex) printf("LBRACE\n");col_num+=yyleng; return LBRACE;}

"<=" {if(flag_tokens_lex) printf("LE\n");yylval.info = gen_token("", line_num,col_num); col_num+=yyleng; return LE;}

"(" {if(flag_tokens_lex) printf("LPAR\n");col_num+=yyleng; return LPAR;}

"[" {if(flag_tokens_lex) printf("LSQ\n");col_num+=yyleng; return LSQ;}

"<" {if(flag_tokens_lex) printf("LT\n"); yylval.info = gen_token("", line_num,col_num); col_num+=yyleng; return LT;}

- {if(flag_tokens_lex) printf("MINUS\n");yylval.info = gen_token("", line_num,col_num);col_num+=yyleng; return MINUS;}

"%" {if(flag_tokens_lex) printf("MOD\n"); yylval.info = gen_token("", line_num,col_num); col_num+=yyleng; return MOD;}

"!""=" {if(flag_tokens_lex) printf("NE\n"); yylval.info = gen_token("", line_num,col_num);col_num+=yyleng; return NE;}

"!" {if(flag_tokens_lex) printf("NOT\n"); yylval.info = gen_token("", line_num,col_num);col_num+=yyleng; return NOT;}

"|""|" {if(flag_tokens_lex) printf("OR\n"); yylval.info = gen_token("", line_num,col_num); col_num+=yyleng; return OR;}

"+" {if(flag_tokens_lex) printf("PLUS\n");yylval.info = gen_token("", line_num,col_num);col_num+=yyleng; return PLUS;}

"}" {if(flag_tokens_lex) printf("RBRACE\n");col_num+=yyleng; return RBRACE;}

")" {if(flag_tokens_lex) printf("RPAR\n");col_num+=yyleng; return RPAR;}

"]" {if(flag_tokens_lex) printf("RSQ\n");col_num+=yyleng; return RSQ;}

";" {if(flag_tokens_lex) printf("SEMICOLON\n");col_num+=yyleng; return SEMICOLON;}

-">" {if(flag_tokens_lex) printf("ARROW\n");col_num+=yyleng; return ARROW;}

"<""<" {if(flag_tokens_lex) printf("LSHIFT\n");col_num+=yyleng; return LSHIFT;}

">"">" {if(flag_tokens_lex) printf("RSHIFT\n");col_num+=yyleng; return RSHIFT;}

"^" {if(flag_tokens_lex) printf("XOR\n");col_num+=yyleng; return XOR;}

boolean {if(flag_tokens_lex) printf("BOOL\n");col_num+=yyleng; return BOOL;}

class {if(flag_tokens_lex) printf("CLASS\n");col_num+=yyleng; return CLASS;}

"."length {if(flag_tokens_lex) printf("DOTLENGTH\n");yylval.info = gen_token("", line_num,col_num); col_num+=yyleng; return DOTLENGTH;}

double {if(flag_tokens_lex) printf("DOUBLE\n");col_num+=yyleng; return DOUBLE;}

else {if(flag_tokens_lex) printf("ELSE\n");col_num+=yyleng; return ELSE;}

if {if(flag_tokens_lex) printf("IF\n");col_num+=yyleng; return IF;}

int {if(flag_tokens_lex) printf("INT\n");col_num+=yyleng; return INT;}

System"."out"."print {if(flag_tokens_lex) printf("PRINT\n"); yylval.info = gen_token("", line_num,col_num);col_num+=yyleng; return PRINT;}

Integer"."parseInt {if(flag_tokens_lex) printf("PARSEINT\n");col_num+=yyleng; return PARSEINT;}

public {if(flag_tokens_lex) printf("PUBLIC\n");col_num+=yyleng; return PUBLIC;}

return {if(flag_tokens_lex) printf("RETURN\n");col_num+=yyleng; return RETURN;}

static {if(flag_tokens_lex) printf("STATIC\n");col_num+=yyleng; return STATIC;}

String {if(flag_tokens_lex) printf("STRING\n");col_num+=yyleng; return STRING;}

void {if(flag_tokens_lex) printf("VOID\n");col_num+=yyleng; return VOID;}

while {if(flag_tokens_lex) printf("WHILE\n");col_num+=yyleng; return WHILE;}

"+""+"|--|null|Integer|System|{reserved_words} {if(flag_tokens_lex) printf("RESERVED(%s)\n",yytext);col_num+=yyleng; return RESERVED;}

([a-z]|[A-Z]|"_"|"$")([a-z]|[A-Z]|[0-9]|"_"|"$")*   {if(flag_tokens_lex) printf("ID(%s)\n",yytext); yylval.info = gen_token(yytext, line_num, col_num); col_num+=yyleng; return ID;}  

([0-9]([0-9_]*[0-9])?"."(([0-9]([0-9_]*[0-9])?{expoente}?)|{expoente})?)|((".")([0-9]([0-9_]*[0-9])?{expoente}?))|([0-9]([0-9_]*[0-9])?{expoente}) {if(flag_tokens_lex) printf("REALLIT(%s)\n",yytext); yylval.info = gen_token(yytext, line_num,col_num); col_num+=yyleng; return REALLIT;}

[0-9]|([1-9]([0-9"_"])*[0-9])  {if(flag_tokens_lex) printf("INTLIT(%s)\n",yytext); yylval.info = gen_token(yytext, line_num,col_num); col_num+=yyleng; return INTLIT;} 


\"    {col_num+=yyleng;yyless(0);BEGIN _STRING;}
<_STRING>\"{newline}   {printf("Line %d, col %d: unterminated string literal\n",line_num,col_num-1);line_num++;col_num=1;BEGIN 0;}
<_STRING>\"({scape}|[^\r\n\"\\])*\" {if(flag_tokens_lex) printf("STRLIT(\"%s)\n",yytext); yylval.info = gen_token(yytext, line_num,col_num); col_num+=yyleng;BEGIN 0;return STRLIT;}
<_STRING>\"[^\r\n\"]*\\[^f|n|r|t|\\|\"][^\r\n\"]*\" {start_string = col_num-1;yyless(1);BEGIN STRING_ERROR;}
<_STRING>\"[^\r\n\"]*{newline}? {start_string = col_num-1;yyless(1);BEGIN STRING_ERROR;}
<_STRING><<EOF>> {printf("Line %d, col %d: unterminated string literal\n",line_num,start_string);yyterminate();}


<STRING_ERROR>\"    {col_num+=yyleng;BEGIN 0;}
<STRING_ERROR>{newline}   {printf("Line %d, col %d: unterminated string literal\n",line_num,start_string);line_num++;col_num=1;BEGIN 0;}
<STRING_ERROR>{scape} {col_num+=yyleng;}
<STRING_ERROR>\\[^\n\r\\\"fnrt] {printf("Line %d, col %d: invalid escape sequence (%s)\n",line_num,col_num,yytext);col_num+=yyleng;}
<STRING_ERROR>\\ {printf("Line %d, col %d: invalid escape sequence (%s)\n",line_num,col_num,yytext);col_num+=yyleng;}
<STRING_ERROR><<EOF>>   {printf("Line %d, col %d: unterminated string literal\n",line_num,start_string);col_num=1;yyterminate();}
<STRING_ERROR>. {col_num+=yyleng;}

<<EOF>> {col_num+=yyleng;yyterminate();}


" "|"\t"|""|"\f"   {col_num+=yyleng;}

{newline}               {line_num++;col_num = 1;}

.   {printf("Line %d, col %d: illegal character (%s)\n",line_num,col_num,yytext);col_num+=yyleng;BEGIN 0;}


%%

void flag_checker(int argc, char *argv[]) {

    for (int i = 1; i < argc; i++) {
        if (argv[i][0]=='-'){
            if (!strcmp(argv[i], "-t")){ // árvore SÓ?
            flag_lexical=0;
                flag_tokens_lex=0;
                flag_tree = 1;
                flag_syntactic= 1;
                }
            else if(!strcmp(argv[i], "-e2")){ // só erro sintático e lexical
            flag_lexical=1;
                flag_tokens_lex=0;
                flag_tree=0;
                flag_syntactic=1;
            }
            else if(!strcmp(argv[i], "-l")){ // só lexical com tokens
            flag_lexical=1;
                flag_tokens_lex=1;
                flag_tree=0;
                flag_syntactic=0;
            }
            else if(!strcmp(argv[i], "-e1")){ // só lexical sem tokens
            flag_lexical=1;
                flag_tokens_lex=0;
                flag_tree=0;
                flag_syntactic=0;
            }
            else if(!strcmp(argv[i], "-s")){ // semantico
                 flag_lexical=0;
                flag_tokens_lex=0;
                flag_tree = 0;
                flag_syntactic= 1;
                flag_semantic=1;
            }
            else{
                printf("Undefined flag!\n");
                exit(1);
            }
        }
    }
}

int main(int argc, char *argv[])
{
flag_checker(argc,argv);

if(flag_lexical==1){
    while(yylex());
}

if (flag_syntactic){
    yyparse();
}
if (flag_tree){
    print_AST(raiz,0);
}
if(flag_semantic){
    symtab = create_element(raiz->filho->info->val,"","", 0);
    create_table(symtab,raiz);
    make_notations_ast(raiz,symtab,NULL);
    printSymbolTable(symtab);
    print_AST(raiz,0);
}

return 0;
}

int yywrap()
{
return 1;
}

void yyerror(const char *s) { 
    flag_tree = 0;

    if( !strcmp("\"String\"",yytext) || !strcmp("\"valid string\"",yytext) || !strcmp("\"strlit\"",yytext) || ( yytext[0] == '\"' && yytext[yyleng-1] == '\"') || !strcmp("",yytext) )
        printf ("Line %d, col %d: %s: %s\n", line_num, (int)(col_num-strlen(yytext))-1, s, yytext);
    else
        printf ("Line %d, col %d: %s: %s\n", line_num, (int)(col_num-strlen(yytext)), s, yytext);
\
}