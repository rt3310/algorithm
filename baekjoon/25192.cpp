#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int n;
unordered_map<string, bool> m;
int answer = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        if (s == "ENTER") {
            m = unordered_map<string, bool>();
            continue;
        }

        if (!m[s]) {
            answer++;
            m[s] = true;
        }
    }

    cout << answer;

    return 0;
}