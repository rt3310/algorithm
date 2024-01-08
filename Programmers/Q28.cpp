#include <algorithm>
#include <deque>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<int> dq(priorities.begin(), priorities.end());

    sort(priorities.rbegin(), priorities.rend());
    int most = 0;

    int curLocation = location;
    while (true) {
        int cur = dq.front();
        dq.pop_front();

        if (cur < priorities[most]) {
            dq.push_back(cur);
            curLocation = curLocation == 0 ? dq.size() - 1 : curLocation - 1;
            continue;
        }
        most++;
        answer++;
        if (curLocation == 0) {
            break;
        }
        curLocation = curLocation == 0 ? dq.size() - 1 : curLocation - 1;
    }

    return answer;
}