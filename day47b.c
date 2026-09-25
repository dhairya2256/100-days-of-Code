#include <stdio.h>
#include <string.h>

int main() {
    char sentence[200], longest[100];
    int i, j = 0, maxLen = 0, currLen = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    for (i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] != ' ' && sentence[i] != '\t') {
            currLen++;
            if (currLen > maxLen) {
                maxLen = currLen;
                j = i - currLen + 1;
            }
        } else {
            currLen = 0;
        }
    }

    if (maxLen == 0) {
        printf("No word found.\n");
        return 0;
    }

    for (i = 0; i < maxLen; i++) {
        longest[i] = sentence[j + i];
    }
    longest[maxLen] = '\0';

    printf("Longest word: %s\n", longest);
    return 0;
}
