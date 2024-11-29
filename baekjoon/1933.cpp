#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int n;
vector<tuple<int, int, int>> building;
vector<tuple<int, int, int>> s;
vector<pair<int, int>> result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int lx, h, rx;
        cin >> lx >> h >> rx;
        building.push_back({lx, rx, h});
    }

    sort(building.begin(), building.end());

    int maxHeight = 0;
    for (int i = 0; i < n; i++) {
        int lx, rx, h;
        tie(lx, rx, h) = building[i];

        if (s.empty()) {
            s.push_back(building[i]);
            maxHeight = max(h, maxHeight);
            result.push_back({lx, h});
            continue;
        }

        if (h > maxHeight) {
            if (lx < get<1>(s.back())) {
                result.push_back({lx, h});
            } else if (lx > get<1>(s.back())) {

            }
            s.push_back(building[i]);
        }
    }

    for (auto b : building) {
        if ()
    }

    return 0;
}