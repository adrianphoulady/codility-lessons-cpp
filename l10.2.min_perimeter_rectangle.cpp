#include <cmath>

int solution(int n) {
    for (int i = sqrt(n) + .1; i; --i)
        if (n % i == 0)
            return 2 * (i + n / i);
    return -1;  // never happens
}
