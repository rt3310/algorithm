#include <cstdio>
#include <vector>
#include <deque>
#include <tuple>
using namespace std;

int n, m;
int map[1001][1001];
int visited[1001][1001][2];
int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int search() {
    deque<tuple<int, int, int>> dq;
    dq.push_back({0, 0, 0});
    visited[0][0][0] = 1;

    while (!dq.empty()) {
        int curr, curc, curw;
        tie(curr, curc, curw) = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int r = curr + d[i][0];
            int c = curc + d[i][1];

            if (r < 0 || r >= n || c < 0 || c >= m) {
                continue;
            }

            if (map[r][c] == 1) {
                if (curw == 0 && (visited[r][c][1] == 0 || visited[r][c][1] > visited[curr][curc][0] + 1)) {
                    dq.push_back({r, c, 1});
                    visited[r][c][1] = visited[curr][curc][0] + 1;
                    if (r == n - 1 && c == m - 1) {
                        return visited[r][c][curw];
                    }
                }
                continue;
            }
            
            if (visited[r][c][curw] > 0) {
                continue;
            }

            dq.push_back({r, c, curw});
            visited[r][c][curw] = visited[curr][curc][curw] + 1;
            if (r == n - 1 && c == m - 1) {
                return visited[r][c][curw];
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &n, &m);
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