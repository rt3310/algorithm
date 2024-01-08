#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        answer += A[i] * B[i];
    }
    
    int total = 0;
    for (int i = n-1; i >= 0; i--) {
        total += A[i] * B[i];
    }
    answer = min(answer, total);

    return answer;
}