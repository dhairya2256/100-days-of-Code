#include <stdio.h>

enum Status {
    SUCCESS,
    FAILURE,
    TIMEOUT
};

int main(void) {
    for (enum Status status = SUCCESS; status <= TIMEOUT; status++) {
        switch (status) {
            case SUCCESS:
                printf("SUCCESS: The operation completed successfully.\n");
                break;
            case FAILURE:
                printf("FAILURE: The operation failed.\n");
                break;
            case TIMEOUT:
                printf("TIMEOUT: The operation timed out.\n");
                break;
        }
    }

    return 0;
}