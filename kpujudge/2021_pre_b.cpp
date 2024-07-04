#include <cstdio>
using namespace std;

int a, b;

int main() {
    scanf("%d %d", &a, &b);

    int arr[21][21];
    printf("M\n");
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            arr[i][j] = (b * (i - 1)) + j;
            printf("%d", arr[i][j]);
            if (j != b) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    printf("R\n");
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= a; j++) {
            printf("%d", arr[a - j + 1][i]);
            if (j != a) {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("L\n");
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= a; j++) {
            printf("%d", arr[j][b - i + 1]);
            if (j != a) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    printf("T\n");
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= a; j++) {
            printf("%d", arr[j][i]);
            if (j != a) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}