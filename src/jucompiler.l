%{
    int line_num = 1;
    int col_num = 1;
    int start_comment = 1;
%}

expoente [eE]["+""-"]?(([0-9])|([0-9][0-9|"_"]*[0-9]))+
newline \r?\n
reserved_words private|protected|abstract|extends|final|implements|interface|native|new|strictfp|synchronized|transient|volatile|break|case|continue|default|do|for|instanceof|switch|assert|catch|finally|throw|throws|try|import|package|byte|char|float|short|super|this|const|goto
scape \[f|n|r|t|\|"\""]

%X ERRO COMMENT

%%   

"/""/".*"\n"                {line_num++;col_num+=yyleng;};
#"/""*".*             {start_comment = line_num; BEGIN COMMENT;col_num+=yyleng;}
"/""*"             {start_comment = line_num; BEGIN COMMENT;col_num+=yyleng;}
<COMMENT>{newline}              {line_num++;col_num = 1;}
<COMMENT>"*""/"             {BEGIN 0;}
<COMMENT><<EOF>>               {printf("Line %d, col %d: unterminated comment\n",start_comment,col_num);BEGIN 0;}
<COMMENT>.               {col_num+=yyleng;}

true|false  {printf("BOOLLIT\n");col_num+=yyleng;}

"&""&"  {printf("AND\n");col_num+=yyleng;}

"=" {printf("ASSIGN\n");col_num+=yyleng;}

"*" {printf("STAR\n");col_num+=yyleng;}

"," {printf("COMMA\n");col_num+=yyleng;}

"/" {printf("DIV\n");col_num+=yyleng;}

"=""=" {printf("EQ\n");col_num+=yyleng;}

">=" {printf("GE\n");col_num+=yyleng;}

">" {printf("GT\n");col_num+=yyleng;}

"{" {printf("LBRACE\n");col_num+=yyleng;}

"<=" {printf("LE\n");col_num+=yyleng;}

"(" {printf("LPAR\n");col_num+=yyleng;}

"[" {printf("LSQ\n");col_num+=yyleng;}

"<" {printf("LT\n");col_num+=yyleng;}

"-" {printf("MINUS\n");col_num+=yyleng;}

"%" {printf("MOD\n");col_num+=yyleng;}

"!""=" {printf("NE\n");col_num+=yyleng;}

"!" {printf("NOT\n");col_num+=yyleng;}

"|""|" {printf("OR\n");col_num+=yyleng;}

"+" {printf("PLUS\n");col_num+=yyleng;}

"}" {printf("RBRACE\n");col_num+=yyleng;}

")" {printf("RPAR\n");col_num+=yyleng;}

"]" {printf("RSQ\n");col_num+=yyleng;}

";" {printf("SEMICOLON\n");col_num+=yyleng;}

"-"">" {printf("ARROW\n");col_num+=yyleng;}

"<""<" {printf("LSHIFT\n");col_num+=yyleng;}

">"">" {printf("RSHIFT\n");col_num+=yyleng;}

"^" {printf("XOR\n");col_num+=yyleng;}

boolean {printf("BOOL\n");col_num+=yyleng;}

class {printf("CLASS\n");col_num+=yyleng;}

"."length {printf("DOTLENGTH\n");col_num+=yyleng;}

double {printf("DOUBLE\n");col_num+=yyleng;}

else {printf("ELSE\n");col_num+=yyleng;}

if {printf("IF\n");col_num+=yyleng;}

int {printf("INT\n");col_num+=yyleng;}

System"."out"."print {printf("PRINT\n");col_num+=yyleng;}

Integer"."parseInt {printf("PARSEINT\n");col_num+=yyleng;}

public {printf("PUBLIC\n");col_num+=yyleng;}

return {printf("RETURN\n");col_num+=yyleng;}

static {printf("STATIC\n");col_num+=yyleng;}

String {printf("STRING\n");col_num+=yyleng;}

void {printf("VOID\n");col_num+=yyleng;}

while {printf("WHILE\n");col_num+=yyleng;}

"+""+"|"-""-"|null|Integer|System|reserved_words {printf("RESERVED\n");col_num+=yyleng;}

([a-z]|[A-Z]|"_"|"$")([a-z]|[A-Z]|[0-9]|"_"|"$")*   {printf("ID(%s)\n",yytext);}col_num+=yyleng;

0|([1-9](0|[0-9]+|"_")*[0-9]*)  {printf("INTLIT(%s)\n",yytext);col_num+=yyleng;}

(([0-9])|([0-9][0-9|"_"]*[0-9]))"."(([0-9])|([0-9][0-9|"_"]*[0-9]))*{expoente}  {printf("REALLIT\n");col_num+=yyleng;}

("\""[^("\r"|"\n"|"\"")]+"\"")|("\""["\f"|"\n"|"\r"|"\t"|"\\""\\"|"\\""\""]+"\"") {printf("STRLIT (%s)\n",yytext);col_num+=yyleng;}

" "|"\t"   {col_num+=yyleng;}

{newline}               {line_num++;col_num = 1;}

#.               {BEGIN ERRO;}

\[^(f|n|r|t|\|"\"")]    {printf("Line %d, col %d: invalid escape sequence (%s)\n",line_num,col_num,yytext);BEGIN 0;}

"\""[^("\"")]* {printf("Line %d, col %d: unterminated string literal\n",start_comment,col_num);BEGIN 0;}

.   {printf("Line %d, col %d: illegal character (%s)\n",line_num,col_num,yytext);BEGIN 0;}

#<ERRO>. 	            {printf("erro linha %d, illegal char %s\n",line_num,yytext);BEGIN 0;}
%%

int main()
{
yylex();
//printf("\n");
//printf("%d",line_num);
return 0;
}

int yywrap()
{
return 1;
}