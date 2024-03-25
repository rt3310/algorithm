#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> s;

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        if (n == 0) {
            s.pop();
            continue;
        }
        s.push(n);
    }

    int total = 0;
    while (!s.empty()) {
        total += s.top();
        s.pop();
    }
    cout << total;

    return 0;
}