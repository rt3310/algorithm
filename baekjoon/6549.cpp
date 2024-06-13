#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            return 0;
        }

        stack<vector<long long>> s;
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            long long h;
            cin >> h;

            long long minHeight = h;
            long long mx = h;
            while (!s.empty()) {
                vector<long long> t = s.top();
                cout << t[0] << ", " << t[1] << "\n";

                long long prevArea = min(t[1], h) * (s.size() + 1);
                cout << "prevArea: " << prevArea << ", h: " << h << "\n";
                if (h <= prevArea) {
                    minHeight = min(t[1], h);
                    break;
                }
                s.pop();
            }
            s.push(vector<long long> {h, minHeight, mx});
        }

        cout << (s.top()[1] * s.size()) << "\n";
    }
    
    return 0;
}