#include <iostream>
#include <deque>
using namespace std;

int t, n, stock[1000000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    for (int i = 0; i < t; i++) {
        deque<pair<int, int>> dq;
        cin >> n; 

        for (int j = 0; j < n; j++) {
            cin >> stock[j];
        }
        stock[n] = 0;

        for (int j = 1; j < n; j++) {
            if (stock[j] > stock[j - 1] && stock[j] > stock[j + 1]) {
                dq.push_back({j, stock[j]});
            }
        }

        int curIdx = 0;
        int dqIdx = 0;
        long long total = 0;
        while (dqIdx < dq.size()) {
            int maxDqIdx = 0;
            int maxIdx = 0;
            int maxNumber = 0;
            for (int j = dqIdx; j < dq.size(); j++) {
                if (dq[j].second > maxNumber) {
                    maxDqIdx = j;
                    maxIdx = dq[j].first;
                    maxNumber = dq[j].second;
                }
            }
            for (int j = curIdx; j < maxIdx; j++) {
                if (maxNumber - stock[j] > 0) {
                    total += maxNumber - stock[j];
                }
            }
            dqIdx = maxDqIdx + 1;
            curIdx = maxIdx + 1;
        }
        cout << total << '\n';
    }

    return 0;
}