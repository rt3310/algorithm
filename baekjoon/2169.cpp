#include <iostream>
#include <queue>
using namespace std;

int n, m;
int region[1000][1000];
int cost[1000][1000][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> region[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cost[i][j][0] = region[i][j];
            cost[i][j][1] = region[i][j];
        }
    }

    for (int i = 1; i < m; i++) {
        cost[0][i][0] += cost[0][i - 1][0];
        cost[0][i][1] += cost[0][i - 1][1];
    }

    for (int i = 1; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            cost[i][j][0] += max(cost[i - 1][j][0], cost[i - 1][j][1]);

            if (j < m - 1) {
                cost[i][j][0] = max(cost[i][j][0], cost[i][j + 1][0] + region[i][j]);
            }
        }
        for (int j = 0; j < m; j++) {
            cost[i][j][1] += max(cost[i - 1][j][0], cost[i - 1][j][1]);
            if (j > 0) {
                cost[i][j][1] = max(cost[i][j][1], cost[i][j - 1][1] + region[i][j]);
            }
        }
    }

    cout << max(cost[n - 1][m - 1][0], cost[n - 1][m - 1][1]);

    return 0;
}