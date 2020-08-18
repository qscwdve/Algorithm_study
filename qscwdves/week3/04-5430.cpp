#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;
void AC();

int main() {
	int test_case;
	scanf("%d", &test_case);
	getchar();
	for (int i = 0; i < test_case; i++) {
		AC();
		getchar();
	}
	return 0;
}
void AC() {
	char op[100002] = { 0 }, ch=1;
	int D_count = 0, i=0;
	int ary[100000] = { 0 }, temp, ary_top = -1, first = -1, last_first = 1;
	
	while (ch != '\n') {
		scanf("%c", &ch);
		if (ch == 'D') D_count++;
		op[i] = ch;
		i++;
	}
	scanf("%d", &temp);
	getchar();
	if (temp < D_count) {
		scanf("%s", &op);
		printf("error\n");
		return;
	}
	else if (temp == 0) {
		scanf("%s", &op);
		printf("[]\n");
		return;
	}
	getchar();     //'[' 받음
	while (ch != ']') {
		scanf("%d", &temp);
		scanf("%c", &ch);
		ary_top++;
		ary[ary_top] = temp;
	}
	i = 0;
	while(op[i] != '\n') {
		if (op[i] == 'D') {
			if (last_first == -1) {  // last!! top!!
				ary_top--;
			}
			else first++;
		}
		else { // R 연산
			last_first *= -1;
		}
		i++;
	}
	printf("[");
	if (last_first == 1) {
		for (int i = first + 1; i <= ary_top; i++) {
			printf("%d", ary[i]);
			if (i == ary_top) break;
			printf(",");
		}
	}
	else {
		for (int i = ary_top; i > first; i--) {
			printf("%d", ary[i]);
			if (i == first + 1) break;
			printf(",");
		}
	}
	printf("]\n");
}
