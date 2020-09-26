#include <stdio.h>
#include<stack>
#pragma warning (disable:4996)
using namespace std;

int main() {
	int num[1000000] = { 0 }, n, temp;
	stack<int> lStack , rStack;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		num[i] = temp;
	}
	lStack.push(0);
	rStack.push(n-1);
	while (!lStack.empty()) {
		int pl, left , pr, right, x;
		pl = lStack.top();
		lStack.pop();
		left = pl;
		pr = rStack.top();
		rStack.pop();
		right = pr;
		x = num[(left + right) / 2];
		do {
			while (num[pl] < x) pl++;
			while (num[pr] > x) pr--;
			if (pl <= pr) {
				int temp = num[pl];
				num[pl] = num[pr];
				num[pr] = temp;
				pl++;
				pr--;
			}
		} while (pl <= pr);
		if (left < pr) {
			lStack.push(left);
			rStack.push(pr);
		}
		if (pl < right) {
			lStack.push(pl);
			rStack.push(right);
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", num[i]);
	}
	return 0;
}
