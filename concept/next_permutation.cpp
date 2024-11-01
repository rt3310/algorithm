#include <iostream>
#include <algorithm>
using namespace std;

int nums[3] = {1, 2, 3};
int nums2[3] = {1, 1, 2};

int main() {
    do {
        for (int i = 0; i < 3; i++)
            cout << nums[i] << ' ';
        cout << '\n';
    } while (next_permutation(nums, nums + 3));

    do {
        for (int i = 0; i < 3; i++)
            cout << nums2[i] << ' ';
        cout << '\n';
    } while (next_permutation(nums2, nums2 + 3));

    return 0;
}