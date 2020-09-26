#include <iostream>
#include <cstring>
using namespace std;

class Queue {
	int front_point;
	int back_point;
	int data[8000] = { 0 };
public:
	Queue(){
		this->front_point = -1;
		this->back_point = -1;
	}
	void push(int x) {
		this->front_point = this->front_point + 1;
		this->data[this->front_point] = x;
	}
	int pop() {
		if (this->empty()) {
			cout << "-1\n";
		}
		else {
			this->back_point = this->back_point + 1;
			cout << this->data[this->back_point] << "\n";
			return this->data[this->back_point];
		}
		return -1;
	}
	void size() {
		cout << this->front_point - this->back_point << "\n";
	}
	int empty() {
		if (this->front_point == this->back_point) {
			return 1;
		}
		return 0;
	}
	void front() {
		if (this->empty()) {
			cout << "-1\n";
		}
		else {
			cout << this->data[this->back_point + 1] << "\n";
		}
	}
	void back() {
		if (this->empty()) {
			cout << "-1\n";
		}
		else {
			cout << this->data[this->front_point] << "\n";
		}
	}
};
int main() {
	int num = 0, x = 0;
	char comnd[10];
	Queue queue;
	
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> comnd;
		if (strncmp(comnd, "pu", 2) == 0) {
			cin >> x;
			queue.push(x);
		}
		else if (strncmp(comnd, "po", 2) == 0) {
			queue.pop();
		}
		else if (strncmp(comnd, "si", 2) == 0) {
			queue.size();
		}
		else if (strncmp(comnd, "em", 2) == 0) {
			if (queue.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (strncmp(comnd, "fr", 2) == 0) {
			queue.front();
		}
		else if (strncmp(comnd, "ba", 2) == 0) {
			queue.back();
		}
	}
	return 0;
}
