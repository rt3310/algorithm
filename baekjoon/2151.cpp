#include <iostream>
#include <deque>
#include <tuple>
using namespace std;

int n;
char house[50][50];
int visited[50][50][4];
int door[2][2];
int d[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
constexpr int N = 0;
constexpr int S = 1;
constexpr int E = 2;
constexpr int W = 3;

int getNextDir(int dir) {
    if (dir == N) {
        return W;
    } 

    if (dir == S) {
        return E;
    }
    
    if (dir == W) {
        return N;
    }
    
    return S;
}

int search(pair<int, int> start, pair<int, int> dest) {
    deque<tuple<int, int, int, int>> dq; // r, c, glass, dir
    for (int i = 0; i < 4; i++) {
        dq.push_back({start.first, start.second, 0, i});
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                visited[i][j][k] = 99999;
            }
        }
    }

    while (!dq.empty()) {
        int r, c, glass, dir;
        tie(r, c, glass, dir) = dq.front(); dq.pop_front();

        int nr = r + d[dir][0];
        int nc = c + d[dir][1];

        if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
            continue;
        }

        if (house[nr][nc] == '*') {
            continue;
        }

        if (house[nr][nc] == '!') {
            if (glass + 1 < visited[nr][nc][dir]) {
                visited[nr][nc][dir] = glass + 1;
                dq.push_back({nr, nc, glass + 1, (dir + 2) % 4});
                dq.push_back({nr, nc, glass + 1, getNextDir(dir)});
            }
        }

        if (glass < visited[nr][nc][dir]) {
            visited[nr][nc][dir] = glass;
            dq.push_back({nr, nc, glass, dir});
        }

    }

    int minGlass = 2500;
    for (int i = 0; i < 4; i++) {
        minGlass = min(minGlass, visited[dest.first][dest.second][i]);
    }

    return minGlass;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    int doorCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> house[i][j];
            if (house[i][j] == '#') {
                door[doorCount][0] = i;
                door[doorCount][1] = j;
                doorCount++;
            }
        }
    }

    cout << search({door[0][0], door[0][1]}, {door[1][0], door[1][1]});

    return 0;
}