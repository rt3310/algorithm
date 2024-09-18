#include <iostream>
using namespace std;

int n, m;
int land[100001];
int soil[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> land[i];
    }

    for (int i = 0; i < m; i++) {
        int a, b, k;
        cin >> a >> b >> k;
        soil[a - 1] += k;
        soil[b] += -k;
    }

    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur += soil[i];
        cout << land[i] + cur << ' ';
    }

    return 0;
}