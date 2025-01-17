#include <iostream>
using namespace std;

constexpr int E = 1, W = 2, N = 3, S = 4;
int n, m, x, y, k;
int xmap[20][20];
int dice[6];

void moveDice(int mv) {
    int up = dice[0];
    int down = dice[5];
    int right = dice[2];
    int left = dice[3];
    int back = dice[1];
    int front = dice[4];

    switch (mv)
    {
    case E:
        if (y + 1 >= m) {
            return;
        }
        y++;
        dice[0] = right;
        dice[1] = back;
        dice[2] = down;
        dice[3] = up;
        dice[4] = front;
        dice[5] = left;
        break;
    case W:
        if (y - 1 < 0) {
            return;
        }
        y--;
        dice[0] = left;
        dice[1] = back;
        dice[2] = up;
        dice[3] = down;
        dice[4] = front;
        dice[5] = right;
        break;
    case N:
        if (x - 1 < 0) {
            return;
        }
        x--;
        dice[0] = back;
        dice[1] = down;
        dice[2] = right;
        dice[3] = left;
        dice[4] = up;
        dice[5] = front;
        break;
    case S:
        if (x + 1 >= n) {
            return;
        }
        x++;
        dice[0] = front;
        dice[1] = up;
        dice[2] = right;
        dice[3] = left;
        dice[4] = down;
        dice[5] = back;
        break;
    }

    cout << dice[0] << endl;

    if (xmap[x][y] == 0) {
        xmap[x][y] = dice[5];
    } else {
        dice[5] = xmap[x][y];
        xmap[x][y] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> xmap[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int mv;
        cin >> mv;
        moveDice(mv);
    }

    return 0;
}