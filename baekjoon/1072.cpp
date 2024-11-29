#include <iostream>
using namespace std;

long long x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> x >> y;

    int rate = (y * 100) / x;

    if (x == y) {
        cout << -1;
        return 0;
    }

    int target = rate + 1;
    int left = 0;
    int right = 1000000000;
    while (left < right) {
        int mid = (left + right) / 2;
        long long addx = x + mid;
        long long addy = y + mid;
        long long result = addy * 100 / addx;

        if (result < target) {
            left = mid + 1;
            continue;
        }
        right = mid;
    }

    if (rate == (y + right) * 100 / (x + right)) {
        cout << -1;
    } else {
        cout << right;
    }

    return 0;
}