#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int brackets = 0;

    string s;
    getline(cin, s);

    int pipes = 0;
    char prev = '0';
    for (const char& c : s) {
        if (c == '(') {
            brackets++;
            prev = c;
            continue;
        }
        brackets--;
        if (prev == '(') {
            pipes += brackets;
        } else if (prev == ')') {
            pipes++;
        }
        prev = c;
    }

    cout << pipes;

    return 0;
}