#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int mx = 0;
    int idx = 0;
    for (int i = 0; i < 9; i++) {
        int num;
        cin >> num;

        if (num > mx) {
            mx = num;
            idx = i + 1;
        }
    }

    cout << mx << "\n" << idx;
}