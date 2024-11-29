#include <iostream>
using namespace std;

int n, m;
int space[1000][1000];
int dp[1000][1000][3];
constexpr int MX = 2100000000;
int result = MX;

// ↘ ↓ ↙
//  0 1 2

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> space[i][j];
            dp[i][j][0] = MX;
            dp[i][j][1] = MX;
            dp[i][j][2] = MX;
        }
    }

    for (int i = 0; i < m; i++) {
        dp[0][i][0] = space[0][i];
        dp[0][i][1] = space[0][i];
        dp[0][i][2] = space[0][i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0) {
                dp[i][j][0] = min(dp[i][j][0], space[i][j] + dp[i - 1][j - 1][1]);
                dp[i][j][0] = min(dp[i][j][0], space[i][j] + dp[i - 1][j - 1][2]);
            }

            dp[i][j][1] = min(dp[i][j][1], space[i][j] + dp[i - 1][j][0]);
            dp[i][j][1] = min(dp[i][j][1], space[i][j] + dp[i - 1][j][2]);

            if (j < m - 1) {
                dp[i][j][2] = min(dp[i][j][2], space[i][j] + dp[i - 1][j + 1][0]);
                dp[i][j][2] = min(dp[i][j][2], space[i][j] + dp[i - 1][j + 1][1]);
            }
        }
    }

    int result = MX;
    for (int i = 0; i < m; i++) {
        result = min(result, min(dp[n - 1][i][0], min(dp[n - 1][i][1], dp[n - 1][i][2])));
    }

    cout << result;

    return 0;
}