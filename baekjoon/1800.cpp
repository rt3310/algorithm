#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, p, k;
vector<pair<int, int>> edges[1001];
int visited[1001];
constexpr int MX = 1000000;

int search(int stand) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i <= n; i++) {
        visited[i] = MX;
    }
    pq.push({0, 1});
    visited[1] = 0;

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int skip = cur.first;
        int curV = cur.second;

        if (skip > visited[curV]) {
            continue;
        }

        for (auto next : edges[curV]) {
            int nextV = next.first;
            int nextPrice = next.second;

            if (nextPrice > stand) {
                if (skip + 1 < visited[nextV]) {
                    pq.push({skip + 1, nextV});
                    visited[nextV] = skip + 1;
                }
                continue;
            }

            if (skip < visited[nextV]) {
                pq.push({skip, nextV});
                visited[nextV] = skip;
            }
        }
    }

    return visited[n] <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> p >> k;
    for (int i = 0; i < p; i++) {
        int a, b, price;
        cin >> a >> b >> price;
        edges[a].push_back({b, price});
        edges[b].push_back({a, price});
    }

    int left = 0;
    int right = MX;
    while (left < right) {
        int mid = (left + right) / 2;

        if (search(mid)) {
            right = mid;
            continue;
        }

        left = mid + 1;
    }

    cout << (right == MX ? -1 : right);

    return 0;
}