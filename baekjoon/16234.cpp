#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int n, l, r;
int land[50][50];
char border[50][50]; // up: 1, down: 2, left: 3, right: 4
int visited[50][50];
int day = 1;
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void search(pair<int, int> start) {
    deque<pair<int, int>> dq;
    vector<pair<int, int>> v;
    dq.push_back(start);
    v.push_back(start);
    visited[start.first][start.second] = day;

    int total = land[start.first][start.second];
    int count = 1;
    while (!dq.empty()) {
        auto cur = dq.front(); dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nr = cur.first + d[i][0];
            int nc = cur.second + d[i][1];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                continue;
            }

            if (!(border[cur.first][cur.second] & (1 << i))) {
                continue;
            }

            if (visited[nr][nc] == day) {
                continue;
            }

            dq.push_back({nr, nc});
            v.push_back({nr, nc});
            total += land[nr][nc];
            count++;
            visited[nr][nc] = day;
        }
    }

    for (auto p : v) {
        land[p.first][p.second] = total / count;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> land[i][j];
        }
    }

    while (true) {
        bool opened = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j < n - 1) {
                    int rightGap = abs(land[i][j] - land[i][j + 1]);
                    if (rightGap >= l && rightGap <= r) {
                        border[i][j] |= (1 << 3);
                        border[i][j + 1] |= (1 << 2);
                        opened = true;
                    }
                }

                if (i < n - 1) {
                    int downGap = abs(land[i][j] - land[i + 1][j]);
                    if (downGap >= l && downGap <= r) {
                        border[i][j] |= (1 << 1);
                        border[i + 1][j] |= (1 << 0);
                        opened = true;
                    }
                }
            }
        }

        if (!opened) {
            break;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] != day && border[i][j] != 0) {
                    search({i, j});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                border[i][j] = 0;
            }
        }

        day++;
    }

    cout << day - 1;

    return 0;
}