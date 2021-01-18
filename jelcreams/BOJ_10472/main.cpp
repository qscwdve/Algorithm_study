#include <iostream>
#include <queue>

using namespace std;
typedef struct node{
    int cur;
    int x,y;
    int map[3][3];
}NODE;
int dirX[4] = {1,-1,0,0};
int dirY[4] = {0,0,1,-1};
int baseMap[3][3];
void solution();
bool check(NODE);
int main(){
    int testCase;
    char tmp;
    scanf("%d",&testCase);
    while(testCase-->0){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                scanf(" %c",&tmp);
                if(tmp =='*') baseMap[i][j] = 0;
                else baseMap[i][j] = 1;
            }
        }
        solution();

    }
    return 0;
}
void solution(){
    queue<NODE> q;
    NODE nod;
    int tmpX, tmpY;
    int x, y;
    nod.cur = 0;
    nod.x = -1;
    nod.y = -1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            nod.map[i][j] = baseMap[i][j];
        }
    }
    q.push(nod);
    while(!q.empty()){
        nod = q.front();
        x = nod.x;
        y = nod.y;
        q.pop();
        if(check(nod)){
            printf("%d\n", nod.cur);
            return;
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(nod.x == j && nod.y == i)continue;
                nod.map[i][j] = !nod.map[i][j];
                for(int k = 0; k < 4; k++){
                    tmpX = j+dirX[k];
                    tmpY = i+dirY[k];
                    if(tmpX >= 0 && tmpY >= 0 && tmpX < 3 && tmpY < 3){
                        nod.map[tmpY][tmpX] = !nod.map[tmpY][tmpX];
                    }
                }
                nod.cur+=1;
                nod.x = j;
                nod.y = i;

                q.push(nod);

                nod.cur-=1;
                nod.x = x;
                nod.y = y;
                nod.map[i][j] = !nod.map[i][j];
                for(int k = 0; k < 4; k++){
                    tmpX = j+dirX[k];
                    tmpY = i+dirY[k];
                    if(tmpX >= 0 && tmpY >= 0 && tmpX < 3 && tmpY < 3){
                        nod.map[tmpY][tmpX] = !nod.map[tmpY][tmpX];
                    }
                }
            }
        }
        
    }

}
bool check(NODE n){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(n.map[i][j] == 0) return false;
        }
    }
    return true;
}