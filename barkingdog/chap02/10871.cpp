#include <iostream>
using namespace std;

int n, x;

int main() {
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num < x) {
            cout << num << " ";
        }
    }

    return 0;
}