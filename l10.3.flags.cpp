#include <cmath>

void mutate(vector<int> &a) {
    int nxt = a.size();
    for (int p = (int) a.size() - 1, app1 = a.back(); p; --p) {
        if (a[p - 1] < a[p] && a[p] > app1)
            nxt = p;
        app1 = a[p];
        a[p] = nxt;
    }
    a[0] = nxt;
}

bool check(vector<int> &nxt, int d) {
    int n = nxt.size(), cnt = 0, p = nxt[0];
    while (p < n && ++cnt < d)  // ++cnt won't execute if p >= n
        p = nxt[min(p + d, n - 1)];
    return cnt >= d;
}

int solution(vector<int> &a) {
    mutate(a);
    int l = 0, r = sqrt(a.size()) + 2, m;  // d can't be larger than sqrt(n) + 1
    while (r - l > 1)
        check(a, m = (l + r) >> 1)? l = m: r = m;
    return l;
}
