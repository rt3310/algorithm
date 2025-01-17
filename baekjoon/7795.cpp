#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t;
int a, b;
int total = 0;
vector<int> av;
vector<int> bv;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    for (int c = 0; c < t; c++) {
        total = 0;
        cin >> a >> b;
        av.clear();
        bv.clear();
        for (int i = 0; i < a; i++) {
            int num;
            cin >> num;
            av.push_back(num);
        }

        for (int i = 0; i < b; i++) {
            int num;
            cin >> num;
            bv.push_back(num);
        }

        sort(av.rbegin(), av.rend());
        sort(bv.begin(), bv.end());

        int idx = bv.size() - 1;
        for (int i = 0; i < a; i++) {
            while (idx >= 0 && av[i] <= bv[idx]) {
                idx--;
            }
            total += idx + 1;
        }

        cout << total << '\n';
    }

    return 0;
}