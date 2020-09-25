#include <stdio.h>
#pragma warning (disable:4996)

int main() {
	int num, temp, check = 0, k;
	scanf("%d", &num);
	for (int i = 0; i < num;i++) {
		scanf("%d", &temp);
		if (temp == 1) continue;
		if (temp % 2 != 0) {
			for (k = 3; k < temp; k = k + 2) {
				if (temp % k == 0) break;
			}
			if (k >= temp) check++;   
		}
		else if (temp == 2) check++;
	}
	printf("%d", check);
}
