#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int,int>> v;

bool compare(pair<int,int> a ,pair<int,int> b){
    if(a.second == b.second)return a.first < b.first;
    else return a.second < b.second;
}

int main(){
    int N;//회의의 수
    int start, end;
    int before,result = 0;
    scanf("%d",&N);
    for(int i = 0; i < N;i++){
        scanf("%d %d", &start, &end);
        v.push_back(make_pair(start,end));
    }
    stable_sort(v.begin(),v.end(),compare);

    for(int i = 0; i<v.size();i++)printf("[%d %d]\n",v[i].first, v[i].second);
    before = 0;
    result++;
    for(int i = 1 ; i<v.size(); i++){
        //printf("%d %d \n", v[i].first, v[i].second);
        if(v[before].second <= v[i].first){
            //printf("(%d %d)\n", v[before].first, v[before].second);
            result++;
            before = i;
        }
    }
    printf("%d\n",result);
    return 0;
}