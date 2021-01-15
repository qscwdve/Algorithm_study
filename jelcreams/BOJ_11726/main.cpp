#include <iostream>

using namespace std;

int array[1001];

int main(){
    int n;
    scanf("%d", &n);
    array[1] = 1;
    array[2] = 2;
    for(int i = 3; i <= n; i++){
        array[i] = (array[i-1] + array[i-2])%10007;
    }
    printf("%d\n", array[n]);
    return 0;
}