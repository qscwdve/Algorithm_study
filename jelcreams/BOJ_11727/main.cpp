#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    vector<int> array;
    array.push_back(0);
    array.push_back(1);
    array.push_back(3);
    scanf("%d", &n);
    for(int i = 3; i<=n;i++){
        array.push_back((array[i-1] + array[i-2]*2)%10007);
    }
    printf("%d\n",array[n]);
    return 0;
}