#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

int result = 51;
string target;

void dfs(string cur, vector<string>& words, vector<bool>& visited, int depth) {
    if (cur == target) {
        result = min(result, depth);
        return;
    }
    
    for (int i = 0; i < words.size(); i++) {
        if (visited[i]) {
            continue;
        }
        int diff = 0;
        for (int j = 0; j < cur.size(); j++) {
            if (cur[j] != words[i][j]) {
                diff++;
                if (diff >= 2) {
                    break;
                }
            }
        }
        if (diff >= 2) {
            continue;
        }
        visited[i] = true;
        dfs(words[i], words, visited, depth + 1);
        visited[i] = false;
    }
}

int solution(string begin, string target, vector<string> words) {
    ::target = target;
    vector<bool> visited(words.size(), false);
    
    dfs(begin, words, visited, 0);
    
    return result == 51 ? 0 : result;
}