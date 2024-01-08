#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq(works.begin(), works.end());
    
    while (n > 0) {
        int work = pq.top();
        if (work == 0) {
            return 0;
        }
        pq.pop();
        
        pq.push(work - 1);
        n--;
    }
    
    while (!pq.empty()) {
        answer += pq.top() * pq.top();
        pq.pop();
    }
    return answer;
}