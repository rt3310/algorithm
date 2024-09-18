#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    getline(cin, s);

    int left = 0;
    int right = s.size() - 1;
    while (left < right && s[left] == 'a') {
        left++;
    }
    while (left < right && s[right] == 'a') {
        right--;
    }

    int result = 0;
    while (left < right) {
        while (left < right && s[left] == 'b') {
            left++;
        }
        while (left < right && s[right] == 'a') {
            right--;
        }
        if (left >= right) {
            break;
        }
        s[left] = 'b';
        s[right] = 'a';
        result++; 
    }

    cout << result;

    return 0;
}