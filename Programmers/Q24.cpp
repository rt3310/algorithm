#include <algorithm>
#include <deque>
#include <string>
#include <vector>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> dq;

    for (string city : cities) {
        if (cacheSize == 0) {
            answer += 5;
            continue;
        }
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        auto it = find(dq.begin(), dq.end(), city);
        if (it != dq.end()) {
            dq.erase(it);
            dq.push_back(city);
            answer++;
            continue;
        }
        if (dq.size() >= cacheSize) {
            dq.pop_front();
        }
        dq.push_back(city);
        answer += 5;
    }

    return answer;
}