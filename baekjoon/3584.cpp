#include <iostream>
#include <unordered_set>
using namespace std;

int t, n;
int parent[10001];
unordered_set<int> s;

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
        int cur1 = n1, cur2 = n2;
        while (cur1 != 0) {
            s.insert(cur1);
            cur1 = parent[cur1];
        }
        while (cur2 != 0) {
            if (s.find(cur2) != s.end()) {
                cout << cur2 << '\n';
                break;
            }
            cur2 = parent[cur2];
        }
        s.clear();

        for (int i = 0; i <= n; i++) {
            parent[i] = 0;
        }
    }

    return 0;
}