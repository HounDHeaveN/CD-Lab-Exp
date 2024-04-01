%{
#include <stdio.h>
%}

%%

[ \t]+   ; /* ignore multiple spaces and tabs */
\n       ; /* ignore newline characters */
.        { /* for any other character */
    putchar(yytext[0]);
}

%%

int yywrap() { return 1; }

int main(int argc, char *argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s inputfile outputfile\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        perror("Error opening input file");
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    yyin = inputFile;
    yyout = outputFile;

    yylex();

    fclose(inputFile);
    fclose(outputFile);

    printf("Spaces, Newline, and Tabs removed. Output saved to %s\n", argv[2]);

    return 0;
}
