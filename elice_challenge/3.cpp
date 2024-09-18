#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);

    vector<pair<int, char>> v;
    int total = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            if (i < s.size() - 1 && s[i + 1] == '(') {
                v.push_back({s[i] - '0', '*'});
                i++;
            } else {
                v.push_back({1, '+'});
            }
            continue;
        }

        if (s[i] == ')') {
            while (true) {
                pair<int, char> cur = v.back();
                v.pop_back();
                
                if (cur.second == '+') {
                    total += cur.first;
                } else {
                    total *= cur.first;
                    break;
                }
            }
        }
    }

    while (!v.empty()) {
        total += v.back().first;
        v.pop_back();
    }

    cout << total;
}
