#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, k;

    cin >> n >> k;

    deque<int> dq;

    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    vector<int> answer;
    int count = 0;

    while (dq.size() > 0) {
        int num = dq.front();
        dq.pop_front();
        count++;

        if (count == k) {
            answer.push_back(num);
            count = 0;
        } else {
            dq.push_back(num);
        }
    }

    cout << "<";
    for (int i = 0; i < n - 1; i++) {
        cout << answer[i] << ", ";
    }
    cout << answer[n - 1] << ">";

    return 0;
}