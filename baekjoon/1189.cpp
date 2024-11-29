#include <iostream>
using namespace std;

int r, c, k;
char m[5][5];
bool visited[5][5];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int count = 0;

void search(int cr, int cc, int dist) {
    if (dist == k) {
        if (cr == 0 && cc == c - 1) {
            count++;
        }
        return;
    }

    for (const int* d : dir) {
        int nr = cr + d[0];
        int nc = cc + d[1];

        if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
            continue;
        }

        if (m[nr][nc] == 'T') {
            continue;
        }

        if (visited[nr][nc]) {
            continue;
        }

        visited[nr][nc] = true;
        search(nr, nc, dist + 1);
        visited[nr][nc] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> k;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> m[i][j];
        }
    }

    visited[r - 1][0] = true;
    search(r - 1, 0, 1);

    cout << count;

    return 0;
}