#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s1 = "abcdefg";
    string s2 = "abcddfg";
    string s3 = "gfedcba";

    string sarr[] = {s1, s2, s3};

    sort(sarr.begin(), sarr.end());

    for (string s: sarr) {
        cout << s;
    }
    return 0;
}