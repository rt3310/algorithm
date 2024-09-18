#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> n;
bool check[7];
vector<char> store;
vector<int> perms;

void perm(int depth) {
    if (depth == n.size()) {
        string s = "";
        for (char c : store) {
            s += c;
        }
        perms.push_back(stoi(s));
        return;
    }

    for (int i = 0; i < n.size(); i++) {
        if (check[i]) {
            continue;
        }
        check[i] = true;
        store.push_back(n[i]);
        perm(depth + 1);
        store.pop_back();
        check[i] = false;
    }
}

int main() {
    string s;
    getline(cin, s);

    for (char c : s) {
        n.push_back(c);
    }

    perm(0);
    sort(perms.begin(), perms.end());

    int cur = stoi(s);
    for (int i = 0; i < perms.size(); i++) {
        if (perms[i] == cur && perms[i] != perms[i + 1]) {
            cout << perms[i + 1];
            return 0;
        }
    }

    return 0;
}
