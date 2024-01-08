#include <map>
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> count;

    for (vector<string> cloth : clothes) {
        count[cloth[1]] += 1;
    }

    for (const auto &[k, v] : count) {
        answer *= (v + 1);
    }

    return answer - 1;
}