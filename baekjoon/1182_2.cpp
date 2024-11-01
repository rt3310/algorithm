#include <iostream>
using namespace std;

int n, s;
int nums[20];
int result = 0;

void search(int cur, int total) {
    if (cur == n) {
        if (total == s) {
            result++;
        }
        return;
    }

    search(cur + 1, total);
    search(cur + 1, total + nums[cur]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    search(0, 0);
    if (s == 0) {
        result--;
    }
    cout << result;

    return 0;
}