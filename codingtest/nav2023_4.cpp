#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int n, vector<vector<int>> chocolate) {
    int length = chocolate.size();

    
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    vector<int> answer = solution(4, vector<vector<int>> {vector<int> {2, 10, 7},
                         vector<int> {1, 10, 10},
                         vector<int> {6, 10, 1}});
    
    cout << answer[0] << ", " << answer[1];
    return 0;
}