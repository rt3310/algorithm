#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int n, c;
unordered_map<int, int> counts;
unordered_map<int, int> first;
vector<tuple<int, int, int>> v;

bool comp(tuple<int, int, int> a, tuple<int, int, int> b) {
    if (get<0>(a) == get<0>(b)) {
        return get<1>(a) < get<1>(b);
    }
    return get<0>(a) > get<0>(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        counts[num]++;
        if (!first.count(num)) {
            first[num] = i;
        }
    }

    for (const auto& p : counts) {
        v.push_back({p.second, first[p.first], p.first});
    }

    sort(v.begin(), v.end(), comp);

    for (auto t : v) {
        int cnt, idx, e;
        tie(cnt, idx, e) = t;
        for (int i = 0; i < cnt; i++) {
            cout << e << ' ';
        }
    }
}