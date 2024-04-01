%{
#include <stdio.h>
int yylex();
void yyerror(const char *s);
%}

%token ZERO ONE
%token START END

%%

start : START expr END   { printf("Valid string\n"); }
      ;

expr : ZERO expr ZERO
     | ZERO expr ONE
     | ONE expr ZERO
     | ONE expr ONE
     | ZERO
     | ONE
     ;

%%

int main() {
    printf("Enter a string: ");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("Invalid string\n");
}
