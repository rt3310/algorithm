#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v;
    int nxt[1000];

    for (int i = 0; i < 6; i++) {
        v.push_back(i + 1);
        nxt[i] = i + 1;
    }
    nxt[5] = 3;

    int one = 0;
    int two = 0;
    while (one < 6) {
        if (one != 0 && v[one] == v[two]) {
            cout << "Cycle!";
            return 0;
        }

        one = nxt[one];
        two = nxt[two];
        if (two == -1) {
            break;
        }
        two = nxt[two];
        if (two == -1) {
            break;
        }
        cout << "one: " << one << ", two: " << two << "\n";
    }

    cout << "No cycle!";

    return 0;
}