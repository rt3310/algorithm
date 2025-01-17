#include <iostream>
#include <unordered_set>
using namespace std;

int t, n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int c = 0; c < t; c++) {
        cin >> n;
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            s.insert(num);

        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            int num;
            cin >> num;
            cout << (s.find(num) != s.end() ? 1 : 0) << endl;
        }
    }

    return 0;
}