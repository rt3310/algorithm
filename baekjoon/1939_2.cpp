#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, m;
int start, finish;
vector<pair<int, int>> bridge[10001];
bool visited[10001];

bool search(int cost) {
    deque<int> dq;
    dq.push_back(start);
    for (int i = 0; i <= n; i++) {
        visited[i] = false;
    }
    visited[start] = true;

    while (!dq.empty()) {
        int cur = dq.front(); dq.pop_front();

        for (auto next : bridge[cur]) {
            if (visited[next.first]) {
                continue;
            }

            if (cost <= next.second) {
                if (next.first == finish) {
                    return true;
                }
                visited[next.first] = true;
                dq.push_back(next.first);
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        bridge[a].push_back({b, c});
        bridge[b].push_back({a, c});
    }

    cin >> start >> finish;

    int left = 0;
    int right = 1000000000;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (search(mid)) {
            left = mid + 1;
            continue;
        }
        right = mid - 1;
    }

    cout << right;

    return 0;
}