#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
void quick(int left, int right);
int num, x[100000] = { 0 }, y[100000] = { 0 };
queue<int> ls;
queue<int> rs;

int main() {
	int X, Y;

	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &X, &Y);
		x[i] = X;
		y[i] = Y;
	}
	ls.push(0);
	rs.push(num-1);
	while (!ls.empty()) {
		quick(ls.front(), rs.front());
		ls.pop();
		rs.pop();
	}
	for (int i = 0; i < num; i++) {
		printf("%d %d\n", x[i], y[i]);
	}
	return 0;
}
void quick(int left, int right) {
	queue<int> lq, rq, lq_y, rq_y;
	int middle = (left + right) / 2, pl = left, pr = right, value, value_y;
	int lq_size, rq_size;
	value = x[middle];
	value_y = y[middle];
	while (pl < middle) {
		if (x[pl] > value || (x[pl] == value && y[pl] > y[middle])) {
			rq.push(x[pl]);
			rq_y.push(y[pl]);
		}
		else {
			lq.push(x[pl]);
			lq_y.push(y[pl]);
		}
		pl++;
	}
	while (pr > middle) {
		if (x[pr] < value || (x[pr] == value && y[pr] < y[middle])) {
			lq.push(x[pr]);
			lq_y.push(y[pr]);
		}
		else {
			rq.push(x[pr]);
			rq_y.push(y[pr]);
		}
		pr--;
	}
	rq_size = rq.size();
	lq_size = lq.size();
	for (int i = 0; i < lq_size; i++) {
		x[left + i] = lq.front();
		y[left + i] = lq_y.front();
		lq.pop();
		lq_y.pop();
	}
	x[left + lq_size] = value;
	y[left + lq_size] = value_y;
	for (int i = 0; i < rq_size; i++) {
		x[right - i] = rq.front();
		y[right - i] = rq_y.front();
		rq.pop();
		rq_y.pop();
	}
	if (lq_size != 0) {
		ls.push(left);
		rs.push(left + lq_size - 1);
	}
	if (rq_size != 0) {
		ls.push(left + lq_size + 1);
		rs.push(right);
	}
}
