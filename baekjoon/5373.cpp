#include <iostream>
#include <string>
using namespace std;

int t, n;
char (*cube)[3][3];

void spinCube(char pos, char dir) {
    int *rot;
    int (*row)[3], (*col)[3];
    int front;

    switch (pos)
    {
    case 'U':
        front = 0;
        if (dir == '+') {
            rot = new int[4]{1, 2, 4, 3};
            row = new int[4][3]{{2, 2, 2}, {2, 1, 0}, {0, 0, 0}, {0, 1, 2}};
            col = new int[4][3]{{0, 1, 2}, {2, 2, 2}, {2, 1, 0}, {0, 0, 0}};
        } else {
            rot = new int[4]{1, 3, 4, 2};
            row = new int[4][3]{{2, 2, 2}, {0, 1, 2}, {0, 0, 0}, {2, 1, 0}};
            col = new int[4][3]{{0, 1, 2}, {0, 0, 0}, {2, 1, 0}, {2, 2, 2}};
        }
        break;
    case 'D':
        front = 5;
        if (dir == '+') {
            rot = new int[4]{4, 2, 1, 3};
            row = new int[4][3]{{2, 2, 2}, {0, 1, 2}, {0, 0, 0}, {2, 1, 0}};
            col = new int[4][3]{{0, 1, 2}, {0, 0, 0}, {2, 1, 0}, {2, 2, 2}};
        } else {
            rot = new int[4]{4, 3, 1, 2};
            row = new int[4][3]{{2, 2, 2}, {2, 1, 0}, {0, 0, 0}, {0, 1, 2}};
            col = new int[4][3]{{0, 1, 2}, {2, 2, 2}, {2, 1, 0}, {0, 0, 0}};
        }
        break;
    case 'F':
        front = 4;
        if (dir == '+') {
            rot = new int[4]{0, 2, 5, 3};
            row = new int[4][3]{{2, 2, 2}, {2, 2, 2}, {0, 0, 0}, {2, 2, 2}};
            col = new int[4][3]{{0, 1, 2}, {0, 1, 2}, {2, 1, 0}, {0, 1, 2}};
        } else {
            rot = new int[4]{0, 3, 5, 2};
            row = new int[4][3]{{2, 2, 2}, {2, 2, 2}, {0, 0, 0}, {2, 2, 2}};
            col = new int[4][3]{{0, 1, 2}, {0, 1, 2}, {2, 1, 0}, {0, 1, 2}};
        }
        break;
    case 'B':
        front = 1;
        if (dir == '+') {
            rot = new int[4]{5, 2, 0, 3};
            row = new int[4][3]{{2, 2, 2}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
            col = new int[4][3]{{0, 1, 2}, {2, 1, 0}, {2, 1, 0}, {2, 1, 0}};
        } else {
            rot = new int[4]{5, 3, 0, 2};
            row = new int[4][3]{{2, 2, 2}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
            col = new int[4][3]{{0, 1, 2}, {2, 1, 0}, {2, 1, 0}, {2, 1, 0}};
        }
        break;
    case 'L':
        front = 2;
        if (dir == '+') {
            rot = new int[4]{1, 5, 4, 0};
            row = new int[4][3]{{0, 1, 2}, {0, 1, 2}, {0, 1, 2}, {0, 1, 2}};
            col = new int[4][3]{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        } else {
            rot = new int[4]{1, 0, 4, 5};
            row = new int[4][3]{{0, 1, 2}, {0, 1, 2}, {0, 1, 2}, {0, 1, 2}};
            col = new int[4][3]{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        }
        break;
    case 'R':
        front = 3;
        if (dir == '+') {
            rot = new int[4]{1, 0, 4, 5};
            row = new int[4][3]{{2, 1, 0}, {2, 1, 0}, {2, 1, 0}, {2, 1, 0}};
            col = new int[4][3]{{2, 2, 2}, {2, 2, 2}, {2, 2, 2}, {2, 2, 2}};
        } else {
            rot = new int[4]{1, 5, 4, 0};
            row = new int[4][3]{{2, 1, 0}, {2, 1, 0}, {2, 1, 0}, {2, 1, 0}};
            col = new int[4][3]{{2, 2, 2}, {2, 2, 2}, {2, 2, 2}, {2, 2, 2}};
        }
        break;
    }

    if (dir == '+') {
        char temp[2] = {cube[front][0][0], cube[front][0][1]};
        cube[front][0][0] = cube[front][2][0];
        cube[front][0][1] = cube[front][1][0];
        cube[front][1][0] = cube[front][2][1];
        cube[front][2][0] = cube[front][2][2];
        cube[front][2][1] = cube[front][1][2];
        cube[front][2][2] = cube[front][0][2];
        cube[front][1][2] = temp[1];
        cube[front][0][2] = temp[0];
    } else {
        char temp[2] = {cube[front][0][0], cube[front][0][1]};
        cube[front][0][0] = cube[front][0][2];
        cube[front][0][1] = cube[front][1][2];
        cube[front][0][2] = cube[front][2][2];
        cube[front][1][2] = cube[front][2][1];
        cube[front][2][2] = cube[front][2][0];
        cube[front][2][1] = cube[front][1][0];
        cube[front][2][0] = temp[0];
        cube[front][1][0] = temp[1];
    }

    int sidetemp[3] = {cube[rot[0]][row[0][0]][col[0][0]], cube[rot[0]][row[0][1]][col[0][1]], cube[rot[0]][row[0][2]][col[0][2]]};
    for (int i = 1; i < 4; i++) {
        cube[rot[i - 1]][row[i - 1][0]][col[i - 1][0]] = cube[rot[i]][row[i][0]][col[i][0]];
        cube[rot[i - 1]][row[i - 1][1]][col[i - 1][1]] = cube[rot[i]][row[i][1]][col[i][1]];
        cube[rot[i - 1]][row[i - 1][2]][col[i - 1][2]] = cube[rot[i]][row[i][2]][col[i][2]];
    }
    cube[rot[3]][row[3][0]][col[3][0]] = sidetemp[0];
    cube[rot[3]][row[3][1]][col[3][1]] = sidetemp[1];
    cube[rot[3]][row[3][2]][col[3][2]] = sidetemp[2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    for (int c = 0; c < t; c++) {
        cin >> n;
        cin.ignore();

        cube = new char[6][3][3]{
            {{'w', 'w', 'w'},
            {'w', 'w', 'w'},
            {'w', 'w', 'w'}},
            {{'o', 'o', 'o'},
            {'o', 'o', 'o'},
            {'o', 'o', 'o'}},
            {{'g', 'g', 'g'},
            {'g', 'g', 'g'},
            {'g', 'g', 'g'}},
            {{'b', 'b', 'b'},
            {'b', 'b', 'b'},
            {'b', 'b', 'b'}},
            {{'r', 'r', 'r'},
            {'r', 'r', 'r'},
            {'r', 'r', 'r'}},
            {{'y', 'y', 'y'},
            {'y', 'y', 'y'},
            {'y', 'y', 'y'}},
        };

        for (int i = 0; i < n; i++) {
            string command;
            cin >> command;

            spinCube(command[0], command[1]);
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << cube[0][i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}