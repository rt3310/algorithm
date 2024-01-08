#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<pair<int, int>> stack;
    
    int index = 0;
    for (const int& price : prices) {
        int popCount = 0;
        while (!stack.empty() && stack.top().first > price) {
            popCount++;
            answer[stack.top().second] = index - stack.top().second;
            stack.pop();
        }
        stack.push(make_pair(price, index++));
    }
    
    while (!stack.empty()) {
        pair<int, int> top = stack.top();
        answer[top.second] += prices.size() - top.second - 1;
        stack.pop();
    }
    return answer;
}