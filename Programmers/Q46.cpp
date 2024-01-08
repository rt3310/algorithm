#include <vector>
#include <queue>
using namespace std;

bool visited[101][101];

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> directions {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; 
    queue<pair<int, int>> dq;
    dq.push(make_pair(0, 0));
    maps[0][0] = 1;
    visited[0][0] = true;
    
    while (!dq.empty()) {
        pair<int, int> cur = dq.front();
        dq.pop();
        
        for (const vector<int>& direction : directions) {
            int row = cur.first + direction[0];
            int col = cur.second + direction[1];
            
            if (row < 0 || row >= n || col < 0 || col >= m) {
                continue;
            }
            
            if (maps[row][col] == 0) {
                continue;
            }
            
            if (visited[row][col]) {
                continue;
            }
            
            if (row == n - 1 && col == m - 1) {
                return maps[cur.first][cur.second] + 1;
            }
            
            visited[row][col] = true;
            maps[row][col] = maps[cur.first][cur.second] + 1;
            dq.push(make_pair(row, col));
        }
    }
    
    return -1;
}