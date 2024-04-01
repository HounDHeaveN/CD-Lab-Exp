//Write a C Program to Scan and Count the number of characters, words, and lines in a file.

//Anamika Debnath
//21UCS029 
//6th Sem , Sec - A

#include <stdio.h>

#define MAX_FILENAME_SIZE 100
#define MAX_BUFFER_SIZE 1024

int main() {
    char filename[MAX_FILENAME_SIZE];                            
    FILE *file;                                                  
    char buffer[MAX_BUFFER_SIZE];
    int charCount = 0, wordCount = 0, lineCount = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file. Make sure the file exists.\n");
        return 1;
    }

        while (fgets(buffer, MAX_BUFFER_SIZE, file) != NULL) {
            lineCount++;

            for (int i = 0; buffer[i] != '\0'; i++) {
                charCount++;

                if (buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n') {
                    wordCount++;
                }
            }
    }

    fclose(file);

    printf("Character Count: %d\n", charCount);
    printf("Word Count: %d\n", wordCount);
    printf("Line Count: %d\n", lineCount);

}