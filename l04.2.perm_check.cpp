int solution(vector<int> &a) {
    vector<bool> f(a.size() + 1);
    for (int const &e: a) {
        if (e > (int) a.size() || f[e])
            return false;
        f[e] = true;
    }
    return true;
}
