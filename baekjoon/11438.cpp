#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> e[100001];
int depth[100001];
int ac[100001][20];
int n, m;
int maxLv;

void init(int cur, int parent) {
    depth[cur] = depth[parent] + 1;

    ac[cur][0] = parent;

    maxLv = floor(log2(100001));

    for (int i = 1; i <= maxLv; i++) {
        int temp = ac[cur][i - 1];
        ac[cur][i] = ac[temp][i - 1];
    }

    int len = e[cur].size();
    for (int i = 0; i < len; i++) {
        int there = e[cur][i];
        if (there != parent) {
            init(there, cur);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    depth[0] = -1;
    init(1, 0);

    cin >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        int lca;
        if (depth[a] > depth[b]) {
            for (int i = maxLv; i >= 0; i--) {
                if (depth[b] <= depth[ac[a][i]]) {
                    a = ac[a][i];
                }
            }
            lca = b;
        }
        if (depth[a] < depth[b]) {
            for (int i = maxLv; i >= 0; i--) {
                if (depth[a] <= depth[ac[b][i]]) {
                    b = ac[b][i];
                }
            }
            lca = a;
        }

        if (a != b) {
            for (int i = maxLv; i >= 0; i--) {
                if (ac[a][i] != ac[b][i]) {
                    a = ac[a][i];
                    b = ac[b][i];
                }
                lca = ac[a][i];
            }
        }
        cout << lca << '\n';
    }

    return 0;
}