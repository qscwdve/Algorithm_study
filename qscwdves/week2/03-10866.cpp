#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

class Deque {  
	int head_top;
	int back_top;
	int first;
	int last;
	int max_size = 9999;
	int data[10000] = { 0 };
public:
	Deque() {
		head_top = -1;
		back_top = max_size + 1;
		first = -1;
		last = max_size + 1;
	}
	void push_front(int x) {
		head_top++;
		data[head_top] = x;
	}
	void push_back(int x){
		back_top--;
		data[back_top] = x;
	}
	void pop_front() {
		if (this->empty()) cout << "-1\n";
		else {
			if (head_top == first) {
				last--;
				cout << data[last] << "\n";
				if (last == back_top) {
					last = max_size + 1;
					back_top = last;
				}
			}
			else {
				cout << data[head_top] << "\n";
				head_top--;
				if (head_top == first) {
					head_top = -1;
					first = -1;
				}
			}
		}
	}
	void pop_back() {
		if (this->empty()) cout << "-1\n";
		else {
			if (back_top == last) {
				first++;
				cout << data[first] << "\n";
				if (first == head_top) {
					head_top = -1;
					first = -1;
				}
			}
			else {
				cout << data[back_top] << "\n";
				back_top++;
				if (back_top == last) {
					last = max_size + 1;
					back_top = last;
				}
			}
		}
	}
	int size() {
		return head_top - first + last - back_top;
	}
	int empty() {
		if (this->size() == 0) return 1;
		else return 0;
	}
	void front() {
		if (this->size() == 0) cout << "-1\n";
		else {
			if (head_top == first) {
				cout << data[last - 1] << "\n";
			}
			else {
				cout << data[head_top] << "\n";
			}
		}

	}
	void back() {
		if (this->size() == 0) cout << "-1\n";
		else {
			if (back_top == last) {
				cout << data[first + 1] << "\n";
			}
			else {
				cout << data[back_top] << "\n";
			}
		}
	}
};
int main() {
	int num, insert;
	char text[15] = { 0 };
	Deque deque;

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> text;
		if (strncmp(text, "s", 1) == 0) {
			cout << deque.size() << "\n";
		}
		else if (strncmp(text, "e", 1) == 0) {
			if (deque.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (strncmp(text, "f", 1) == 0) {
			deque.front();
		}
		else if (strncmp(text, "b", 1) == 0) {
			deque.back();
		}
		else if (strncmp(text, "pop_b", 5) == 0) {
			deque.pop_back();
		}
		else if (strncmp(text, "pop_f", 5) == 0) {
			deque.pop_front();
		}
		else if (strncmp(text, "push_f", 6) == 0) {
			cin >> insert;
			deque.push_front(insert);
		}
		else{
			cin >> insert;
			deque.push_back(insert);
		}
	}
	return 0;
}
