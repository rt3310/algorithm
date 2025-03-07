#include <iostream>
#include <string>
using namespace std;

char arr[50];
string s, t;
int result = 0;
int a = 0, b = 0;

void search(int left, int right, bool isRight) {
    if (result == 1) {
        return;
    }

    if (right - left + 1 == s.size()) {
        if (isRight) {
            for (int i = 0; i < s.size(); i++) {
                if (arr[left + i] != s.at(i)) {
                    return;
                }
            }
        } else {
            for (int i = 0; i < s.size(); i++) {
                if (arr[right - i] != s.at(i)) {
                    return;
                }
            }
        }
        result = 1;
        return;
    }

    if (isRight) {
        if (arr[right] == 'A') {
            search(left, right - 1, true);
        }
        if (arr[left] == 'B') {
            search(left + 1, right, false);
        }
    } else {
        if (arr[left] == 'A') {
            search(left + 1, right, false);
        }
        if (arr[right] == 'B') {
            search(left, right - 1, true);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getline(cin, s);
    getline(cin, t);
    for (int i = 0; i < t.size(); i++) {
        arr[i] = t.at(i);
    }

    search(0, t.size() - 1, true);
    cout << result;

    return 0;
}