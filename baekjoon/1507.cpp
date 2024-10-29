#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n;
int route[21][21];
bool shortest[21][21];
map<pair<int, int>, int> paths;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> route[i][j];
        }
    }

    for (int m = 0; m < n; m++) {
        for (int i = 0; i < n; i++) {
            if (m == i) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (i == j || i == m || j == m) {
                    continue;
                }

                if (route[i][j] > route[i][m] + route[m][j]) {
                    cout << -1;
                    return 0;
                }

                if (route[i][j] == route[i][m] + route[m][j]) {
                    shortest[i][j] = true;
                }
            }
        }
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (!shortest[i][j]) {
                total += route[i][j];
            }
        }
    }

    cout << total;

    return 0;
}