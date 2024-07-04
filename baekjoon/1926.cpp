#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
using namespace std;

int n, m;
char map[501][501];
int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
bool visited[501][501];

int bfs(pair<int, int> start) {
    deque<pair<int, int>> dq;
    dq.push_back(start);
    visited[start.first][start.second] = true;

    int area = 1;
    while (!dq.empty()) {
        pair<int, int> cur = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int r = cur.first + d[i][0];
            int c = cur.second + d[i][1];

            if (r < 0 || r >= n || c < 0 || c >= m) {
                continue;
            }

            if (map[r][c] == '0') {
                continue;
            }

            if (visited[r][c]) {
                continue;
            }

            visited[r][c] = true;
            dq.push_back({r, c});
            area++;
        }
    }

    return area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int count = 0;
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '1' && !visited[i][j]) {
                maxArea = max(maxArea, bfs({i, j}));
                count++;
            }
        }
    }

    cout << count << "\n" << maxArea;
    return 0;
}