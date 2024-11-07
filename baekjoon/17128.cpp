#include <iostream>
using namespace std;

int n, q;
int cows[200001];
int s[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> cows[i];
    }

    s[1] = cows[1] * cows[2] * cows[3] * cows[4];
    int left = 1;
    int right = 4;
    while (true) {
        int value = s[left];

        value /= cows[left];
        right = right % n + 1;
        value *= cows[right];

        left++;
        if (left > n) {
            break;
        }
        s[left] = value;
    }

    int total = 0;
    for (int i = 1; i <= n; i++) {
        total += s[i];
    }

    for (int i = 0; i < q; i++) {
        int qi;
        cin >> qi;
        int start = qi - 3;
        if (start < 1) {
            start = n + start;
        }
        int changedTotal = 0;
        for (int j = 0; j < 4; j++) {
            s[start] *= -1;
            changedTotal += s[start];
            start = start % n + 1;
        }
        total += changedTotal * 2;
        cout << total << '\n';
    }

    return 0;
}