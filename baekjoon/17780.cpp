#include <iostream>
using namespace std;

int n, k;
int board[13][13];
int piece[10][3];
int floor[10];
int state[13][13];
int d[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
constexpr int W = 0, R = 1, B = 2;
int turn = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> piece[i][0] >> piece[i][1] >> piece[i][2];
        state[piece[i][0]][piece[i][1]] |= (1 << i);
        int f = 1;
        for (int j = 0; j < i; j++) {
            if (state[piece[i][0]][piece[i][1]] & (1 << j)) {
                f++;
            }
        }
        floor[i] = f;
    }
    cout << endl;

    while (turn <= 1000) {
        for (int i = 0; i < k; i++) {
            if (floor[i] == 1) {
                if (move(i)) {
                    cout << turn;
                    return 0;
                }

                for (int rr = 0; rr < n; rr++) {
                    for (int cc = 0; cc < n; cc++) {
                        bool exists = false;
                        for (int j = 0; j < k; j++) {
                            if (state[rr][cc] & (1 << j)) {
                                cout << (j + 1);
                                exists = true;
                            } 
                        }
                        if (!exists) {
                            cout << 0 << ' ';
                        } else {
                            cout << ' ';
                        }
                    }
                    cout << endl;
                }
            }
        }
        turn++;
    }

    cout << "-1";

    return 0;
}