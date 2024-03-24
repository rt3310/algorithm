#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

vector<int> problem1(vector<int> plants, vector<int> watered) {
    vector<int> answer;
    int n = plants.size();
    vector<int> states(n, 0);

    for (int water : watered) {
        for (int i = 0; i < n; i++) {
            if (states[i] == -1) {
                continue;
            }

            if (water - 1 == i) {
                states[i] = 0;
            } else {
                states[i]++;
            }

            if (states[i] >= plants[i]) {
                states[i] = -1;
            }
        }

        int goodCount = 0;
        for (int i = 0; i < n; i++) {
            if (states[i] != -1) {
                goodCount++;
            }
        }
        answer.push_back(goodCount);
    }

    return answer;
}

vector<int> problem1_2(vector<int> plants, vector<int> watered) {
    vector<int> answer(watered.size(), 0);
    int n = plants.size();

    vector<vector<int>> sortedWatered;
    for (int i = 0; i < n; i++) {
        sortedWatered.push_back(vector<int> {i + 1, 0});
        sortedWatered.push_back(vector<int> {i + 1, (int) watered.size() + 1});
    }

    for (int i = 0; i < watered.size(); i++) {
        sortedWatered.push_back(vector<int> {watered[i], i + 1});
    }
    sort(sortedWatered.begin(), sortedWatered.end());

    int curPlant = 1;
    for (int i = 1; i < sortedWatered.size(); i++) {
        if (curPlant < sortedWatered[i][0]) {
            curPlant = sortedWatered[i][0];
        }

        if (curPlant > sortedWatered[i][0] || sortedWatered[i][0] != sortedWatered[i - 1][0]) {
            continue;
        }

        int term = sortedWatered[i][1] - sortedWatered[i - 1][1];
        if (term >= plants[curPlant - 1]) {
            int dead = min(watered.size(), (unsigned int) (sortedWatered[i - 1][1] + plants[curPlant - 1] - 1));
            for (int j = sortedWatered[i - 1][1]; j < dead; j++) {
                answer[j]++;
            }
            curPlant++;
        } else {
            for (int j = sortedWatered[i - 1][1]; j < sortedWatered[i][1]; j++) {
                answer[j]++;
            }
        }
    }

    return answer;
}

vector<int> problem1_3(vector<int> plants, vector<int> watered) {
    vector<int> answer;

    return answer;
}

int main() {
    srand((unsigned int) time(NULL));
    clock_t start;

    vector<int> plants;
    vector<int> watered;
    for (int i = 0; i < 300000; i++) {
        plants.push_back(rand() % 11);
    }

    for (int i = 0; i < 300000; i++) {
        watered.push_back(rand() % 100001);
    }

    start = clock();
    vector<int> answer1 = problem1(plants, watered);
    cout << (double) (clock() - start) / CLOCKS_PER_SEC << "\n";

    start = clock();
    vector<int> answer2 = problem1_2(plants, watered);
    cout << (double) (clock() - start) / CLOCKS_PER_SEC << "\n";
    // vector<int> answer = problem1_3(vector<int> {2, 4, 1, 3}, vector<int> {1, 2, 3, 4, 2, 3, 1, 4});

    // for (int ans : answer) {
    //     cout << ans << " ";
    // }
    // cout << "\n";
}