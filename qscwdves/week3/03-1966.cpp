#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;
int answer(int num, int order);

struct node {
	int text;
	int qurity;
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
	void insert_last(int data,int qurity) {   // last 뒤에 삽입, 마지막 노드 뒤에 삽입
		node* ch = new node;
		ch->addr = NULL;
		ch->text = data;
		ch->qurity = qurity;
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
	void first_delete() {  // 처음 노드를 삭제한다.
		node* temp = first;
		first = (*first).addr;
		delete temp;
	}
	int first_qurity() {
		return (*first).qurity;
	}
	int first_data() {
		return (*first).text;
	}
	void first_to_last() {   // 처음노드를 마지막 노드 뒤로 옮긴다.
		(*last).addr = first;
		last = first;
		first = (*first).addr;
		(*last).addr = NULL;
	}
};
int main() {
	int test_case, order, num;
	scanf("%d", &test_case);
	getchar();
	for (int i = 0; i < test_case; i++) {
		scanf("%d", &num);
		scanf("%d", &order);
		getchar();
		answer(num, order);
	}
	return 0;
}
int answer(int num,int order) {
	LinkedList list;
	int temp, qurity[9] = { 0 }, qurity_now = 8;
	int delete_count = 0;
	for (int i = 0; i < num; i++) {
		scanf("%d", &temp);
		list.insert_last(i, temp);
		qurity[temp - 1] += 1;
	}
	while (qurity[qurity_now] == 0) qurity_now--;
	while (!list.isEmpty()) {
		if (list.first_qurity() == qurity_now + 1) {
			if (list.first_data() == order) {
				delete_count++;
				printf("%d\n", delete_count);
				getchar();
				return 0;
			}
			qurity[qurity_now] -= 1;
			list.first_delete();
			delete_count++;
			if (qurity[qurity_now] == 0) {
				while (qurity[qurity_now] == 0) qurity_now--;
			}
		}
		else list.first_to_last();
	}
	return -1;
}
