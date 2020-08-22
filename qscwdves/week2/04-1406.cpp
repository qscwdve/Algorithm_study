#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

int main() {
	char ch;
	char text[600000] = { 0 }, temp[300000] = { 0 };
	int num, text_top = -1, temp_top = -1;

	scanf("%c", &ch);
	while (ch != '\n') {
		text_top++;
		text[text_top] = ch;
		scanf("%c", &ch);
	}
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> ch;
		if (ch == 'P') {
			cin >> ch;
			text_top++;
			text[text_top] = ch;
		}
		else if (ch == 'B') {
			if(text_top >= 0) text_top--;
		}
		else if (ch == 'L') {
			if (text_top >= 0) {
				temp_top++;
				temp[temp_top] = text[text_top];
				text_top--;
			}
		}
		else if (ch == 'D') {
			if (temp_top >= 0) {
				text_top++;
				text[text_top] = temp[temp_top];
				temp_top--;
			}
		}
	}
	for (int i = 0; i <= text_top; i++) cout << text[i];
	for (int i = temp_top; i >= 0; i--) cout << temp[i];
	return 0;
}
