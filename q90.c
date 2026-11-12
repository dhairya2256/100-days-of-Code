#include <stdio.h>

enum Gender {
    MALE,
    FEMALE,
    OTHER
};

struct Person {
    const char *name;
    enum Gender gender;
};

int main(void) {
    const struct Person person = {"Alex", OTHER};

    printf("%s's gender: ", person.name);
    switch (person.gender) {
        case MALE:
            printf("Male\n");
            break;
        case FEMALE:
            printf("Female\n");
            break;
        case OTHER:
            printf("Other\n");
            break;
    }

    return 0;
}