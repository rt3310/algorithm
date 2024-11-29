#include <iostream>
using namespace std;

int t;
int count[3]; // a, b, c
int cost[3]; // ab, bc, ca
int comb[3][2] = {{0, 1}, {1, 2}, {2, 0}};
int result = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int input[3];
        for (int i = 0; i < 3; i++) {
            cin >> input[i];
        }
        for (int i = 0; i < 3; i++) {
            cin >> cost[i];
        }

        for (int i = 0; i < 3; i++) {
            count[i] = input[i];
        }
        int canMix = min(count[comb[0][0]], count[comb[0][1]]);
        for (int i = 0; i <= canMix; i++) {
            int total = 0;

            total = cost[0] * i;
            count[comb[0][0]] -= i;
            count[comb[0][1]] -= i;

            int bcmin = min(count[comb[1][0]], count[comb[1][1]]);
            total += bcmin * cost[1];
            count[comb[1][0]] -= bcmin;
            count[comb[1][1]] -= bcmin;

            int camin = min(count[comb[2][0]], count[comb[2][1]]);
            total += camin * cost[2];

            result = max(result, total);

            total = cost[0] * i;
            count[comb[1][0]] += bcmin;
            count[comb[1][1]] += bcmin;

            camin = min(count[comb[2][0]], count[comb[2][1]]);
            total += camin * cost[2];
            count[comb[2][0]] -= camin;
            count[comb[2][1]] -= camin;

            bcmin = min(count[comb[1][0]], count[comb[1][1]]);
            total += bcmin * cost[1];

            result = max(result, total);

            for (int j = 0; j < 3; j++) {
                count[j] = input[j];
            }
        }

        cout << result << '\n';
        result = 0;
    }

    return 0;
}