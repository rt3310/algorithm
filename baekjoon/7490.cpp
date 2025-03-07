#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int t, n;
char ops[8];
char op[3] = {' ', '+', '-'};

void calc() {
    deque<int> nums;
    string temp = "1";
    for (int i = 1; i < n; i++) {
        if (ops[i - 1] != ' ') {
            nums.push_back(stoi(temp));
            temp = "";
        }
        temp += to_string(i + 1);
    }
    nums.push_back(stoi(temp));

    int total = num
    int total = nums.front(); nums.pop_front();
    for (int i = 0; i < n - 1; i++) {
        if (ops[i] == '+') {
            total += nums.front(); nums.pop_front();
        } else if (ops[i] == '-') {
            total -= nums.front(); nums.pop_front();
        } 
    }

    if (total == 0) {
        for (int i = 0; i < n - 1; i++) {
            cout << to_string(i + 1) << ops[i];
        }
        cout << n << '\n';
    }
}

void perm(int depth) {
    if (depth == n - 1) {
        calc();
        return;
    }

    for (int i = 0; i < 3; i++) {
        ops[depth] = op[i];
        perm(depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> n;

        perm(0);
        cout << '\n';
    }

    return 0;
}