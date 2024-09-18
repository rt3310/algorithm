#include <iostream>
using namespace std;

int n, k;
int dp[101][100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        for (int j = 0; j <= k; j++) {
            if (j >= w) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - w] + v);
            }

            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }

    }
    cout << dp[n][k];

    return 0;
}