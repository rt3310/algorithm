#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    while (n > 1) {
        int temp = s / n;
        if (temp == 0) {
            return vector<int> {-1};
        }
        
        answer.push_back(temp);
        s -= temp;
        n--;
    }
    
    answer.push_back(s);
    return answer;
}

vector<int> solution2(int n, int s) {
    if (n > s) {
        return {-1};
    }

    int avg{ s / n };
    int res{ s % n };
    vector<int> left(n - res, avg);
    vector<int> right(res, avg + 1);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}