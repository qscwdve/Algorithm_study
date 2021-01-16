#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define DMAX  4000001
//연속된 소수의 합으로 나타낼 수 있는 자연수

//입력 값까지의 소수들을 구한다.
//구한 소수들을 길이를 이용하여 합을 구하고 슬라이드하여 합을 구하고 비교한다.

using namespace std;

//prime number
char prime[4000001];
vector<int> v;
//setting prime
void Eratos();

int main(){
    int dest;
    int result, length;
    int start, end;
    int sum = 0;
    int count = 0;
    sum = 0;
    start = 0;
    end = 0;
    result = 0;
    v.clear();
    
    scanf("%d", &dest);

    Eratos();

    length = v.size();
    while(end <= length && v[end] <= dest){
        printf("start %d, end %d, dest %d, sum %d\n", start, end, dest, sum);
        if(sum < dest){
            sum += v[end++];
            continue;
        }
        else if(sum == dest){
            result++;
        }
        else{
            sum -= v[start++];    
        }
        
    }
    printf("%d\n",  result);
    return 0;
}

void Eratos(){
    prime[0] = 1;
    prime[1] = 1;
    for(int i = 2; i <= DMAX; i++){
        if(prime[i] == 1){
            continue;
        }
        v.push_back(i);
        for(int j = i + i; j <= DMAX; j+=i){
            prime[j] = 1;
        }
    }
}