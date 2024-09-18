#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long

int n, k;
vector<pair<ll, ll>> jws;
vector<ll> bags;

struct cmp {
    bool operator()(ll a, ll b) {
        return a < b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        ll m, v;
        cin >> m >> v;
        jws.push_back({m, v});
    }

    for (int i = 0; i < k; i++) {
        ll bag;
        cin >> bag;
        bags.push_back(bag);
    }

    sort(jws.begin(), jws.end(), [](pair<ll, ll> a, pair<ll, ll> b) -> bool {
        return a.first < b.first;
    });

    sort(bags.begin(), bags.end());

    priority_queue<ll, vector<ll>, cmp> pq;
    ll total = 0;
    int jwIdx = 0;
    for (ll bag : bags) {
        while (jwIdx < n) {
            if (jws[jwIdx].first > bag) {
                break;
            }
            pq.push(jws[jwIdx].second);
            jwIdx++;
        }

        if (!pq.empty()) {
            total += pq.top(); pq.pop();
        }
    }

    cout << total;

    return 0;
}