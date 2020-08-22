#include <iostream>
#pragma warning (disable:4996)
using namespace std;
void count_order_positive();
void count_order_negaitive();
int positive_check[1001] = { 0 }, negative_check[1001] = { 0 };

int main() {
	int num, temp;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &temp);
		if (temp < 0) negative_check[temp * (-1)]++;
		else positive_check[temp]++;
	}
	count_order_negaitive();
	count_order_positive();
	return 0;
}
void count_order_positive() {
	int count = 0;
	while (1) {
		while (positive_check[count] == 0) {
			count++;
			if (count > 1000) return ;
		}
		printf("%d ", count);
		positive_check[count] = 0;
	}
	return;
}
void count_order_negaitive() {
	int count = 1000;
	while (1) {
		while (negative_check[count] == 0) {
			count--;
			if (count < 1) return;
		}
		printf("%d ", count*(-1));
		negative_check[count] = 0;
	}
	return;
}
