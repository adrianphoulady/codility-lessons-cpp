int solution(vector<int> &a) {
    int mn = 1e9, promax = 0;
    for (int const &e: a)
        if (promax < e - (mn = min(mn, e)))
            promax = e - mn;
    return promax;
}
