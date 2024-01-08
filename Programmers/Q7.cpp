#include <bitset>
using namespace std;

int solution(int n) {
    int answer = n + 1;
    
    int count = bitset<20>(n).count();
    while (true) {
        if (bitset<20>(answer).count() == count) {
            return answer;
        }
        answer++;
    }
    return answer;
}