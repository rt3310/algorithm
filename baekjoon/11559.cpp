#include <iostream>
#include <deque>
#include <vector>
using namespace std;

char field[12][6];
int visited[12][6];
int d[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int chainCount = 0;
int loopCount = 0;

char numToChar(int num) {
    return num + 48;
}

bool search(char stand, pair<int, int> start) {
    vector<pair<int, int>> willRemove;
    deque<pair<int, int>> dq;
    dq.push_back(start);
    visited[start.first][start.second] = loopCount;
    willRemove.push_back(start);

    while (!dq.empty()) {
        auto cur = dq.front(); dq.pop_front();

        for (const int* dir : d) {
            int nr = cur.first + dir[0];
            int nc = cur.second + dir[1];

            if (nr < 0 || nr >= 12 || nc < 0 || nc >= 6) {
                continue;
            }

            if (field[nr][nc] != stand) {
                continue;
            }

            if (visited[nr][nc] == loopCount) {
                continue;
            }

            dq.push_back({nr, nc});
            visited[nr][nc] = loopCount;
            willRemove.push_back({nr, nc});
        }
    }

    if (willRemove.size() >= 4) {
        for (const auto& p : willRemove) {
            field[p.first][p.second] = '.';
        }
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> field[i][j];
        }
    }

    while (true) {
        loopCount++;

        bool existsBlank = false;
        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (field[i][j] != '.') {
                    existsBlank |= search(field[i][j], {i, j});
                }
            }
        }

        if (!existsBlank) {
            break;
        }

        chainCount++;

        for (int i = 0; i < 6; i++) {
            for (int j = 11; j >= 1; j--) {
                if (field[j][i] == '.') {
                    bool finished = true;
                    for (int k = j - 1; k >= 0; k--) {
                        if (field[k][i] != '.') {
                            field[j][i] = field[k][i];
                            field[k][i] = '.';
                            finished = false;
                            break;
                        }
                    }

                    if (finished) {
                        break;
                    }
                }
            }
        }
    }

    cout << chainCount;


    return 0;
}