#include <iostream>
#include <vector>
#include <deque>
#include <map>
using namespace std;

int n, m;
int room[101][101];
vector<pair<int, int>> light[101][101];
bool visited[101][101];
int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
map<pair<int, int>, bool> check;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        light[x][y].push_back({a, b});
        room[a][b] = 1;
    }

    deque<pair<int, int>> dq;
    dq.push_back({1, 1});
    room[1][1] = 2;
    visited[1][1] = true;

    while (!dq.empty()) {
        pair<int, int> cur = dq.front(); dq.pop_front();
        for (pair<int, int> l : light[cur.first][cur.second]) {
            room[l.first][l.second] = 2;
            if (check[l]) {
                check[l] = false;
                dq.push_back(l);
                visited[l.first][l.second] = true;
            }
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.first + d[i][0];
            int c = cur.second + d[i][1];

            if (r < 1 || r > n || c < 1 || c > n) {
                continue;
            }

            if (room[r][c] == 0) {
                continue;
            }

            if (visited[r][c]) {
                continue;
            }

            if (room[r][c] == 1) {
                check[{r, c}] = true;
                continue;
            }

            dq.push_back({r, c});
            visited[r][c] = true;

        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (room[i][j] == 2) {
                result++;
            }
        }
    }

    cout << result;

    return 0;
}