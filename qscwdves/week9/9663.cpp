#include <stdio.h>
#pragma warning (disable: 4996)

void N_Queen(int floor, int width, int M[15][15]);
int N, ans = 0;

int main() {
	int map[15][15] = { 0 };
	scanf("%d", &N);
	for (int k = 0; k < N; k++) N_Queen(0, k, map);
	printf("%d", ans);
	return 0;
}
void N_Queen(int floor, int width, int M[15][15]) {
	int num[50][2] = { 0 }, check = 0;
	for (int i = floor + 1; i < N; i++) {
		if (M[i][width] != 1) {
			M[i][width] = 1;
			num[check][0] = i;
			num[check++][1] = width;
		}
		if (width - (i - floor) >= 0 && M[i][width - (i - floor)] != 1) {
			M[i][width - (i - floor)] = 1;
			num[check][0] = i;
			num[check++][1] = width - (i - floor);
		}
		if (width + i - floor < N && M[i][width + (i - floor)] != 1)  {
			M[i][width + i - floor] = 1;
			num[check][0] = i;
			num[check++][1] = width + (i - floor);
		}
	}
	if (floor == N - 1) ans++;
	else {
		for (int i = 0; i < N; i++) {
			if (M[floor + 1][i] == 0) N_Queen(floor + 1, i, M);
		}
	}
	while (--check >= 0) {   
		M[num[check][0]][num[check][1]] = 0;
	}
}
