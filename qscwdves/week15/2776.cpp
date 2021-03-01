#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning(disable:4996) 
int look[1000000] = { 0 }, question[1000000] = { 0 };
int main() {
    int T, note1, note2;

    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d", &note1);
        for (int i = 0; i < note1; i++) {
            scanf("%d", &(look[i]));
        }
        scanf("%d", &note2);
        for (int i = 0; i < note2; i++) {
            scanf("%d", &(question[i]));
        }

        sort(look, look + note1); 
       
        for (int i = 0; i < note2; i++) {
            int middle = note1 / 2, left = 0, right = note1 - 1, flag = 0;
     
            while (left <= right) {
                if (look[middle] == question[i]) {
                    printf("1\n");
                    flag = 1;
                    break;
                }
                else {
                    if (look[middle] < question[i]) left = middle + 1;
                    else right = middle - 1;
                    middle = (left + right) / 2;
                }
            }
            if(flag == 0) printf("0\n");
        }
        
    }
    return 0;
}