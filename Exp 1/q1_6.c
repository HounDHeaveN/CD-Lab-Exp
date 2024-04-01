// // Write a C program takes two text files “stop_words.txt”, and “story.txt”.
//  It then removes all the stop word occurrences in the “story.txt” file by matching with “stop_words.txt” . 
//  After removing all stop words create a file called “story_without_stopwords.txt”, which will contains sentences without any stop word.



//Anamika Debnath
//21UCS029 
//6th Sem , Sec - A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1000

int isStopWord(const char *word, FILE *stopWordsFile) {                           
    char stopWord[MAX_WORD_LEN];                                                  

    rewind(stopWordsFile); 
    while (fgets(stopWord, MAX_WORD_LEN, stopWordsFile) != NULL) {
        stopWord[strcspn(stopWord, "\n")] = '\0';
        if (strcmp(stopWord, word) == 0) {
            return 1; 
        }
    }
    return 0; 
}

void removeStopWords(char *sentence, FILE *stopWordsFile) {
    char *token;
    const char delimiters[] = " \t\n.,;:!?()\"";

    token = strtok(sentence, delimiters);

    while (token != NULL) {
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }
        if (!isStopWord(token, stopWordsFile)) {
            printf("%s ", token); 
        }
        token = strtok(NULL, delimiters);
    }
}

int main() {
    FILE *stopWordsFile, *storyFile, *outputFile;
    char stopWord[MAX_WORD_LEN];
    char sentence[MAX_LINE_LEN];

    stopWordsFile = fopen("stop_words.txt", "r");
    if (stopWordsFile == NULL) {
        printf("Error: Unable to open stop_words.txt\n");
        return 1;
    }

    storyFile = fopen("story.txt", "r");
    if (storyFile == NULL) {
        printf("Error: Unable to open story.txt\n");
        fclose(stopWordsFile);
        return 1;
    }

    outputFile = fopen("story_without_stopwords.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Unable to create story_without_stopwords.txt\n");
        fclose(stopWordsFile);
        fclose(storyFile);
        return 1;
    }

    while (fgets(sentence, MAX_LINE_LEN, storyFile) != NULL) {
        sentence[strcspn(sentence, "\n")] = '\0';
        removeStopWords(sentence, stopWordsFile);
        fprintf(outputFile, "%s\n", sentence);
    }

    printf("Stop words removed successfully from story.txt\n");

    fclose(stopWordsFile);
    fclose(storyFile);
    fclose(outputFile);

}