//3.  Write a C Program Delete a specific Line from a Text File.

//Anamika Debnath
//21UCS029   
//6th Sem , Sec - A


#include <stdio.h>
#include <stdlib.h>

void deleteLine(const char *filename, int lineToDelete) {
    FILE *originalFile, *tempFile;
    char buffer[1000];
    int currentLine = 1;                     

    originalFile = fopen(filename, "r");
    if (originalFile == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file\n");
        exit(1);
    }
    while (fgets(buffer, sizeof(buffer), originalFile) != NULL) {
        if (currentLine != lineToDelete) {
            fputs(buffer, tempFile);
        }
        currentLine++;
    }
    fclose(originalFile);
    fclose(tempFile);
    remove(filename);
    rename("temp.txt", filename);
    printf("Line %d deleted successfully from %s\n", lineToDelete, filename);
}

int main() {
    const char *filename = "sample.txt";
    int lineToDelete = 3; 
    deleteLine(filename, lineToDelete);

}