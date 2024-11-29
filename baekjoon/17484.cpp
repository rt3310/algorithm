#include <iostream>
using namespace std;

int n, m;
int space[6][6];
constexpr int MX = 2100000000;
int result = MX;

void search(int r, int c, int total, int prevDir) {
    if (r == n - 1) {
        result = min(result, total);
        return;
    }

    if (c > 0 && prevDir != -1) {
        search(r + 1, c - 1, total + space[r + 1][c - 1], -1);
    }
    if (prevDir != 0) {
        search(r + 1, c, total + space[r + 1][c], 0);
    }
    if (c < m - 1 && prevDir != 1) {
        search(r + 1, c + 1, total + space[r + 1][c + 1], 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> space[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        search(0, i, space[0][i], 2);
    }

    cout << result;

    return 0;
}