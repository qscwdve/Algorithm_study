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



int main() {

	int T, a, b;
	int left, right; //left는 처음 값, right는 끝 값
	int num;


	scanf("%d", &T);
	
	for (int i = 0; i < T; i++) {
		vector<int> v1, v2; //v1는 찾는 범위, v2는 찾는 수

		scanf("%d", &a);
		for (int j = 0; j < a; j++) {
			cin >> num;
			v1.push_back(num);
		}
		scanf("%d", &b);
		for (int j = 0; j < b; j++) {
			cin >> num;
			v2.push_back(num);
		}

		sort(v1.begin(), v1.end());


		for (int j = 0; j < v2.size(); j++) {
			bool flag = false;
			left = 0;
			right = v1.size() - 1;
			while (left <= right) {	//찾는 범위까지 반복
				int mid = (left + right) / 2;	//중간값
				if (v2[j] == v1[mid]) {	//중간값 숫자와 같다면
					flag = true;
					break;
				}
				if (v2[j] > v1[mid]) {	//중간값 숫자보다 크다면, 오른쪽 비교
					left = mid + 1;
				}
				else {
					right = mid - 1;	//중간값 숫자모다 작다면, 왼쪽 비교
				}
			}
			cout << flag << '\n';
		}

	}




	return 0;
}
