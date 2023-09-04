#include <climits>

int solution(vector<int> &a) {
    int min_abs_sum = INT_MAX;
    sort(begin(a), end(a));
    for (auto p1 = begin(a), p2 = end(a) - 1; p1 <= p2; ) {
        min_abs_sum = min(min_abs_sum, abs(*p1 + *p2));
        *p1 + *p2 > 0? --p2: ++p1;
    }
    return min_abs_sum;
}
