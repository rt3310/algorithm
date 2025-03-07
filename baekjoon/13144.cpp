#include <iostream>
using namespace std;

int n;
int perm[100001];
bool check[100001];
long long result = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> perm[i];
    }

    int left = 0;
    int right = 0;
    int prevRight = 0;
    check[perm[0]] = true;
    while (left < n && right < n) {
        while (right < n - 1 && !check[perm[right + 1]]) {
            right++;
            check[perm[right]] = true;
        }

        result += right - left + 1;
        check[perm[left]] = false;
        left++;
    }

    cout << result;

    return 0;
}