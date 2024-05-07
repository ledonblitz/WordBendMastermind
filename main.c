#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define LIMIT_WORDS 5000
#define LIMIT_WORD_SIZE 50

typedef struct {
    char content[LIMIT_WORD_SIZE];
} DictionaryWord;

bool unique(const char* s);
void printWordPattern(const char* reference, const char* known, char* representation);

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Syntax: %s <dictionary_path> <word_size> <allowed_attempts>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    srand((unsigned int)time(NULL));

    DictionaryWord wordArray[LIMIT_WORDS];
    int totalWords = 0;
    char alreadyGuessed[LIMIT_WORD_SIZE] = {0};
    char currentRepresentation[LIMIT_WORD_SIZE] = {0};
    char chosenWord[LIMIT_WORD_SIZE] = {0};

    int wordLen = atoi(argv[2]);
    int remainingAttempts = atoi(argv[3]);

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Failed to open the specified dictionary");
        exit(EXIT_FAILURE);
    }

    char tempWord[LIMIT_WORD_SIZE];
    while (fscanf(fp, "%49s", tempWord) != EOF && totalWords < LIMIT_WORDS) {
        if (strlen(tempWord) == wordLen && unique(tempWord)) {
            strcpy(wordArray[totalWords++].content, tempWord);
        }
    }
    fclose(fp);

    strcpy(chosenWord, wordArray[rand() % totalWords].content);

    while (remainingAttempts > 0) {
        printWordPattern(chosenWord, alreadyGuessed, currentRepresentation);
        printf("%s Guesses: %d, Enter letter: ", currentRepresentation, remainingAttempts);

        char guessedChar;
        scanf(" %c", &guessedChar);
        guessedChar = tolower(guessedChar);

        if (!isalpha(guessedChar)) {
            printf("Enter a valid letter, please.\n");
            continue;
        }

        if (strchr(alreadyGuessed, guessedChar)) {
            printf("You've already guessed that letter! Previous letters: %s\n", alreadyGuessed);
            continue;
        }

        strncat(alreadyGuessed, &guessedChar, 1);
        if (!strchr(chosenWord, guessedChar)) remainingAttempts--;

        if (strcmp(currentRepresentation, chosenWord) == 0) {
            printf("Congratulations! You've correctly guessed: %s.\n", chosenWord);
            return 0;
        }
    }

    printf("Sorry, you didn't guess it! The word was: %s.\n", chosenWord);
    return 0;
}

bool unique(const char* s) {
    int alphabet[26] = {0};

    for (int i = 0; s[i]; i++) {
        int position = tolower(s[i]) - 'a';
        if (position >= 0 && position < 26) {
            if (alphabet[position]) return false;
            alphabet[position] = 1;
        }
    }
    return true;
}

void printWordPattern(const char* reference, const char* known, char* representation) {
    while (*reference) {
        *representation = (strchr(known, *reference)) ? *reference : '_';
        reference++;
        representation++;
    }
    *representation = '\0';
}
