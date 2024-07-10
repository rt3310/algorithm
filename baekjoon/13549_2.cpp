#include <cstdio>
#include <deque>
#include <vector>
using namespace std;

const int LMT = 100001;
int n, k;
int board[LMT];
deque<int> dq;

void tel(int num) {
    int tmp = num;
    if (!tmp) {
        return;
    }
    while (tmp < LMT && !board[k]) {
        if (!board[tmp]) {
            board[tmp] = board[num];
            dq.push_back(tmp);
            if (tmp == k) {
                return;
            }
        }
        tmp <<= 1;
    }
}

int main(){
    scanf("%d %d", &n, &k);

    board[n] = 1;
    dq.push_back(n);
    tel(n);
    while (!board[k]) {
        int cur = dq.front();
        dq.pop_front();

        vector<int> nexts = {cur + 1, cur - 1};
        for (int next : nexts) {
            if (next < 0 || next >= LMT) {
                continue;
            }
            if (board[next]) {
                continue;
            }
            board[next] = board[cur] + 1;
            dq.push_back(next);
            tel(next);
        }
    }
    printf("%d", board[k] - 1);

    return 0;
}