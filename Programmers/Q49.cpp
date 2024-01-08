#include <string>
#include <map>
#include <vector>

using namespace std;

int solution(string word) {
    char arr[] = {'A', 'E', 'I', 'O', 'U'};
    map<char, char> nexts;
    
    nexts['A'] = 'E';
    nexts['E'] = 'I';
    nexts['I'] = 'O';
    nexts['O'] = 'U';
    
    string cur = "A";
    
    int order = 0;
    while (cur != word) {
        int len = cur.size();
        
        if (len < 5) {
            cur += 'A';
            order++;
            continue;
        }
        
        while (cur[cur.size() - 1] == 'U') {
            cur = cur.substr(0, cur.size() - 1);
        }
        if (cur.size() == 0) {
            break;
        }
        cur[cur.size() - 1] = nexts[cur[cur.size() - 1]];
        order++;
    }
    return order + 1;
}