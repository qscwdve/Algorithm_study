#include <iostream>
#include <queue>
#include <memory.h>
#include <stdlib.h>
using namespace std;

typedef struct node{
    bool check[9];
    int map[3][3];
}NODE;

int baseMap[3][3];
int X[4] = {1,-1,0,0};
int Y[4] = {0,0,1,-1};
void solution();
bool check(NODE n);
int main(){
    int testCase;
    char temp;
    scanf("%d",&testCase);
    while(testCase-- > 0){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                scanf(" %c", &temp);
                if(temp == '*') baseMap[i][j] = 1;
                else baseMap[i][j] = 0;
            }
        }
        solution();
    }
    return 0;
}


void solution(){
    NODE cur;
    queue<NODE> q;
    int dirx, diry;
    int count = 0;
    memset(&cur,0,sizeof(NODE));
    memcpy(cur.map,baseMap,sizeof(baseMap));
    q.push(cur);
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(check(cur)){
            for(int i = 0 ; i < 9; i++){
                if(cur.check[i]) count++;
            }
            printf("%d\n", count);
            return;
        }
        for(int i = 0 ; i < 9; i++){
            if(!cur.check[i]){
                cur.check[i] = true;
                cur.map[i/3][i%3] = !cur.map[i/3][i%3];
                for(int j = 0; j < 4; j++){
                    dirx = i%3 + X[j];
                    diry = i/3 + Y[j];
                    if(dirx >=0 && diry >= 0 && dirx < 3 && diry < 3){
                        cur.map[diry][dirx] = !cur.map[diry][dirx];
                    }
                }
                q.push(cur);

                cur.check[i] = false;
                cur.map[i/3][i%3] = !cur.map[i/3][i%3];
                for(int j = 0; j < 4; j++){
                    dirx = i%3 + X[j];
                    diry = i/3 + Y[j];
                    if(dirx >=0 && diry >= 0 && dirx < 3 && diry < 3){
                        cur.map[diry][dirx] = !cur.map[diry][dirx];
                    }
                }
            }
        }
    }
}
bool check(NODE n){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(n.map[i][j] == 1)return  false;
        }
    }
    return true;
}