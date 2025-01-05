#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int r, c;
char lake[1500][1500];
int swan[2][2];
int direct[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool visited[1500][1500];
deque<pair<int, int>> dq;
deque<pair<int, int>> dontMove;
vector<pair<int, int>> meltList;
vector<pair<int, int>> nextMeltList;

void melting() {
    while (!nextMeltList.empty()) {
        meltList.push_back(nextMeltList.back());
        nextMeltList.pop_back();
    }

    while (!meltList.empty()) {
        auto melt = meltList.back(); meltList.pop_back();
        lake[melt.first][melt.second] = '.';
        for (int d = 0; d < 4; d++) {
            int nr = melt.first + direct[d][0];
            int nc = melt.second + direct[d][1];
            if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
                continue;
            }

            if (lake[nr][nc] == 'X') {
                nextMeltList.push_back({nr, nc});
                lake[nr][nc] = '!';
            }
        }
    }
}

bool search() {
    while (!dontMove.empty()) {
        dq.push_back(dontMove.front());
        dontMove.pop_front();
    }

    while (!dq.empty()) {
        auto cur = dq.front(); dq.pop_front();

        if (lake[cur.first][cur.second] == 'X') {
            dontMove.push_back({cur.first, cur.second});
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nr = cur.first + direct[i][0];
            int nc = cur.second + direct[i][1];

            if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
                continue;
            }

            if (visited[nr][nc]) {
                continue;
            }

            if (lake[nr][nc] == 'X' || lake[nr][nc] == '!') {
                visited[nr][nc] = true;
                dontMove.push_back({nr, nc});
                continue;
            }


            if (nr == swan[1][0] && nc == swan[1][1]) {
                return true;
            }

            visited[nr][nc] = true;
            dq.push_back({nr, nc});
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;
    int swanCount = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> lake[i][j];
            if (lake[i][j] == 'L') {
                lake[i][j] = '.';
                swan[swanCount][0] = i;
                swan[swanCount][1] = j;
                swanCount++;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (lake[i][j] == 'X') {
                for (int d = 0; d < 4; d++) {
                    int nr = i + direct[d][0];
                    int nc = j + direct[d][1];
                    if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
                        continue;
                    }

                    if (lake[nr][nc] == '.') {
                        meltList.push_back({i, j});
                        break;
                    }
                }
            }
        }
    }

    dq.push_back({swan[0][0], swan[0][1]});
    visited[swan[0][0]][swan[0][1]] = true;
    int day = 0;
    while (true) {
        if (search()) {
            break;
        }
        melting();
        day++;
    }

    cout << day;

    return 0;
}