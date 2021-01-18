#include <iostream>
#include <queue>

using namespace std;
int dirX[8] = {1, -1, 0, 0, 1,-1, 1, -1};
int dirY[8] = {1, -1, 1,-1, 0, 0, -1, 1};

void solution(int, int);

int main(){
    int n, m;
    scanf("%d %d",&n, &m);
    solution(n, m);
    return 0;
}
void solution(int n, int m){
    int map[n][m];
    int y, x;
    int tmpX, tmpY;
    int max = 1;
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&map[i][j]);
            if(map[i][j])q.push(make_pair(i,j));
            else map[i][j] = 3000;
        }
    }
    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int k = 0; k < 8; k++){
            tmpX = x + dirX[k];
            tmpY = y + dirY[k];
            if(tmpX>=0 && tmpY>=0 && tmpX<m && tmpY<n){
                if(map[tmpY][tmpX] > map[y][x] + 1){
                    map[tmpY][tmpX] = map[y][x] + 1;
                    q.push(make_pair(tmpY, tmpX));
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j<m; j++){
            if(max < map[i][j])max = map[i][j];
        }
    }
    printf("%d\n", max-1);
    
}