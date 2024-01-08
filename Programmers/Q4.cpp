#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(string s) {
    int stack = 0;
    
    for (char c: s) {
        if (c == '(') {
            stack++;
            continue;
        }
        
        if (stack == 0) {
            return false;
        }
        stack--;
    }

    return stack == 0;
}