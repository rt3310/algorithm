#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<pair<int, int>> buildings;
stack<pair<int, int>> s;
const int MX = 10000000;
int views[100001][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int height;
        cin >> height;
        buildings.push_back({i, height});
        views[i][0] = MX;
        views[i][1] = MX;
    }

    for (auto building : buildings) {
        while (!s.empty() && s.top().second <= building.second) {
            s.pop();
        }

        views[building.first][2] += s.size();
        if (!s.empty()) {
            int gap = abs(building.first - s.top().first);
            if (gap < views[building.first][0]) {
                views[building.first][0] = gap;
                views[building.first][1] = s.top().first;
            }
        }

        s.push(building);
    }

    while (!s.empty()) {
        s.pop();
    }

    for (int i = n - 1; i >= 0; i--) {
        auto building = buildings[i];
        while (!s.empty() && s.top().second <= building.second) {
            s.pop();
        }

        views[building.first][2] += s.size();
        if (!s.empty()) {
            int gap = abs(building.first - s.top().first);
            if (gap < views[building.first][0]) {
                views[building.first][0] = gap;
                views[building.first][1] = s.top().first;
            }
        }

        s.push(building);
    }

    for (int i = 1; i <= n; i++) {
        if (views[i][2] == 0) {
            cout << 0 << '\n';
        } else {
            cout << views[i][2] << ' ' << views[i][1] << '\n';
        }
    }
    
    return 0;
}