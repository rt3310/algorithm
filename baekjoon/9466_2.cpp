#include <cstdio>
#include <deque>
using namespace std;


int t, n;
int students[100001];
bool team[100001];
int visited[100001];
int in[100001];

pair<int, bool> search(int cur, int start) {
    if (visited[cur] != -1 && visited[cur] != start) {
        return {cur, false};
    }

    if (visited[cur] == start) {
        team[cur] = true;
        return {cur, true};
    }

    visited[cur] = start;
    pair<int, bool> result = search(students[cur], start);
    if (result.second && cur != result.first) {
        team[cur] = true;
        return {result.first, true};
    }
    return {result.first, false};
}

int main() {
    scanf("%d", &t);

    for (int c = 0; c < t; c++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            team[i] = false;
            visited[i] = -1;
            in[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            scanf("%d", &students[i]);
            if (i == students[i]) {
                team[i] = i;
                visited[i] = i;
            }
            in[students[i]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                visited[i] = i;
                int next = students[i];
                while (in[next] <= 1) {
                    visited[next] = next;
                    next = students[next];
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (team[i] || visited[i] != -1) {
                continue;
            }
            search(i, i);
        }

        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (!team[i]) {
                result++;
            }
        }
        printf("%d\n", result);
    }

    return 0;
}