#include <iostream>
#include <stdio.h>
#pragma warning (disable:4996)
using namespace std;

int main() {
	int text[11] = { 0 };
	char temp;
	int N, start = 9, end = 0;

	scanf("%d", &N);
	getchar();
	for (int i = 1; i <= N; i++) {
		scanf("%c", &temp);
		getchar();
		text[i] = temp;
	}
	text[0] = text[1];

	for (int i = 0; i <= N; i++) {
		if (text[i + 1] == '<') end++;
		else if (text[i + 1] == '>') {
			if (text[i] == '<') {
				end++;
				for (int k = start - end + 1; k <= start; k++) {
					printf("%d", k);
				}
				start -= end;
				end = 0;
			}
			else printf("%d", start--);
		}
		else {
			if (text[i] == '>') {
				for (int k = start; k >= 9 - N; k--) printf("%d", k);
			}
			else {
				for (int k = 9 - N; k <= start; k++) printf("%d", k);
			}
		}
	}
	start = 0;
	end = 0;
	printf("\n");

	for (int i = 0; i <= N; i++) {
		if (text[i + 1] == '>') end++;
		else if (text[i + 1] == '<') {
			if(text[i] == '<')	printf("%d", start++);
			else {
				end++;
				for (int k = start + end - 1; k >= start; k--) {
					printf("%d", k);
				}
				start += end;
				end = 0;
			}
		}
		else {
			if (text[i] == '<') {
				for (int k = start; k <= N; k++) printf("%d", k);
			}
			else {
				for (int k = start + end; k >= start; k--) printf("%d", k);
			}
		}
	}
	return 0;
}
