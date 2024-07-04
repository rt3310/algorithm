#include <cstdio>
#include <deque>
#include <vector>
using namespace std;

int n, m;
int g, r;
int map[51][51];
int liquid[51][51];
int times[51][51];
vector<pair<int, int>> inits;
vector<pair<int, int>> gv;
vector<pair<int, int>> rv;
int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int maxFlowers = 0;

void bfs() {
    deque<vector<int>> dq; // 1: green, 2: red
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            liquid[i][j] = 0;
            times[i][j] = 0;
        }
    }
    for (auto v : gv) {
        dq.push_back(vector<int> {v.first, v.second, 1});
        liquid[v.first][v.second] = 1;
        times[v.first][v.second] = 1;
    }
    for (auto v : rv) {
        dq.push_back(vector<int> {v.first, v.second, 2});
        liquid[v.first][v.second] = 2;
        times[v.first][v.second] = 1;
    }

    int flowers = 0;
    while (!dq.empty()) {
        vector<int> cur = dq.front();
        dq.pop_front();
        if (liquid[cur[0]][cur[1]] == 3) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int r = cur[0] + d[i][0];
            int c = cur[1] + d[i][1];

            if (r < 0 || r >= n || c < 0 || c >= m) {
                continue;
            }

            if (map[r][c] == 0 || liquid[r][c] == 3) {
                continue;
            }

            if (liquid[r][c] == 1 && cur[2] == 2) {
                if (times[r][c] == times[cur[0]][cur[1]] + 1) {
                    liquid[r][c] = 3;
                    flowers++;
                }
                continue;
            }

            if (liquid[r][c] == 2 && cur[2] == 1) {
                if (times[r][c] == times[cur[0]][cur[1]] + 1) {
                    liquid[r][c] = 3;
                    flowers++;
                }
                continue;
            }

            if (liquid[r][c] == 0) {
                liquid[r][c] = cur[2];
                times[r][c] = times[cur[0]][cur[1]] + 1;
                dq.push_back(vector<int> {r, c, cur[2]});
            }

        }
    }
    maxFlowers = max(maxFlowers, flowers);
}

void search(int gCount, int rCount, int start) {
    if (gCount == 0 && rCount == 0) {
        bfs();
        return;
    }

    if (gCount > 0) {
        for (int i = start; i < inits.size(); i++) {
            gv.push_back({inits[i].first, inits[i].second});
            search(gCount - 1, rCount, i + 1);
            gv.pop_back();
        }
    }

    if (rCount > 0) {
        for (int i = start; i < inits.size(); i++) {
            rv.push_back({inits[i].first, inits[i].second});
            search(gCount, rCount - 1, i + 1);
            rv.pop_back();
        }
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &g, &r);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2) {
                inits.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < inits.size(); i++) {
        gv.push_back({inits[i].first, inits[i].second});
        search(g - 1, r, i + 1);
        gv.pop_back();
        rv.push_back({inits[i].first, inits[i].second});
        search(g, r - 1, i + 1);
        rv.pop_back();
    }

    printf("%d", maxFlowers);

    return 0;
}