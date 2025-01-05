#include <iostream>
using namespace std;

int n;
int building[51];

int result = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> building[i];
    }

    for (int i = 1; i <= n; i++) {
        int leftMaxCanView = 0;
        int rightMaxCanView = 0;
        for (int j = i + 1; j <= n; j++) {
            float iToJIncli= (float)(building[j] - building[i]) / (j - i);
            bool canView = true;
            for (int k = i + 1; k < j; k++) {
                float iToKIncli = (float)(building[k] - building[i]) / (k - i);
                if (iToKIncli >= iToJIncli) {
                    canView = false;
                    break;
                }
            }
            if (canView) {
                rightMaxCanView++;
            }
        }
        for (int j = i - 1; j >= 1; j--) {
            float iToJIncli= (float)(building[j] - building[i]) / (j - i);
            bool canView = true;
            for (int k = i - 1; k > j; k--) {
                float iToKIncli = (float)(building[k] - building[i]) / (k - i);
                if (iToKIncli <= iToJIncli) {
                    canView = false;
                    break;
                }
            }
            if (canView) {
                leftMaxCanView++;
            }
        }
        result = max(result, rightMaxCanView + leftMaxCanView);
    }

    cout << result;

    return 0;
}