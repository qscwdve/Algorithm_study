#include <stdio.h>
#pragma warning (disable:4996)
//아스키코드 97 = 'a', 122 = 'z'
int main() {
	int num;
	char text = NULL, before, count = 0;

	scanf("%d", &num);
	getchar();
	for (int i = 0; i < num; i++) {
		int alp[26] = { 0 }, index_count = 0;
		count++;
		before = NULL;
		while (1) {
			scanf("%c", &text);
			if (text == '\n')break;
			if (before != text) {
				int k;
				for (k = 0; k < index_count; k++) {
					if (alp[k] == text) {
						count--;
						break;
					}
				}
				if (k < index_count) break;
				alp[index_count] = text;
				index_count++;
			}
			before = text;
		}
		while (text != '\n') scanf("%c", &text);
	}
	printf("%d", count);
	return 0;
}
