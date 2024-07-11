#include <iostream>
#include <deque>
using namespace std;

int n;
int map[100][100];
int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void search(pair<int, int> start) {
    deque<pair<int, int>> dq;

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    int r = i + d[k][0];
                    int c = j + d[k][1];
                    if (r < 0 || r >= n || c < 0 || c >= n) {
                        continue;
                    }
                    if (map[r][c] == 0) {
                        map[r][c] = 2;
                    }
                }
            }
        }
    }
    
    return 0;
}