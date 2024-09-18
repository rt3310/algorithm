#include <iostream>
#include <deque>
using namespace std;

int n, k;
int pos[100001][2];

void printPath() {
    int cur = n;
    while (cur != k) {
        cout << cur << " ";
        cur = pos[cur][1];
    }
    cout << k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    deque<int> dq;
    dq.push_back(k);
    pos[k][0] = 1;

    while (!dq.empty()) {
        int cur = dq.front(); dq.pop_front();

        if (cur == n) {
            cout << pos[cur][0] - 1 << "\n";
            printPath();
            return 0;
        }

        if (cur - 1 >= 0 && pos[cur - 1][0] == 0) {
            dq.push_back(cur - 1);
            pos[cur - 1][0] = pos[cur][0] + 1;
            pos[cur - 1][1] = cur;
        }

        if (cur + 1 <= 100000 && pos[cur + 1][0] == 0) {
            dq.push_back(cur + 1);
            pos[cur + 1][0] = pos[cur][0] + 1;
            pos[cur + 1][1] = cur;
        }

        if (cur % 2 == 0 && pos[cur / 2][0] == 0) {
            dq.push_back(cur / 2);
            pos[cur / 2][0] = pos[cur][0] + 1;
            pos[cur / 2][1] = cur;
        }
    }

    return 0;
}