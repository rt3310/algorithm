#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    if (n == 0) {
        return 0;
    }

    stack<vector<int>> s;
    for (int i = 0; i < n; i++) {
        long long h;
        cin >> h;

        int w = 1;
        int prevH = 1;
        while (!s.empty()) {
            
        }
        s.push(vector<int> {h, min(h, prevH), });
    }
}