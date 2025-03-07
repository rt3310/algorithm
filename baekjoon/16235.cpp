#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int n, m, k;
int A[10][10];
int land[10][10];
deque<int> trees[10][10];
int dead[10][10];
int sides[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int seedlingTreeTotal[10][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            land[i][j] = 5;
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        trees[x - 1][y - 1].push_back(z);
        if (z % 5 == 0) {
            seedlingTreeTotal[x - 1][y - 1]++;
        }
    }

    for (int year = 0; year < k; year++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vector<int> temp;
                while (!trees[i][j].empty()) {
                    int age = trees[i][j].front(); trees[i][j].pop_front();

                    if (age % 5 == 0) {
                        seedlingTreeTotal[i][j]--;
                    }
                    if (age <= land[i][j]) {
                        land[i][j] -= age;
                        temp.push_back(age + 1);
                    } else {
                        dead[i][j] += age / 2;
                    }
                }

                for (int t : temp) {
                    if (t % 5 == 0) {
                        seedlingTreeTotal[i][j]++;
                    }
                    trees[i][j].push_back(t);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                land[i][j] += dead[i][j];
                dead[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (seedlingTreeTotal[i][j] > 0) {
                    for (int* side : sides) {
                        int r = i + side[0];
                        int c = j + side[1];
                        if (r < 0 || r >= n || c < 0 || c >= n) {
                            continue;
                        }
                        for (int count = 0; count < seedlingTreeTotal[i][j]; count++) {
                            trees[r][c].push_front(1);
                        }
                    }
                }
                land[i][j] += A[i][j];
            }
        }
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            total += trees[i][j].size();
        }
    }

    cout << total;

    return 0;
}