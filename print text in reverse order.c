#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char text[500]; // Adjust size as needed
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove trailing newline

    char *words[100]; // Adjust max number of words as needed
    int word_count = 0;

    char *token = strtok(text, " ");
    while (token != NULL) {
        words[word_count] = (char *)malloc(strlen(token) + 1); // Allocate memory
        strcpy(words[word_count], token);
        word_count++;
        token = strtok(NULL, " ");
    }

    for (int i = word_count - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if (i > 0) {
            printf(" ");
        }
        free(words[i]); // Free allocated memory
    }
    printf("\n");

    return 0;
}
