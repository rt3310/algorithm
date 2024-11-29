#include <iostream>
using namespace std;

int n;
int path[1000];
int dp[1100];
const int INF = 2100000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> path[i];
        dp[i] = INF;
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int range = path[i];
        for (int j = 1; j <= range; j++) {
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }

    cout << (dp[n - 1] == INF ? -1 : dp[n - 1] - 1);

    return 0;
}