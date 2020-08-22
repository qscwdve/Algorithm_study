#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)


using namespace std;



int a[100001];


int num, h;




int main() { 

	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &h);
		a[i] = h;
	}
	sort(a, a + num);

	for (int j = 0; j < num; j++) {
		
		if (a[j - 1] != a[j]) {
			printf("%d\n", a[j]);
		}
	}







getchar();
getchar();
return 0; 
}
