#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include <errno.h>
#pragma warning (disable:4996)

int stack[10000];
//rear = 삽입이 일어나는 부분
//front = 삭제가 일어나는 부분
int front = 0, rear = -1;


//EMPTY
//비어있는지 확인하는 부분
int IsEmpty() {
	if (front > rear) return 1;	//비었음
	else return 0;	//안 비었음
}





//PUSH
void push(int value) {
		stack[++rear] = value;
}

//POP
void pop() {
	if (IsEmpty() == 1) {	//비었다면..
		printf("%d\n", -1);
	}
	else {
		printf("%d\n", stack[front]);
		stack[front++];
	}
}

//FRONT
void fronts() {
	if (IsEmpty() == 1) {	//비었다면..
		printf("%d\n", -1);
	}
	else printf("%d\n", stack[front]);
}

//BACK
void backs() {
	if (IsEmpty() == 1) {	//비었다면..
		printf("%d\n", -1);
	}
	else printf("%d\n", stack[rear]);
}

//SIZE

void size() {
	printf("%d\n", rear - front + 1);
}

int main() {
	
	int ActNum;//명령의 입력을 받는 갯수
	char ActCh[6];



	scanf("%d", &ActNum);	
	int nums = 0;

	for (int i = 0; i < ActNum; i++) {
		//"%[^\n]s"
		scanf("%s", ActCh);

		//push X: 정수 X를 큐에 넣는 연산이다.
		if (ActCh[0] == 'p' && ActCh[1] == 'u' && ActCh[2] == 's' && ActCh[3] == 'h') {
			//nums = atoi(ActCh + 5);

			scanf("%d", &nums);
			push(nums);
		}


		//pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		if (ActCh[0] == 'p' && ActCh[1] == 'o' && ActCh[2] == 'p') {
			pop();
		}

		//size: 큐에 들어있는 정수의 개수를 출력한다.
		if (ActCh[0] == 's' && ActCh[1] == 'i' && ActCh[2] == 'z' && ActCh[3] == 'e') {
			size();
		}

		//empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
		if (ActCh[0] == 'e' && ActCh[1] == 'm' && ActCh[2] == 'p' && ActCh[3] == 't' && ActCh[4] == 'y') {
			int em = IsEmpty();
			printf("%d\n", em);
		}

		/*
		//top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		if (ActCh[0] == 't' && ActCh[1] == 'o' && ActCh[2] == 'p') {
			tops();
		}
		*/

		//front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		if (ActCh[0] == 'f' && ActCh[1] == 'r' && ActCh[2] == 'o' && ActCh[3] == 'n' && ActCh[4] == 't') {
			fronts();
		}

		//back: 큐의 가장 뒤에 있는 정수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
		if (ActCh[0] == 'b' && ActCh[1] == 'a' && ActCh[2] == 'c' && ActCh[3] == 'k') {
			backs();
		}

	}

	getchar();
	return 0;
}
