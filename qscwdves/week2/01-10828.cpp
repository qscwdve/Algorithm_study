#include <iostream>
#include <cstring>
using namespace std;

class Stack {
	int top_point;
	int data[1000] = { 0 };
public:
	Stack() {
		this->top_point = -1;
	}
	void top() {
		if (this->empty()) {
			printf("-1\n");
		}
		else printf("%d\n", this->data[top_point]);
	}
	void push(int x) {
		this->top_point = this->top_point + 1;
		this->data[top_point] = x;
	}
	void pop() {
		if (this->empty()) {
			printf("-1\n");
		}
		else {
			printf("%d\n", this->data[top_point]);
			this->top_point = this->top_point - 1;
		}
	}
	void size() {
		if (this->empty()) {
			printf("0\n");
		}
		else {
			printf("%d\n", top_point + 1);
		}
	}
	int empty() {
		if (this->top_point < 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
};
int main() {
	int num, x = 0;
	char comnd[5];
	Stack stack;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> comnd;
		if (strncmp(comnd, "pu", 2) == 0) {
			cin >> x;
			stack.push(x);
		}
		else if (strncmp(comnd, "po", 2) == 0) {
			stack.pop();
		}
		else if (strncmp(comnd, "si", 2) == 0) {
			stack.size();
		}
		else if (strncmp(comnd, "em", 2) == 0) {
			if (stack.empty()) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (strncmp(comnd, "to", 2) == 0) {
			stack.top();
		}
	}
	return 0;
}
