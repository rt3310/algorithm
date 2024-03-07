#include <iostream>
#include <unordered_map>
using namespace std;

int func2(int arr[], int n) {
    unordered_map<int, int> sub;

    for (int i = 0; i < n; i++) {
        sub[100 - arr[i]] += i;
    }

    for (int i = 0; i < n; i++) {
        if (sub[arr[i]] > 0 && sub[arr[i]] != i) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int arr[] = {1, 52, 48};
    cout << func2(arr, 3) << "\n";

    int arr2[] = {50, 42};
    cout << func2(arr2, 2) << "\n";

    int arr3[] = {4, 13, 63, 87};
    cout << func2(arr3, 4) << "\n";
    return 0;
}