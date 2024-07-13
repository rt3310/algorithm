#include <cstdio>
#include <vector>
#include <deque>
#include <tuple>
using namespace std;

int n, m, k;
int map[1001][1001];
int visited[1001][1001][11];
int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const int MX = 2100000000;

int search() {
    deque<tuple<int, int, int, int, int>> dq; // 0:낮, 1:밤
    dq.push_back({0, 0, k, 0, 0});
    visited[0][0][0] = 1;

    while (!dq.empty()) {
        int curr, curc, curw, curt, stand;
        tie(curr, curc, curw, curt, stand) = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int r = curr + d[i][0];
            int c = curc + d[i][1];

            if (r < 0 || r >= n || c < 0 || c >= m) {
                continue;
            }

            if (map[r][c] == 1) {
                if (curt == 1) {
                    dq.push_back({curr, curc, curw, 0, stand + 1});
                    continue;
                }
                if (curw > 0 && (visited[r][c][k - curw + 1] == 0 || visited[r][c][k - curw + 1] > visited[curr][curc][k - curw] + 1 + stand)) {
                    dq.push_back({r, c, curw - 1, (curt + 1) % 2, stand});
                    visited[r][c][k - curw + 1] = visited[curr][curc][k - curw] + 1;
                }
                continue;
            }
            
            if (visited[r][c][k - curw] == 0 || visited[r][c][k - curw] > visited[curr][curc][k - curw] + 1 + stand) {
                dq.push_back({r, c, curw, (curt + 1) % 2, stand});
                visited[r][c][k - curw] = visited[curr][curc][k - curw] + 1;
                if (r == n - 1 && c == m - 1) {
                    return visited[r][c][k - curw] + stand;
                }
            }

        }
    }
    return -1;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    if (n == 1 && m == 1) {
        printf("1");
        return 0;
    }

    printf("%d", search());
    
    return 0;
}