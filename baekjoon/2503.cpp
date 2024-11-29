#include <iostream>
using namespace std;

int n;
bool check[1000];

void checkNumber(int num, int strike, int ball) {
    int index[10];
    for (int i = 1; i < 10; i++) {
        index[i] = 0;
    }
    index[num / 100] = 1;
    index[(num % 100) / 10] = 2;
    index[num % 10] = 3;

    for (int d = 123; d <= 987; d++) {
        int hundred = d / 100;
        int ten = (d % 100) / 10;
        int one = d % 10;
        int st = 0;
        int b = 0;

        if (hundred == 0 || ten == 0 || one == 0) {
            check[d] = false;
            continue;
        }

        if (hundred == ten || ten == one || one == hundred) {
            check[d] = false;
            continue;
        }

        if (index[hundred] != 0) {
            if (index[hundred] == 1) {
                st++;
            } else {
                b++;
            }
        }
        if (index[ten] != 0) {
            if (index[ten] == 2) {
                st++;
            } else {
                b++;
            }
        }
        if (index[one] != 0) {
            if (index[one] == 3) {
                st++;
            } else {
                b++;
            }
        }

        if (strike != st || ball != b) {
            check[d] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 123; i <= 987; i++) {
        check[i] = true;
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num, strike, ball;
        cin >> num >> strike >> ball;

        checkNumber(num, strike, ball);
    }

    int count = 0;
    for (int i = 123; i <= 987; i++) {
        if (check[i]) {
            count++;
        }
    }

    cout << count;

    return 0;
}