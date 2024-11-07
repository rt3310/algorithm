#include <iostream>
using namespace std;

int main() {
    int a[10] = {3, 79, 10, 611, 4, 2, 7, 8, 9, 1};

    int st = 0;
    int nd = 0;
    for (int n : a) {
        if (n > st) {
            nd = st;
            st = n;
            continue;
        }
        if (n > nd) {
            nd = n;
        }
    }
    cout << "first: " << st << ", second: " << nd << endl;
    return 0;
}