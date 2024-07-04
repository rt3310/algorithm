#include <cstdio>
#include <deque>
#include <vector>
using namespace std;

// visited 처리를 안해서 메모리 초과가 생김
// 경곗값 테스트를 시도 하지 않아 탈출 가능한 상황에도 IMPOSSIBLE 경우가 생김
int r, c;
char map[1001][1001];
int visited[1001][1001];
int minutes = 1;
deque<vector<int>> fdq;
deque<vector<int>> jdq;
int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void fireSpread() {
    while (!fdq.empty()) {
        vector<int> cur = fdq.front();

        if (cur[2] != minutes) {
            break;
        }
        fdq.pop_front();

        for (int i = 0; i < 4; i++) {
            int curr = cur[0] + d[i][0];
            int curc = cur[1] + d[i][1];

            if (curr < 0 || curr >= r || curc < 0 || curc >= c) {
                continue;
            }

            if (map[curr][curc] == '#' || map[curr][curc] == 'F') {
                continue;
            }

            fdq.push_back(vector<int> {curr, curc, cur[2] + 1});
            map[curr][curc] = 'F';
        }
    }
    minutes++;
}

int bfs() {
    while (!jdq.empty()) {
        vector<int> cur = jdq.front();
        if (cur[0] == 0 || cur[1] == 0 || cur[0] == r - 1 || cur[1] == c - 1) {
            return visited[cur[0]][cur[1]];
        }
        if (visited[cur[0]][cur[1]] >= minutes) {
            fireSpread();
        }
        jdq.pop_front();

        for (int i = 0; i < 4; i++) {
            int curr = cur[0] + d[i][0];
            int curc = cur[1] + d[i][1];

            if (curr < 0 || curr >= r || curc < 0 || curc >= c) {
                continue;
            }

            if (map[curr][curc] == '#' || map[curr][curc] == 'F') {
                continue;
            }

            if (visited[curr][curc] == 0) {
                jdq.push_back(vector<int> {curr, curc});
                visited[curr][curc] = visited[cur[0]][cur[1]] + 1;

                if (curr == 0 || curc == 0 || curr == r - 1 || curc == c - 1) {
                    return visited[curr][curc];
                }
            }
        }
    }

    return -1;
}

int main() {
    scanf("%d %d ", &r, &c);

    for (int i = 0; i < r; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < c; j++) {

            if (map[i][j] == 'F') {
                fdq.push_back(vector<int> {i, j, 1});
            }
            if (map[i][j] == 'J') {
                jdq.push_back(vector<int> {i, j});
                visited[i][j] = 1;
            }
        }
    }

    int result = bfs();

    if (result == -1) {
        printf("IMPOSSIBLE");
    } else {
        printf("%d", result);
    }
    return 0;
}