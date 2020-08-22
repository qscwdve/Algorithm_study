#include <iostream>
#include <queue>
using namespace std;
int main() {
	int count = 0;
	int test_case;
	cin >> test_case;
	int n, m, ipt;//문서의 개수, 궁금한 문서 위치, 중요도
	for (int i = 0; i < test_case; ++i) {
		count = 0;
		cin >> n >> m;

		//STL 컨테이너의 한 종류인 Pair은 두개의 변수를 저장할 수 있는 구조입니다.
		queue<pair<int, int> > q;
		priority_queue<int> pq; // 우선순위 큐
		for (int j = 0; j < n; ++j) {
			cin >> ipt;
			//j에는 0부터 n까지 번호를 세겨줍니다.
			//ipt에는 적은 숫자를 순서대로 넣어줍니다.
			q.push({ j, ipt });
			//우선순위 큐에 적은 번호를 순서대로 넣어줍니다.
			pq.push(ipt);
		}
		while (!q.empty()) {	//q가 비지 않을 때까지..
			int index = q.front().first;	//j가 적힌 값은 index에 넣기.
			int value = q.front().second;	//ipt가 적힌 값은 value에 넣기.
			q.pop();
			if (pq.top() == value) {	//q의 back부분과 pq의 front부분을 비교해줍니다.
										//만약 같다면 이 if문을 실행합니다.
				pq.pop();
				++count;
				if (index == m) {	//만약 뽑은 것의 값이 q의 index에 세긴 값과 입력한 수 m과 같다면..
					cout << count << endl;
					break;
				}
			}
			else q.push({ index,value });	//같지 않다면 추가해줍니다. (참고로 q는 빼낸 상태)
		}
	}
}
