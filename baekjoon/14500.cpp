#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> square;
int answer = 0;

vector<vector<vector<int>>> blocks {
    {{1, 1, 1},
     {0, 0, 1}},
    {{1, 1, 0},
     {0, 1, 1}},
    {{1, 1, 1},
     {0, 1, 0}},
    {{0, 1, 1},
     {1, 1, 0}},
    {{0, 0, 1},
     {1, 1, 1}}
};

vector<vector<int>> rotate(vector<vector<int>>& block) {
    vector<vector<int>> newBlock;
    for (int i = 0; i < block[0].size(); i++) {
        vector<int> r;
        for (int j = 0; j < block.size(); j++) {
            r.push_back(block[block.size() - j - 1][i]);
        }
        newBlock.push_back(r);
    }

    return newBlock;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < m; j++) {
            int e;
            cin >> e;
            row.push_back(e);
        }
        square.push_back(row);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 3; j++) {
            int sum = square[i][j] + square[i][j + 1] + square[i][j + 2]+ square[i][j + 3];
            answer = max(answer, sum);
        }
    }

    for (int i = 0; i < n - 3; i++) {
        for (int j = 0; j < m; j++) {
            int sum = square[i][j] + square[i + 1][j] + square[i + 2][j] + square[i + 3][j];
            answer = max(answer, sum);
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            int sum = square[i][j] + square[i][j + 1] + square[i + 1][j] + square[i + 1][j + 1];
            answer = max(answer, sum);
        }
    }

    for (vector<vector<int>>& block : blocks) {
        vector<vector<int>> b;
        b.assign(block.size(), vector<int>(block.size()));
        copy(block.begin(), block.end(), b.begin());
        for (int i = 0; i < 4; i++) {
            b = rotate(b);
            int c = b.size(); 
            int r = b[0].size();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i + c > n || j + r > m) {
                        continue;
                    }
                    int sum = 0;
                    for (int k = 0; k < c; k++) {
                        for (int l = 0; l < r; l++) {
                            if (b[k][l] == 1) {
                                sum += square[i + k][j + l];
                            }
                        }
                    }
                    answer = max(answer, sum);
                }
            }
        }
    }

    cout << answer;
    return 0;
}