#include <cstdio>
using namespace std;

int cogwheel[4][8];
int leftRight[4][2];
int k;
int result = 0;

// checkDir) 1: left, 2: right, 3: both 
void rotate(int cog, int dir, int checkDir, int prevPole) {
    if (cog > 3 || cog < 0) {
        return;
    }
    int left = cogwheel[cog][leftRight[cog][0]];
    int right = cogwheel[cog][leftRight[cog][1]];
    if (checkDir == 3
    || (checkDir == 1 && (right != prevPole))
    || (checkDir == 2 && (left != prevPole))) {
        leftRight[cog][0] -= dir;
        leftRight[cog][1] -= dir;
        if (leftRight[cog][0] < 0) {
            leftRight[cog][0] = 7;
        }
        if (leftRight[cog][1] < 0) {
            leftRight[cog][1] = 7;
        }
        leftRight[cog][0] %= 8;
        leftRight[cog][1] %= 8;

        if (checkDir & 1) {
            rotate(cog - 1, -dir, 1, left);
        }
        if (checkDir & 2) {
            rotate(cog + 1, -dir, 2, right);
        }
    } 
}

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%1d", &cogwheel[i][j]);
        }
        leftRight[i][0] = 6;
        leftRight[i][1] = 2;
    }

    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int cog, dir; // -> 1 / <- -1
        scanf("%d %d", &cog, &dir);
        rotate(cog - 1, dir, 3, 0);
    }

    for (int i = 0; i < 4; i++) {
        result += (cogwheel[i][(leftRight[i][0] + 2) % 8] << i);
    }

    printf("%d", result);

    return 0;
}