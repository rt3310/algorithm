#include <iostream>
#include <vector>
using namespace std;

int n, k = 0;
int total = 0;
vector<pair<int, int>> result;

void hanoi(int from, int mid, int to, int cnt) {
    if (cnt == 0) {
        return;
    }

    hanoi(from, to, mid, cnt - 1);
    total++;
    result.push_back({from, to});
    hanoi(mid, from, to, cnt - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    hanoi(1, 2, 3, n);
    cout << total << '\n';
    for (auto p : result) {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}