#include <iostream>
#include <algorithm>
using namespace std;

using ull = unsigned long long;

int n, m;
int times[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    ull left = 0;
    ull right = 1000000000000000000;
    while (left < right) {
        ull mid = (left + right) / 2;

        ull count = 0;
        for (int i = 0; i < n; i++) {
            count += mid / times[i];
            if (count >= m) {
                break;
            }
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