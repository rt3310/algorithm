#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int n;
unordered_map<string, int> m;
int answer = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin.ignore();

    int entered = 0;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        if (s == "ENTER") {
            entered++;
            continue;
        }

        if (!m[s] || m[s] != entered) {
            answer++;
            m[s] = entered;
        }
    }

    cout << answer;

    return 0;
}