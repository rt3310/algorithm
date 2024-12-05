#include <iostream>
using namespace std;

int w, h, p, q, t;
int x = 1, y = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> w >> h;
    cin >> p >> q;
    cin >> t;

    int shuttlex = t / w;
    int shuttley = t / h;
    int remainx = t % w;
    int remainy = t % h;

    int curx = 0, cury = 0;
    if (shuttlex % 2 == 1) {
        curx = w;
    }
    if (shuttley % 2 == 1) {
        cury = h;
    }

    for (int i = 0; i < p + remainx; i++) {
        if (curx == w) {
            x = -1;
        } else if (curx == 0) {
            x = 1;
        }
        curx += x;
    }

    for (int i = 0; i < q + remainy; i++) {
        if (cury == h) {
            y = -1;
        } else if (cury == 0) {
            y = 1;
        }
        cury += y;
    }

    cout << curx << ' ' << cury;


    return 0;
}