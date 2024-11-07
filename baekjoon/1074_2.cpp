#include <iostream>
using namespace std;

int search(int n, int r, int c) {
    if (n == 0)
        return 0;

    int half = 1 << (n - 1);
    if (r < half && c < half) {
        return search(n - 1, r, c);
   }
    if (r < half && c >= half) {
        return half * half + search(n - 1, r, c - half);
    }
    if (r >= half && c < half) {
        return 2 * half * half + search(n - 1, r - half, c);
    }
    return 3 * half * half + search(n - 1, r - half, c - half);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, r, c;
    cin >> n >> r >> c;

    cout << search(n, r, c);

    return 0;
}