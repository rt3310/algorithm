#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n;
vector<int> graph[501];
int inDegree[501];
int time[501];
int frontTime[501];
int totalTime[501];

void search() {
    deque<int> dq;

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            dq.push_back(i);
            totalTime[i] = time[i];
        }
    }

    while (!dq.empty()) {
        int cur = dq.front(); dq.pop_front();

        for (int next : graph[cur]) {
            inDegree[next]--;
            if (inDegree[next] == 0) {
                dq.push_back(next);
                totalTime[next] = max(frontTime[next], totalTime[cur]) + time[next];
            } else {
                frontTime[next] = max(frontTime[next], totalTime[cur]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> time[i];

        while (true) {
            int f;
            cin >> f;
            if (f == -1) {
                break;
            }

            graph[f].push_back(i);
            inDegree[i]++;
        }
    }

    search();

    for (int i = 1; i <= n; i++) {
        cout << totalTime[i] << '\n';
    }

    return 0;
}