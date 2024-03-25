#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    stack<pair<int, int>> s;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;

        bool exists = false;
        while (!s.empty()) {
            pair<int, int> t = s.top();
            s.pop();

            if (t.first > num) {
                cout << t.second << " ";
                s.push(t);
                exists = true;
                break;
            }
        }

        if (!exists) {
            cout << "0 ";
        }
        s.push({num, i});
    }

    return 0;
}