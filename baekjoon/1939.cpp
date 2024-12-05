#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

int n, m;
int i1, i2;
vector<pair<int, int>> bridge[10001];
int weights[10001];
constexpr int MX = 2100000000;
int maxWeight = 0;

int search() {
    priority_queue<pair<int, int>> pq;
    pq.push({MX, i1});
    weights[i1] = MX;

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if (cur.first < weights[cur.second]) {
            continue;
        }

        for (auto next : bridge[cur.second]) {
            int nextWeight = min(cur.first, next.second);
            if (nextWeight > weights[next.first]) {
                weights[next.first] = nextWeight;
                pq.push({nextWeight, next.first});
            }
        }
    }

    return weights[i2];
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

    cin >> i1 >> i2;

    cout << search();
    
    return 0;
}