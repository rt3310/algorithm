#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int pos[200000];

bool search(int stand) {
    int cur = 0;
    int count = 1;
    for (int i = cur + 1; i < n; i++) {
        if (pos[i] - pos[cur] >= stand) {
            cur = i;
            count++;
        }
    }

    return count >= c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }

    sort(pos, pos + n);
    int left = 1;
    int right = pos[n - 1] - pos[0];
    int result = 1;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (search(mid)) {
            left = mid + 1;
            result = mid;
            continue;
        }
        right = mid - 1;
    }

    cout << result;

    return 0;
}