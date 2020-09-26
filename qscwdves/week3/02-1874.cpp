#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

class Stack {
	int top_point;
	int data[100000] = { 0 };
public:
	Stack() {
		this->top_point = -1;
	}
	void push(int x) {
		this->top_point = this->top_point + 1;
		this->data[top_point] = x;
	}
	int pop() {
		int num = this->data[top_point];
		this->top_point = this->top_point - 1;
		return num;
	}
};
int main() {
	int num, number, now_num = 1, ans_point = -1;
	char answer[200000] = { 0 };
	Stack stack;

	scanf("%d", &num);
	getchar();
	for (int i = 1; i <= num; i++) {
		scanf("%d", &number);
		getchar();
		if (now_num <= number) {
			while (now_num <= number) {
				ans_point++;
				answer[ans_point] = '+';
				stack.push(now_num);
				now_num++;
			}
			stack.pop();
			ans_point++;
			answer[ans_point] = '-';
		}
		else {
			if (stack.pop() != number) {
				printf("NO\n");
				return 0;
			}
			else {
				ans_point++;
				answer[ans_point] = '-';
			}
		}
	}
	for (int i = 0; i <= ans_point; i++) {
		printf("%c\n", answer[i]);
	}
	return 0;
}
