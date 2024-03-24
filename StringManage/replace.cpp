#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abcdefg";

    s.replace(s.find("de"), 2, "vv");
    // s.replace(s.begin() + 3, s.begin() + 4, "ae");

    cout << s;
    return 0;
}