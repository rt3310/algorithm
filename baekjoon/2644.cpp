#include <iostream>
using namespace std;

int n, a, b, m;
int parent[101];

auto a = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> a >> b;

    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        parent[y] = x;
    }

    return 0;
}