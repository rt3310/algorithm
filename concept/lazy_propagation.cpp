#include <iostream>
#include <vector>
using namespace std;

// https://www.acmicpc.net/problem/10999

long long tree[4000001];
long long lazy[4000001];
long long arr[1000001];

void propagate(int node, int start, int end) {
    if (lazy[node] != 0) { // 값이 있는지 확인
        tree[node] += (end - start + 1) * lazy[node]; // lazy 값으로 현재 노드 업데이트

        if (start != end) { // leaf node가 아닐 경우 자식으로 전파
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0; // 현재 노드의 lazy 값을 초기화
    }
}

void update(int node, int start, int end,
            int left, int right, long long add) {
    propagate(node, start, end);

    if (right < start || left > end) {
        return;
    }

    if (left <= start && right >= end) {
        tree[node] += (end - start + 1) * add;
        if (start != end) {
            lazy[node * 2] += add;
            lazy[node * 2 + 1] += add;
        }
        return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, add);
    update(node * 2 + 1, mid + 1, end, left, right, add);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int start, int end,
                int left, int right) {
    propagate(node, start, end);
    
    if (right < start || left > end) {
        return 0;
    }

    if (left <= start && right >= end) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

long long init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    init(1, n, 1);

    for (int i = 0; i < m + k; i++) {
        long long a, b, c, d;
        cin >> a;

        if (a == 1) {
            cin >> b >> c >> d;
            update(1, 1, n, b, c, d);
            continue;
        }

        cin >> b >> c;
        cout << query(1, 1, n, b, c) << "\n";
    }

    return 0;
}