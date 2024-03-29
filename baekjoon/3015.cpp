#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<pair<long long, long long>> s;
    long long result = 0;
    for (int i = 0; i < n; i++) {
        long long h;
        cin >> h;

        long long value = 1;
        while (!s.empty()) {
            pair<long long, long long> t = s.top();
            if (t.first > h) {
                result++;
                break;
            }

            result += t.second;
            if (t.first == h) {
                value += t.second;
            }
            s.pop();
        }
        s.push({h, value});
    }

    cout << result;
    return 0;
}