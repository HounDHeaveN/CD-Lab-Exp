#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE 100

// Stack definition
char stack[STACK_SIZE];
int top = -1;

// Push operation
void push(char item) {
    if (top >= STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    } else {
        stack[++top] = item;
    }
}

// Pop operation
char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        exit(1);
    } else {
        return stack[top--];
    }
}

int main() {
    char input[100];
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);

    int i = 0;
    while (input[i] != '\0' && input[i] != '\n') {
        if (input[i] == 'i' || input[i] == '+' || input[i] == '*') {
            push(input[i]);
            i++;
        } else {
            printf("Invalid input\n");
            exit(1);
        }
    }

    // Check if the symbols on the stack form a valid expression
    int operandCount = 0;
    int operatorCount = 0;
    while (top >= 0) {
        char symbol = pop();
        if (symbol == 'i') {
            operandCount++;
        } else if (symbol == '+' || symbol == '*') {
            operatorCount++;
        } else {
            printf("Invalid input\n");
            exit(1);
        }
    }

    // The expression is valid if there is one more operand than operators
    if (operandCount == operatorCount + 1) {
        printf("Input string accepted\n");
    } else {
        printf("Input string rejected\n");
    }

    return 0;
}
