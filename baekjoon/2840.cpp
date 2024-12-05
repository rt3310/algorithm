#include <iostream>
#include <unordered_set>
using namespace std;

int n, k;
char wheel[25];
unordered_set<char> check;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    int idx = 0;
    for (int i = 0; i < k; i++) {
        int s;
        char alpha;
        cin >> s >> alpha;

        idx = (idx + s) % n;
        if (wheel[idx] != 0 && wheel[idx] != alpha) {
            cout << '!';
            return 0;
        }

        if (wheel[idx] == 0 && check.find(alpha) != check.end()) {
            cout << '!';
            return 0;
        }

        wheel[idx] = alpha;
        check.insert(alpha);
    }

    int end = idx;
    do {
        if (wheel[idx] == 0) {
            cout << '?';
        } else {
            cout << wheel[idx];
        }
        idx--;
        if (idx < 0) {
            idx = n - 1;
        }
    } while (idx != end);

    return 0;
}