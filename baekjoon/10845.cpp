#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cin.ignore();

    queue<int> q;
    for (int i = 0; i < n; i++) {
        string cmd;
        getline(cin, cmd);

        if (cmd.substr(0, 4) == "push") {
            q.push(stoi(cmd.substr(5, cmd.length() - 5)));
            continue;
        }

        if (cmd.substr(0, 3) == "pop") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
            continue;
        }

        if (cmd.substr(0, 4) == "size") {
            cout << q.size() << "\n";
            continue;
        }

        if (cmd.substr(0, 5) == "front") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
            }
            continue;
        }

        if (cmd.substr(0, 4) == "back") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.back() << "\n";
            }
            continue;
        }

        if (q.empty()) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}