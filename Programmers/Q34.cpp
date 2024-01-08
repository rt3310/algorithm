#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    map<string, bool> m;
    
    sort(phone_book.begin(), phone_book.end(), [](string &a, string &b) {
        return a.size() > b.size();
    });
    
    for (string p : phone_book) {
        if (m[p]) {
            return false;
        }
        for (int i = 1; i <= p.size(); i++) {
            string n = p.substr(0, i);
            if (m[n] != true) {
                m[n] = true;
            }
        }
    }
    return true;
}