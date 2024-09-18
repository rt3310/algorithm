#include <iostream>
using namespace std;

int n, k;
int dp[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        if (w > k) {
            continue;
        }
        for (int j = k; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }

    }
    cout << dp[k];

    return 0;
}