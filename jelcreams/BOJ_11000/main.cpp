#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};
struct cmp2{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pqt;
void solution();

int main(){
    int N;
    int a,b;
    scanf("%d", &N);
    for(int i = 0; i < N;i++){
        scanf("%d %d", &a, &b);
        pqt.push(make_pair(a,b));
    }
    solution();
    return 0;
}

void solution(){
    priority_queue<pair<int, int>,vector<pair<int,int>>, cmp2> tempPqt;
    pair<int,int> cur;
    int sizeOfV;
    bool check = false;
    tempPqt.push(pqt.top());
    pqt.pop();
    while(!pqt.empty()){
        check = false;
        cur = pqt.top();
        sizeOfV = (int)tempPqt.size();
        //printf("print: %d %d\n",pqt.top().first, pqt.top().second);
        if(tempPqt.top().second <= cur.first){
            tempPqt.pop();
            tempPqt.push(cur);
        }
        else{
            tempPqt.push(cur);
        }
        pqt.pop();
    }
    printf("%ld\n", tempPqt.size());
}