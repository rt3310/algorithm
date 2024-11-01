#include <iostream>
#include <algorithm>
using namespace std;

int n, s
int nums[20];
int result = 0;

void search(int start, int total) {
    if (total == s) {
        result++;
    }

    for (int i = start; i < n; i++) {
        int next = total + nums[i];
        if (nums[i] >= 0 && next > s) {
            continue;
        }
        search(i + 1, next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + n);

    search(0, 0);
    if (s == 0) {
        result--;
    }
    cout << result;

    return 0;
}