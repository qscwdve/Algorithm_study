#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef struct node{
    char name[11];
    int korean;
    int english;
    int math;
} Node;

vector<Node> v;
bool compare(Node a, Node b){
    if(a.korean == b.korean){
        if(a.english == b.english){
            if(a.math == b.math){
                return strcmp(a.name, b.name) > 0 ? false : true;
            }
            else{
                return a.math > b.math;
            }
        }
        else{
            return a.english < b.english;
        }
    }
    else{
        return a.korean > b.korean;
    }
}


int main(){
    char temp[11];
    int kor, eng, ma;
    int n;
    Node student;
    scanf("%d",&n);
    for(int i = 0; i< n; i++){
        scanf("%s %d %d %d",temp, &kor, &eng, &ma);
        strcpy(student.name, temp);
        student.korean = kor;
        student.english = eng;
        student.math = ma;
        v.push_back(student);
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i< n; i++){
        printf("%s\n",v[i].name);
    }
    return 0;
}