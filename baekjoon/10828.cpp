#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cin.ignore();

    stack<int> s;
    for (int i = 0; i < n; i++) {
        string cmd;
        getline(cin, cmd);

        if (cmd.substr(0, 4) == "push") {
            s.push(stoi(cmd.substr(5, cmd.length() - 5)));
            continue;
        }

        if (cmd.substr(1, 3) == "op") {
            if (s.empty()) {
                cout << -1 << "\n";
            } else {
                cout << s.top() << "\n";
                if (cmd[0] == 'p') {
                    s.pop();
                }
            }
            continue;
        }

        if (cmd.substr(0, 4) == "size") {
            cout << s.size() << "\n";
            continue;
        }

        if (s.empty()) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}