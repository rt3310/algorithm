#include <iostream>
using namespace std;
int h, w, n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w >> n >> m;
    cout << (h / (n + 1) + (h % (n + 1) >= 1 ? 1 : 0)) * (w / (m + 1) + (w % (m + 1) >= 1 ? 1 : 0));
}