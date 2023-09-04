#include <numeric>

bool same_factors(int a, int b) {
    int g = gcd(a, b), d;
    while ((d = gcd(a, g)) != 1)
        a /= d;
    while ((d = gcd(b, g)) != 1)
        b /= d;
    return a == 1 && b == 1;
}

int solution(vector<int> &a, vector<int> &b) {
    int ans = 0;
    for (size_t i = 0; i < a.size(); ++i)
        ans += same_factors(a[i], b[i]);
    return ans;
}
