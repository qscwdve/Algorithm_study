#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, d, c;
int INF = 100000001;
vector<pair<int, int>> g[10001];

void solution(int start);
 
int main(){
    int testCase;
    int a, b, s;
    scanf("%d",&testCase);
    while(testCase-->0){
        scanf("%d %d %d", &n, &d, &c);
        for(int i = 0 ; i < d ; i++){
            scanf("%d %d %d", &a, &b, &s);
            g[b].push_back(make_pair(a,s));
        }
        solution(c);
        for(int i = 1; i <= n; i++){
            g[i].clear();
        }

    }
    return 0;
}

void solution(int start){
    bool visited[n+1];
    int distance[n+1];
    int hacked = 0;
    int cur = start;
    int max = 0;
    int curCost = 0;

    queue<pair<int,int>> q;
    q.push(make_pair(start,0));

    for(int i = 0; i <= n ; i++){
        distance[i] = INF;
        visited[i] = false;
    }
    distance[start] = 0;
    while(!q.empty()){
        pair<int,int> pa = q.front();
        q.pop();
        cur = pa.first;
        curCost = pa.second;
        //printf("cur, curCost: %d %d\n",cur, curCost);
        visited[cur] = true;
        for(int j = 0 ; j < g[cur].size() ; j++){
            if(g[cur][j].second + curCost < distance[g[cur][j].first]){
                distance[g[cur][j].first] = g[cur][j].second + curCost;
                q.push(make_pair(g[cur][j].first, distance[g[cur][j].first]));
            }
        }
    }   
    for(int i = 1; i<n+1; i++){
        if(visited[i]){
            hacked++;
            if(distance[i] > max) max = distance[i];
        }
    }
    printf("%d %d\n",hacked, max);
}