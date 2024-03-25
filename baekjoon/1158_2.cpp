#include <iostream>
#include <vector>
using namespace std;

int nxt[5000];
int prv[5000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums;
    int n, k;

    cin >> n >> k;

    nums.push_back(-1);
    prv[0] = -1;
    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
        nxt[i - 1] = i;
        prv[i] = i - 1;
    }
    prv[1] = n;
    nxt[n] = 1;

    int cur = k;
    cout << "<";
    for (int i = 0; i < n; i++) {
        cout << nums[cur];
        if (i < n - 1) {
            cout << ", ";
        }
        nxt[prv[cur]] = nxt[cur];
        prv[nxt[cur]] = prv[cur];
        cur = prv[cur];

        for (int j = 0; j < k; j++) {
            cur = nxt[cur];
        }
    }
    cout << ">";

    return 0;
}