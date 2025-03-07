#include <iostream>
#include <deque>
using namespace std;

int n, m;
int graph[201][201];
int plan[1000];
bool visited[201];

bool search(int start, int dest) {
    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    dq.push_back(start);
    visited[start] = true;

    while (!dq.empty()) {
        int cur = dq.front(); dq.pop_front();

        for (int i = 1; i <= n; i++) {
            if (graph[cur][i] == 0) {
                continue;
            }

            if (i == dest) {
                return true;
            }

            if (visited[i]) {
                continue;
            }

            dq.push_back(i);
            visited[i] = true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> plan[i];
    }

    for (int i = 0; i < m - 1; i++) {
        if (plan[i] == plan[i + 1]) {
            continue;
        }

        if (!search(plan[i], plan[i + 1])) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}