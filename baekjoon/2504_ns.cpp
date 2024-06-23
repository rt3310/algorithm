#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<char> brackets;
    string s;
    getline(cin, s);

    int total = 0;
    int subtotal = 1;
    for (int i = 0; i < s.size(); i++) {
        const char& c = s[i];
        if (c == '(') {
            subtotal *= 2;
            brackets.push_back(c);
            continue;
        }
        if (c == '[') {
            subtotal *= 3;
            brackets.push_back(c);
            continue;
        }

        if (c == ')') {
            if (brackets.empty() || brackets.back() != '(') {
                cout << 0;
                return 0;
            }
            if (s[i - 1] == '(') {
                total += subtotal;
            }
            subtotal /= 2;
            brackets.pop_back();
            continue;
        }

        if (c == ']') {
            if (brackets.empty() || brackets.back() != '[') {
                cout << 0;
                return 0;
            }
            if (s[i - 1] == '[') {
                total += subtotal;
            }
            subtotal /= 3;
            brackets.pop_back();
        }
    }
    if (!brackets.empty()) {
        cout << 0;
        return 0;
    }
    cout << total;
    return 0;
}