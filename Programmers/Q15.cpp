#include <vector>

using namespace std;

int gcd(int a, int b) {
    int gt = max(a, b);
    int lt = min(a, b);
    while (true) {
        int remain = gt % lt;
        if (remain == 0) {
            return lt;
        }
        gt = lt;
        lt = remain;
    }
    return lt;
}

int solution(vector<int> arr) {
    int answer = 1;

    int idx = 0;
    while (arr.size() != 1) {
        int a = arr.back();
        arr.pop_back();
        int b = arr.back();
        arr.pop_back();
        arr.push_back(a * b / gcd(a, b));
    }
    return arr[0];
}