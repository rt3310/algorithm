#include <cstdio>
#include <vector>
using namespace std;

bool hor[9][10];
bool ver[9][10];
bool box[9][10];

int sudoku[9][9];

vector<pair<int, int>> v;
bool finish = false;

int getBoxOrder(int i, int j) {
    if (i <= 2) {
        if (j <= 2) {
            return 0;
        }
        if (j <= 5) {
            return 1;
        }
        return 2;
    }
    
    if (i <= 5) {
        if (j <= 2) {
            return 3;
        }
        if (j <= 5) {
            return 4;
        }
        return 5;
    }

    if (j <= 2) {
        return 6;
    }
    if (j <= 5) {
        return 7;
    }
    return 8;
}

void search(int idx) {
    if (finish) {
        return;
    }
    if (idx == v.size()) {
        finish = true;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d", sudoku[i][j]);
            }
            printf("\n");
        }
        return;
    }

    int curr = v[idx].first;
    int curc = v[idx].second;
    for (int i = 1; i <= 9; i++) {
        if (hor[curr][i]) {
            continue;
        }
        if (ver[curc][i]) {
            continue;
        }
        if (box[getBoxOrder(curr, curc)][i]) {
            continue;
        }
        sudoku[curr][curc] = i;
        hor[curr][i] = true;
        ver[curc][i] = true;
        box[getBoxOrder(curr, curc)][i] = true;
        search(idx + 1);
        hor[curr][i] = false;
        ver[curc][i] = false;
        box[getBoxOrder(curr, curc)][i] = false;
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%1d", &sudoku[i][j]);
            hor[i][sudoku[i][j]] = true;
            ver[j][sudoku[i][j]] = true;
            box[getBoxOrder(i, j)][sudoku[i][j]] = true;
            if (sudoku[i][j] == 0)
                v.push_back({i, j});
        }
    }

    search(0);

    return 0;
}