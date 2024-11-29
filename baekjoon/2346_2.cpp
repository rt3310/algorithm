#include <iostream>
using namespace std;

int n;

struct Node {
    int value;
    int order;
};

Node node[1001];
int prv[1001];
int nxt[1001];

void erase(int nodeIndex) {
    int nextNodeIndex = nxt[nodeIndex];
    int prevNodeIndex = prv[nodeIndex];
    prv[nextNodeIndex] = prevNodeIndex;
    nxt[prevNodeIndex] = nextNodeIndex;
    prv[nodeIndex] = -1;
    nxt[nodeIndex] = -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        node[i] = {num, i};
        prv[i] = i - 1;
        nxt[i] = i + 1;
    }
    prv[1] = n;
    nxt[n] = 1;

    int cur = 1;
    for (int remove = 0; remove < n; remove++) {
        int nextIndex = node[cur].value;

        int removeNode = cur;
        if (nextIndex > 0) {
            cur = nxt[cur];
        } else {
            cur = prv[cur];
        }
        erase(removeNode);
        cout << node[removeNode].order << ' ';

        if (remove == n - 1) {
            return 0;
        }

        if (nextIndex > 0) {
            for (int i = 0; i < nextIndex - 1; i++) {
                cur = nxt[cur];
            }
        } else {
            for (int i = 0; i > nextIndex + 1; i--) {
                cur = prv[cur];
            }
        }
    }

    return 0;
}