#include <iostream>
#pragma warning (disable:4996)
using namespace std;

int main() {
	int data_check[10001] = { 0 };
	int num, temp, count = 1;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &temp);
		data_check[temp]++;

	}
	while (1) {
		while (data_check[count] == 0) {
			count++;
			if (count > 10000) return 0;
		}
		int size = data_check[count];
		for (int i = 0; i < size; i++) {
			printf("%d\n", count);
			data_check[count]--;
		}
	}
	return 0;
}
