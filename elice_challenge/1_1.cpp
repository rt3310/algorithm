#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int pos1, pos2;
    string N;
    cin >> N;
    for (pos1 = N.length() - 2; N[pos1] >= N[pos1 + 1]; pos1--);
    for (pos2 = pos1 + 1; N[pos1] < N[pos2] && pos2 < N.length(); pos2++);
    pos2--;
    swap(N[pos1], N[pos2]);
    sort(N.begin() + pos1 + 1, N.end());
    cout << N;
}