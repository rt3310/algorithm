#include <iostream>
#include <cmath>
using namespace std;

float n;
float dots[3][2];

void convert(float& a, float& b) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
}

int main() {
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < 3; i++) {
        cin >> dots[i][0] >> dots[i][1];
        convert(dots[i][0], dots[i][1]);
    }

    for (int i = 0; i < 3; i++) {
        if (dots[i][0] == dots[i][1]) {
            continue;
        }

        float mid = (dots[i][0] + dots[i][1]) / 2.0f;

        for (int j = 0; j < 3; j++) {
            dots[j][0] = abs(mid - dots[j][0]);
            dots[j][1] = abs(mid - dots[j][1]);
        }

        if (n - mid > mid) {
            n -= mid;
        } else {
            n = mid;
        }
    }

    printf("%.1f", n);
    
    return 0;
}