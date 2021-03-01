#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning(disable:4996) 
typedef struct student {
    int y;
    int m;
    int d;
    char name[15] = {0};
}Student;
bool compare(Student a, Student b) {
    if (a.y == b.y) {   
        if (a.m == b.m) {
            return a.d < b.d;
        }
        else return a.m < b.m;
    }
    else {
        if (a.y >= 90) {
            if (b.y >= 90) return a.y < b.y;
            else return true;
        }
        else {
            if (b.y >= 90) return false;
            else return a.y < b.y;
        }
    }
}
int main() {
    int T, k;
    vector<Student> list;
    Student temp;
    char ch;
 
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%c", &ch);
        for (k = 0; k < 15; k++) {
            scanf("%c", &ch);
            if (ch == ' ') break;
            temp.name[k] = ch;
        }
        temp.name[k] = '\0';
        scanf("%d %d %d", &temp.d, &temp.m, &temp.y);
        temp.y = temp.y % 100;
        list.push_back(temp);
    }
    sort(list.begin(), list.end(), compare);
    printf("%s\n%s", list[T-1].name, list[0].name);
    return 0;
}
​