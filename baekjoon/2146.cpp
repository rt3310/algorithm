#include <iostream>
#include <deque>
using namespace std;

int n;
int map[100][100];
int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool initVisit[100][100];

int search(pair<int, int> start, int startNumber) {
    deque<pair<int, int>> dq;
    int visited[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 999;
        }
    }
    dq.push_back(start);
    visited[start.first][start.second] = 1;

    while (!dq.empty()) {
        pair<int, int> cur = dq.front(); dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int r = cur.first + d[i][0];
            int c = cur.second + d[i][1];

            if (r < 0 || r >= n || c < 0 || c >= n) {
                continue;
            }

            if (map[r][c] == startNumber) {
                continue;
            }

            if (visited[r][c] <= visited[cur.first][cur.second] + 1) {
                continue;
            }

            if (map[r][c] != 0) {
                return visited[cur.first][cur.second];
            }

            dq.push_back({r, c});
            visited[r][c] = visited[cur.first][cur.second] + 1;
        }
    }
    return 99999;
}

void initOcean(pair<int, int> start, int initNumber) {
    deque<pair<int, int>> dq;
    dq.push_back(start);
    initVisit[start.first][start.second] = true;
    map[start.first][start.second] = initNumber;

    while (!dq.empty()) {
        pair<int, int> cur = dq.front(); dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int r = cur.first + d[i][0];
            int c = cur.second + d[i][1];

            if (r < 0 || r >= n || c < 0 || c >= n) {
                continue;
            }

            if (map[r][c] > 1) {
                continue;
            }

            if (initVisit[r][c]) {
                continue;
            }

            if (map[r][c] == 1) {
                map[r][c] = initNumber;
                dq.push_back({r, c});
                initVisit[r][c] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    int number = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && !initVisit[i][j]) {
                initOcean({i, j}, number++);
            }
        }
    }

    int minBridge = 99999;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) {
                if (map[i][j] > 1 && map[i - 1][j] == 0) {
                    minBridge = min(minBridge, search({i - 1, j}, map[i][j]));
                }
            }
            if (i < n - 1) {
                if (map[i][j] > 1 && map[i + 1][j] == 0) {
                    minBridge = min(minBridge, search({i + 1, j}, map[i][j]));
                }
            }
            if (j > 0) {
                if (map[i][j] > 1 && map[i][j - 1] == 0) {
                    minBridge = min(minBridge, search({i, j - 1}, map[i][j]));
                }
            }
            if (j < n - 1) {
                if (map[i][j] > 1 && map[i][j + 1] == 0) {
                    minBridge = min(minBridge, search({i, j + 1}, map[i][j]));
                }
            }
        }
    }

    cout << minBridge;
    
    return 0;
}