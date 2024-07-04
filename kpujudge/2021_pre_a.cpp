#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;

    cin >> n;
    cin.ignore();
    getline(cin, s);

    int top = 0;
    int bot = 0;
    int height = 0;
    for (int i = 0; i < n; i++) {
        const char& c = s[i];
        if (c == '+') {
            if (i > 0 && s[i - 1] == '+') {
                height++;
            }
        } else if (c == '-') {
            if (i > 0 && (s[i - 1] == '=' || s[i - 1] == '-')) {
                height--;
            }
        } else {
            if (i > 0 && s[i - 1] == '+') {
                height++;
            }
        }
        top = max(top, height);
        bot = min(bot, height);
    }

    int row = top - bot + 1;
    int col = s.size();
    char graph[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            graph[i][j] = '.';
        }
    }

    int v = top;
    for (int i = 0; i < col; i++) {
        if (s[i] == '+') {
            if (i > 0 && s[i - 1] == '-') {
                v--;
            }
            graph[v][i] = '/';
            v--;
        } else if (s[i] == '-') {
            if (i > 0 && s[i - 1] == '+') {
                v++;
            }
            if (i > 0 && s[i - 1] == '=') {
                v++;
            }
            graph[v][i] = '\\';
            v++;
        } else {
            if (i > 0 && s[i - 1] == '-') {
                v--;
            }
            graph[v][i] = '_';
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << graph[i][j];
        }
        cout << "\n";
    }

    return 0;
}