#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<string> split(string s, char delim) {
    stringstream ss(s);
    
    string token;
    vector<string> result;
    while (getline(ss, token, delim)) {
        result.push_back(token);
    }
    return result;
}

vector<string> solution(vector<string> record) {
    unordered_map<string, string> nicknames;
    vector<pair<string, string>> users;
    vector<string> answer;
    
    for (string r : record) {
        vector<string> sr = split(r, ' ');
        
        if (sr[0] == "Change") {
            nicknames[sr[1]] = sr[2];
            continue;
        }
        if (sr[0] == "Enter") {
            nicknames[sr[1]] = sr[2];
            users.push_back(pair<string, string> {sr[0], sr[1]});
            continue;
        }
        users.push_back(pair<string, string> {sr[0], sr[1]});
    }
    
    for (auto user : users) {
        if (user.first == "Enter") {
            answer.push_back(nicknames[user.second] + "님이 들어왔습니다.");
            continue;
        }
        answer.push_back(nicknames[user.second] + "님이 나갔습니다.");
    }
    return answer;
}