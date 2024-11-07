#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> tree[10001];
int weight[10001];
bool visited[10001];

int dp[10001][2]; // 1: 선택, 0: 비선택

vector<int> path[10001][2];

void search(int cur) {
    visited[cur] = true;
    dp[cur][1] = weight[cur];
    path[cur][1].push_back(cur);

    for (int child : tree[cur]) {
        if (visited[child]) {
            continue;
        }
        search(child);
        dp[cur][1] += dp[child][0];
        dp[cur][0] += max(dp[child][1], dp[child][0]);
        for (int c : path[child][0]) {
            path[cur][1].push_back(c);
        }
        if (dp[child][1] > dp[child][0]) {
            for (int c : path[child][1]) {
                path[cur][0].push_back(c);
            }
        } else {
            for (int c : path[child][0]) {
                path[cur][0].push_back(c);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    search(1);

    cout << max(dp[1][0], dp[1][1]) << '\n';
    if (dp[1][1] > dp[1][0]) {
        sort(path[1][1].begin(), path[1][1].end());
        for (int p : path[1][1]) {
            cout << p << ' ';
        }
    } else {
        sort(path[1][0].begin(), path[1][0].end());
        for (int p : path[1][0]) {
            cout << p << ' ';
        }
    }

    return 0;
}