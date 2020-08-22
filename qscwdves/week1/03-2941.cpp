#include <stdio.h>
#pragma warning (disable:4996)

int main() {
	char text , temp = 0, count = 1;
	int d_count = 0;
	scanf("%c", &temp);
	if (temp == 'd') d_count = 2;
	while (temp != '\n') {
		text = temp;
		d_count--;
		scanf("%c", &temp);
		if (temp == '\n') break;
		if (temp == 'd') d_count = 2;
		else if (temp == '-') continue;
		else if (temp == 'j' && (text == 'l' || text == 'n')) continue;
		else if (temp == '=') {
			if (text == 'z') {
				if (d_count == 0) count--;
			}
			continue;
		}
		count++;
	}
	printf("%d", count);
	return 0;
}
