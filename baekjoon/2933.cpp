#include <iostream>
using namespace std;

int r, c, n;
int cave[100][100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> cave[i][j];
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;
    }

    return 0;
}