#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abcdefg";

    cout << s.substr(3, 3); // s.substr(i, size); i에서 부터 size만큼 잘라온다.
    return 0;
}