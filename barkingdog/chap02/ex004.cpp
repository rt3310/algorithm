#include <iostream>
using namespace std;

int func4(int n) {
    int result = 2;

    while (result <= n) {
        if (result * 2 > n) {
            return result;
        }
        result *= 2;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << func4(5) << "\n";
    cout << func4(97615282) << "\n";
    cout << func4(1024) << "\n";

    return 0;
}