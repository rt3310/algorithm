#include <iostream>
using namespace std;

int n;
int egg[8][2];
int result = 0;

void search(int depth) {
    if (depth == n) {
        int broken = 0;
        for (int i = 0; i < n; i++) {
            if (egg[i][0] <= 0) {
                broken++;
            }
        }
        result = max(result, broken);
        return;
    }

    if (egg[depth][0] <= 0) {
        search(depth + 1);
        return;
    }

    bool exists = false;
    for (int i = 0; i < n; i++) {
        if (i == depth || egg[i][0] <= 0) {
            continue;
        }
        egg[depth][0] -= egg[i][1];
        egg[i][0] -= egg[depth][1];
        search(depth + 1);
        egg[depth][0] += egg[i][1];
        egg[i][0] += egg[depth][1];
        exists = true;
    }

    if (!exists) {
        search(depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> egg[i][0] >> egg[i][1];
    }

    search(0);

    cout << result;

    return 0;
}