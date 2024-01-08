using namespace std;

int solution(int n, int a, int b)
{
    int count = 0;
    while (true) {
        if ((a % 2 == 0 && a - 1 == b) || (b % 2 == 0 && b - 1 == a)) {
            return count + 1;
        }
        if (a % 2 == 0) {
            a /= 2;
        } else {
            a = (a + 1) / 2;
        }
        if (b % 2 == 0) {
            b /= 2;
        } else {
            b = (b + 1) / 2;
        }
        
        count++;
    }

    return count + 1;
}