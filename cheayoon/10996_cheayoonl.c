#include<stdio.h>
#pragma warning (disable:4996)



int main() {

	//숫자 받음
	int num;
	scanf("%d", &num);	// 1 ~ 100 사이의 수.
	
	int a = 1;
	int b = 0;

	for (int i = 0; i < num; i++) {
		// 내부 묶음
		for (int j = 0; j < num ; j++) {	// num에 따른 *의 갯수..
			if (j % 2 == 0) {
				printf("*");
			}
			if (j % 2 == 1) {
				printf(" ");
			}
		}
		printf("\n");
		for (int h = 0; h < num ; h++) {
			if (h % 2 == 0) {
				printf(" ");
			}
			if (h % 2 == 1) {
				printf("*");
			}
		}
		
		printf("\n");




		// 외부 묶음
		/*
		for (int j = 0; j < num; j++) {

		}
		*/
		
	}

	


	return 0;
}

