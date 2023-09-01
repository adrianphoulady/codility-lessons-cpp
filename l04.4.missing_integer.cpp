int solution(vector<int> &a) {
    int n = a.size();
    vector<bool> present(n + 1);
    for (int const &e: a)
        if (1 <= e && e <= n)
            present[e] = true;
    for (int i = 1; i <= n; ++i)
        if (!present[i])
            return i;
    return n + 1;
}
