#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int solution(int n) {
    int count = 0;
    while (n > 0) {
        if (n % 2 == 0) {
            n /= 2;
            continue;
        }
        n -= 1;
        count++;
    }
    return count;
}