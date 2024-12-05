#include <iostream>
using namespace std;

int t;
int n, m;
int a, b, c;
int k;
int path[101][101];
int friends[101];
constexpr int INF = 99999;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                path[i][j] = INF;
            }
        }
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            path[a][b] = c;
            path[b][a] = c;
        }

        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> friends[i];
        }

        for (int mid = 1; mid <= n; mid++) {
            for (int i = 1; i <= n; i++) {
                if (mid == i) {
                    continue;
                }
                for (int j = 1; j <= n; j++) {
                    if (i == j || j == mid) {
                        continue;
                    }
                    path[i][j] = min(path[i][j], path[i][mid] + path[mid][j]);
                }
            }
        }

        int minPath = 2100000000;
        int minIndex = 0;
        for (int i = 1; i <= n; i++) {
            int total = 0;
            for (int j = 0; j < k; j++) {
                if (friends[j] == i) {
                    continue;
                }
                total += path[friends[j]][i];
            }
            if (total < minPath) {
                minPath = total;
                minIndex = i;
            }
        }
        cout << minIndex << '\n';
    }

    return 0;
}