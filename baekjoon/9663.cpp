#include <iostream>
using namespace std;

int n;
bool col[31];
bool leftDown[31];
bool leftUp[31];
int result = 0;

void write(int r, int c) {
    col[c] = true;
    leftDown[n - 1 - r + c] = true;
    leftUp[r + c] = true;
}

void remove(int r, int c) {
    col[c] = false;
    leftDown[n - 1 - r + c] = false;
    leftUp[r + c] = false;
}

bool isInValid(int r, int c) {
    return col[c] || leftDown[n - 1 - r + c] || leftUp[r + c];
}

void search(int depth) {
    if (depth == n) {
        result++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isInValid(depth, i)) {
            continue;
        }
        write(depth, i);
        search(depth + 1);
        remove(depth, i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    search(0);

    cout << result;

    return 0;
}