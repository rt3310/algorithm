#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    
    for (int start = 0; start < elements.size(); start++) {
        int total = elements[start];
        s.insert(total);
        for (int end = start + 1; end < start + elements.size(); end++) {
            total += elements[end % elements.size()];
            s.insert(total);
        }
    }
    
    return s.size();
}