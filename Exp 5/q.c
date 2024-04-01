//Write a C program to simulate lexical analyzer for validating operators.

//Titu Ray choudhury
//21UCS020  Sec - A     6th Sem



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isOperator(char ch) {
    switch (ch) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '=':
        case '>':
        case '<':
        case '&':
        case '|':
        case '^':
        case '!':
        case '~':
            return 1;
        default:
            return 0;
    }
}

int main() {
    char input[100];
    int i = 0;

    printf("Enter the expression: ");
    fgets(input, sizeof(input), stdin);

    printf("Operators in the expression: ");

    while (input[i] != '\0') {
        if (isOperator(input[i])) {
            printf("%c ", input[i]);
        }
        i++;
    }

    printf("\n");

    return 0;
}
