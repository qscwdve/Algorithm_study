#include <stdio.h>
#pragma warning (disable:4996)

int main() {
	int num;
	scanf("%d", &num);
	getchar();
	for (int i = 0; i < num; i++) {
		check();
	}
	return 0;
}
int check() {
	int top = -1;
	char ch = 0;
	while (1) {
		scanf("%c", &ch);
		if (ch == '\n') {
			break;
		}
		if (ch == '(') top++;
		else {
			if (top == -1) {
				printf("NO\n");
				while (ch != '\n') scanf("%c", &ch);
				return 0;
			}
			top--;
		}
	}
	if (top == -1) printf("YES\n");
	else printf("NO\n");
	return 0;
}
