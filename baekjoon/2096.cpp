#include <iostream>
using namespace std;

int n;
int board[100000][3];
int temp[2][3][2];
int mx = 0;
int mn = 2100000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> board[i][0] >> board[i][1] >> board[i][2];
    }

    temp[0][0][0] = board[0][0];
    temp[0][1][0] = board[0][1];
    temp[0][2][0] = board[0][2];
    temp[0][0][1] = board[0][0];
    temp[0][1][1] = board[0][1];
    temp[0][2][1] = board[0][2];

    int idx = 1;
    for (int i = 1; i < n; i++) {
        temp[idx][0] = board[i][0] + max(temp[(idx + 1) % 2][0], temp[(idx + 1) % 2][1]);
        temp[idx][1] = board[i][1] + max(temp[(idx + 1) % 2][0], max(temp[(idx + 1) % 2][1], temp[(idx + 1) % 2][2]));
        temp[idx][2] = board[i][2] + max(temp[(idx + 1) % 2][1], temp[(idx + 1) % 2][2]);
        idx = (idx + 1) % 2;
    }

    for (int i = 0; i < 3; i++) {
        mx = max(mx, temp[(idx + 1) % 2][i]);
    }

    temp[0][0] = board[0][0];
    temp[0][1] = board[0][1];
    temp[0][2] = board[0][2];

    idx = 1;
    for (int i = 1; i < n; i++) {
        temp[idx][0] = board[i][0] + min(temp[(idx + 1) % 2][0], temp[(idx + 1) % 2][1]);
        temp[idx][1] = board[i][1] + min(temp[(idx + 1) % 2][0], min(temp[(idx + 1) % 2][1], temp[(idx + 1) % 2][2]));
        temp[idx][2] = board[i][2] + min(temp[(idx + 1) % 2][1], temp[(idx + 1) % 2][2]);
        idx = (idx + 1) % 2;
    }

    for (int i = 0; i < 3; i++) {
        mn = min(mn, temp[(idx + 1) % 2][i]);
    }

    cout << mx << ' ' << mn;

    return 0;
}