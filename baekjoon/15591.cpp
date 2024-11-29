#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, q;
int usado[5001][5001];
vector<int> graph[5001];
bool visited[5001];
const int MX = 2100000000;

void renew(int start) {
    deque<pair<int, int>> dq;
    dq.push_back({start, MX});
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    visited[start] = true;

    while (!dq.empty()) {
        auto cur = dq.front(); dq.pop_front();

        for (int next : graph[cur.first]) {
            if (visited[next]) {
                continue;
            }
            
            visited[next] = true;
            usado[start][next] = min(usado[cur.first][next], cur.second);
            dq.push_back({next, usado[start][next]});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        graph[p].push_back(q);
        graph[q].push_back(p);
        usado[p][q] = r;
        usado[q][p] = r;
    }

    for (int i = 1; i <= n; i++) {
        renew(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << usado[i][j] << ' ';
        }
        cout << '\n';
    }


    for (int i = 0; i < q; i++) {
        int k, v;
        cin >> k >> v;
        int total = 0;
        for (int j = 1; j <= n; j++) {
            if (j == v) {
                continue;
            }
            if (usado[v][j] >= k) {
                total++;
            }
        }
        cout << total << '\n';
    }

    return 0;
}