#include <iostream>
#include <stdio.h>
#pragma warning (disable: 4996)
using namespace std;
int order_s[6] = { 0 }, str, num[14] = { 0 };
void lotto(int order, int finish);

int main() {
	while (true) {
		scanf("%d", &str);   
		if (str == 0) break;
		for (int i = 0; i < str; i++) scanf("%d", (num + i));
		order_s[0] = 0;
		lotto(0, 0);    
		printf("\n");
	}
	return 0;
}
void lotto(int order, int finish) {   
	if (finish++ < str || order < 6) {
		if (order + 1 == 6) { 
			for (int i = 0; i < 6; i++) printf("%d ", num[order_s[i]]);
			printf("\n");
		}
		if (finish < str) {
			if (order + 1 != 6) {  
				order_s[order + 1] = finish;
				lotto(order + 1, finish);
			}
			if (finish - 1 <= str - 6 + order) { 
				order_s[order] = finish;
				lotto(order, finish);
			}
		}
	}
}
