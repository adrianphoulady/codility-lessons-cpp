#include <numeric>

int solution(vector<int> &a) {
    int lsum = 0, rsum = accumulate(begin(a), end(a), 0), ans = INT_MAX;
    for (int i = 0; i < (int) a.size() - 1; ++i)
        ans = min(ans, abs((lsum += a[i]) - (rsum -= a[i])));
    return ans;
}
