#include <iostream>
#include <cmath>
using namespace std;

int func3(int n) {

    int left = 0;
    int right = n;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (mid * mid == n) {
            return 1;
        }

        if (mid * mid < n) {
            left = mid + 1;
            continue;
        }
        right = mid - 1;
    }

    return 0;
}

int main() {
    cout << func3(9) << "\n";
    cout << func3(693953651) << "\n";
    cout << func3(756580036) << "\n";
    return 0;
}