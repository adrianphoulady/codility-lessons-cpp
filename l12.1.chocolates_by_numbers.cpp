#include <numeric>

int solution(int n, int m) {
    // if this occurs after x jumps, we have xm mod n = am mod n,
    // meaning (x-a)m mod n = 0. So, we need the smallest x which
    // xm mod n = 0, or xm = kn. The least possible value for this
    // would be lcm(n, m):
    // xm = lcm(n, m) = mn / gcd(n, m), or, x = n / gcd(n, m).
    return n / gcd(n, m);
}
