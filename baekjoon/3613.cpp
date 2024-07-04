#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    string result;

    getline(cin, s);

    if (!islower(s[0])) {
        cout << "Error!";
        return 0;
    }
    int under = 0;
    int upper = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            cout << "Error!";
            return 0;
        }
        if (isupper(s[i])) {
            if (under > 0) {
                cout << "Error!";
                return 0;
            }
            result += "_";
            result += tolower(s[i]);
            upper++;
            continue;
        }
        if (s[i] == '_') {
            if (upper > 0 || !islower(s[i + 1])) {
                cout << "Error!";
                return 0;
            }
            result += toupper(s[i + 1]);
            under++;
            i = i + 1;
            continue;
        }
        result += s[i];
    }

    cout << result;
    return 0;
}