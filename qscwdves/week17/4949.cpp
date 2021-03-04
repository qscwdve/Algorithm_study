#include <stdio.h>
#include <stack>
#include <string>
#include <iostream>
using namespace std;
#pragma warning(disable:4996) 

int main() {
    while (1) {
        string str;
        stack<char> bracket;
       
        getline(cin, str);          
        if (str[0] == '.') break;    

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') bracket.push(')');
            else if (str[i] == '[') bracket.push(']');          
            else if (str[i] == ')' || str[i] == ']') {
                if (bracket.empty() || bracket.top() != str[i]) {
                    bracket.push('n');
                    break;
                }
                bracket.pop();
            }
        }
       
        if (!bracket.empty()) printf("no\n");
        else printf("yes\n");
    }
  
    return 0;
}