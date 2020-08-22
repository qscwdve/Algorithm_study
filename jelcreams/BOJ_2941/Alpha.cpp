#include <iostream>

using namespace std;

int find_alpa(char array[]){
    int number=0;

    for(int i = 0; array[i]!= 0;i++){
        number++;
        if(array[i]=='='){
            if(i>1&& array[i-2] == 'd'&&array[i-1]=='z')number-=2;
            else if(i>0&& array[i-1] == 'c'||array[i-1]=='z'||array[i-1]=='s')number--;
        }
        else if(array[i]=='-'){
            if(i>0&&array[i-1]=='c'||array[i-1]=='d')number--;
        }
        else if(array[i]=='j'){
            if(i>0&&array[i-1]=='l'||array[i-1]=='n')number--;
        }
    }
    return number;
}

int main(){
    char array[101];
    scanf("%s",array);
    printf("%d", find_alpa(array));

}
