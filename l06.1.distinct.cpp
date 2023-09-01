#include <unordered_set>

int solution(vector<int> &a) {
    return unordered_set<int>(begin(a), end(a)).size();
}

int solution2(vector<int> &a) {
    sort(begin(a), end(a));
    return unique(begin(a), end(a)) - begin(a);
}

#include <numeric>

int solution3(vector<int> &a) {
    int constexpr max_v = 1'000'000;
    vector<bool> present(2 * max_v + 1);
    for (int const &e: a)
        present[e + max_v] = true;
    return accumulate(present.begin(), present.end(), 0);
}
