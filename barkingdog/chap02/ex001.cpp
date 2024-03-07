#include <iostream>
using namespace std;

int func1(int n) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            result += i;
        }
    }

    return result;
}

int main() {
    cout << func1(16) << "\n";
    return 0;
}