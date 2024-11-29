#include <iostream>
using namespace std;

using ll = long long;

int n, m;
ll times[1000000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    ll left = 0;
    ll right = 1000000000000;
    while (left < right) {
        ll mid = (left + right) / 2;

        ll count = 0;
        for (int i = 0; i < n; i++) {
            count += mid / times[i];
        }

        if (count < m) {
            left = mid + 1;
            continue;
        }
        right = mid;
    }

    cout << right;

    return 0;
}