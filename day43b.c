#include <stdio.h>

int main() {
    char str[100];
    int i = 0, j, isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    while (str[j = i] != '\0') {
        i++;
    }

    for (int left = 0, right = i - 1; left < right; left++, right--) {
        if (str[left] != str[right]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
