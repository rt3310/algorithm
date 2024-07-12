#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        int s, e, k;
        cin >> s >> e >> k;
        vector<int> tmp;
        for (int j = s - 1; j < e; j++) {
            tmp.push_back(arr[j]);
        }
        sort(tmp.begin(), tmp.end());
        cout << tmp[k - 1] << "\n";
    }
}
