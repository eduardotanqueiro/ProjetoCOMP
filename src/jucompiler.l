expoente [eE]["+""-"]?(([0-9])|([0-9][0-9|"_"]*[0-9]))+
%X ERRO COMMENT
%{
    int line_num = 1;
    int col_num = 1;
    int start_comment = 1;
%}

newline \r?\n

%%   

"/""/".*"\n"                {line_num++;};
"/""*".*             {start_comment = line_num; BEGIN COMMENT;}
<COMMENT>{newline}              {line_num++;col_num = 1;}
<COMMENT>"*""/"             {BEGIN 0;}
<COMMENT><<EOF>>               {printf("Line %d, col %d: unterminated comment\n",start_comment,col_num);BEGIN 0;}
<COMMENT>.               ;

true|false  {printf("BOOLLIT\n");}

"&""&"  {printf("AND\n");}

"=" {printf("ASSIGN\n");}

"*" {printf("STAR\n");}

"," {printf("COMMA\n");}

"/" {printf("DIV\n");}

"=""=" {printf("EQ\n");}

">=" {printf("GE\n");}

">" {printf("GT\n");}

"{" {printf("LBRACE\n");}

"<=" {printf("LE\n");}

"(" {printf("LPAR\n");}

"[" {printf("LSQ\n");}

"<" {printf("LT\n");}

"-" {printf("MINUS\n");}

"%" {printf("MOD\n");}

"!""=" {printf("NE\n");}

"!" {printf("NOT\n");}

"|""|" {printf("OR\n");}

"+" {printf("PLUS\n");}

"}" {printf("RBRACE\n");}

")" {printf("RPAR\n");}

"]" {printf("RSQ\n");}

";" {printf("SEMICOLON\n");}

"-"">" {printf("ARROW\n");}

"<""<" {printf("LSHIFT\n");}

">"">" {printf("RSHIFT\n");}

"^" {printf("XOR\n");}

boolean {printf("BOOL\n");}

"class" {printf("CLASS\n");}

"."length {printf("DOTLENGTH\n");}

double {printf("DOUBLE\n");}

else {printf("ELSE\n");}

if {printf("IF\n");}

int {printf("INT\n");}

System"."out"."print {printf("PRINT\n");}

Integer"."parseInt {printf("PARSEINT\n");}

public {printf("PUBLIC\n");}

return {printf("RETURN\n");}

static {printf("STATIC\n");}

String {printf("STRING\n");}

void {printf("VOID\n");}

while {printf("WHILE\n");}

"+""+"|"-""-"|"\\"0|Integer|System {printf("RESERVED\n");}

([a-z]|[A-Z]|"_"|"$")([a-z]|[A-Z]|[0-9]|"_"|"$")*   {printf("ID(%s)\n",yytext);}

[1-9](0|[0-9]+|"_")*[0-9]*  {printf("INTLIT\n");}

(([0-9])|([0-9][0-9|"_"]*[0-9]))"."(([0-9])|([0-9][0-9|"_"]*[0-9]))*{expoente}  {printf("REALLIT\n");}

[^("\r"|"\n"|"\"""\""|" ")]*|("\""["\f"|"\n"|"\r"|"\t"|"\\""\\"|"\\""\""]+"\"") {printf("STRLIT\n");}

" "|"\n"|"\t"|"/""/".*"\n"|"/""*".*"*""/"   ;

{newline}               {line_num++;col_num = 1;}

.               {BEGIN ERRO;}

#<ERRO>. 	            {printf("erro linha %d, illegal char %s\n",line_num,yytext);BEGIN 0;}
%%

int main()
{
yylex();
printf("\n");
//printf("%d",line_num);
return 0;
}

int yywrap()
{
return 1;
}