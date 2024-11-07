#include <cstdio>
using namespace std;

char check[4200000];

void setBit(int num) {
    check[num / 8] |= (1 << (num % 8));
}

bool exists(int num) {
    return check[num / 8] & (1 << (num % 8));
}

int main() {
    int num;
    while (~scanf("%d", &num)) {
        if (!exists(num)) {
            setBit(num);
            printf("%d ", num);
        }
    }
    return 0;
}