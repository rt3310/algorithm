#include <iostream>
#define ll long long
using namespace std;

ll a, b, c;

ll search(ll num) {
    if (num == 1) {
        return a % c;
    }

    ll half = search(num / 2);
    ll result = (half * half) % c;
    if (num % 2) {
        result *= a % c;
    }
    return result % c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b >> c;

    cout << search(b);

    return 0;
}