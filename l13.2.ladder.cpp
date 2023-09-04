vector<int> solution(vector<int> &a, vector<int> &b) {
    int const max_a = *max_element(begin(a), end(a)), max_b = *max_element(begin(b), end(b));
    vector<int> f(max_a + 2), res(a.size());
    f[1] = 1;
    for (int i = 2; i < (int) f.size(); ++i)
        f[i] = (f[i - 1] + f[i - 2]) & ((1 << max_b) - 1);
    for (size_t i = 0; i < a.size(); ++i)
        res[i] = f[a[i] + 1] & ((1 << b[i]) - 1);
    return res;
}
