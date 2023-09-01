int solution(vector<int> &a) {
    int n = a.size(), rep = 0, can = 0, eq = 0, neq = 0, ans = 0;
    for (int i = 0; i < n; ++i)
        if (!rep) {
            can = i;
            rep = 1;
        }
        else
            rep += a[i] == a[can]? +1: -1;
    rep = 0;
    for (int const &e: a)
        rep += e == a[can];
    for (int const &e: a) {
        e == a[can]? ++eq: ++neq;
        ans += eq > neq && (rep - eq) > (n - rep - neq);
    }
    return ans;
}
