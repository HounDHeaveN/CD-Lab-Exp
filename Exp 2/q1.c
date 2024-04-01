// Experiment 2- Design a lexical analyzer for given language and the lexical analyzer should ignore redundant spaces, tabs and new lines. It should also ignore comments. Although the syntax specification states that identifiers can be arbitrarily long, you may restrict the length to some reasonable value. Simulate the same in C language. After lexical analysis separate file for each type of tokens will be created.


//Titu Ray choudhury 
//21UCS020
//6th Sem   Sec A 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int isIdentifierChar(char ch) {
    return isalnum(ch) || ch == '_';
}
FILE* createTokenFile(const char* tokenType) {                                                           
    char fileName[50];                                                                                   
    sprintf(fileName, "%s.txt", tokenType);
    return fopen(fileName, "w");
}
void processInput(FILE* inputFile) {
    FILE *keywordsFile, *identifiersFile, *operatorsFile, *constantsFile;
    keywordsFile = createTokenFile("keywords");
    identifiersFile = createTokenFile("identifiers");
    operatorsFile = createTokenFile("operators");
    constantsFile = createTokenFile("constants");
    if (!keywordsFile || !identifiersFile || !operatorsFile || !constantsFile) {
        perror("Error creating token files");
        exit(EXIT_FAILURE);
    }
    int ch;
    char buffer[100];
    int bufferIndex = 0;
    while ((ch = fgetc(inputFile)) != EOF) {
        if (isspace(ch)) {
            continue;
        } else if (ch == '#') {
            while ((ch = fgetc(inputFile)) != '\n' && ch != EOF);
        } else if (isalpha(ch) || ch == '_') {
            buffer[bufferIndex++] = ch;
            while ((isalpha(ch = fgetc(inputFile)) || isdigit(ch) || ch == '_') && bufferIndex < sizeof(buffer) - 1) {
                buffer[bufferIndex++] = ch;
            }
            buffer[bufferIndex] = '\0';
            if (strcmp(buffer, "int") == 0 || strcmp(buffer, "float") == 0 || strcmp(buffer, "if") == 0) {
                fprintf(keywordsFile, "%s\n", buffer);
            } else {
                fprintf(identifiersFile, "%s\n", buffer);
            }
            bufferIndex = 0;
            ungetc(ch, inputFile); 
        } else if (isdigit(ch)) {
            buffer[bufferIndex++] = ch;
            while ((isdigit(ch = fgetc(inputFile)) || ch == '.') && bufferIndex < sizeof(buffer) - 1) {
                buffer[bufferIndex++] = ch;
            }
            buffer[bufferIndex] = '\0';
            fprintf(constantsFile, "%s\n", buffer);

            bufferIndex = 0;
            ungetc(ch, inputFile); // Put back the non-digit character
        } else {
            // Identify operators
            fprintf(operatorsFile, "%c\n", ch);
        }
    }

    // Close all files
    fclose(keywordsFile);
    fclose(identifiersFile);
    fclose(operatorsFile);
    fclose(constantsFile);
}

// Function to print the content of a file
void printFileContent(const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (!file) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

int main() {
    // Specify the input file
    FILE *inputFile = fopen("input.txt", "r");

    if (!inputFile) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // Process the input and create token files
    processInput(inputFile);

    fclose(inputFile);

    // Print the content of the generated token files
    printf("\nContent of generated token files:\n");
    printf("Keywords:\n");
    printFileContent("keywords.txt");

    printf("\nIdentifiers:\n");
    printFileContent("identifiers.txt");

    printf("\nOperators:\n");
    printFileContent("operators.txt");

    printf("\nConstants:\n");
    printFileContent("constants.txt");

    return EXIT_SUCCESS;
}