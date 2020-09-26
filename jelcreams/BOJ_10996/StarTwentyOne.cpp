#include <iostream>
#include <cstdio>
#pragma warning (disable:4996)

//별을 규칙성에 맞게 찍어주는 함수
void printStar(int temp) {
	int max = temp * 2;
	int t = 0;
	int check = 0;
	for (int i = 0; i < max; i++) {
		t = 0;
		while (t < temp) {
			if (i % 2 == 0) {
				check = 0;
			}
			else {
				check = 1;
			}
			printf("%c", (t%2) == check ? '*' : ' ');
			if ((t + 1) % temp == 0)printf("\n");
			t++;
		}
	}
}

int main() {
	int temp;
	scanf("%d", &temp);
	printStar(temp);
	return 0;
}
