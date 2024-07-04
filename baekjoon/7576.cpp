#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
using namespace std;

int n, m;
int map[1001][1001];
vector<pair<int, int>> tomatos;
int d[4][2] = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};

int bfs() {
    deque<pair<int, int>> dq;
    int visited[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }
    for (pair<int, int> tomato: tomatos) {
        dq.push_back(tomato);
    }

    while (!dq.empty()) {
        pair<int, int> cur = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int r = cur.first + d[i][0];
            int c = cur.second + d[i][1];

            if (r < 0 || r >= n || c < 0 || c >= m) {
                continue;
            }

            if (map[r][c] == -1 || map[r][c] == 1) {
                continue;
            }

            dq.push_back({r, c});
            map[r][c] = 1;
            visited[r][c] = visited[cur.first][cur.second] + 1;
        }
    }

    int time = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                return -1;
            }
            time = max(time, visited[i][j]);
        }
    }

    return time;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                tomatos.push_back({i, j});
            }
        }
    }

    cout << bfs();

    return 0;
}