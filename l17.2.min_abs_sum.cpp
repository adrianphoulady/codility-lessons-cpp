#include <numeric>

int solution(vector<int> &a) {
    int mx = -1;
    for (int &e: a) {
        if (e < 0)
            e = -e;
        mx = max(mx, e);
    }
    vector<int> cnt(mx + 1);
    for (int &e: a)
        ++cnt[e];
    int sum = accumulate(begin(a), end(a), 0);
    vector<int> reachable(sum / 2 + 1, -1);
    reachable[0] = 0;
    for (size_t e = 0; e < cnt.size();  ++e)
        if (cnt[e])
            for (size_t s = 0; s < reachable.size(); ++s) {
                if (reachable[s] >= 0)
                    reachable[s] = cnt[e];
                else if (s >= e && reachable[s - e] >= 1)
                    reachable[s] = reachable[s - e] - 1;
            }
    for (int s = sum / 2; s >= 0; --s)
        if (reachable[s] >= 0)
            return sum - 2 * s;
    return -1;
}
