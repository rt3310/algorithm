#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

int m, n, h;
int box[101][101][101];
int times[101][101][101];
deque<vector<int>> dq;
int d[6][3] = {{0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {0, 0, -1}, {0, -1, 0}, {-1, 0, 0}};

int bfs() {

    while (!dq.empty()) {
        vector<int> cur = dq.front();
        dq.pop_front();

        for (int i = 0; i < 6; i++) {
            int v = cur[0] + d[i][0];
            int r = cur[1] + d[i][1];
            int c = cur[2] + d[i][2];

            if (v < 0 || v >= h || r < 0 || r >= n || c < 0 || c >= m) {
                continue;
            }

            if (box[v][r][c] == 0) {
                dq.push_back(vector<int> {v, r, c});
                times[v][r][c] = times[cur[0]][cur[1]][cur[2]] + 1;
                box[v][r][c] = 1;
            }
        }
    }

    int maxTime = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (box[i][j][k] == 0) {
                    return -1;
                }
                maxTime = max(maxTime, times[i][j][k]);
            }
        }
    }

    return maxTime;
}

int main() {
    scanf("%d %d %d", &m, &n, &h);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                scanf("%d", &box[i][j][k]);

                if (box[i][j][k] == 1) {
                    dq.push_back(vector<int> {i, j, k});
                }
            }
        }
    }

    printf("%d", bfs());

    return 0;
}