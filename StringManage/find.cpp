#include <string>
#include <iostream>
using namespace std;

int main() {
    string s = "abcdefg";

    auto found = s.find('e');

    cout << found;
    return 0;
}