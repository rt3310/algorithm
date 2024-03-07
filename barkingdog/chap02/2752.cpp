#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;

    for (int i = 0; i < 3; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    for (const int& n : v) {
        cout << n << " ";
    }
    return 0;
}