#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int n, m;
int map[50][50];
deque<pair<int, int>> dq;
int visited[50][50];
int order = 0;
int maxRoomSize = 0;
vector<int> roomSizes;

int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int search(pair<int, int> start) {
    dq.clear();
    dq.push_back(start);
    visited[start.first][start.second] = order;

    int roomSize = 1;
    while (!dq.empty()) {
        auto cur = dq.front(); dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int r = cur.first + dir[i][0];
            int c = cur.second + dir[i][1];

            if (r < 0 || r >= m || c < 0 || c >= n) {
                continue;
            }

            if (map[cur.first][cur.second] & (1 << i)) {
                continue;
            }

            if (visited[r][c] != 0) {
                continue;
            }

            roomSize++;
            visited[r][c] = order;
            dq.push_back({r, c});
        }
    }

    return roomSize;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) {
                continue;
            }
            order++;
            int roomSize = search({i, j});
            roomSizes.push_back(roomSize);
            maxRoomSize = max(maxRoomSize, roomSize);
        }
    }

    int maxSum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j < n - 1 && visited[i][j] != visited[i][j + 1]) {
                maxSum = max(maxSum, roomSizes[visited[i][j] - 1] + roomSizes[visited[i][j + 1] - 1]);
            }

            if (i < m - 1 && visited[i][j] != visited[i + 1][j]) {
                maxSum = max(maxSum, roomSizes[visited[i][j] - 1] + roomSizes[visited[i + 1][j] - 1]);
            }
        }
    }

    cout << order << '\n' << maxRoomSize << '\n' << maxSum;

    return 0;
}