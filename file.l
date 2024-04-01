%{
    /*Lex program to take input from file and 
    remove multiple spaces, newline and tab
     and write output in a separate file*/
	#include<stdio.h>
	#include<file.h>
%}
  

%%
[ \n\t]+ {fprintf(yyout, "");}
     { fprintf(yyout, "%s", yytext); }
%%
  
int yywrap()
{
return 1;
}
  
int main()
{
  
    /* yyin and yyout as pointer
    of File type */
    extern FILE *yyin, *yyout;
  
    /* yyin points to the file input.txt
    and opens it in read mode*/
    yyin = fopen("Input.txt", "r");
  
    /* yyout points to the file output.txt
    and opens it in write mode*/
    yyout = fopen("Output.txt", "w");
    yylex();
    return 0;
}

