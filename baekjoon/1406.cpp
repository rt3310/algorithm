#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> v;
    string s;
    int comCnt;

    getline(cin, s);
    cin >> comCnt;
    cin.ignore();

    for (char c : s) {
        v.push_back(c);
    }

    list<char>::iterator cursor = v.end();

    for (int i = 0; i < comCnt; i++) {
        string com;
        getline(cin, com);

        if (com[0] == 'L') {
            if (cursor != v.begin()) {
                --cursor;
            }
            continue;
        }

        if (com[0] == 'D') {
            if (cursor != v.end()) {
                ++cursor;
            }
            continue;
        }

        if (com[0] == 'B') {
            if (cursor != v.begin() && v.size() > 0) {
                list<char>::iterator eraseCur = cursor;
                v.erase(--eraseCur);
            }
            continue;
        }

        v.insert(cursor, com[2]);
    }

    for (char c : v) {
        cout << c;
    }
    return 0;
}