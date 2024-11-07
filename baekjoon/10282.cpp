#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int tc;
int n, d, c;
int a, b, s;
vector<pair<int, int>> graph[10001];
int visited[10001];
const int MX = 2100000000;

pair<int, int> search(int start) {
    deque<int> dq;
    dq.push_back(start);
    for (int i = 1; i <= n; i++) {
        visited[i] = MX;
    }
    visited[start] = 0;

    int count = 1;
    while (!dq.empty()) {
        int cur = dq.front(); dq.pop_front();

        for (auto next : graph[cur]) {
            if (visited[next.first] > visited[cur] + next.second) {
                dq.push_back(next.first);
                if (visited[next.first] == MX) {
                    count++;
                }
                visited[next.first] = visited[cur] + next.second;
            }
        }
    }
    int time = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i] != MX) {
            time = max(time, visited[i]);
        }
    }
    return {count, time};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> tc;

    for (int t = 0; t < tc; t++) {
        cin >> n >> d >> c;
        for (int i = 1; i <= n; i++) {
            graph[i].clear();
        }
        for (int i = 0; i < d; i++) {
            cin >> a >> b >> s;
            graph[b].push_back({a, s});
        }
        auto result = search(c);
        cout << result.first << ' ' << result.second << '\n';
    }

    return 0;
}