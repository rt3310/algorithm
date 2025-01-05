#include <iostream>
#include <vector>
#include <deque>
using namespace std;

char student[5][5];
bool visited[25];
vector<int> nums;
int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int count = 0;

bool isLinked() {
    bool check[25];
    for (int i = 0; i < 25; i++) {
        check[i] = false;
    }
    deque<int> dq;
    dq.push_back(nums[0]);
    check[nums[0]] = true;

    int visitCount = 1;
    while (!dq.empty()) {
        int cur = dq.front(); dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nr = cur / 5 + d[i][0];
            int nc = cur % 5 + d[i][1];

            if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) {
                continue;
            }

            if (!visited[nr * 5 + nc]) {
                continue;
            }

            if (check[nr * 5 + nc]) {
                continue;
            }

            dq.push_back(nr * 5 + nc);
            check[nr * 5 + nc] = true;
            visitCount++;
        }
    }

    if (visitCount == 7) {
        return true;
    }
    return false;
}

void search(int start, int depth, int y, int s) {
    if (depth == 7) {
        if (s > y && isLinked()) {
            count++;
        }
        return;
    }

    for (int i = start; i < 25; i++) {
        if (visited[i])
            continue;
        int ny = y;
        int ns = s;
        if (student[i / 5][i % 5] == 'Y') {
            ny++;
        } else {
            ns++;
        }
        nums.push_back(i);
        visited[i] = true;
        search(i + 1, depth + 1, ny, ns);
        nums.pop_back();
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> student[i][j];
        }
    }

    search(0, 0, 0, 0);

    cout << count;

    return 0;
}