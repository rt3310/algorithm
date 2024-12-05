#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int n;
int student[1000][5];
vector<int> count[5][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> student[i][j];
            count[j][student[i][j]].push_back(i);
        }
    }

    int maxCount = 0;
    int maxStudent = 0;
    for (int i = 0; i < n; i++) {
        unordered_set<int> other;
        for (int j = 0; j < 5; j++) {
            for (int o : count[j][student[i][j]]) {
                other.insert(o);
            }
        }
        if (other.size() > maxCount) {
            maxCount = other.size();
            maxStudent = i + 1;
        }
    }

    cout << maxStudent;

    return 0;
}