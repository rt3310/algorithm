#include <iostream>
#include <list>
using namespace std;

int n;
list<pair<int, int>> balloon;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        balloon.push_back({num, i});
    }

    auto cur = balloon.begin();
    for (int remove = 0; remove < n; remove++) {
        int next = cur->first;

        auto prev = cur;
        if (next > 0) {
            cur++;
            if (cur == balloon.end()) {
                cur = balloon.begin();
            }
        } else {
            if (cur == balloon.begin()) {
                cur = balloon.end();
            }
            cur--;
        }
        balloon.erase(prev);
        cout << prev->second << ' ';

        if (remove == n - 1) {
            return 0;
        }

        if (next > 0) {
            for (int i = 0; i < next - 1; i++) {
                cur++;
                if (cur == balloon.end()) {
                    cur = balloon.begin();
                }
            }
        } else {
            for (int i = 0; i > next + 1; i--) {
                if (cur == balloon.begin()) {
                    cur = balloon.end();
                }
                cur--;
            }
        }
    }

    return 0;
}