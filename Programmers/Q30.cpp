#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool visited[9] = {false};
int order[9] = {0};
int n;
int curk;
int maxi = 0;
void perm(int depth, vector<vector<int>> dg) {
    if (depth == n) {
        int cur = curk;
        for (int i = 0; i < n; i++) {
            vector<int> curDungeon = dg[order[i]];
            if (cur < curDungeon[0]) {
                maxi = max(maxi, i);
                return;
            }
            cur -= curDungeon[1];
        }
        maxi = n;
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }
        visited[i] = true;
        order[depth] = i;
        perm(depth + 1, dg);
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    n = dungeons.size();
    curk = k;
    
    perm(0, dungeons);
    
    return maxi;
}