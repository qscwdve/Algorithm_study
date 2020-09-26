#include <iostream>
#include <cstdio>
#pragma warning (disable:4996)

int number;
// 소수 인지 판별하는 함수
int prime_number(int i) {
	if (i < 2) return 0;
	else {
		
		for (int j = i - 1; j != 1; j--) {
			if (i % j == 0) {
				return 0;
			}
		}
	}
	return 1;
}


int main() {
	int num, temp;
	scanf("%d", &num); //개수 입력
	for (int i = 0; i < num; i++) {
		scanf("%d", &temp); //판별할 수 입력
		number += prime_number(temp);
	}
	printf("%d\n", number); //소수 개수 출력
	

}
