#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer {0, 0};
    map<string, int> m;
    
    m[words[0]] = 1;
    for (int i = 1; i < words.size(); i++) {
        if (words[i-1][words[i-1].size() - 1] != words[i][0]) {
            return vector<int> { i % n + 1, i / n + 1 };
        }
        
        if (m[words[i]] != 0) {
            return vector<int> { i % n + 1, i / n + 1 };
        }
        m[words[i]] = m[words[i]] + 1;
    }

    return answer;
}