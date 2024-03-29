#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> s;

    int n;
    cin >> n;

    int cur = 1;
    vector<char> answer;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        while (cur <= num) {
            s.push(cur);
            cur++;
            answer.push_back('+');
        }

        while (!s.empty()) {
            int t = s.top();
            s.pop();
            answer.push_back('-');

            if (t == num) {
                break;
            }

            cout << "NO";
            return 0;
        }
    }

    for (char ans : answer) {
        cout << ans << "\n";
    }

    return 0;
}