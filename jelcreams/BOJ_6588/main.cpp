#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int prime_numbers[1000001];

void setPrime();
void solution(int);

int main(){
    int temp = -1;
    int dest;
    setPrime();
    while(true){
        scanf("%d", &dest);
        if(dest<=4)break;
        solution(dest);

    }
    return 0;
}
void setPrime(){
    prime_numbers[0] = 1;
    prime_numbers[1] = 1;
    int sqr = (int)sqrt(1000000);
    for(int i = 2; i <= sqr; i++){
        if(prime_numbers[i]==0){
            //printf("%d ", i);
            for(int j = i+i; j<=1000000;j+=i){
                prime_numbers[j] = 1;
            }
        }
    }
}
void solution(int num){
    for(int  i = 3; i <= num/2 ; i+=2){
        if(!prime_numbers[i] && !prime_numbers[num - i]){
            printf("%d = %d + %d\n", num, i, num-i);
            return;
        }
    }
    printf("Goldbach's conjecture is wrong.\n");
    
}