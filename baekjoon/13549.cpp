#include <cstdio>
#include <deque>
using namespace std;

int n, k;
int visited[100001];

int bfs() {
    deque<int> dq;
    dq.push_back(n);
    for (int i = 0; i < 100001; i++) {
        visited[i] = 999999;
    }
    visited[n] = 1;

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        if (cur + 1 <= 100000 && visited[cur] + 1 < visited[cur + 1]) {
            dq.push_back(cur + 1);
            visited[cur + 1] = visited[cur] + 1;
        }
        if (cur - 1 <= 100000 && visited[cur] + 1 < visited[cur - 1]) {
            dq.push_back(cur - 1);
            visited[cur - 1] = visited[cur] + 1;
        }
        if (cur * 2 <= 100000 && visited[cur] < visited[cur * 2]) {
            dq.push_back(cur * 2);
            visited[cur * 2] = visited[cur];
        }
    }
    return visited[k] - 1;
}

int main() {
    scanf("%d %d", &n, &k);

    printf("%d", bfs());
    return 0;
}