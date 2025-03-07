#include <iostream>
using namespace std;

int n;
int t[1500000];
int p[1500000];
int price[1500001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> p[i];
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            price[i] = max(price[i], price[i - 1]);
        }
        if (i + t[i] <= n) {
            price[i + t[i]] = max(price[i + t[i]], price[i] + p[i]);
        }
    }

    int result = 0;
    for (int i = 0; i <= n; i++) {
        result = max(result, price[i]);
    }
    cout << result;

    return 0;
}