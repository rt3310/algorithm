#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>
#include <cmath>
using namespace std;

vector<string> split(string s, char delim) {
    vector<string> result;
    stringstream ss(s);
    
    string buf;
    while(getline(ss, buf, delim)) {
        result.push_back(buf);
    }
    
    return result;
}

int calcGapTimes(string startTime, string endTime) {
    int start = stoi(startTime.substr(0, 2)) * 60 + stoi(startTime.substr(3, 2));
    int end = stoi(endTime.substr(0, 2)) * 60 + stoi(endTime.substr(3, 2));
    
    return end - start;
}

// 기본 시간, 기본 요금, 단위 시간, 단위 요금
vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, int> total;
    unordered_map<string, string> enterTimes;
    unordered_map<string, bool> enters;
    vector<int> answer;
    int baseTime = fees[0];
    int baseFee = fees[1];
    int perTime = fees[2];
    int perFee = fees[3];
    
    for (string record: records) {
        vector<string> vRecord = split(record, ' ');
        if (vRecord[2] == "OUT") {
            total[vRecord[1]] += calcGapTimes(enterTimes[vRecord[1]], vRecord[0]);
            enters[vRecord[1]] = false;
            continue;
        }
        enterTimes[vRecord[1]] = vRecord[0];
        enters[vRecord[1]] = true;
    }
    
    for (pair<string, bool> entry: enters) {
        if (entry.second) {
            total[entry.first] += calcGapTimes(enterTimes[entry.first], "23:59");
        }
    }
    
    for (pair<string, int> entry: total) {
        if (entry.second < baseTime) {
            answer.push_back(baseFee);
            continue;
        }
        answer.push_back(baseFee + (ceil((double) (entry.second - baseTime) / perTime) * perFee));
    }
    return answer;
}