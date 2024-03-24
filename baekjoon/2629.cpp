#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k; // n <= 30, k <= 7

    cin >> n;

    bool dp[40001] = {false, };
    int mx = 1;
    for (int i = 0; i < n; i++) {
        int chu;
        cin >> chu;
        int curMx = max(chu, mx);
        vector<int> next {chu};
        for (int j = mx; j > 0; j--) {
            if (dp[j]) {
                next.push_back(chu + j);
                next.push_back(abs(chu - j));
                curMx = max(chu + j, curMx);
            }
        }

        for (int nxt: next) {
            dp[nxt] = true;
        }
        mx = max(mx, curMx);
    }

    cin >> k;

    for (int i = 0; i < k; i++) {
        int marble;
        cin >> marble;
        if (dp[marble]) {
            cout << "Y ";
        } else {
            cout << "N ";
        }
    }

    return 0;
}