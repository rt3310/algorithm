#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
using namespace std;

int n, m;
int parent[100001];
unordered_set<int> parents;

int getParent(int n) {
    if (n == parent[n]) {
        return n;
    }

    return parent[n] = getParent(parent[n]);
}


bool uni(int a, int b) {
    int pa = getParent(a);
    int pb = getParent(b);

    if (pa == pb) {
        return false;
    }

    if (pa < pb) {
        parent[pb] = pa;
    } else {
        parent[pa] = pb;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    int cal = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (!uni(u, v)) {
            cal++;
        }
    }

    for (int i = 1; i <= n; i++) {
        parents.insert(getParent(i));
    }

    cout << cal + parents.size() - 1;

    return 0;
}