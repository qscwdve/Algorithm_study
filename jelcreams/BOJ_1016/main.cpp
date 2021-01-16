#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#define MM 1000002

using namespace std;
void solution(long long, long long);
bool memo[MM];

int main(){
    long long min, max;
    scanf("%lld %lld",&min, &max);
    solution(min, max);
    return 0;
}

void solution(long long min, long long max){
    int result = 0;
    long long temp = min/(4);
    long long i = 2;
    while((i*i) <= max){
        temp = min/(i*i);
        if(min%(i*i) != 0){
            temp+=1;
        }
        for(long long j = temp; j * (i*i) <= max; j++){
            memo[j*(i*i) - min] = true;
        }
        i++;
    }

    for(int k = 0 ; k <= max-min;k++){
        if(!memo[k])result++;
    }
    printf("%d\n", result);
}


