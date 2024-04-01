
//Write a program to take C program as input and identify all types comment line inside the program.  After identifying all types of comment line it’s needs to be written back to a separate file.


//Titu Ray Choudhury
//21UCS020  Sec-A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[MAX_LINE_LENGTH], outputFileName[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int inComment = 0;

    printf("Enter the input C file name: ");
    fgets(inputFileName, sizeof(inputFileName), stdin);
    inputFileName[strcspn(inputFileName, "\n")] = '\0'; // Remove trailing newline
    printf("Enter the output file name: ");
    fgets(outputFileName, sizeof(outputFileName), stdin);
    outputFileName[strcspn(outputFileName, "\n")] = '\0'; // Remove trailing newline

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error: Unable to open output file.\n");
        fclose(inputFile);
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        // Check for single-line comments
        if (strstr(line, "//") != NULL) {
            fprintf(outputFile, "%s", line);
        }
        // Check for multi-line comments
        else if (strstr(line, "/*") != NULL) {
            fprintf(outputFile, "%s", line);
            inComment = 1;
        } else if (strstr(line, "*/") != NULL) {
            fprintf(outputFile, "%s", line);
            inComment = 0;
        } else if (inComment) {
            fprintf(outputFile, "%s", line);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Comments extracted and written to %s\n", outputFileName);

    return 0;
}
