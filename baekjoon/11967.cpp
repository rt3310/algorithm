#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, m;
vector<pair<int, int>> light[101][101];
int visit[101][101]; // 1: canOn, 2: on, 3: visit, 4: offVisit
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int search() {
    deque<pair<int, int>> dq;
    visit[1][1] = 2;
    dq.push_back({1, 1});

    while (!dq.empty()) {
        auto cur = dq.front(); dq.pop_front();

        for (auto on : light[cur.first][cur.second]) {
            if (visit[on.first][on.second] == 1) {
                visit[on.first][on.second] = 2;
            } else if (visit[on.first][on.second] == 4) {
                dq.push_back({on.first, on.second});
                visit[on.first][on.second] = 3;
            }
        }

        for (const int* d : dir) {
            int r = cur.first + d[0];
            int c = cur.second + d[1];

            if (r < 1 || r > n || c < 1 || c > n) {
                continue;
            }

            if (visit[r][c] == 0 || visit[r][c] == 3) {
                continue;
            }

            if (visit[r][c] == 1) {
                visit[r][c] = 4;
            } else if (visit[r][c] == 2) {
                dq.push_back({r, c});
                visit[r][c] = 3;
            }
        }
    }

    int onCount = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (visit[i][j] == 2 || visit[i][j] == 3) {
                onCount++;
            }
        }
    }

    return onCount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        light[x][y].push_back({a, b});
        visit[a][b] = 1;
    }

    cout << search();

    return 0;
}