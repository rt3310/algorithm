#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
int cnt;
vector<long long> nums;
unordered_map<long long, pair<int, int>> check;
vector<long long> elements;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cnt = pow(2, n);
    
    for (int i = 0; i < cnt; i++) {
        long long number;
        cin >> number;
        nums.push_back(number);
    }
    sort(nums.begin(), nums.end());

    for (int i = 1; i < cnt; i++) {
        if (check[nums[i]].first > 0) {
            check[nums[i]].first--;
            continue;
        }
        if (!check.count(nums[i]) || check[nums[i]].first == 0) {
            for (auto iter = check.begin(); iter != check.end(); iter++) {
                int numCnt = check[iter->first].second;
                if (numCnt > 0) {
                    check[iter->first + nums[i]].first += numCnt;
                    check[iter->first + nums[i]].second += numCnt;
                }
            }
            check[nums[i]].first = 0;
            check[nums[i]].second++;
            elements.push_back(nums[i]);
            // cout << "check: " << nums[i] << ", " << check[nums[i]].first << "\n";
        }
        // for (auto iter = check.begin(); iter != check.end(); iter++) {
        //     cout << "{" << iter->first << ", " << iter->second.first << ", " << iter->second.second << "} ";
        // }
        // cout << "\n";
    }

    sort(elements.begin(), elements.end());
    for (int i = 0; i < elements.size(); i++) {
        cout << elements[i] << " ";
    }

    return 0;
}
