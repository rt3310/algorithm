#include <iostream>
using namespace std;

int paper[7];
int remain[7];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i <= 6; i++) {
        cin >> paper[i];
    }

    int total = paper[6] + paper[5] + paper[4] + (paper[3] / 4) + (paper[2] / 9) + (paper[1] / 36);
    paper[6] = 0;
    remain[1] = paper[5] * 11;
    paper[5] = 0;
    remain[2] = paper[4] * 5;
    paper[4] = 0;
    remain[3] = paper[3] % 4;
    paper[3] = 0;
    paper[2] %= 9;
    paper[1] %= 36;

    if (paper[2] >= 5) {
        if (remain[3] >= 3) {
            remain[3] -= 3;
            remain[1] += 7;
            paper[2] -= 5;
        }

        if (remain[2] > 0) {
            if (paper[2] > remain[2]) {
                paper[2] -= remain[2];
                remain[2] = 0;
            } else {
                remain[2] -= paper[2];
                paper[2] = 0;
            }
        }
    }
    
    if (paper[2] >= 3) {
        if (remain[3] == 2) {
            remain[3] -= 2;
            remain[1] += 6;
            paper[2] -= 3;
        }

        if (remain[2] > 0) {
            if (paper[2] > remain[2]) {
                paper[2] -= remain[2];
                remain[2] = 0;
            } else {
                remain[2] -= paper[2];
                paper[2] = 0;
            }
        }
    }

    if (paper[2] > 0) {
        if (remain[3] == 1) {
            remain[3] -= 1;
            remain[1] += 5;
            paper[2] -= 1;
        }

        if (remain[2] > 0) {
            if (paper[2] > remain[2]) {
                paper[2] -= remain[2];
                remain[2] = 0;
            } else {
                remain[2] -= paper[2];
                paper[2] = 0;
            }
        }
    }

    if (paper[1] > remain[1]) {
        total++;
    }

    cout << total << '\n';

    return 0;
}