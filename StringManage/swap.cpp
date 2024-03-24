#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "abcdefg";
    string s2 = "gfedcba";

    s2.swap(s1);

    cout << s1 << "\n";
    cout << s2 << "\n";
    return 0;
}