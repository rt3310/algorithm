#include <iostream>
using namespace std;

int n, m;
int graph[201][201];
int plan[1000];
int parent[201];

int getParent(int x) {
    if (x == parent[x]) {
        return x;
    }

    return parent[x] = getParent(parent[x]); // 경로 압축
}

void uni(int a, int b) {
    int pa = getParent(a);
    int pb = getParent(b);

    if (pa == pb) {
        return;
    }

    if (pa < pb) {
        parent[pb] = pa;
    } else {
        parent[pa] = pb;
    }
}

bool check(int a, int b) {
    int pa = getParent(a);
    int pb = getParent(b);

    if (pa == pb) {
        return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> m;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 1) {
                uni(i, j);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> plan[i];
    }

    for (int i = 0; i < m - 1; i++) {
        if (plan[i] == plan[i + 1]) {
            continue;
        }

        if (!check(plan[i], plan[i + 1])) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}