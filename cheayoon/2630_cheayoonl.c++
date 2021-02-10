#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <tuple>
#include <time.h>
#include <math.h>
#include <cmath>
#include <string>

#pragma warning (disable:4996)

using namespace std;

int c[2] = { 0 };
int map[3000][3000] = { 0 };

void divCon(int n, int m, int x)
{
	int check = map[n][m];

	for (int i = n; i < n + x; ++i) {
		for (int j = m; j < m + x; ++j) {
			if (check != map[i][j]) {	//만약 색이 다르다면
				check = 2;
			}
			//4조각으로 나눠서 작업 반복
			if (check == 2) {
				int div = x / 2;	
				divCon(n, m, div);	//제2사분면
				divCon(n + div, m, div);	//제1사분면

				divCon(n, m + div, div);	//제3사분면
				divCon(n + div, m + div, div);	//제4사분면

				return;
			}
		}
	}

	if (check == 0) {
		++c[0];
	}
	else if (check == 1) {
		++c[1];
	}

	return;
}


int main() {

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}


	divCon(0, 0, n);

	cout << c[0] << endl;
	cout << c[1] << endl;



	return 0;
}
