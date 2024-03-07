#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;

    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; i++) {
        string s;
        getline(cin, s);

        list<char> l;
        list<char>::iterator cursor = l.end();
        for (char& c : s) {
            if (c == '<') {
                if (cursor == l.begin()) {
                    continue;
                }
                cursor--;
                continue;
            }

            if (c == '>') {
                if (cursor == l.end()) {
                    continue;
                }
                cursor++;
                continue;
            }

            if (c == '-') {
                if (l.size() == 0 || cursor == l.begin()) {
                    continue;
                }
                list<char>::iterator del = cursor;
                l.erase(--del);
                continue;
            }

            l.insert(cursor, c);
        }

        for (list<char>::iterator iter = l.begin(); iter != l.end(); iter++) {
            cout << *iter;
        }
        cout << "\n";
    }

    return 0;
}