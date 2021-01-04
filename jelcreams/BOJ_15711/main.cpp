#include <iostream>
#include <cmath>
#include <vector>
#define MM 2000001

using namespace std;
char prime[MM];
vector<int> v;

void setPrime();
bool checkPrime(long long);
bool solution(long long, long long);

int main(){
    int temp;
    long long first, second;
    setPrime();
    scanf("%d", &temp);
    while(temp-->0){
        scanf("%lld %lld",&first, &second);
        if(solution(first, second)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

void setPrime(){
    for(int i = 2; i < MM; i++){
        if(prime[i]==0){
            v.push_back(i);
            for(int j = i+i; j< MM; j+=i){
                prime[j] = 1;
            }
        }
    }
}

bool checkPrime(long long num){
    if(num<MM){
        return !prime[num];
    }
    for(int i = 0; i < v.size() && v[i] * v[i] <= num; i++){
        if(num%v[i]==0) return false;
    }
    return true;
}

bool solution(long long first, long long second){
    long long sum = first+second;
    if(sum<4)return false;
    if(sum%2==0)return true;
    if(checkPrime(sum-2)) return true;
    return false;
}