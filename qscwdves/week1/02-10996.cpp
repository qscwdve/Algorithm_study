#include <stdio.h>
int main() {
	int num, end;
	scanf("%d", &num);
	if (num % 2 == 0) end = num / 2;
	else end = num / 2 + 1;
	for (int i = 1; i <= num*2; i++) {
		if (i % 2 == 0) {
			printf(" ");
			for (int k = 0; k < num / 2; k++) {
				printf("* ");
			}
		}
		else {
			for (int k = 0; k < end; k++) {
				printf("* ");
			}
		}
		printf("\n");
	}
	return 0;
}
