#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> bottles;
int result = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    while (n > 0) {
        for (int i = 0; i < 25; i++) {
            if ((1 << i) > n) {
                n -= 1 << (i - 1);
                bottles.push_back(1 << (i - 1));
                break;
            }
        }
    }

    while (bottles.size() > k) {
        int last = bottles.back();
        bottles.pop_back();

        int prev = bottles.back();
        bottles.pop_back();
        while (last != prev) {
            result += last;
            last += last;
        }
        bottles.push_back(last + prev);
    }

    cout << result;

    return 0;
}