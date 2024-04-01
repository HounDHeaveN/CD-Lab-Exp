%{
	/*To find whether given letter is a vowel or not*/
	#include<stdio.h>
    int vowel=0;
    int cons=0;
%}
%%
"a"|"e"|"i"|"o"|"u"|"A"|"E"|"I"|"O"|"U" {printf("It is an Vowel"); vowel++;}
[a-zA-z] {printf("It is a Consonant"); cons++;}
%%
int yywrap()
{
return 1;
}
int main()
{
printf(" Enter the Character :\n");
yylex();
printf(" Total Vowel=%d & Total Consonant= %d", vowel,cons);
return 0;
}
