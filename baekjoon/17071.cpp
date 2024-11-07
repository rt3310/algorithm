#include <iostream>
#include <deque>
using namespace std;

int n, k;
deque<pair<int, int>> dq; // 위치, 구분, 초
int line[500001];
int check[500001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    if (k == n) {
        cout << 0;
        return 0;
    }

    int cur = k;
    for (int i = 1; cur + i <= 500000; i++) {
        line[cur + i] = i;
        cur += i;
    }

    dq.push_back({n, 0});

    while (!dq.empty()) {
        pair<int, int> cur = dq.front(); dq.pop_front();
        int nexts[] = {cur.first - 1, cur.first + 1, cur.first * 2};

        for (int next: nexts) {
            if (next < 0 || next > 500000) {
                continue;
            }

            if (check[next] == 0 || check[next] > cur.second + 1) {
                dq.push_back({next, cur.second + 1});
                if (line[next] > 0) {
                    if (line[next] < cur.second + 1) {
                        continue;
                    }
                    if (next % 2 == 1) {
                        if ((line[next] % 2) != ((cur.second + 1) % 2)) {
                            continue;
                        }
                    } else {
                        if ((line[next] % 2) != ((cur.second + 1) % 2) && (line[next] - (cur.second + 1)) % (next / 2 + 1) != 0) {
                            continue;
                        }
                    }
                }
                check[next] = cur.second + 1;
            }
        }
    }

    int idx = k;
    for (int i = 1; idx + i <= 500000; i++) {
        if (check[idx + i] > 0 && line[idx + i] >= check[idx + i]) {
            cout << line[idx + i];
            return 0;
        }
        idx += i;
    }

    cout << -1;

    return 0;
}