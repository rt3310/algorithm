#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

constexpr int R = 1, L = 2, U = 3, D = 4;
int oppo[4] = {1, 0, 3, 2};
int d[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int r, c, k, w;
int room[21][21];
char wall[21][21];
int visited[21][21];
int addedTemp[21][21];
int result = 0;

vector<tuple<int, int, int>> fan;
vector<pair<int, int>> investigate;

void edgeDownTemp() {
    for (int i = 1; i <= c; i++) {
        if (room[1][i] > 0) {
            room[1][i]--;
        }
        if (room[r][i] > 0) {
            room[r][i]--;
        }
    }

    for (int i = 2; i < r; i++) {
        if (room[i][1] > 0) {
            room[i][1]--;
        }
        if (room[i][c] > 0) {
            room[i][c]--;
        }
    }
}

void adjustTemp() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int sub;
            int moveTemp;
            if (j < c && !(wall[i][j] & (1 << R - 1))) {
                sub = abs(room[i][j] - room[i][j + 1]);
                moveTemp = sub / 4;
                if (room[i][j] > room[i][j + 1]) {
                    addedTemp[i][j] -= moveTemp;
                    addedTemp[i][j + 1] += moveTemp;
                } else {
                    addedTemp[i][j] += moveTemp;
                    addedTemp[i][j + 1] -= moveTemp;
                }
            }

            if (i < r && !(wall[i][j] & (1 << D - 1))) {
                sub = abs(room[i][j] - room[i + 1][j]);
                moveTemp = sub / 4;
                if (room[i][j] > room[i + 1][j]) {
                    addedTemp[i][j] -= moveTemp;
                    addedTemp[i + 1][j] += moveTemp;
                } else {
                    addedTemp[i][j] += moveTemp;
                    addedTemp[i + 1][j] -= moveTemp;
                }
            }
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            room[i][j] += addedTemp[i][j];
            addedTemp[i][j] = 0;
        }
    }
}

void upWind(int curr, int curc, int order, int temp) {
    if (temp == 1 || curr == 1) {
        return;
    }

    if (curc > 1 && !(wall[curr][curc] & (1 << (L - 1))) && !(wall[curr][curc - 1] & (1 << (U - 1)))) {
        if (visited[curr - 1][curc - 1] != order) {
            room[curr - 1][curc - 1] += temp - 1;
            visited[curr - 1][curc - 1] = order;
            upWind(curr - 1, curc - 1, order, temp - 1);
        }
    }
    if (curc < c && !(wall[curr][curc] & (1 << (R - 1))) && !(wall[curr][curc + 1] & (1 << (U - 1)))) {
        if (visited[curr - 1][curc + 1] != order) {
            room[curr - 1][curc + 1] += temp - 1;
            visited[curr - 1][curc + 1] = order;
            upWind(curr - 1, curc + 1, order, temp - 1);
        }
    }
    if (!(wall[curr][curc] & (1 << (U - 1)))) {
        if (visited[curr - 1][curc] != order) {
            room[curr - 1][curc] += temp - 1;
            visited[curr - 1][curc] = order;
            upWind(curr - 1, curc, order, temp - 1);
        }
    }
}

void downWind(int curr, int curc, int order, int temp) {
    if (temp == 1 || curr == r) {
        return;
    }

    if (curc > 1 && !(wall[curr][curc] & (1 << (L - 1))) && !(wall[curr][curc - 1] & (1 << (D - 1)))) {
        if (visited[curr + 1][curc - 1] != order) {
            room[curr + 1][curc - 1] += temp - 1;
            visited[curr + 1][curc - 1] = order;
            downWind(curr + 1, curc - 1, order, temp - 1);
        }
    }
    if (curc < c && !(wall[curr][curc] & (1 << (R - 1))) && !(wall[curr][curc + 1] & (1 << (D - 1)))) {
        if (visited[curr + 1][curc + 1] != order) {
            room[curr + 1][curc + 1] += temp - 1;
            visited[curr + 1][curc + 1] = order;
            downWind(curr + 1, curc + 1, order, temp - 1);
        }
    }
    if (!(wall[curr][curc] & (1 << (D - 1)))) {
        if (visited[curr + 1][curc] != order) {
            room[curr + 1][curc] += temp - 1;
            visited[curr + 1][curc] = order;
            downWind(curr + 1, curc, order, temp - 1);
        }
    }
}

