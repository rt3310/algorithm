#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    stringstream ss(s);
    
    string buffer;
    vector<int> v;
    while (getline(ss, buffer, ' ')) {
        v.push_back(stoi(buffer));
    }
    
    sort(v.begin(), v.end());
    
    return to_string(v[0]) + " " + to_string(v[v.size() - 1]);
}

int main() {
    cout << solution("1 2 3 4") << "\n";
    cout << solution("-1 -2 -3 -4") << "\n";

    return 0;
}