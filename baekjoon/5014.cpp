#include <cstdio>
#include <deque>
using namespace std;

int main() {
    int f, s, g, u, d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    if (s == g) {
        printf("0");
        return 0;
    }
    if ((u == 0 && g > s) || (d == 0 && g < s)) {
        printf("use the stairs");
        return 0;
    }
    int elev[f + 1];
    int visited[f + 1];
    deque<int> dq;
    dq.push_back(s);
    for (int i = 0; i <= f; i++) {
        visited[i] = 9999999;
    }
    visited[s] = 1;

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        if (cur + u <= f && visited[cur + u] > visited[cur] + 1) {
            if (cur + u == g) {
                printf("%d", visited[cur]);
                return 0;
            }
            dq.push_back(cur + u);
            visited[cur + u] = visited[cur] + 1;
        }

        if (cur - d > 0 && visited[cur - d] > visited[cur] + 1) {
            if (cur - d == g) {
                printf("%d", visited[cur]);
                return 0;
            }
            dq.push_back(cur - d);
            visited[cur - d] = visited[cur] + 1;
        }
    }

    printf("use the stairs");
    return 0;
}