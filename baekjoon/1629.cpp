#include <cstdio>
using namespace std;

long long a, b, mod;

long long square(int number, int count) {
    if (count == 1) {
        return number;
    }

    int half = count / 2;
    long long result = square(number, half);
    if (count % 2 == 1) {
        return (result % mod) * (result * a % mod) % mod;
    }
    return (result % mod) * (result % mod) % mod;
}

int main() {
    scanf("%lld %lld %lld", &a, &b, &mod);
    printf("%lld", square(a, b) % mod);

    return 0;
}