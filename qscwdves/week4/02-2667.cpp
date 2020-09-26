#include <iostream>
#include <cstring>
#include <stack>
#pragma warning (disable:4996)
using namespace std;
struct x_or_y{
	int x;
	int y;
};
int map[25][25] = { 0 }, map_one[25] = { 0 }, num;
int check_group(int x,int y);

int main() {
	int order[625]={0}, count = 0;
	char ch;
	scanf("%d", &num);
	getchar();
	for (int i = 0; i < num; i++) {
		int count_temp = 0;
		for (int k = 0; k < num; k++) {
			scanf("%c", &ch);
			if (ch == '1') {
				map[i][k] = 1;
				count_temp++;
			}
		}
		map_one[i] = count_temp;
		getchar();
	}

	for (int i = 0; i < num; i++) {
		for (int k = 0; k < num; k++) {
			if (map_one[i] < 1) break;
			if (map[i][k] == 1) {
				int temp;
				temp = check_group(i, k);
				order[count] = temp;
				count++;
			}
		}
	}
	// 오름차순 정렬
	for (int i = 0; i < count; i++) {
		for (int k = i; k < count; k++) {
			if (order[i] > order[k]) {
				int num = order[i];
				order[i] = order[k];
				order[k] = num;
			}
		}
	}
	printf("%d\n", count);
	for (int i = 0; i < count; i++) printf("%d\n",order[i]);
	return 0;
}
int check_group(int y,int x) {
	stack<x_or_y> stack;
	x_or_y start;
	int count = 1;
	start.x = x;
	start.y = y;
	map[start.y][start.x] = 0;
	map_one[start.y]--;
	stack.push(start);
	while (!stack.empty()) {
		x_or_y temp = stack.top(), input;
		stack.pop();
		if (temp.y != 0 && map[temp.y - 1][temp.x] == 1) { // 위 탐색
			input.x = temp.x;
			input.y = temp.y - 1;
			stack.push(input);
			count++;
			map_one[temp.y - 1]--;
			map[temp.y - 1][temp.x] = 0;
		}
		if (temp.y != num - 1 && map[temp.y + 1][temp.x] == 1) {  // 아래 탐색
			input.x = temp.x;
			input.y = temp.y + 1;
			stack.push(input);
			count++;
			map_one[temp.y + 1]--;
			map[temp.y + 1][temp.x] = 0;
		}
		if (temp.x != 0 && map[temp.y][temp.x - 1] == 1) {  // 왼쪽 탐색
			input.x = temp.x - 1;
			input.y = temp.y;
			stack.push(input);
			count++;
			map_one[temp.y]--;
			map[temp.y][temp.x - 1] = 0;
		}
		if (temp.x != num - 1 && map[temp.y][temp.x + 1] == 1) {  // 오른쪽 탐색
			input.x = temp.x + 1;
			input.y = temp.y;
			stack.push(input);
			count++;
			map_one[temp.y]--;
			map[temp.y][temp.x + 1] = 0;
		}
	}
	return count;
}
