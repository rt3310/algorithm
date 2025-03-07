#include <iostream>
using namespace std;

int n, m, h;
bool horizontal[270];
int result = 4;

bool check() {
    for (int i = 1; i <= n; i++) {
        int dep = 1;
        int col = i;
        while (dep <= h) {
            if (col < n && horizontal[((dep - 1) * (n - 1)) + col]) {
                col++;
            } else if (col > 1 && horizontal[((dep - 1) * (n - 1)) + col - 1]) {
                col--;
            }
            dep++;
        }

        if (col != i) {
            return false;
        }
    }
    return true;
}

void search(int depth, int start) {
    if (depth == min(4, m + 1)) {
        return;
    }

    if (check()) {
        result = min(result, depth);
    }
    for (int i = start; i <= (n - 1) * h; i++) {
        if (horizontal[i]) {
            continue;
        }
        horizontal[i] = true;
        search(depth + 1, i + 1);
        horizontal[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        horizontal[((a - 1) * (n - 1)) + b] = true;
    }

    search(0, 1);

    cout << (result > 3 ? -1 : result);


    return 0;
}