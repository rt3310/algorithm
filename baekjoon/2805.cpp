#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    vector<int> trees;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tree;
        cin >> tree;
        trees.push_back(tree);
    }

    int left = 0;
    int right = 1000000000;
    while (left < right) {
        int mid = (left + right) / 2;

        long long total = 0;
        for (int t : trees) {
            if (mid < t) {
                total += t - mid;
            }
        }

        if (total >= m) {
            left = mid + 1;
            continue;
        }
        right = mid;
    }
    cout << (right < 0 ? 0 : right - 1);

    return 0;
}