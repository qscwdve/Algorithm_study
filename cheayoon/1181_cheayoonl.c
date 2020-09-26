#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;





int num, nu;
string h;


int main() {
	vector <string> sv;
	string temp;

	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%s", h);
		sv.push_back(h);
	}
	sort(sv.begin(), sv.end());	//정렬하는 부분





	for (int j = 0; j < sv.size(); j++) {

		h = sv[j];


		printf("%s\n", h);
	}



	getchar();
	getchar();
	return 0;
}
