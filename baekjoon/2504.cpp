#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);

    stack<char> st;
    int total = 0;
    int temp = 1;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '(') {
            st.push(c);
            temp *= 2;
            continue;
        }

        if (c == '[') {
            st.push(c);
            temp *= 3;
            continue;
        }

        if (st.empty()) {
            cout << 0;
            return 0;
        }

        if (c == ')') {
            char t = st.top();
            if (t != '(') {
                cout << 0;
                return 0;
            }
            if (s[i - 1] == '(') {
                total += temp;
            }
            temp /= 2;
            st.pop();
            continue;
        }

        if (c == ']') {
            char t = st.top();
            if (t != '[') {
                cout << 0;
                return 0;
            }
            if (s[i - 1] == '[') {
                total += temp;
            }
            temp /= 3;
            st.pop();
            continue;
        }

    }

    if (!st.empty()) {
        cout << 0;
    } else {
        cout << total;
    }

    return 0;
}