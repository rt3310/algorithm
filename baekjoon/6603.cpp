#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[50];
vector<int> nums;

void search(int start, int depth) {
    if (depth == 6) {
        for (const int& num : nums)
            cout << num << ' ';
        cout << '\n';
        return;
    }

    for (int i = start; i < n; i++) {
        nums.push_back(arr[i]);
        search(i + 1, depth + 1);
        nums.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        cin >> n;
        if (n == 0)
            return 0;
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        search(0, 0);
        cout << '\n';
    }

    return 0;
}