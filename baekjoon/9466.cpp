#include <cstdio>
#include <deque>
using namespace std;


int t, n;
int students[100001];
bool team[100001];
int visited[100001];
int in[100001];

int main() {
    scanf("%d", &t);

    for (int c = 0; c < t; c++) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &students[i]);
            team[i] = false;
            visited[i] = -1;
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
            deque<int> dq; 
            dq.push_back(i);
            visited[i] = i;

            while (!dq.empty()) {
                int cur = dq.front();
                dq.pop_front();

                if (visited[students[cur]] == i) {
                    int end = students[cur];
                    team[end] = true;
                    int next = students[end];
                    while (next != end) {
                        team[next] = true;
                        next = students[next];
                    }
                    break;
                }

                dq.push_back(students[cur]);
                visited[students[cur]] = i;
            }
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