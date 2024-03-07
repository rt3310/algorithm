#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<char>> v;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        vector<char> sub;
        for (const char c : s) {
            sub.push_back(c);
        }
        v.push_back(sub);
    }

    return 0;
}