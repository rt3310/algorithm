#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int i = 1; i <= sqrt(yellow) + 1; i++) {
        if (yellow % i == 0) {
            if ((i * 2) + ((yellow / i) * 2) == brown - 4) {
                return vector<int> {max(i + 2, yellow / i + 2), min(i + 2, yellow / i + 2)};
            }
        }
    }
    return answer;
}