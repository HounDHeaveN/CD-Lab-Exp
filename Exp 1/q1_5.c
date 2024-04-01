//Write a C program to detect tokens in a C program.


//Anamika Debnath
//21UCS029  
//6th Sem , Sec - A

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char *token) {
    char keywords[32][10] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",                           
        "double", "else", "enum", "extern", "float", "for", "goto", "if",                                 
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };
    int i;
    for (i = 0; i < 32; ++i) {
        if (strcmp(keywords[i], token) == 0) {
            return 1;
        }
    }
    return 0;
}

void detectTokens(FILE *file) {
    int c;
    char token[100];
    int tokenIndex = 0;

    while ((c = fgetc(file)) != EOF) {
        if (isalnum(c) || c == '_') {
            token[tokenIndex++] = c;
        } else if (tokenIndex > 0) {
            token[tokenIndex] = '\0';
            if (isKeyword(token)) {
                printf("Keyword: %s\n", token);
            } else {
                printf("Identifier: %s\n", token);
            }
            tokenIndex = 0;
        }
    }
}

int main() {
    FILE *file;
    char filename[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s.\n", filename);
        return 1;
    }

    detectTokens(file);

    fclose(file);

}