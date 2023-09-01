#include <numeric>
#include <functional>

int solution(vector<int> &a) {
    return accumulate(begin(a), end(a), 0, bit_xor<int>());
}

int solution2(vector<int> &a) {
    int ans = 0;
    for (int const &e: a)
        ans ^= e;
    return ans;
}
