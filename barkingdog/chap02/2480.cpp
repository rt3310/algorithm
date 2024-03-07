#include <iostream>
using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;
    
    if (a == b && b == c) {
        cout << 10000 + (a * 1000);
        return 0;
    }

    if (a == b || a == c) {
        cout << 1000 + (a * 100);
        return 0;
    } 
    if (b == c) {
        cout << 1000 + (b * 100);
        return 0;
    }

    cout << max(a, max(b, c)) * 100;
    return 0;
}