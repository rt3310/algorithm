#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int t;
int result = 0;
vector<int> nums;
void search(int depth, int total) {
    if (depth == n) {
        if (total == t) {
            result++;
        }
        return;
    }
    
    search(depth + 1, total + nums[depth]);
    search(depth + 1, total - nums[depth]);
}

int solution(vector<int> numbers, int target) {
    n = numbers.size();
    t = target;
    
    copy(numbers.begin(), numbers.end(), back_inserter(nums));
    search(0, 0);
    return result;
}