#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> count;
    
    for (int i = 0; i < 10; i++) {
        count[discount[i]] += 1;
    }
    
    int left = 0;
    int right = 9;
    while (right < discount.size()) {
        bool valid = true;
        for (int i = 0; i < want.size(); i++) {
            if (count[want[i]] != number[i]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            answer++;
        }
        right++;
        if (right >= discount.size()) {
            break;
        }
        count[discount[right]] += 1;
        count[discount[left++]] -= 1;
    }
    
    return answer;
}