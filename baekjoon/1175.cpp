#include <iostream>
#include <deque>
#include <tuple>
#include <vector>
using namespace std;

constexpr int MX = 2100000000;
char sch[50][50];
int n, m;
int start[2];
int finish[2][2];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // N, W, S, E / 0, 1, 2, 3

vector<pair<int, int>> search(pair<int, int> st, pair<int, int> dest, int prevD, bool isFirst) {
    deque<tuple<int, int, int, int>> dq; // r, c, prevDir, time
    dq.push_back({st.first, st.second, prevD, 0});
    char visited[50][50];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }

    vector<pair<int, int>> arriveList;
    while (!dq.empty()) {
        int curr, curc, prevDir, time;
        tie(curr, curc, prevDir, time) = dq.front(); dq.pop_front();

        for (int i = 0; i < 4; i++) {
            if (prevDir == i)
                continue;

            int r = curr + dir[i][0];
            int c = curc + dir[i][1];

            if (r < 0 || r >= n || c < 0 || c >= m)
                continue;

            if (sch[r][c] == '#') {
                continue;
            }

            if (visited[r][c] & (1 << i))
                continue;

            if (r == dest.first && c == dest.second) {
                if (!isFirst) {
                    return vector<pair<int, int>> {{time + 1, i}};
                }
                arriveList.push_back({time + 1, i});
            }

            dq.push_back({r, c, i, time + 1});
            visited[r][c] |= (1 << i);
        }
    }

    return arriveList;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int finishCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> sch[i][j];
            if (sch[i][j] == 'S') {
                start[0] = i;
                start[1] = j;
            }
            if (sch[i][j] == 'C') {
                finish[finishCount][0] = i;
                finish[finishCount][1] = j;
                finishCount++;
            }
        }
    }

    int firstResult = MX;
    int secondResult = MX;

    auto firstList = search({start[0], start[1]}, {finish[0][0], finish[0][1]}, 4, true);
    auto secondList = search({start[0], start[1]}, {finish[1][0], finish[1][1]}, 4, true);

    for (auto f : firstList) {
        auto result = search({finish[0][0], finish[0][1]}, {finish[1][0], finish[1][1]}, f.second, false);
        if (!result.empty()) {
            firstResult = min(firstResult, f.first + result[0].first);
        }
    }

    for (auto s : secondList) {
        auto result = search({finish[1][0], finish[1][1]}, {finish[0][0], finish[0][1]}, s.second, false);
        if (!result.empty()) {
            secondResult = min(secondResult, s.first + result[0].first);
        }
    }

    if (firstResult == MX && secondResult == MX) {
        cout << -1;
        return 0;
    } 

    if (firstResult == MX) {
        cout << secondResult;
        return 0;
    }

    if (secondResult == MX) {
        cout << firstResult;
        return 0;
    }

    cout << min(firstResult, secondResult);

    return 0;
}