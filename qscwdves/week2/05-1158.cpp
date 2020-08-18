#include <iostream>
using namespace std;

struct node {
	int text;
	node* addr;
};
class LinkedList {
	node* first;
	node* last;
public:
	LinkedList() {
		first = NULL;
		last = NULL;
	}
	~LinkedList() {
		node* temp;
		if (first != NULL) {
			while ((*first).addr != NULL) {
				temp = (*first).addr;
				delete first;
				first = temp;
			}
			delete first;
		}
	}
	void insert_last(node* ch) {   // last 뒤에 삽입 
		if (first == NULL) {
			first = ch;
			last = ch;
		}
		else {
			(*last).addr = ch;
			last = ch;
		}
	}
	int isEmpty() {
		if (first == NULL) return 1;
		else return 0;
	}
	void first_delete() {
		node* temp = first;
		cout << (*first).text;
		first = (*first).addr;
		delete temp;
	}
	void first_to_last() {   // 처음노드를 마지막 노드로 옮긴다.
		(*last).addr = first;
		last = first;
		first = (*first).addr;
		(*last).addr = NULL;
	}
};
int main() {
	int n, k, count;
	LinkedList link;
	node* print;

	cin >> n;
	cin >> k;
	
	for (int i = 1; i <= n; i++) {
		node* temp = new node;
		temp->addr = NULL;
		temp->text = i;
		link.insert_last(temp);
	}
	cout << "<";
	count = 0;  
	while (1) {
		count++;
		if (count == k) {
			link.first_delete();
			count = 0;
			if (!link.isEmpty()) cout << ", ";
			else break;
		}
		else {
			link.first_to_last();
		}
	}
	cout << ">";
	return 0;
}
