#include <iostream>
#include <deque>
using namespace std;

int n, k;
int path[500001];
int bro[500001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    int move = 1;
    bro[k] = 1;
    while (k <= 500000) {
        k += move;
        if (k > 500000) {
            break;
        }
        bro[k] = move + 1;
        move++;
    }

    deque<int> dq;
    dq.push_back(n);
    path[n] = 1;

    while (!dq.empty()) {
        int cur = dq.front(); dq.pop_front();
        cout << cur << endl;

        if (cur < 0 || cur > 500000) {
            continue;
        }

        int nexts[3] = { cur + 1, cur - 1, cur * 2 };
        for (int next : nexts) {
            if (next >= 0 && next <= 500000) {
                if (path[next] == 0 && bro[next] <= path[cur] + 1) {
                    cout << path[cur];
                    return 0;
                }
                path[next] = path[cur] + 1;
                dq.push_back(next);
            }
        }
    }
    return 0;
}