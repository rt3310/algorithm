#include <cmath>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int time = 0;
    int count = 0;
    for (int i = 0; i < progresses.size(); i++) {
        int remain = ceil((double)(100 - progresses[i]) / speeds[i]);

        if (remain > time) {
            if (count > 0) {
                answer.push_back(count);
                count = 0;
            }
            time = remain;
            count++;
            continue;
        }
        count++;
    }
    answer.push_back(count);
    return answer;
}