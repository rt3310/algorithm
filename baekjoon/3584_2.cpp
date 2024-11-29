#include <iostream>
using namespace std;

int t, n;
int parent[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    for (int c = 0; c < t; c++) {
        cin >> n;
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            parent[b] = a;
        }

        int n1, n2;
        cin >> n1 >> n2;
        int depth1 = 0, depth2 = 0;
        int cur1 = n1, cur2 = n2;
        while (parent[cur1] != 0) {
            cur1 = parent[cur1];
            depth1++;
        }
        while (parent[cur2] != 0) {
            cur2 = parent[cur2];
            depth2++;
        }

        if (depth1 > depth2) {
            for (int j = 0; j < depth1 - depth2; j++) {
                n1 = parent[n1];
            }
        } else if (depth1 < depth2) {
            for (int j = 0; j < depth2 - depth1; j++) {
                n2 = parent[n2];
            }
        }

        while (n1 != n2) {
            n1 = parent[n1];
            n2 = parent[n2];
        }
        cout << n1 << '\n';

        for (int i = 0; i <= n; i++) {
            parent[i] = 0;
        }
    }

    return 0;
}