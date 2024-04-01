//Write a C program to recognize strings under 'a*', 'a*b+', 'abb'


//Titu Ray Choudhury 
//21UCS020  Sec- A  6th Sem

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_a_star(char *str) {
    int i = 0;
    while (str[i] == 'a') {
        i++;
    }
    return i == strlen(str);
}

int is_a_b_plus(char *str) {
    int a_count = 0, b_count = 0, i = 0;

    while (str[i] == 'a') {
        a_count++;
        i++;
    }

    while (str[i] == 'b') {
        b_count++;
        i++;
    }

    return (a_count > 0 && b_count > 0 && i == strlen(str));
}

int is_abb(char *str) {
    if (strlen(str) != 3) {
        return 0;
    }

    return (str[0] == 'a' && str[1] == 'b' && str[2] == 'b');
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the trailing newline character
    str[strcspn(str, "\n")] = '\0';

    if (is_a_star(str)) {
        printf("'%s' is recognized under 'a*'\n", str);
    } else if (is_a_b_plus(str)) {
        printf("'%s' is recognized under 'a*b+'\n", str);
    } else if (is_abb(str)) {
        printf("'%s' is recognized under 'abb'\n", str);
    } else {
        printf("'%s' does not match any of the specified patterns.\n", str);
    }

    return 0;
}
