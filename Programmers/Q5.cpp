#include <iostream>
#include <string>
#include <vector>
using namespace std;

string toBinary(string prev, int& deleted) {
    string x = "";
    for (char c: prev) {
        if (c == '1') {
            x += c;
            continue;
        }
        deleted++;
    }
    
    long long n = x.size();
    string result = "";
    while (n >= 1) {
        result = to_string(n % 2) + result;
        n /= 2;
    }
    
    return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int count = 0;
    int deleted = 0; 
    while (s != "1") {
        s = toBinary(s, deleted);
        count++;
    }
    
    answer.push_back(count);
    answer.push_back(deleted);
    return answer;
}