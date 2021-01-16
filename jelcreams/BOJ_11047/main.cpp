#include <iostream>

using namespace std;
int coin[11];

int main(){
    int K;// K
    int N;// N
    int j;
    int result = 0;
    scanf("%d %d", &N, &K);
    for(int i = 0; i<N;i++){
        scanf("%d",&coin[i]);
    }
    j = N-1;
    while(K>0 && j>=0){
        if(K/coin[j] > 0){
            result += K/coin[j];
            K -= K/coin[j] * coin[j] ;
        }
        j--;
    }
    printf("%d\n",result);

    return 0;
}