#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)


int stack[50];
int top = -1;
int check = 0;



//EMPTY
//비어있는지 확인하는 부분
int IsEmpty() {
	if (top < 0) return 1;	//비었음
	else return 0;	//안 비었음
}

//PUSH
void push(char value) {
	stack[++top] = value;
}

//POP
void pop() {
	if (IsEmpty() == 1) {	//비었다면..
		check = 1;
	}
	else {
		stack[top--];
	}
}





int main()
{
	int t;	//처음에 입력받는 명령어 수
	char c[50];	//괄호 입력

	scanf("%d", &t);




	for (int i = 0; i < t; i++) {	//입력받은 명렁어 수 만큼 실행
		scanf("%s", &c);
		int j = 0;



		while (c[j] != NULL) {

			if (c[j] == '(') push('(');
			if (c[j] == ')') {
				pop();

				if (IsEmpty() == 1 && check == 1) {	//비었다면..
					printf("NO\n");
					check = 1;
					break;

				}

			}
			j++;
		}
		if (IsEmpty() == 1 && check == 0) {	//비었다면..
			printf("YES\n");	//'('과 ')'의 개수가 딱 맞아서 스택이 빈 것이므로
		}
		else if (IsEmpty() != 1 && check == 0) {
			printf("NO\n");
			while (1) {
				pop();
				if (IsEmpty() == 1) break;
			}
		}
		check = 0;

	}
	


	return 0;
}
