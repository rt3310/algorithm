#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n[3];

    for (int i = 0; i < 3; i++) {
        cin >> n[i];
    }

    cout << n[0] + n[1] - n[2] << '\n';
    cout << stoi(to_string(n[0]) + to_string(n[1])) - n[2];

    return 0;
}