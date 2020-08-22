#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;
struct List {
	int data;
	List* next;
};
class Stack {
	int top_point;
	int data[50000] = { 0 };
public:
	Stack() {
		this->top_point = -1;
	}
	void push(int x) {
		this->top_point = this->top_point + 1;
		this->data[top_point] = x;
	}
	int pop() {
		int temp = data[this->top_point];
		data[this->top_point] = 0;
		this->top_point = this->top_point - 1;
		return temp;
	}
	int empty() {
		if (this->top_point < 0) return 1;
		else return 0;
	}
	int top() {
		return data[this->top_point];
	}
};
int main() {
	int N, M;
	int temp1, temp2, before[100000] = { 0 }, num_check[100000] = { 0 };
	List *list[100000];  
	Stack stack;
	scanf("%d", &N);
	scanf("%d", &M);
	getchar();
	for (int i = 0; i < M; i++) {
		struct List *temp = new struct List;
		scanf("%d", &temp1);
		scanf("%d", &temp2);
		getchar();
		before[temp2 - 1] += 1;
		temp->data = temp1;
		temp->next = NULL;
		if (before[temp2 - 1] == 1) {
			list[temp2 - 1] = temp;
			num_check[temp2 - 1] = 1;
		}
		else {
			struct List* travel = list[temp2 - 1];
			while (travel->next != NULL) travel = travel->next;
			travel->next = temp;
			num_check[temp2 - 1] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		if (before[i] > 0) {
			stack.push(i+1);  
			while (!stack.empty()) {
				int top = stack.top();
				if (before[top - 1] == 0) {
					printf("%d ", stack.pop());
					before[top - 1] = -1;
				}
				else if (before[top - 1] == -1) {
					stack.pop();
				}
				else {
					struct List* temp = list[top - 1];
					while (1) {
						if(before[temp->data - 1] != -1) stack.push(temp->data);
						before[top-1]--;
						if (before[top - 1] == 0) break;
						temp = temp->next;
					}
				}
			}
		}
		else if (before[i] == 0) {
			printf("%d ", i+1);
			before[i] = -1;
		}
	}
	
	for (int i = 0; i < N; i++) {
		if (num_check[i] == 1) {
			struct List* t = list[i];
			while (1) {
				struct List* t2 = t;
				if (t->next == NULL) break;
				t = t->next;
				delete t2;
			}
			delete t;
		}
	}
	return 0; 
}
