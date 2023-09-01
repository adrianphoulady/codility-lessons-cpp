vector<int> partial_peak_sum(vector<int> &a) {
    vector<int> pps(a.size() + 1);
    for (int p = 1; p < (int) a.size() - 1; ++p)
        pps[p + 1] = pps[p] + (a[p - 1] < a[p] && a[p] > a[p + 1]);
    pps[a.size()] = pps[a.size() - 1];
    return pps;
}

bool check(vector<int> &pps, int d) {
    for (int i = d; i <= (int) pps.size(); i += d)
        if (pps[i] - pps[i - d] == 0)
            return false;
    return true;
}

int solution(vector<int> &a) {
    auto pps = partial_peak_sum(a);
    for (int d = 2; d <= (int) a.size(); ++d)
        if (a.size() % d == 0 && check(pps, d))
            return a.size() / d;
    return 0;
}
