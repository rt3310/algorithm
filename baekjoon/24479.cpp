#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r;
vector<int> graph[100001];
int result[100001];
int order = 1;

void dfs(int cur) {
    result[cur] = order++;

    for (int next : graph[cur]) {
        if (result[next] != 0) {
            continue;
        }

        dfs(next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> r;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(r);

    for (int i = 1; i <= n; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}