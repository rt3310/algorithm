#include <iostream>
using namespace std;

using ll = long long;

int k, n;
ll ran[10000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> k >> n;

    for (int i = 0; i < k; i++) {
        cin >> ran[i];
    }

    ll left = 0;
    ll right = (1LL << 31) - 1;
    while (left < right) {
        ll mid = (left + right) / 2;

        ll count = 0;
        for (int i = 0; i < k; i++) {
            count += ran[i] / mid;
            if (count > n) {
                break;
            }
        }

        if (count >= n) {
            left = mid + 1;
            continue;
        }
        right = mid;
    }

    cout << right - 1;

    return 0;
}