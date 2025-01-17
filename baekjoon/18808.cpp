#include <iostream>
using namespace std;

int n, m, k;
int notebook[40][40];
int stickerSize[100][2];
int sticker[100][10][10];
int result = 0;

void attach(int stickerIdx, int startRow, int startCol) {
    for (int i = 0; i < stickerSize[stickerIdx][0]; i++) {
        for (int j = 0; j < stickerSize[stickerIdx][1]; j++) {
            notebook[startRow + i][startCol + j] |= sticker[stickerIdx][i][j];
        }
    }
}

void rotate(int stickerIdx) {
    int rotateN = stickerSize[stickerIdx][1];
    int rotateM = stickerSize[stickerIdx][0];
    int temp[rotateN][rotateM];

    for (int i = 0; i < rotateM; i++) {
        for (int j = 0; j < rotateN; j++) {
            temp[j][rotateM - i - 1] = sticker[stickerIdx][i][j];
        }
    }

    for (int i = 0; i < rotateN; i++) {
        for (int j = 0; j < rotateM; j++) {
            sticker[stickerIdx][i][j] = temp[i][j];
        }
    }

    stickerSize[stickerIdx][0] = rotateN;
    stickerSize[stickerIdx][1] = rotateM;
}

bool isOverlapped(int stickerIdx, int startRow, int startCol) {
    for (int i = 0; i < stickerSize[stickerIdx][0]; i++) {
        for (int j = 0; j < stickerSize[stickerIdx][1]; j++) {
            if (notebook[startRow + i][startCol + j] == 1 && sticker[stickerIdx][i][j] == 1) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        cin >> stickerSize[i][0] >> stickerSize[i][1];
        for (int r = 0; r < stickerSize[i][0]; r++) {
            for (int c = 0; c < stickerSize[i][1]; c++) {
                cin >> sticker[i][r][c];
            }
        }

        bool attached = false;

        for (int rot = 0; rot < 4; rot++) {
            for (int downShift = 0; downShift < n; downShift++) {
                for (int rightShift = 0; rightShift < m; rightShift++) {
                    if (stickerSize[i][0] + downShift > n || stickerSize[i][1] + rightShift > m) {
                        continue;
                    }

                    if (!isOverlapped(i, downShift, rightShift)) {
                        attach(i, downShift, rightShift);
                        attached = true;
                    }

                    if (attached) {
                        break;
                    }
                }
                if (attached) {
                    break;
                }
            }
            if (attached) {
                break;
            }
            rotate(i);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (notebook[i][j] > 0) {
                result++;
            }
        }
    }

    cout << result;
    return 0;
}