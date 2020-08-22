#include <iostream>
#include <queue>
#pragma warning (disable:4996)
using namespace std;
struct node {
	int count = 0;
	int num = 0;
};
int main() {
	int n, k, check[200001] = { 0 };
	queue<node> q;
	node start;
	scanf("%d %d", &n, &k);
	check[n] = 1;
	start.num = n;
	q.push(start);
	if (n > k) printf("%d", n - k);
	else if (n == k) printf("0");
	else {
		while (1) {
			node now = q.front(), temp;
			int num, count;
			num = now.num;
			count = now.count;
			q.pop();
			if (num == k ) {
				printf("%d", count);
				break;
			}
			if (check[num + 1] == 0 && num < k) {
				check[num + 1] = 1;
				temp.num = num + 1;
				temp.count = count + 1;
				q.push(temp);
			}
			if (num - 1 >= 0 && check[num - 1] == 0) {
				check[num - 1] = 1;
				temp.num = num - 1;
				temp.count = count + 1;
				q.push(temp);
			}
			if (num < k && check[num * 2] == 0) {
				check[num * 2] = 1;
				temp.num = num * 2;
				temp.count = count + 1;
				q.push(temp);
			}
		}
	}
	return 0;
}
