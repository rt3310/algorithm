#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    while (true) {
        int a = pq.top();
        pq.pop();
        
        if (a >= K) {
            return answer;
        }
        
        if (pq.empty()) {
            return -1;
        }
        
        int b = pq.top();
        pq.pop();
        
        int result = a < b ? a + (b * 2) : (a * 2) + b;
        answer++;
        pq.push(result);
    }
    
    return -1;
}