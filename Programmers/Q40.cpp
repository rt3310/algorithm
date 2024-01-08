#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<int, string> match;

void initMatch() {
    for (int i = 0; i < 10; i++) {
        match[i] = to_string(i);
    }
    match[10] = "A";
    match[11] = "B";
    match[12] = "C";
    match[13] = "D";
    match[14] = "E";
    match[15] = "F";
}

string calcArithmetic(int n, int number) {
    string result = "";
    if (number == 0) {
        return "0";
    }
    while (number > 0) {
        result = match[number % n] + result;
        number /= n;
    }
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    initMatch();
    
    int count = 0;
    int num = 0;
    vector<char> nums;
    while (nums.size() < t) {
        string transform = calcArithmetic(n, num);
        for (char arith: transform) {
            if (count % m + 1 == p) {
                nums.push_back(arith);
            }
            count++;
            if (nums.size() >= t) {
                break;
            }
        }
        num++;
    }
    
    for (char n: nums) {
        answer += n;
    }
    return answer;
}