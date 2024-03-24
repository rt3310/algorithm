#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abcdefg";

    s += "hijk";
    cout << s << "\n";

    s.append("lmnop");
    cout << s << "\n";

    s.push_back('q');
    cout << s << "\n";

    s.pop_back();
    cout << s << "\n";

    string copied = s;
    copied += "abc";
    cout << "original: " << s << "\n";
    cout << "copied: " << copied << "\n";

    return 0;
}