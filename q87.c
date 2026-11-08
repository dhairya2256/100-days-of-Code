#include <stdio.h>

enum UserRole {
    ADMIN = 1,
    USER,
    GUEST
};

int main(void) {
    int choice;

    printf("Select a role:\n");
    printf("%d. ADMIN\n", ADMIN);
    printf("%d. USER\n", USER);
    printf("%d. GUEST\n", GUEST);
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1) {
        fprintf(stderr, "Invalid choice. Enter 1, 2, or 3.\n");
        return 1;
    }

    switch ((enum UserRole)choice) {
        case ADMIN:
            printf("Welcome, administrator. You have full access.\n");
            break;
        case USER:
            printf("Welcome, user. You have standard access.\n");
            break;
        case GUEST:
            printf("Welcome, guest. You have limited access.\n");
            break;
        default:
            fprintf(stderr, "Invalid choice. Enter 1, 2, or 3.\n");
            return 1;
    }

    return 0;
}