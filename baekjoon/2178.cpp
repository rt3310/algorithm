#include <cstdio>
#include <deque>
#include <string>
#include <vector>
using namespace std;

int n, m;
int map[101][101];
int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int bfs() {
    deque<pair<int, int>> dq;
    int visited[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }
    dq.push_back({0, 0});
    visited[0][0] = 1;

    while (!dq.empty()) {
        pair<int, int> cur = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int r = cur.first + d[i][0];
            int c = cur.second + d[i][1];

            if (r < 0 || r >= n || c < 0 || c >= m) {
                continue;
            }

            if (map[r][c] == 0) {
                continue;
            }

            if (visited[r][c] != 0) {
                continue;
            }

            if (r == n - 1 && c == m - 1) {
                return visited[cur.first][cur.second] + 1;
            }

            dq.push_back({r, c});
            visited[r][c] = visited[cur.first][cur.second] + 1;
        }
    }
    
    return 1;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    printf("%d", bfs());

    return 0;
}