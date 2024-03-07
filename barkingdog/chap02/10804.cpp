#include <iostream>
using namespace std;

void swap(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[21];

    for (int i = 1; i <= 20; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        int a, b;
        cin >> a >> b;
        swap(arr, a, b);
    }

    for (int i = 1; i <= 20; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}