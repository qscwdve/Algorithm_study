#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <cstdio>
#pragma warning (disable:4996)

#define MAX_V 10001
using namespace std;

void dijkstra(int src, int V, vector<pair<int, int>> *adj){
    int computer = 1, time = 0;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;  

    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;

        pq.pop();

        if (dist[here] < cost) {
            computer--;
            continue;
        }
        time = cost;
       
        for (int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            
            if (dist[there] > nextDist){
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
                computer++;
            }
        }
    }
    printf("%d %d\n", computer, time);
}
int main() {
    int T, start, end, sec, d, c, n;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d %d %d", &n, &d, &c);
        vector< pair<int, int>> adj[MAX_V];
        while (d-- > 0) {
            scanf("%d %d %d", &end, &start, &sec);
            adj[start].push_back(make_pair(end, sec));
        }
        dijkstra(c, n + 1, adj);
    }
    return 0;
}