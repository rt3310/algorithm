#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(int k, vector<int> tangerine) {
    map<int, int> count;
    int answer = 0;
    for (int t : tangerine) {
        count[t] = count[t] + 1;
    }

    priority_queue<int> pq;
    for (auto it = count.begin(); it != count.end(); it++) {
        pq.push(it->second);
    }

    int total = 0;
    while (!pq.empty()) {
        if (total >= k) {
            return answer;
        }
        total += pq.top();
        pq.pop();
        answer++;
    }

    return answer;
}