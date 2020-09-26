#include <iostream>

using namespace std;

int group_checker(char arr[]){
    int i = 0;
    int check_char[26] = {0,};
    while(arr[i] != 0){
        if(check_char[arr[i]%26]>0 && i>0 && arr[i] != arr[i-1]) return 0;
        check_char[arr[i]%26]++;
        i++;
    }

    return 1; 
}
int main(){
    int number;
    char array[100] = {0,};
    int result = 0;
    scanf("%d", &number);
    while(number--){
        scanf("%s",array);
        result += group_checker(array);
    }
    printf("%d\n",result);
    return 0;
}
