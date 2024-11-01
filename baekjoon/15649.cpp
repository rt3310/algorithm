#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
bool check[9];

void search(int depth) {
    if (depth == m) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (check[i]) {
            continue;
        }
        v.push_back(i);
        check[i] = true;
        search(depth + 1);
        v.pop_back();
        check[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    search(0);
    return 0;
}