#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
vector<char> v;
//<> 60 62
int oneToTen[11];
void solution(int length, bool rev);
bool possible(int a, int b, char v);
void swap(int* a, int *b);
int main(){
    int N;
    char temp;
    scanf("%d", &N);
    for(int i = 0; i<N;i++){
        scanf(" %c", &temp);
        v.push_back(temp);
    }
    solution(N, false);
    solution(N, true);
    return 0;
}

bool possible(int a, int b, char v){
    switch(v){
        case '<':
            return a < b;
        case '>':
            return a > b;
    }
    return false;
}

void swap(int * a, int * b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void solution(int length, bool rev){
    int start = 0;
    int result[11] = {0};
    int check = 1 , x = 0;
    memset(result, 0, sizeof(result));
    if(rev){
        for(int i = 0 ; i <= length; i++){
            result[i] = i;
            oneToTen[i] = i;
        }
    }
    else{
        for(int i = 0 ; i <= length; i++){
            result[i] = 9-i;
            oneToTen[i] = 9-i;
        }
    }

    while(x < check){
        if(start >=length){
            start = 0;
            x++;
        }
        if(!possible(result[start], result[start+1], v[start])){
            //유효한 식이 아니라면..
            check = x+2;
            swap(result+start, result + start+ 1);
        }
        start++;
    }
    for(int m = 0; m <=length; m++){
        printf("%d",result[m]);
    }
    printf("\n");
}