#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
bool compare(int a, int b){
    return a > b;
}
int main(){
    int N, temp;
    int k = 0, result = 0;//k는 선택한 밧줄 개수, result는 가장 큰 무게
    int result2 = 0;// 모든 밧줄을 선택하고 나온 큰 무게
    int before;// 선택한 밧줄중 최소 무게
    scanf("%d", &N);
    for(int i =0;i<N;i++){
        scanf("%d",&temp);
        v.push_back(temp);
    }

    stable_sort(v.begin(),v.end(),compare);

    before = 0;
    k++;
    result = v[before];

    for(int i = 1; i < v.size(); i++){
        if(v[i] * (k + 1) >= result){
            k++;
            before = i;
            result = v[i] * k;
        }
        if(v[i] * (i+1) >= result2){
            result2 = v[i]*(i+1);
        }
    }
    printf("%d\n",result < result2 ? result2 : result);
    return 0;
}