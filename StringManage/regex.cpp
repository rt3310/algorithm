#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

int main() {
    vector<string> fileNames = {"db-123-log.txt", "db-124-log.txt",
                                 "not-db-log.txt", "db-12-log.txt",
                                 "db-12-log.jpg"};
    
    regex re("db-\\d*-log\\.txt");
    for (const auto &fileName: fileNames) {
        // 정규 표현식에 맞는 파일 이름들만 true로 나온다.
        // boolalpha는 0, 1이 아닌 bool 형태(false, true)로 출력하게 해주는 것
        cout << fileName << ": " << boolalpha << regex_match(fileName, re) << '\n';
    }
    return 0;
}