#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    int arr[26];

    fill(arr, arr + 26, 0);
    getline(cin, s);

    for (char c: s) {
        arr[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}