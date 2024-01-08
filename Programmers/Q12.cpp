#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    
    sort(people.begin(), people.end());
    int left = 0;
    int right = people.size() - 1;
    while (left < right) {
        
        if (people[left] + people[right] > limit) {
            right--;
            continue;
        }
        
        left++;
        right--;
    }
    
    
    return people.size() - left;
}