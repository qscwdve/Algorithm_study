#include <iostream>
#include <algorithm>
#include <cmath>

//연속된 소수의 합으로 나타낼 수 있는 자연수

//prime numbers
int prime[4000000];
//setting prime
int makePrime(int, int);
int setPrime(int);
int listSum(int, int);


int main(){
    int dest;
    int result, length;
    int temp = 0;
    
    scanf("%d", &dest);

    length = setPrime(dest);
    temp = length;
    while(temp-- > 0){
        for(int i = 0; i+temp < length; i++){
            if(dest == listSum(i, i+temp)){
                result++;
            }
        }
    }
    printf("%d", result);
    return 0;
}
int setPrime(int n){
    int length = 0;
    //printf("setPrime %d \n", n);
    if(n<2) return 0;

    for(int i = 2 ; i <= n; i++){
        length = makePrime(i,length);
    }

    return length;
}

int makePrime(int n, int length){
    //printf("make prime %d %d \n", n , length);
    if(n < 2);
    else if(n == 2){
        prime[length++] = 2;
    }
    else{
        for(int i = 2 ; i <= sqrt(n); i++){
            if(n%i == 0) return length;// not prime
        }
        prime[length++] = n; // is prime
        //printf("%d \n",n);
    }
    return length;
}

int listSum(int start, int end){
    //printf("List sum %d %d\n",prime[start], prime[end]);
    //printf("start: %d, end: %d\n", start, end);
    int sum = 0;
    for(int i = start; i <= end ; i++){
        sum+= prime[i];
    }
    return sum;
}