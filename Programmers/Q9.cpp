#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = -1;
    vector<int> check {-1};

    int index = 0;
    while (index < s.size()) {
        if (check.back() >= 0 && s[check.back()] == s[index]) {
            check.pop_back();
        } else {
            check.push_back(index);
        }
        index++;
    }
    
    return check.back() == -1;
}