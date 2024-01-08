#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int size = s.size();
    bool first = true;
    for (int i = 0; i < size; i++) {
        if (s[i] == ' ') {
            first = true;
            answer += s[i];
            continue;
        }
        
        if (first) {
            first = false;
            answer += toupper(s[i]);
            continue;
        }
        answer += tolower(s[i]);
    }
    return answer;
}