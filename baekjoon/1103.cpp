#include <iostream>
using namespace std;

int n, m;
char board[50][50];
int count[50][50];
bool visited[50][50];
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int maxMove = 0;

void search(int r, int c) {
    if (maxMove == -1) {
        return;
    }

    int number = board[r][c] - 48;
    for (int i = 0; i < 4; i++) {
        if (maxMove == -1) {
            return;
        }

        int nr = r + (d[i][0] * number);
        int nc = c + (d[i][1] * number);

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
            maxMove = max(maxMove, count[r][c]);
            continue;
        }

        if (board[nr][nc] == 'H') {
            maxMove = max(maxMove, count[r][c]);
            continue;
        }

        if (visited[nr][nc]) {
            maxMove = -1;
            return;
        }

        if (count[r][c] + 1 > count[nr][nc]) {
            count[nr][nc] = count[r][c] + 1;
            visited[nr][nc] = true;
            search(nr, nc);
            visited[nr][nc] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    visited[0][0] = true;
    count[0][0] = 1;
    search(0, 0);

    cout << maxMove;

    return 0;
}