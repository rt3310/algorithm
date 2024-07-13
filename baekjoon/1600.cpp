#include <iostream>
#include <deque>
#include <tuple>
using namespace std;

int k, w, h;
int map[201][201];
int visited[201][201][31];
int hd[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isOutOfBound(int r, int c) {
    if (r < 0 || r >= h || c < 0 || c >= w) {
        return true;
    }
    return false;
}

int search() {
    deque<tuple<int, int, int>> dq;
    dq.push_back({0, 0, k});
    visited[0][0][0] = 1;
    visited[0][0][1] = 1;

    while (!dq.empty()) {
        int curr, curc, curk;
        tie(curr, curc, curk) = dq.front(); dq.pop_front();

        if (curk > 0) {
            for (int i = 0; i < 8; i++) {
                int r = curr + hd[i][0];
                int c = curc + hd[i][1];

                if (isOutOfBound(r, c)) {
                    continue;
                }

                if (map[r][c] == 1) {
                    continue;
                }

                if (visited[r][c][k - curk + 1] > 0) {
                    continue;
                }

                dq.push_back({r, c, curk - 1});
                visited[r][c][k - curk + 1] = visited[curr][curc][k - curk] + 1;

                if (r == h - 1 && c == w - 1) {
                    return visited[r][c][k - curk + 1] - 1;
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            int r = curr + d[i][0];
            int c = curc + d[i][1];

            if (isOutOfBound(r, c)) {
                continue;
            }

            if (map[r][c] == 1) {
                continue;
            }

            if (visited[r][c][k - curk] > 0) {
                continue;
            }

            dq.push_back({r, c, curk});
            visited[r][c][k - curk] = visited[curr][curc][k - curk] + 1;

            if (r == h - 1 && c == w - 1) {
                return visited[r][c][k - curk] - 1;
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> map[i][j];
        }
    }

    if (w == 1 && h == 1) {
        cout << 0;
        return 0;
    }

    cout << search();

    return 0;
}