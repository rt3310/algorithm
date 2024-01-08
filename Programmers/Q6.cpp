#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int total = 1;
    int left = 0;
    int right = 1;
    while (left <= n) {
        if (total == n) {
            answer++;
        }
        
        if (total < n) {
            right++;
            total += right;
            continue;
        }
        left++;
        total -= left;
    }
    
    return answer;
}