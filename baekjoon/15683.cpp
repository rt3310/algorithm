#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, m;
int cctv[8][3];
int cctvDir[8];
int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int office[8][8];
int cctvCount = 0;
int result = 65;

void noteBlindSpotCount() {
    int blindSpot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (office[i][j] == 0) {
                blindSpot++;
            }
        }
    }

    result = min(result, blindSpot);
}

vector<int> getDirs(int type, int dir) {
    if (type == 1) {
        return vector<int> { dir };
    }
    if (type == 2) {
        return vector<int> { dir, (dir + 2) % 4 };
    }
    if (type == 3) {
        return vector<int> { dir, (dir + 1) % 4 };
    }
    if (type == 4) {
        return vector<int> { dir, (dir + 1) % 4, (dir + 2) % 4 };
    }
    return vector<int> { dir, (dir + 1) % 4, (dir + 2) % 4, (dir + 3) % 4 };
}

void drawObserveArea() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (office[i][j] == 7) {
                office[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < cctvCount; i++) {
        vector<int> dirs = getDirs(cctv[i][2], cctvDir[i]);

        for (int& dir : dirs) {
            int r = cctv[i][0];
            int c = cctv[i][1];

            while (true) {
                r += d[dir][0];
                c += d[dir][1];

                if (r < 0 || r >= n || c < 0 || c >= m) {
                    break;
                }

                if (office[r][c] == 6) {
                    break;
                }

                if (office[r][c] == 0) {
                    office[r][c] = 7;
                }
            }
        }
    }
}

void search(int depth) {
    if (depth == cctvCount) {
        drawObserveArea();
        noteBlindSpotCount();
        return;
    }

    for (int i = 0; i < 4; i++) {
        cctvDir[depth] = i;
        search(depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> office[i][j];

            if (office[i][j] > 0 && office[i][j] < 6) {
                cctv[cctvCount][0] = i;
                cctv[cctvCount][1] = j;
                cctv[cctvCount][2] = office[i][j];
                cctvCount++;
            }
        }
    }

    search(0);

    cout << result;

    return 0;
}