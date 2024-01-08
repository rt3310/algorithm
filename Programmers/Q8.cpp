#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> v {0, 1, 1};
    
    for (int i = 3; i <= n; i++) {
        v.push_back((v[i-1] + v[i-2]) % 1234567);
    }
    
    return v[n];
}