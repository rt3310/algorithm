#include <iostream>
#include <deque>
using namespace std;

int n, k, r;
int land[101][101];
int cows[101][2];
char path[101][101];
char visited[101][101];
constexpr int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
constexpr int U = 1, D = 2, L = 3, R = 4;
int order = 1;
int result = 0;

void search() {
    deque<pair<int, int>> dq;
    dq.push_back({cows[order][0], cows[order][1]});
    visited[cows[order][0]][cows[order][1]] = order;
    land[cows[order][0]][cows[order][1]] = 0;

    int meet = 0;
    while (!dq.empty()) {
        auto cur = dq.front(); dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nr = cur.first + d[i][0];
            int nc = cur.second + d[i][1];

            if (nr < 1 || nr > n || nc < 1 || nc > n) {
                continue;
            }

            if (visited[nr][nc] == order) {
                continue;
            }

            if (path[cur.first][cur.second] & (1 << (i + 1))) {
                continue;
            }

            if (land[nr][nc] != 0) {
                meet++;
            }
            visited[nr][nc] = order;
            dq.push_back({nr, nc});
        }
    }

    result += (k - meet - order);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> r;

    for (int i = 0; i < r; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 == r2) {
            if (c1 < c2) {
                path[r1][c1] |= (1 << R);
                path[r2][c2] |= (1 << L);
            } else {
                path[r1][c1] |= (1 << L);
                path[r2][c2] |= (1 << R);
            }
            continue;
        }

        if (r1 < r2) {
            path[r1][c1] |= (1 << D);
            path[r2][c2] |= (1 << U);
        } else {
            path[r1][c1] |= (1 << U);
            path[r2][c2] |= (1 << D);
        }
    }

    for (int i = 1; i <= k; i++) {
        cin >> cows[i][0] >> cows[i][1];
        land[cows[i][0]][cows[i][1]] = i;
    }

    for (int i = 1; i <= k; i++) {
        search();
        order++;
    }

    cout << result;

    return 0;
}