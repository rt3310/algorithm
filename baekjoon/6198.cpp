#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    stack<int> s;
    long long total = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        while (!s.empty()) {
            int t = s.top();
            
            if (t > num) {
                total += s.size(); // 이전에 쌓인 스택은 현재 빌딩보다 다 높으므로 현재 빌딩을 다 볼 수 있다. 때문에 size만큼 더하는 것
                break;
            }
            s.pop(); // 높이가 작다면 다음 빌딩은 전부 못보므로 스택에서 제외시킨다.
        }
        s.push(num);
    }

    cout << total;

    return 0;
}