#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)


int stack[100000];
int top = -1;
int re = 0;
int count = 1;

char res[200000];	//'+'와 '-'를 저장할 부분
int resTop = 0;

int check = 1;

//PUSH
void push(int value) {
	stack[++top] = value;
	res[resTop++] = '+';
	re++;
}

//POP
void pop() {

	stack[top--];
	res[resTop++] = '-';

}





int main()
{
	int n;	//처음에 입력받는 명령어 수
	int k;	//입력한 수만큼 쌓아올리고 끝에꺼 빼냄.
	scanf("%d", &n);





	for (int i = 1; i < n + 1; i++) {	//입력받은 명렁어 수 만큼 실행
		scanf("%d", &k);

		for (int p = re; p < k; p++) {
			push(count);
			count++;
		}
		if (stack[top] == k) {
			pop();
		}else {
			check = 0;
		}
	}


	if (check != 0) {
		for (int j = 0; j < resTop; j++) {
			printf("%c\n", res[j]);
		}
	}
	else {
		printf("NO\n");
	}






	return 0;
}
