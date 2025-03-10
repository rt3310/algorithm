#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
ll card[100000];
ll maxNum = 0, maxCount = 0, curNum = 0, curCount = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }

    sort(card, card + n);

    for (int i = 0; i < n; i++) {
        if (card[i] != curNum) {
            if (curCount > maxCount) {
                maxNum = curNum;
                maxCount = curCount;
            }
            curNum = card[i];
            curCount = 1;
            continue;
        }

        curCount++;
    }

    if (curCount > maxCount) {
        maxNum = curNum;
        maxCount = curCount;
    }

    cout << maxNum;

    return 0;
}