bool check(vector<int> &a, vector<int> &b, vector<int> &c, int k) {
    vector<int> prefix_nails_sum(2 * c.size() + 2);
    while (k--)
        prefix_nails_sum[c[k]] = 1;
    for (size_t i = 1; i < prefix_nails_sum.size(); ++i)
        prefix_nails_sum[i] += prefix_nails_sum[i - 1];
    for (size_t i = 0; i < a.size(); ++i)
        if (prefix_nails_sum[b[i]] == prefix_nails_sum[a[i] - 1])
            return false;
    return true;
}

int solution(vector<int> &a, vector<int> &b, vector<int> &c) {
    size_t l = 0, r = c.size() + 1;
    while (r - l != 1)
        (check(a, b, c, (l + r) >> 1)? r: l) = (l + r) >> 1;
    return l + 1 <= c.size()? l + 1: -1;
}
