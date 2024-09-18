#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    
    for (string op : operations) {
        if (op[0] == 'I') {
            pq1.push(stoi(op.substr(2)));
            continue;
        }
        
        if (op[2] == '-') {
            while (!pq1.empty()) {
                pq2.push(pq1.top());
                pq1.pop();
            }
            if (pq2.empty()) {
                continue;
            }
            pq2.pop();
            continue;
        }
        
        while (!pq2.empty()) {
            pq1.push(pq2.top());
            pq2.pop();
        }
        if (pq1.empty()) {
            continue;
        }
        pq1.pop();
    }
    
    if (pq1.empty() && pq2.empty()) {
        return vector<int> {0, 0};
    }
    
    int mn = 2100000000;
    int mx = 0;
    while (!pq1.empty()) {
        int val = pq1.top();
        pq1.pop();
        mn = min(mn, val);
        mx = max(mx, val);
    }
    
    while (!pq2.empty()) {
        int val = pq2.top();
        pq2.pop();
        mn = min(mn, val);
        mx = max(mx, val);
    }
    
    return vector<int> {mx, mn};
}