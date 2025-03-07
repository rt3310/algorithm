#include <iostream>
#include <string>
using namespace std;

char board[3][3];

int winCase[8][3][2] = {
    {{0, 0}, {0, 1}, {0, 2}},
    {{1, 0}, {1, 1}, {1, 2}},
    {{2, 0}, {2, 1}, {2, 2}},
    {{0, 0}, {1, 0}, {2, 0}},
    {{0, 1}, {1, 1}, {2, 1}},
    {{0, 2}, {1, 2}, {2, 2}},
    {{0, 0}, {1, 1}, {2, 2}},
    {{2, 0}, {1, 1}, {0, 2}}
};

bool check() {
    bool xWin = false;
    bool oWin = false;

    for (int i = 0; i < 8; i++) {
        if (board[winCase[i][0][0]][winCase[i][0][1]] != '.' &&
            board[winCase[i][0][0]][winCase[i][0][1]] == board[winCase[i][1][0]][winCase[i][1][1]] &&
            board[winCase[i][1][0]][winCase[i][1][1]] == board[winCase[i][2][0]][winCase[i][2][1]]) {
            if (board[winCase[i][0][0]][winCase[i][0][1]] == 'X') {
                xWin = true;
            } else {
                oWin = true;
            }
            
        }
    }

    int xCount = 0;
    int oCount = 0;
    for (int i = 0; i < 9; i++) {
        if (board[i / 3][i % 3] == 'X') {
            xCount++;
        } else if (board[i / 3][i % 3] == 'O') {
            oCount++;
        }
    }
    if (!oWin && !xWin && xCount == 5 && oCount == 4) {
        return true;
    }
    if (xWin && !oWin && xCount - oCount == 1) {
        return true;
    }
    if (oWin && !xWin && xCount == oCount) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        string row;
        cin >> row;
        if (row == "end") {
            break;
        }

        for (int i = 0; i < 9; i++) {
            board[i / 3][i % 3] = row[i];
        }

        if (check()) {
            cout << "valid\n";
        } else {
            cout << "invalid\n";
        }
    }

    return 0;
}