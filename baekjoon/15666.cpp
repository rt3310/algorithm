#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int nums[8];
bool useOrder[8][10001];
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
        if (useOrder[depth][nums[i]])
            continue;
        result.push_back(nums[i]);
        useOrder[depth][nums[i]] = true;
        search(i, depth + 1);
        result.pop_back();
    }

    for (int i = 0; i < n; i++)
        useOrder[depth][nums[i]] = false;
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