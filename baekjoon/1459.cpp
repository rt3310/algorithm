#include <iostream>
#include <queue>
using namespace std;

long long x, y, w, s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> x >> y >> w >> s;

    long long total = 0;
    if (s <= w * 2) {
        int cross = min(x, y);
        x -= cross;
        y -= cross;

        total += cross * s;

        if (s < w) {
            if ((x + y) % 2 == 1) {
                total += (x + y - 1) * s;
                total += w;
            } else {
                total += (x + y) * s;
            }
        } else {
            total += (x + y) * w;
        }
    } else {
        total += (x + y) * w;
    }

    cout << total;

    return 0;
}