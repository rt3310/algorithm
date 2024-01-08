#include <string>
#include <deque>
#include <map>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    deque<char> dq(s.begin(), s.end());
    int count = 0;
    while (count < s.size()) {
        deque<char> stack;

        bool valid = true;
        for (int i = 0; i < dq.size(); i++) {
            if (dq[i] == ')') {
                if (stack.empty() || stack.back() != '(') {
                    valid = false;
                    break;
                }
                stack.pop_back();
                continue;
            }
            if (dq[i] == '}') {
                if (stack.empty() || stack.back() != '{') {
                    valid = false;
                    break;
                }
                stack.pop_back();
                continue;
            }
            if (dq[i] == ']') {
                if (stack.empty() || stack.back() != '[') {
                    valid = false;
                    break;
                }
                stack.pop_back();
                continue;
            }
            stack.push_back(dq[i]);
        }
        if (stack.empty() && valid) {
            answer++;
        }
        dq.push_back(dq.front());
        dq.pop_front();
        count++;
    }
    
    return answer == s.size() ? 0 : answer;
}