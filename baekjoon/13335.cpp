#include <iostream>
using namespace std;

int n, w, L;
int truck[1001][2];
int in = 0, out = 0;
int totalWeight = 0;
int time = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> w >> L;
    for (int i = 1; i <= n; i++) {
        cin >> truck[i][0];
    }

    while (out < n) {
        for (int i = out + 1; i <= in; i++) {
            truck[i][1]++;
            if (truck[i][1] > w) {
                out = i;
                totalWeight -= truck[i][0];
            }
        }

        if (totalWeight + truck[in + 1][0] <= L) {
            in++;
            totalWeight += truck[in][0];
            truck[in][1]++;
        }

        time++;
    }

    cout << time;

    return 0;
}