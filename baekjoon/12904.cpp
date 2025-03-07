#include <iostream>
#include <string>
using namespace std;

char arr[1001];
string s, t;
int result = 1;
int l = 0, r;
bool reverse = false;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getline(cin, s);
    getline(cin, t);
    for (int i = 0; i < t.size(); i++) {
        arr[i] = t.at(i);
    }
    r = t.size() - 1;


    for (int i = 0; i < t.size() - s.size(); i++) {
        if (!reverse) {
            if (arr[r] == 'A') {
                r--;
            } else {
                r--;
                reverse = true;
            }
        } else {
            if (arr[l] == 'A') {
                l++;
            } else {
                l++;
                reverse = false;
            }
        }
    }

    if (reverse) {
        for (int i = 0; i < s.size(); i++) {
            if (s.at(i) != arr[r - i]) {
                result = 0;
            }
        }
    } else {
        for (int i = 0; i < s.size(); i++) {
            if (s.at(i) != arr[l + i]) {
                result = 0;
            }
        }
    }

    cout << result;

    return 0;
}