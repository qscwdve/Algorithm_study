#include<stdio.h>
#pragma warning (disable:4996)

int process(int a);


int main() {
	int j = 0;	//소수면 카운트 해준다.
	int a;
	


	//숫자 받음, 갯수만큼 랜덤숫자 생성.
	int num;
	scanf("%d", &num);	//100이하 수

	//num갯수만큼 scanf를 또 받음
	for (int i = 0; i < num; i++) {
		scanf("%d", &a);	//1000이하 수
	
		//2가 아님, 
		//for문 으로 돌렸을 때 %로 했을 때 나머지가 0이 아니면 소수
	
		j += process(a);
		
		



	}
	printf("%d", j);



	


	return 0;
}

int process(int a) {

	int re;
	
	if (a == 1) return 0;
	if (a == 2) return 1;
	for (int count = a - 1; count > 1; count--) {
		re = a % count;
		if (re == 0) return 0;
	}
	

	


	return 1;
}
