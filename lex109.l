%{
#include<stdio.h>
%}

%%
"if"|"else"|"while"|"do"|"break"|"continue"|"case"|"sizeof"|"typedef"|"switch"|"return"|"int"|"char"|"double"|"float"|"long"|"short"|"string"|"void"|"static"|"struct"|"goto" 	{printf("Keyword ");}
[*][_a-zA-Z][a-zA-Z0-9]* 	{printf("Pointer ");}
[_a-zA-Z][a-zA-Z0-9]*("[")[0-9]*("]") 	{printf("Array ");}
[_a-zA-Z][a-zA-Z0-9]* 	{printf("Identifier ");}
("\"")[a-zA-Z0-9]*("\"") 	{printf("String ");}
[/][/].* 	{printf("Comment ");}
[0-9]* 	{printf("Constant ");}
[0-9]*"."[0-9]+ 	{printf("Constant ");} 
[+|-][0-9]+ 	{printf("Constant ");}
"@"|"*"|";"|"'"|","|"%"|"$"|"#"|"("|")"|"{"|"}"|"&" 	{printf("SpecialCharacter ");}
"+"|"-"|"*"|"/"|"!"|"|"|"^"|"=="|"="|"<"|">" 	{printf("Operator ");}
%%

int yywrap()
{
return 0;
}
int main()
{
printf("Enter input: \n");
yylex();
return 0;
}
