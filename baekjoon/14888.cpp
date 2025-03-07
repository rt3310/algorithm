#include <iostream>
#include <stack>
using namespace std;

int n;
int numbers[100];
int operators[100];
int opCount[4];
stack<int> s;
int mn = 1000000000;
int mx = -1000000000;

void calc() {
    s.push(numbers[0]);

    for (int i = 1; i < n; i++) {
        int operand = s.top(); s.pop();
        switch (operators[i - 1])
        {
        case 0:
            s.push(operand + numbers[i]);
            break;
        case 1:
            s.push(operand - numbers[i]);
            break;
        case 2:
            s.push(operand * numbers[i]);
            break;
        case 3:
            if (operand < 0) {
                s.push(-((-operand) / numbers[i]));
            } else {
                s.push(operand / numbers[i]);
            }
            break;
        }
    }
    mn = min(mn, s.top());
    mx = max(mx, s.top());
}

void perm(int depth) {
    if (depth == n - 1) {
        calc();
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (opCount[i] > 0) {
            opCount[i]--;
            operators[depth] = i;
            perm(depth + 1);
            opCount[i]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> opCount[i];
    }

    perm(0);

    cout << mx << '\n' << mn;

    return 0;
}