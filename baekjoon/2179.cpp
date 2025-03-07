#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool comp(const pair<string, pair<int, int>>& a, const pair<string, pair<int, int>>& b) {
    if (a.first.size() == b.first.size()) {
        return a.second.first < b.second.first;
    }
    return a.first.size() > b.first.size();
}

int n;
unordered_map<string, int> word;
vector<string> inverseWord;
unordered_map<string, pair<int, int>> m;
unordered_map<string, vector<int>> origins;
vector<pair<string, pair<int, int>>> result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin.ignore();

    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
        if (word.find(s) == word.end()) {
            word[s] = i;
        }
        inverseWord.push_back(s);
    }

    for (auto iter = word.begin(); iter != word.end(); iter++) {
        string s = iter->first;
        for (int j = 1; j <= s.size(); j++) {
            string sub = s.substr(0, j);
            if (m.find(sub) == m.end()) {
                m[sub].first = iter->second;
                m[sub].second= 1;
                origins[sub].push_back(iter->second);
            } else {
                m[sub].first = iter->second;
                m[sub].second++;
                origins[sub].push_back(iter->second);
            }
        }
    }

    result = vector<pair<string, pair<int, int>>>(m.begin(), m.end());
    sort(result.begin(), result.end(), comp);

    bool found = false;
    for (auto iter = result.begin(); iter != result.end(); iter++) {
        if (iter->second.second >= 2) {
            vector<int>& w = origins[iter->first];
            sort(w.begin(), w.end());
            for (int i = 0; i < 2; i++) {
                cout << inverseWord[w[i] - 1] << endl;
            }
            found = true;
            break;
        }
    }

    if (!found) {
        cout << inverseWord[0]<< '\n' << inverseWord[1];
    }

    return 0;
}