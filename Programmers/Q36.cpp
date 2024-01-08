#include <string>
#include <vector>
using namespace std;

bool visited[201];
int n;
void search(vector<vector<int>> &c, int cur) {
    for (int i = 0; i < ::n; i++) {
        if (c[cur][i] == 0) {
            continue;
        }
        
        if (visited[i] || i == cur) {
            continue;
        }
        
        visited[i] = true;
        search(c, i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    ::n = n;
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }
        visited[i] = true;
        answer++;
        search(computers, i);
    }
    
    return answer;
}