#include <iostream>
using namespace std;

using ll = long long;

ll fact[20];
ll n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    if (n == 0) {
        cout << "NO";
        return 0;
    }

    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < 20; i++) {
        fact[i] = fact[i - 1] * i;
    }

    for (int i = 19; i >= 0; i--) {
        if (n >= fact[i]) {
            n -= fact[i];
        }
        if (n == 0) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}