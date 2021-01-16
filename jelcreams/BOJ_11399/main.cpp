#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int main(){
    int n;
    int temp, sum = 0, result = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i<n ;i++){
        sum += v[i];
        result += sum;
    }
    printf("%d\n",result);
    return 0;
}