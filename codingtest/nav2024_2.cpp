#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

bool invalidCandidates(vector<int>& server, const int& a, const int& b, const int& left, const int& right) {
    return server[left] * a < server[right] || server[left] + (b * 1000) < server[right];
}

vector<int> problem2(int a, int b, vector<vector<int>> delay) {
    int n = delay[0].size();
    int m = delay.size();

    int maxCandidatesServer = 0;
    int maxCandidatesCount = 0;
    for (int i = 0; i < n; i++) {
        vector<int> server;
        for (int j = 0; j < m; j++) {
            server.push_back(delay[j][i]);
        }

        sort(server.begin(), server.end());

        int maxCount = 0;
        int left = 0;
        int right = 0;
        while (left <= right) {

            if (!invalidCandidates(server, a, b, left, right)) {
                maxCount = max(maxCount, right - left + 1);
            }

            if (invalidCandidates(server, a, b, left, right)) {
                left++;
                continue;
            }
            right++;
        }

        if (maxCount > maxCandidatesCount) {
            maxCandidatesServer = i + 1;
            maxCandidatesCount = maxCount;
        }
    }

    return vector<int> {maxCandidatesServer, maxCandidatesServer};
}

int main() {
    vector<int> answer = problem2(2, 1, vector<vector<int>> {vector<int>{123, 90}, vector<int>{20, 39}});

    for (int ans : answer) {
        cout << ans << " ";
    }
    cout << "\n";
    return 0;
}