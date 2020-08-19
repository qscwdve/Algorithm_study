#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int a[101], b[101];
int n, h;
int s;	//결과



int main() { 
	scanf("%d", &n);	

	for (int i = 0; i < n; i++) {
		scanf("%d", &h);
		a[i] = h;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &h);
		b[i] = h;
	}


	sort(a, a + n);
	sort(b, b + n);


	for (int i = 0; i < n; i++) {
		s += a[i] * b[n - i - 1];

	}

	printf("%d", s);



getchar();
getchar();
return 0; 
}
