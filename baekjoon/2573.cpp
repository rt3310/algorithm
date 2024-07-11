#include <iostream>
#include <deque>
using namespace std;

int n, m;
int map[301][301];
bool visited[301][301];
int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void search(pair<int, int> start) {
    deque<pair<int, int>> dq;
    dq.push_back(start);
    visited[start.first][start.second] = true;

    while (!dq.empty()) {
        pair<int, int> cur = dq.front(); dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int r = cur.first + d[i][0];
            int c = cur.second + d[i][1];

            if (r < 0 || r >= n || c < 0 || c >= m) {
                continue;
            }

            if (visited[r][c]) {
                continue;
            }

            if (map[r][c] == 0) {
                if (map[cur.first][cur.second] > 0) {
                    map[cur.first][cur.second]--;
                }
                continue;
            }

            dq.push_back({r, c});
            visited[r][c] = true;
        }
    }
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int count = 0;
    int year = 0;
    while (true) {
        bool allMelt = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] > 0 && !visited[i][j]) {
                    count++;
                    allMelt = false;
                    search({i, j});
                    if (count >= 2) {
                        cout << year;
                        return 0;
                    }
                }
            }
        }
        count = 0;
        year++;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = false;
            }
        }


        if (allMelt) {
            cout << 0;
            return 0;
        }
    }
    
    return 0;
}