#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int start;
    int end;
    int cost;
};

constexpr int INF = 2100000000;
int v, e;
vector<Edge> edges;
int dists[501];

bool bellmanFord(int start) {
    dists[start] = 0;

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < e; j++) {
            Edge edge = edges[j];
            if (dists[edge.start] != INF && dists[edge.end] > dists[edge.start] + edge.cost) {
                dists[edge.end] = dists[edge.start] + edge.cost;
                if (i == v - 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> v >> e;
    for (int i = 0; i <= v; i++) {
        dists[i] = INF;
    }

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(Edge {a, b, c});
    }

    bool negativeCycle = bellmanFord(1);

    if (negativeCycle) {
        cout << "-1\n";
        return 0;
    } 

    for (int i = 2; i <= v; i++) {
        if (dists[i] == INF) {
            cout << "-1\n";
        } else {
            cout << dists[i] << '\n';
        }
    }

    return 0;
}