#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char, bool> m;
    int skillCount = skill.size();
    for (char s : skill) {
        m[s] = true;
    }
    
    string s = "a";
    
    for (string tree : skill_trees) {
        int order = 0;
        bool valid = true;
        for (char t : tree) {
            if (t == skill[order]) {
                order++;
                continue;
            }
            if (order >= skillCount) {
                valid = true;
                break;
            }
            if (m[t]) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            answer++;
        }
    }
    return answer;
}