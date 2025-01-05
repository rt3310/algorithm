#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int nums[8];
bool visited[8];
bool useOrder[8][10001];
vector<int> result;

void search(int depth) {
    if (depth == m) {
        for (int num : result) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (visited[i] || useOrder[depth][nums[i]])
            continue;
        result.push_back(nums[i]);
        visited[i] = true;
        useOrder[depth][nums[i]] = true;
        search(depth + 1);
        result.pop_back();
        visited[i] = false;
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

    search(0);

    return 0;
}