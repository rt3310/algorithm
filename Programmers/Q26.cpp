#include <algorithm>
#include <regex>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    set<int> check;

    regex re("\\d+");
    smatch match;

    vector<vector<int>> numbers;
    vector<int> subnums;
    while (regex_search(s, match, re)) {
        subnums.push_back(stoi(match.str()));
        s = match.suffix();
        if (s[0] == '}') {
            numbers.push_back(subnums);
            subnums.clear();
        }
    }

    sort(numbers.begin(), numbers.end(), [](vector<int> &v1, vector<int> &v2) {
        return v1.size() < v2.size();
    });
    for (vector<int> sub : numbers) {
        for (int number : sub) {
            if (check.find(number) == check.end()) {
                answer.push_back(number);
                check.insert(number);
            }
        }
    }

    return answer;
}