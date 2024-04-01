//2.  Write a C program to read names and marks of n number of students from users and store them in a file.


///Anamika Debnath
//21UCS029  
//6th Sem , Sec - A


#include <stdio.h>

#define MAX_STUDENTS 100
#define MAX_NAME_SIZE 50
#define FILENAME "student_records.txt"

struct Student {
    char name[MAX_NAME_SIZE];                           
    int marks;                                          
};

int main() {
    FILE *file;
    struct Student students[MAX_STUDENTS];
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks);
    }

    file = fopen(FILENAME, "w");

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%s %d\n", students[i].name, students[i].marks);
    }

    fclose(file);

    printf("Student records written to %s.\n", FILENAME);

}