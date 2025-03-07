#include <iostream>
#include <cmath>
using namespace std;

int t, x, y;

int search() {
    int dist = y - x;

    if (dist <= 3) {
        return dist;
    }

    int i = sqrt(y - x);

    if (dist == i * i) {
        return i * 2 - 1;
    }
    
    if (dist <= (i + 1) * i) {
        return i * 2;
    } 

    return i * 2 + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> x >> y;

        cout << search() << '\n';
    }

    return 0;
}