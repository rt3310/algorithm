#include <iostream>
using namespace std;

int n, m;
int paper[500][500];
bool visited[500][500];
int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int d2[6][2][2] = {
    {{-1, 0}, {0, 1}},
    {{1, 0}, {0, 1}},
    {{-1, 0}, {0, -1}},
    {{1, 0}, {0, -1}},
    {{-1, 0}, {1, 0}},
    {{0, -1}, {0, 1}}
};
int result = 0;

int search(int r, int c, int depth) {
    if (depth == 4) {
        return paper[r][c];
    }

    int mx = 0;
    if (depth == 2) {
        for (int i = 0; i < 6; i++) {
            int nr1 = r + d2[i][0][0];
            int nc1 = c + d2[i][0][1];
            int nr2 = r + d2[i][1][0];
            int nc2 = c + d2[i][1][1];

            if (nr1 < 0 || nr1 >= n || nc1 < 0 || nc1 >= m ||
                nr2 < 0 || nr2 >= n || nc2 < 0 || nc2 >= m) {
                continue;
            }

            if (visited[nr1][nc1] || visited[nr2][nc2]) {
                continue;
            }

            mx = max(mx, paper[nr1][nc1] + paper[nr2][nc2]);
        }
    }

    for (int i = 0; i < 4; i++) {
        int nr = r + d[i][0];
        int nc = c + d[i][1];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
            continue;
        }

        if (visited[nr][nc]) {
            continue;
        }

        visited[nr][nc] = true;
        mx = max(mx, search(nr, nc, depth + 1));
        visited[nr][nc] = false;
    }

    return mx + paper[r][c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = true;
            result = max(result, search(i, j, 1));
            visited[i][j] = false;
        }
    }

    cout << result;

    return 0;
}