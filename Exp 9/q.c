//Write a C program to implement shift reduce parsing


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

// Reduce operation
void reduce() {
    int count = 0;
    char reduced = 0; // Flag to track if any reduction occurred
    while (stack[top] != '(') {
        pop();
        count++;
        reduced = 1; // Set flag indicating reduction occurred
    }
    pop();  // Pop '('
    if (reduced) { // Check if any reduction occurred
        push('E');  // Push the non-terminal
        printf("Reduced %d symbols\n", count);
    } else {
        printf("Invalid input\n");
        exit(1);
    }
}

int main() {
    char input[100];
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);

    int i = 0;
    while (input[i] != '\0' && input[i] != '\n') {
        if (input[i] == 'i') {
            push('i');  // Push terminal 'i'
            i++;
        } else if (input[i] == '+' || input[i] == '*' || input[i] == '(') {
            push(input[i]);
            i++;
        } else if (input[i] == ')') {
            reduce();
            i++;
        } else {
            printf("Invalid input\n");
            exit(1);
        }
    }

    // Check if the remaining symbols on the stack can be reduced to 'E'
    while (top > 0) {
        if ((stack[top] == 'i' && stack[top - 1] == '+') || 
            (stack[top] == 'i' && stack[top - 1] == '*')) {
            reduce();
        } else {
            printf("Invalid input\n");
            exit(1);
        }
    }

    // If the stack contains only 'E', parsing is successful
    if (top == 0 && stack[top] == 'E') {
        printf("Input string accepted\n");
    } else {
        printf("Input string rejected\n");
    }

    return 0;
}
