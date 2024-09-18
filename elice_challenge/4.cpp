#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> nodes[100001];
int parent[100001];
int maxScores[100001];

pair<int, int> initScores(int cur, int depth) {
    if (nodes[cur].empty()) {
        maxScores[cur] = cur;
        if (depth % 2 == 1) {
            return {cur, 0};
        }
        return {0, cur};
    }

    int mx = 100001;
    int st = 0;
    int nd = 0;
    int node = 0;
    pair<int, int> result;
    for (int next : nodes[cur]) {
        result = initScores(next, depth + 1);
        if (depth % 2 == 1) {
            if (result.second - result.first < mx) {
                mx = result.second - result.first;
                st = result.second;
                nd = result.first;
                node = next;
            }
        } else {
            if (result.first - result.second < mx) {
                mx = result.first - result.second;
                st = result.first;
                nd = result.second;
                node = next;
            }
        }
    }

    maxScores[cur] = node;
    if (depth % 2 == 1) {
        return {nd + cur, st};
    } else {
        return {st, nd + cur};
    }    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    parent[1] = 1;

    cin >> n;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        if (parent[a] != 0) {
            nodes[a].push_back(b);
            parent[b] = a;
        } else {
            nodes[b].push_back(a);
            parent[a] = b;
        }
    }

    initScores(1, 1);

    for (int i = 1; i <= n; i++) {
        int cur = i;
        int depth = 1;
        int a = cur, b = 0;
        while (cur != maxScores[cur]) {
            cur = maxScores[cur];
            depth++;

            if (depth % 2 == 1) {
                a += cur;
            } else {
                b += cur;
            }
        }

        if (a >= b) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}
