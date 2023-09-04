vector<int> solution(vector<int> &a) {
    int const n = a.size(), mx = *max_element(begin(a), end(a));
    vector<int> cnt(mx + 1), nondivs(mx + 1, n), res(n);
    for (int const &e: a)
        ++cnt[e];
    for (int i = 0; i < (int) nondivs.size(); ++i)
        if (cnt[i])
            for (int d = 1; d * d <= i; ++d)
                if (i % d == 0)
                    nondivs[i] -= cnt[d] + (d * d != i) * cnt[i / d];
    for (int i = 0; i < (int) a.size(); ++i)
        res[i] = nondivs[a[i]];
    return res;
}
