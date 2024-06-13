#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<char> s;

    string l;
    getline(cin, l);

    int answer = 0;
    int height = 0;
    for (char c : l) {
        if (c == '(') {
            height = s.size();
            s.push(c);
            continue;
        }

        s.pop();
        if (s.size() < height) {
            answer++;
            height--;
            continue;
        }
        answer += height;
    }
    cout << answer;
    return 0;
}