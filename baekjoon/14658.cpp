#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, l, k;
vector<pair<int, int>> stars;
int result = 101;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> l >> k;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        stars.push_back({x, y});
    }

    sort(stars.begin(), stars.end());

    for (int i = 0; i < k; i++) {
        for (int j = i; j < k; j++) {
            int minX = min(stars[i].first, stars[j].first);
            int minY = min(stars[i].second, stars[j].second);
            int maxX = minX + l;
            int maxY = minY + l;

            int inCount = 0;
            for (int star = 0; star < k; star++) {
                if (stars[star].first > maxX) {
                    break;
                }

                if (stars[star].first <= maxX && stars[star].first >= minX &&
                    stars[star].second <= maxY && stars[star].second >= minY) {
                    inCount++;
                }
            }

            result = min(result, k - inCount);
        }
    }

    cout << result;

    return 0;
}