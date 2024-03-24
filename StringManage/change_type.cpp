#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "1234";

    cout << stoi(s) + 100 << "\n";
    cout << stol(s) + 100 << "\n";
    cout << stod(s) + 100.0 << "\n";
    cout << stof(s) + 100.0f << "\n";
    cout << stoll(s) + 100 << "\n";
    cout << stoul(s) + 100 << "\n";
    cout << stoull(s) + 100 << "\n";

    cout << to_string(1234) + "100" << "\n";
    return 0;
}