#include <cstdio>
#include <deque>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m, p;
int s[10];
char map[1001][1001];
deque<tuple<int, int, int>> dq[10];
int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int result[10];

int main() {
    scanf("%d %d %d", &n, &m, &p);

    for (int i = 1; i <= p; i++) {
        scanf("%d", &s[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%s", map[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] != '.' && map[i][j] != '#') {
                dq[map[i][j] - '0'].push_back({i, j, 0});
            }
        }
    }

    int cnt = 1;
    int turn = 1;
    int lim = p;
    while (lim > 0) {
        if (cnt == lim && dq[cnt].empty()) {
            lim--;
        }
        while (!dq[cnt].empty()) {
            int curr, curc, curn;
            tie(curr, curc, curn) = dq[cnt].front();
            if (curn >= s[cnt] * turn) {
                if (cnt == lim) {
                    turn++;
                }
                break;
            }
            dq[cnt].pop_front();

            for (int i = 0; i < 4; i++) {
                int r = curr + d[i][0];
                int c = curc + d[i][1];

                if (r < 0 || r >= n || c < 0 || c >= m) {
                    continue;
                }

                if (map[r][c] != '.') {
                    continue;
                }

                dq[cnt].push_back({r, c, curn + 1});
                map[r][c] = cnt + '0';
            }
        }
        cnt = (cnt % p) + 1;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[map[i][j] - '0']++;
        }
    }

    for (int i = 1; i <= p; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}