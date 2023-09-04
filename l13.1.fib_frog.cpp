int solution(vector<int> &a) {
    int const n = a.size(), oo = 1e9;
    vector<int> f{0, 1}, mn(n + 2, oo);
    for (int i = 2, s = 1; s <= n + 1; ++i)
        f.emplace_back(s = f[i - 1] + f[i - 2]);
    mn[0] = 0;
    for (int p = 0; p <= n; ++p)
        if (p == 0 || a[p - 1])
            for (int i = 1; p + f[i] <= n + 1; ++i)
                mn[p + f[i]] = min(mn[p + f[i]], mn[p] + 1);
    return mn[n + 1] < oo? mn[n + 1]: -1;
}
