#include <iostream>
using namespace std;

int n, k, q, m;
bool sleep[5003];
bool attendCode[5003];

void attendCheck(int cur) {
    if (cur > n + 2) {
        return;
    }

    attendCode[cur] = true;
    for (int j = 2; cur * j <= n + 2; j++) {
        if (sleep[cur * j] || attendCode[cur * j]) {
            continue;
        }

        attendCheck(cur * j);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> q >> m;

    for (int i = 0 ; i < k; i++) {
        int slp;
        cin >> slp;
        sleep[slp] = true;
    }

    for (int i = 0; i < q; i++) {
        int attend;
        cin >> attend;

        if (sleep[attend] || attendCode[attend]) {
            continue;
        }

        attendCheck(attend);
    }

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;

        int count = 0;
        for (int j = s; j <= e; j++) {
            if (!attendCode[j]) {
                count++;
            }
        }

        cout << count << '\n';
    }

    return 0;
}