#include <iostream>
using namespace std;

int N, gr, gc;

void search(int r, int c, int n, int total) {
    if (n == 0) {
        cout << total << '\n';
        return;
    }

    int half = (1 << n) / 2;

    if (r < half && c < half) {
        search(r, c, n - 1, total);
    } else if (r < half && c >= half) {
        search(r, c - half, n - 1, total + (half * half));
    } else if (r >= half && c < half) {
        search(r - half, c, n - 1, total + (half * half * 2));
    } else {
        search(r - half, c - half, n - 1, total + (half * half * 3));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> gr >> gc;

    search(gr, gc, N, 0);
}