void rightWind(int curr, int curc, int order, int temp) {
    if (temp == 1 || curc == c) {
        return;
    }

    if (curr > 1 && !(wall[curr][curc] & (1 << (U - 1))) && !(wall[curr - 1][curc] & (1 << (R - 1)))) {
        if (visited[curr - 1][curc + 1] != order) {
            room[curr - 1][curc + 1] += temp - 1;
            visited[curr - 1][curc + 1] = order;
            rightWind(curr - 1, curc + 1, order, temp - 1);
        }
    }
    if (curr < r && !(wall[curr][curc] & (1 << (D - 1))) && !(wall[curr + 1][curc] & (1 << (R - 1)))) {
        if (visited[curr + 1][curc + 1] != order) {
            room[curr + 1][curc + 1] += temp - 1;
            visited[curr + 1][curc + 1] = order;
            rightWind(curr + 1, curc + 1, order, temp - 1);
        }
    }
    if (!(wall[curr][curc] & (1 << (R - 1)))) {
        if (visited[curr][curc + 1] != order) {
            room[curr][curc + 1] += temp - 1;
            visited[curr][curc + 1] = order;
            rightWind(curr, curc + 1, order, temp - 1);
        }
    }
}

void leftWind(int curr, int curc, int order, int temp) {
    if (temp == 1 || curc == 1) {
        return;
    }

    if (curr > 1 && !(wall[curr][curc] & (1 << (U - 1))) && !(wall[curr - 1][curc] & (1 << (L - 1)))) {
        if (visited[curr - 1][curc - 1] != order) {
            room[curr - 1][curc - 1] += temp - 1;
            visited[curr - 1][curc - 1] = order;
            leftWind(curr - 1, curc - 1, order, temp - 1);
        }
    }
    if (curr < r && !(wall[curr][curc] & (1 << (D - 1))) && !(wall[curr + 1][curc] & (1 << (L - 1)))) {
        if (visited[curr + 1][curc - 1] != order) {
            room[curr + 1][curc - 1] += temp - 1;
            visited[curr + 1][curc - 1] = order;
            leftWind(curr + 1, curc - 1, order, temp - 1);
        }
    }
    if (!(wall[curr][curc] & (1 << (L - 1)))) {
        if (visited[curr][curc - 1] != order) {
            room[curr][curc - 1] += temp - 1;
            visited[curr][curc - 1] = order;
            leftWind(curr, curc - 1, order, temp - 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> k;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> room[i][j];

            if (room[i][j] == 5) {
                investigate.push_back({i, j});
                room[i][j] = 0;
                continue;
            }

            if (room[i][j] > 0) {
                fan.push_back({i, j, room[i][j]});
                room[i][j] = 0;
            }
        }
    }

    cin >> w;
    for (int i = 0; i < w; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        if (t == 0) {
            wall[x][y] |= (1 << (U - 1));
            wall[x - 1][y] |= (1 << (D - 1));
        } else {
            wall[x][y] |= (1 << (R - 1));
            wall[x][y + 1] |= (1 << (L - 1));
        }
    }

    while (result < 101) {
        for (int i = 0; i < fan.size(); i++) {
            int fr, fc, fdir;
            tie(fr, fc, fdir) = fan[i];
            if (fdir == R && fc < c) {
                room[fr][fc + 1] += 5;
                rightWind(fr, fc + 1, i + 1, 5);
            } else if (fdir == L && fc > 1) {
                room[fr][fc - 1] += 5;
                leftWind(fr, fc - 1, i + 1, 5);
            } else if (fdir == U && fr > 1) {
                room[fr - 1][fc] += 5;
                upWind(fr - 1, fc, i + 1, 5);
            } else {
                room[fr + 1][fc] += 5;
                downWind(fr + 1, fc, i + 1, 5);
            }
        }

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                visited[i][j] = 0;
            }
        }
        
        adjustTemp();
        edgeDownTemp();

        result++;
        bool valid = true;
        for (int i = 0; i < investigate.size(); i++) {
            if (room[investigate[i].first][investigate[i].second] < k) {
                valid = false;
                break;
            }
        }

        if (valid) {
            break;
        }
    }

    cout << result;

    return 0;
}