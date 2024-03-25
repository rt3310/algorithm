#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    stack<pair<int, int>> s;
    int answer[n];
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        while (!s.empty()) {
            pair<int, int> t = s.top();

            if (t.first >= num) {
                break;
            }

            answer[t.second] = num;
            s.pop();
        }
        s.push({num, i});
    }

    while (!s.empty()) {
        pair<int, int> t = s.top();
        s.pop();

        answer[t.second] = -1;
    }

    for (int ans : answer) {
        cout << ans << " ";
    }
    return 0;
}