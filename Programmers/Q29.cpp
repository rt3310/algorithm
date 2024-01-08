#include <iostream>
#include <map>
#include <string>

using namespace std;

bool isAlpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int solution(string str1, string str2) {
    map<string, int> count1;
    map<string, int> count2;
    map<string, int> cross;

    for (int i = 0; i < str1.size() - 1; i++) {
        if (isAlpha(str1[i]) && isAlpha(str1[i + 1])) {
            count1[string(1, tolower(str1[i])) +
                   string(1, tolower(str1[i + 1]))]++;
        }
    }
    for (int i = 0; i < str2.size() - 1; i++) {
        if (isAlpha(str2[i]) && isAlpha(str2[i + 1])) {
            count2[string(1, tolower(str2[i])) +
                   string(1, tolower(str2[i + 1]))]++;
        }
    }

    int crossTotal = 0;
    int sumTotal = 0;
    for (auto &c1 : count1) {
        int oppo = count2[c1.first];
        if (oppo == 0) {
            continue;
        }
        crossTotal += min(c1.second, oppo);
    }

    map<string, int> sum(count1.begin(), count1.end());

    for (auto &c2 : count2) {
        int oppo = sum[c2.first];
        if (oppo < c2.second) {
            sum[c2.first] = c2.second;
        }
    }

    for (auto &s : sum) {
        sumTotal += s.second;
    }

    if (sumTotal == 0) {
        return 65536;
    }

    return (int)((double)crossTotal / sumTotal * 65536);
}