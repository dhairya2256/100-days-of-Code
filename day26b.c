#include <stdio.h>

int main() {
	int group, line, stars;

	for (group = 1; group <= 4; group++) {
		if (group == 1 || group == 4) {
			stars = 1;
		} else if (group == 2) {
			stars = 4;
		} else {
			stars = 3;
		}

		for (line = 1; line <= stars; line++) {
			printf("*\n");
		}

		if (group < 4) {
			printf("\n");
		}
	}

	return 0;
}
