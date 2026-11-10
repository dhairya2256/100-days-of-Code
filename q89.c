#include <stdio.h>

enum ResultCode {
    RESULT_OK = 200,
    RESULT_NOT_FOUND = 404,
    RESULT_ERROR = 500
};

int main(void) {
    printf("RESULT_OK = %d\n", (int)RESULT_OK);
    printf("RESULT_NOT_FOUND = %d\n", (int)RESULT_NOT_FOUND);
    printf("RESULT_ERROR = %d\n", (int)RESULT_ERROR);

    return 0;
}