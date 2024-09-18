#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Test
{
private:
    mutable int val;
public:
    Test(int val) {
        cout << "기본 생성자 val : " << val << endl;
        this->val = val;
    }

    Test(const Test& src)
    {
        cout << "복사 생성자 val : " << src.val << endl;
        val = src.val;
    }

    void operator=(const Test& src)
    {
        cout << "대입 연산자 val : " << src.val << endl;
        val = src.val;
    }

    int GetVal() { return val; }

    void DoSomething(int x) const {
        val = x;
    }
};

vector<int> find_original_sequence(vector<int>& sums) {
    sort(sums.rbegin(), sums.rend());
    vector<int> original;
    unordered_map<int, bool> check;
    
    int stand = sums[0];
    for (int i = 1; i < sums.size(); i++) {
        int new_element = stand - sums[i];
        if (!check.count(new_element)) {
            original.push_back(new_element);
            for (auto iter = check.begin(); iter != check.end(); iter++) {
                check[iter->first + new_element] = true;
            }
            check[new_element] = true;
            stand = sums[i];
        }
    }
    
    return original;
}

int main() {
    vector<vector<int>> test_cases = {
        {0, 1000},
        {0, 1, 2, 3},
        {0, 1, 2, 3, 4, 5, 6, 7},
        {0, 3, 3, 3, 6, 6, 6, 9},
        {0, 1, 2, 3, 3, 4, 5, 6},
        {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6}
    };

    for (auto& case_ : test_cases) {
        vector<int> result = find_original_sequence(case_);
        cout << "Input: ";
        for (int num : case_) cout << num << " ";
        cout << "\nOriginal sequence: ";
        for (int num : result) cout << num << " ";
        cout << "\n\n";
    }

    return 0;
}