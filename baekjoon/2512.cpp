#include <iostream>
#define ll long long
using namespace std;

int n;
ll city[10000];
ll m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    ll maxMoney = 0;
    for (int i = 0; i < n; i++) {
        cin >> city[i];
        maxMoney = max(maxMoney, city[i]);
    }

    cin >> m;

    ll left = 0;
    ll right = maxMoney + 1;
    while (left < right) {
        ll mid = (left + right) / 2;

        ll total = 0;
        for (int i = 0; i < n; i++) {
            total += min(city[i], mid);
        }

        if (total <= m) {
            left = mid + 1;
            continue;
        }
        right = mid;
    }

    cout << right - 1;

    return 0;
}
