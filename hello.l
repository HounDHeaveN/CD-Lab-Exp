%{
	/*To print Hello World in Lex */
	#include<stdio.h>
   
%}
%%

%%
int yywrap()
{
return 1;
}
main()
{
printf(" This is the first program in Lex ( Flex) Windows\n");
printf(" **********  Hello World **********");
yylex();

}
