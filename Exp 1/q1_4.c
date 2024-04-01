//Write a C Program copy content from one file to another.


///Anamika Debnath
//21UCS029 
//6th Sem , Sec - A

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destinationFile;                       
    char sourceFileName[100], destinationFileName[100];     
    char ch;

    printf("Enter the source file name: ");
    scanf("%s", sourceFileName);

    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Error: Unable to open source file %s.\n", sourceFileName);
        exit(EXIT_FAILURE);
    }

    printf("Enter the destination file name: ");
    scanf("%s", destinationFileName);

    destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Error: Unable to create destination file %s.\n", destinationFileName);
        fclose(sourceFile);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    printf("File copied successfully from %s to %s.\n", sourceFileName, destinationFileName);

    fclose(sourceFile);
    fclose(destinationFile);

}