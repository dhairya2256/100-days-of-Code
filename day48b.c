#include <stdio.h>
#include <string.h>

void reverseWord(char *start, char *end) {
    char temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reverseEachWord(char *sentence) {
    char *start = sentence;
    char *end = sentence;

    while (*end != '\0') {
        if (*end == ' ') {
            reverseWord(start, end - 1);
            start = end + 1;
        }
        end++;
    }

    reverseWord(start, end - 1);
}

int main() {
    char sentence[200];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    reverseEachWord(sentence);

    printf("Modified sentence: %s\n", sentence);
    return 0;
}
