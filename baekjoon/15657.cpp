#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int nums[8];
vector<int> result;

void search(int start, int depth) {
    if (depth == m) {
        for (int num : result) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = start; i < n; i++) {
        result.push_back(nums[i]);
        search(i, depth + 1);
        result.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + n);

    search(0, 0);

    return 0;
}