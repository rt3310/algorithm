#include <iostream>
using namespace std;

int n, m, k;
int notebook[40][40];
int stickerSize[100][2];
int sticker[100][4][10][10];
int result = 0;

void attach(int stickerIdx, int rotIdx, int startRow, int startCol) {
    int rotN = stickerSize[stickerIdx][0];
    int rotM = stickerSize[stickerIdx][1];
    if (rotIdx % 2 == 1) {
        rotN = stickerSize[stickerIdx][1];
        rotM = stickerSize[stickerIdx][0];
    }
    for (int i = 0; i < rotN; i++) {
        for (int j = 0; j < rotM; j++) {
            notebook[startRow + i][startCol + j] |= sticker[stickerIdx][rotIdx][i][j];
        }
    }
}

void rotate(int stickerIdx, int rotateCount) {
    int rotN = stickerSize[stickerIdx][0];
    int rotM = stickerSize[stickerIdx][1];
    if (rotateCount % 2 == 1) {
        rotN = stickerSize[stickerIdx][1];
        rotM = stickerSize[stickerIdx][0];
    }
    for (int i = 0; i < rotM; i++) {
        for (int j = 0; j < rotN; j++) {
            sticker[stickerIdx][rotateCount][j][rotM  - i - 1] = sticker[stickerIdx][rotateCount - 1][i][j];
        }
    }
}

bool isOverlapped(int stickerIdx, int rotIdx, int startRow, int startCol) {
    int rotN = stickerSize[stickerIdx][0];
    int rotM = stickerSize[stickerIdx][1];
    if (rotIdx % 2 == 1) {
        rotN = stickerSize[stickerIdx][1];
        rotM = stickerSize[stickerIdx][0];
    }
    for (int i = 0; i < rotN; i++) {
        for (int j = 0; j < rotM; j++) {
            if (notebook[startRow + i][startCol + j] == 1 && sticker[stickerIdx][rotIdx][i][j] == 1) {
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
                cin >> sticker[i][0][r][c];
            }
        }

        for (int j = 1; j <= 3; j++) {
            rotate(i, j);
        }
    }

    for (int i = 0; i < k; i++) {
        bool attached = false;

        for (int rot = 0; rot < 4; rot++) {
            int rotN = stickerSize[i][0];
            int rotM = stickerSize[i][1];
            if (rot % 2 == 1) {
                rotN = stickerSize[i][1];
                rotM = stickerSize[i][0];
            }

            for (int downShift = 0; downShift < n; downShift++) {
                for (int rightShift = 0; rightShift < m; rightShift++) {

                    if (rotN + downShift > n || rotM + rightShift > m) {
                        continue;
                    }

                    if (!isOverlapped(i, rot, downShift, rightShift)) {
                        attach(i, rot, downShift, rightShift);
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