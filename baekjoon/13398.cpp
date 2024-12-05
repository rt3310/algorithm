#include <iostream>
using namespace std;

int n;
int sums[100000];
int mn = 0;
int minIdx = -1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> sums[i];
        if (sums[i] < mn) {
            mn = sums[i];
            minIdx = i;
        }
    }

    int mx = -100000000;
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (minIdx == i) {
            continue;
        }
        if (sums[i] > total + sums[i]) {
            total = sums[i];
        } else {
            total += sums[i];
        }
        mx = max(mx, total);
    }

    cout << mx;

    return 0;
}