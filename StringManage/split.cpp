#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string s = "abcdefg";
    stringstream ss(s); // 문자열을 스트림에 넣어 놓는다.

    string buf;
    while (getline(ss, buf, 'd')) { // 스트림에서 하나씩 읽어온다. delim은 'd'로 지정했다. 지정하지 않을 시 '\n'로 자동 지정된다.
        cout << buf;
    }
    
    return 0;
}