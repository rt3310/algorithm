#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> v;
vector<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    v.push_back({0, 0});
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    v.push_back({1000001, 0});

    int height = 0;
    int count = 0;
    for (auto pos : v) {
        if (st.empty() || pos.second > st.back()) {
            st.push_back(pos.second);
            continue;
        }

        while (!st.empty() && pos.second < st.back()) {
            st.pop_back();
            count++;
        }
        if (!st.empty() && st.back() == pos.second) {
            continue;
        }
        st.push_back(pos.second);
    }

    cout << count;

    return 0;
}