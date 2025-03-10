#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long revs[1000000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        revs[i] = stoll(s);
    }

    sort(revs, revs + n);

    for (int i = 0; i < n; i++) {
        cout << revs[i] << '\n';
    }

    return 0;
}