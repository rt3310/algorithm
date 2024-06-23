#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int r, c, n;

    cin >> r >> c >> n;
    cin.ignore();

    vector<vector<char>> map;
    vector<pair<int, int>> init;
    for (int i = 0; i < r; i++) {
        vector<char> v;
        string row;
        getline(cin, row);

        for (int j = 0; j < row.size(); j++) {
            v.push_back(row[j]);
            if (row[j] == 'O') {
                init.push_back(make_pair(i, j));
            }
        }
        map.push_back(v);
    }

    if (n <= 1) {
        for (vector<char> r : map) {
            for (char c : r) {
                cout << c;
            }
            cout << "\n";
        }
        return 0;
    }

    if (n % 2 == 0) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << 'O';
            }
            cout << "\n";
        }
        return 0;
    }

    int sec = 1;
    while (true) {
        if (sec % 2 == 1) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    map[i][j] = 'O';
                }
            }
        } else {
            for (pair<int, int> p : init) {
                map[p.first][p.second] = '.';
                if (p.first > 0) {
                    map[p.first - 1][p.second] = '.';
                }
                if (p.first < r - 1) {
                    map[p.first + 1][p.second] = '.';
                }
                if (p.second > 0) {
                    map[p.first][p.second - 1] = '.';
                }
                if (p.second < c - 1) {
                    map[p.first][p.second + 1] = '.';
                }
            }
            init.clear();
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (map[i][j] == 'O') {
                        init.push_back(make_pair(i, j));
                    }
                }
            }
        }
        sec++;
        if (sec == n) {
            for (vector<char> r : map) {
                for (char c : r) {
                    cout << c;
                }
                cout << "\n";
            }
            return 0;
        }
    }

    return 0;
}