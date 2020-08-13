#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include <errno.h>
#pragma warning (disable:4996)

int stack[10000];
//rear = 삽입이 일어나는 부분
//front = 삭제가 일어나는 부분
int front = 1000, rear = 1001;


//EMPTY
//비어있는지 확인하는 부분
int IsEmpty() {
	if (rear - front - 1 == 0) return 1;	//비었음
	else return 0;	//안 비었음
}





//push_front X
void push_front(int value) {
	stack[front--] = value;
}

//push_back X
void push_back(int value) {
	stack[rear++] = value;
}

//pop_front
void pop_front() {
	if (IsEmpty() == 1) {	//비었다면..
		printf("%d\n", -1);
	}
	else {
		printf("%d\n", stack[front + 1]);
		stack[++front] = 0;
	}
}

//pop_back
void pop_back() {
	if (IsEmpty() == 1) {	//비었다면..
		printf("%d\n", -1);
	}
	else {
		printf("%d\n", stack[rear - 1]);
		stack[--rear] = 0;
	}
}

//FRONT
void fronts() {
	if (IsEmpty() == 1) {	//비었다면..
		printf("%d\n", -1);
	}
	else printf("%d\n", stack[front + 1]);
}

//BACK
void backs() {
	if (IsEmpty() == 1) {	//비었다면..
		printf("%d\n", -1);
	}
	else printf("%d\n", stack[rear - 1]);
}

//SIZE

void size() {
	printf("%d\n", rear - front - 1);
}

int main() {
	
	int ActNum;//명령의 입력을 받는 갯수
	char ActCh[6];



	scanf("%d", &ActNum);	
	int nums = 0;

	for (int i = 0; i < ActNum; i++) {
		scanf("%s", ActCh);

		//push_front X: 정수 X를 덱의 앞에 넣는다.
		if (ActCh[0] == 'p' && ActCh[1] == 'u' && ActCh[2] == 's' && ActCh[3] == 'h' && ActCh[4] == '_'
			&& ActCh[5] == 'f' && ActCh[6] == 'r' && ActCh[7] == 'o' && ActCh[8] == 'n' && ActCh[9] == 't') {

			scanf("%d", &nums);
			push_front(nums);
		}

		//push_back X: 정수 X를 덱의 뒤에 넣는다.
		if (ActCh[0] == 'p' && ActCh[1] == 'u' && ActCh[2] == 's' && ActCh[3] == 'h' && ActCh[4] == '_'
			&& ActCh[5] == 'b' && ActCh[6] == 'a' && ActCh[7] == 'c' && ActCh[8] == 'k') {

			scanf("%d", &nums);
			push_back(nums);
		}

		//pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		if (ActCh[0] == 'p' && ActCh[1] == 'o' && ActCh[2] == 'p' && ActCh[3] == '_' && ActCh[4] == 'f'
			&& ActCh[5] == 'r' && ActCh[6] == 'o' && ActCh[7] == 'n' && ActCh[8] == 't') {
			pop_front();
		}

		//pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다.만약, 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
		if (ActCh[0] == 'p' && ActCh[1] == 'o' && ActCh[2] == 'p' && ActCh[3] == '_' && ActCh[4] == 'b'
			&& ActCh[5] == 'a' && ActCh[6] == 'c' && ActCh[7] == 'k') {
			pop_back();
		}

		//size: 덱에 들어있는 정수의 개수를 출력한다.
		if (ActCh[0] == 's' && ActCh[1] == 'i' && ActCh[2] == 'z' && ActCh[3] == 'e') {
			size();
		}



		//empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
		if (ActCh[0] == 'e' && ActCh[1] == 'm' && ActCh[2] == 'p' && ActCh[3] == 't' && ActCh[4] == 'y') {
			int em = IsEmpty();
			printf("%d\n", em);
		}

		//front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		if (ActCh[0] == 'f' && ActCh[1] == 'r' && ActCh[2] == 'o' && ActCh[3] == 'n' && ActCh[4] == 't') {
			fronts();
		}

		//back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		if (ActCh[0] == 'b' && ActCh[1] == 'a' && ActCh[2] == 'c' && ActCh[3] == 'k') {
			backs();
		}

	}

	getchar();
	return 0;
}
