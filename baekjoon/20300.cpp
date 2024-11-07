#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

int n;
ll machine[10000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> machine[i];
    }
    sort(machine, machine + n);

    ll maxi = 0;
    int left = 0;
    int right = n - 1;
    if (n % 2 == 1) {
        maxi = machine[n - 1];
        right = n - 2;
    }

    while (left < right) {
        ll sum = machine[left] + machine[right];
        maxi = max(maxi, sum);
        left++;
        right--;
    }

    cout << maxi;

    return 0;
}