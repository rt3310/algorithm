#include <iostream>
using namespace std;

int k;
constexpr int E = 1, W = 2, S = 3, N = 4;
int smallBox = 0;
int horizontal = 0, vertical = 0;
int startDist = 0, endDist = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> k;

    int prevDir = 0;
    int prevDist = 0;
    for (int i = 0; i < 6; i++) {
        int dir, dist;

        cin >> dir >> dist;

        if (i == 0) {
            startDist = dist;
        } else if (i == 5) {
            endDist = dist;
        }

        switch (dir)
        {
        case E:
            if (prevDir == N) {
                smallBox = dist * prevDist;
            }
            horizontal += dist;
            break;
        case W:
            if (prevDir == S) {
                smallBox = dist * prevDist;
            }
            horizontal += dist;
            break;
        case S:
            if (prevDir == E) {
                smallBox = dist * prevDist;
            }
            vertical += dist;
            break;
        case N:
            if (prevDir == W) {
                smallBox = dist * prevDist;
            }
            vertical += dist;
            break;
        default:
            break;
        }
        prevDir = dir;
        prevDist = dist;
    }

    if (smallBox == 0) {
        smallBox = startDist * endDist;
    }

    int result = ((horizontal / 2) * (vertical / 2) - smallBox) * k;
    cout << result;

    return 0;
}