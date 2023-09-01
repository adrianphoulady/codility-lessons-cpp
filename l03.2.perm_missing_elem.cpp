#include <numeric>

int solution(vector<int> &a) {
    return (a.size() + 1) * (a.size() + 2) / 2 - accumulate(begin(a), end(a), 0);
}

int solution2(vector<int> &a) {
    int n = a.size(), ans = n ^ (n + 1);
    for (int i = 0; i < n; ++i)
        ans ^= i ^ a[i];
    return ans;
}

int solution3(vector<int> &a) {
    vector<bool> f(a.size() + 2);
    for (int const &e: a)
        f[e] = true;
    int ans = 1;
    while (f[ans])
        ++ans;
    return ans;
}
