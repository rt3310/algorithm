#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int d[6][3] = {{0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {0, 0, -1}, {0, -1, 0}, {-1, 0, 0}};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int l, r, c;
        cin >> l >> r >> c;
        if (l == 0) {
            return 0;
        }

        deque<vector<int>> dq;

        char map[l][r][c];
        int visited[l][r][c];
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    cin >> map[i][j][k];
                    visited[i][j][k] = 99999;
                    if (map[i][j][k] == 'S') {
                        dq.push_back(vector<int> {i, j, k});
                        visited[i][j][k] = 1;
                    }
                }
            }
        }

        bool escaped = false;
        while (!dq.empty() && !escaped) {
            vector<int> cur = dq.front();
            dq.pop_front();

            for (int i = 0; i < 6; i++) {
                int nh = cur[0] + d[i][0];
                int nr = cur[1] + d[i][1];
                int nc = cur[2] + d[i][2];

                if (nh < 0 || nh >= l || nr < 0 || nr >= r || nc < 0 || nc >= c) {
                    continue;
                }

                if (map[nh][nr][nc] == '#') {
                    continue;
                }

                if (visited[nh][nr][nc] > visited[cur[0]][cur[1]][cur[2]] + 1) {
                    if (map[nh][nr][nc] == 'E') {
                        escaped = true;
                        cout << "Escaped in " << visited[cur[0]][cur[1]][cur[2]] << " minute(s).\n";
                        break;
                    }
                    dq.push_back(vector<int> {nh, nr, nc});
                    visited[nh][nr][nc] = visited[cur[0]][cur[1]][cur[2]] + 1;
                }
            }
        }
        if (!escaped) {
            cout << "Trapped!\n";
        }
    }

    return 0;
}