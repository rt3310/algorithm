#include <iostream>
using namespace std;

int n;
int nums[200];
int length[200];
int maxLength = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
        length[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                length[i] = max(length[i], length[j] + 1);
            }
        }
        maxLength = max(maxLength, length[i]);
    }

    cout << (n - maxLength);

    return 0;
}