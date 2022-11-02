%{
    //  Eduardo Carneiro - 2020240332
    //  Ricardo Silva - 2020

    int line_num = 1;
    int col_num = 1;
    int comment_line = 1;
    int comment_col = 1;
    int flag_tokens = 0;
    int start_string = 1;
%}

expoente [eE]["+"-]?[0-9]([0-9_]*[0-9])?
newline (\r?\n)|\r
reserved_words private|protected|abstract|extends|final|implements|interface|native|new|strictfp|synchronized|transient|volatile|break|case|continue|default|do|for|instanceof|switch|assert|catch|finally|throw|throws|try|import|package|byte|char|float|short|super|this|const|goto|enum|long
scape \\[fnrt\\\"]

%X STRING COMMENT1 COMMENT2 STRING_ERROR EOF_TEST

%%

"//"                {col_num += yyleng;BEGIN COMMENT1;}
<COMMENT1>{newline} {line_num++;col_num = 1;BEGIN 0;}
<COMMENT1>. {col_num+=yyleng;}

"/*"             {comment_line = line_num; comment_col = col_num + yyleng;BEGIN COMMENT2;}
<COMMENT2>"*/"             {line_num = comment_line; col_num = comment_col + yyleng;BEGIN 0;}
<COMMENT2>{newline}              {comment_line++;comment_col = 1;}
<COMMENT2><<EOF>>               {comment_col+=yyleng;printf("Line %d, col %d: unterminated comment\n",line_num,col_num);BEGIN EOF_TEST;}
<COMMENT2>.               {comment_col+=yyleng;}

<EOF_TEST><<EOF>>   {return 0;}
<EOF_TEST>.   {BEGIN 0;}


true|false  {if(flag_tokens) printf("BOOLLIT(%s)\n",yytext);col_num+=yyleng;}

"&""&"  {if(flag_tokens) printf("AND\n");col_num+=yyleng;}

"=" {if(flag_tokens) printf("ASSIGN\n");col_num+=yyleng;}

"*" {if(flag_tokens) printf("STAR\n");col_num+=yyleng;}

"," {if(flag_tokens) printf("COMMA\n");col_num+=yyleng;}

"/" {if(flag_tokens) printf("DIV\n");col_num+=yyleng;}

"=""=" {if(flag_tokens) printf("EQ\n");col_num+=yyleng;}

">=" {if(flag_tokens) printf("GE\n");col_num+=yyleng;}

">" {if(flag_tokens) printf("GT\n");col_num+=yyleng;}

"{" {if(flag_tokens) printf("LBRACE\n");col_num+=yyleng;}

"<=" {if(flag_tokens) printf("LE\n");col_num+=yyleng;}

"(" {if(flag_tokens) printf("LPAR\n");col_num+=yyleng;}

"[" {if(flag_tokens) printf("LSQ\n");col_num+=yyleng;}

"<" {if(flag_tokens) printf("LT\n");col_num+=yyleng;}

- {if(flag_tokens) printf("MINUS\n");col_num+=yyleng;}

"%" {if(flag_tokens) printf("MOD\n");col_num+=yyleng;}

"!""=" {if(flag_tokens) printf("NE\n");col_num+=yyleng;}

"!" {if(flag_tokens) printf("NOT\n");col_num+=yyleng;}

"|""|" {if(flag_tokens) printf("OR\n");col_num+=yyleng;}

"+" {if(flag_tokens) printf("PLUS\n");col_num+=yyleng;}

"}" {if(flag_tokens) printf("RBRACE\n");col_num+=yyleng;}

")" {if(flag_tokens) printf("RPAR\n");col_num+=yyleng;}

"]" {if(flag_tokens) printf("RSQ\n");col_num+=yyleng;}

";" {if(flag_tokens) printf("SEMICOLON\n");col_num+=yyleng;}

-">" {if(flag_tokens) printf("ARROW\n");col_num+=yyleng;}

"<""<" {if(flag_tokens) printf("LSHIFT\n");col_num+=yyleng;}

">"">" {if(flag_tokens) printf("RSHIFT\n");col_num+=yyleng;}

"^" {if(flag_tokens) printf("XOR\n");col_num+=yyleng;}

boolean {if(flag_tokens) printf("BOOL\n");col_num+=yyleng;}

class {if(flag_tokens) printf("CLASS\n");col_num+=yyleng;}

"."length {if(flag_tokens) printf("DOTLENGTH\n");col_num+=yyleng;}

double {if(flag_tokens) printf("DOUBLE\n");col_num+=yyleng;}

else {if(flag_tokens) printf("ELSE\n");col_num+=yyleng;}

if {if(flag_tokens) printf("IF\n");col_num+=yyleng;}

int {if(flag_tokens) printf("INT\n");col_num+=yyleng;}

System"."out"."print {if(flag_tokens) printf("PRINT\n");col_num+=yyleng;}

Integer"."parseInt {if(flag_tokens) printf("PARSEINT\n");col_num+=yyleng;}

public {if(flag_tokens) printf("PUBLIC\n");col_num+=yyleng;}

return {if(flag_tokens) printf("RETURN\n");col_num+=yyleng;}

static {if(flag_tokens) printf("STATIC\n");col_num+=yyleng;}

String {if(flag_tokens) printf("STRING\n");col_num+=yyleng;}

void {if(flag_tokens) printf("VOID\n");col_num+=yyleng;}

while {if(flag_tokens) printf("WHILE\n");col_num+=yyleng;}

"+""+"|--|null|Integer|System|{reserved_words} {if(flag_tokens) printf("RESERVED(%s)\n",yytext);col_num+=yyleng;}

([a-z]|[A-Z]|"_"|"$")([a-z]|[A-Z]|[0-9]|"_"|"$")*   {if(flag_tokens) printf("ID(%s)\n",yytext);col_num+=yyleng;}  

([0-9]([0-9_]*[0-9])?"."(([0-9]([0-9_]*[0-9])?{expoente}?)|{expoente})?)|((".")([0-9]([0-9_]*[0-9])?{expoente}?))|([0-9]([0-9_]*[0-9])?{expoente}) {if(flag_tokens) printf("REALLIT(%s)\n",yytext);col_num+=yyleng;}

[0-9]|([1-9]([0-9|"_"])*[0-9])  {if(flag_tokens) printf("INTLIT(%s)\n",yytext);col_num+=yyleng;} 



\"    {col_num+=yyleng;BEGIN STRING;}
<STRING>{newline}   {printf("Line %d, col %d: unterminated string literal\n",line_num,col_num-1);line_num++;col_num=1;BEGIN 0;}
<STRING>({scape}|[^\r\n\"\\])*\" {if(flag_tokens) printf("STRLIT(\"%s)\n",yytext);col_num+=yyleng;BEGIN 0;}
<STRING>[^\r\n\"]*\\[^f|n|r|t|\\|\"][^\r\n\"]*\" {start_string = col_num-1;yyless(0);BEGIN STRING_ERROR;}
<STRING>[^\r\n\"]*{newline}? {start_string = col_num-1;yyless(0);BEGIN STRING_ERROR;}
<STRING><<EOF>> {printf("Line %d, col %d: unterminated string literal\n",line_num,start_string);yyless(0);BEGIN EOF_TEST;}


<STRING_ERROR>\"    {col_num=+yyleng;BEGIN 0;}
<STRING_ERROR>{newline}   {printf("Line %d, col %d: unterminated string literal\n",line_num,start_string);line_num++;col_num=1;BEGIN 0;}
<STRING_ERROR>{scape} {col_num+=yyleng;}
<STRING_ERROR>\\[^\r\\\"fnrt] {printf("Line %d, col %d: invalid escape sequence (%s)\n",line_num,col_num,yytext);col_num+=yyleng;}
<STRING_ERROR>\\ {printf("Line %d, col %d: invalid escape sequence (%s)\n",line_num,col_num,yytext);col_num+=yyleng;}
<STRING_ERROR><<EOF>>   {printf("Line %d, col %d: unterminated string literal\n",line_num,start_string);col_num=1;BEGIN 0;}
<STRING_ERROR>. {col_num+=yyleng;}

" "|"\t"|""|"\f"   {col_num+=yyleng;}

{newline}               {line_num++;col_num = 1;}

.   {printf("Line %d, col %d: illegal character (%s)\n",line_num,col_num,yytext);col_num+=yyleng;BEGIN 0;}

%%

void flag_checker(int argc, char *argv[]) {

    for (int i = 1; i < argc; i++) {
        if (argv[i][0]=='-'){
            if (!strcmp(argv[i], "-l")){
                flag_tokens = 1;}
            else if (!strcmp(argv[i], "-e1")){
                flag_tokens = 0;}
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
yylex();
return 0;
}

int yywrap()
{
return 1;
}