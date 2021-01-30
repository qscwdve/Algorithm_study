#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct compare{
    bool operator() (pair<int, int> a , pair<int,int> b){
        if(a.second == b.second){
            return a.first < b.second;
        }
        return a.second > b.second;
    }
};

struct compareTwo{
    bool operator() (pair<int,int> a, pair<int, int> b){
        return a.first > b.first;
    }
};
priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;

void solution(int, int, int);
int main(){
    int N, M, K;
    int a, b;
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < K; i++){
        scanf("%d %d", &a , &b);
        pq.push(make_pair(a,b));
    }
    solution(N,M,K);
    return 0;
}
void solution(int n, int m, int k){
    //n개 선택해야함, m의 선호도를 만족할 것, k종류의 맥주
    int sum = 0, max = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>,compareTwo> pqt;

    for(int i = 0; i < n; i++){
        pqt.push(pq.top());
        sum += pq.top().first;
        pq.pop();
    }

    while(sum < m){
        if(pq.empty()){
            printf("-1\n");
            return;
        }
        sum -= pqt.top().first;
        pqt.pop();
        pqt.push(pq.top());
        sum += pq.top().first;
        pq.pop();

    }
    //printf("size: %d\n",pqt.size());
    for(int i = 0; i < n; i++){
        //printf("%d %d\n",pqt.top().first,pqt.top().second);
        if(max < pqt.top().second) {
            max = pqt.top().second;
        }
        pqt.pop();
    }
    printf("%d\n",max);
}