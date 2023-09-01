vector<int> solution(int n, vector<int> &a) {
    vector<int> res(n);
    int mn = 0, mx = 0;  // minimum and maximum value
    for (int const &e: a)
        if (e == n + 1)
            mn = mx;
        else
            mx = max(mx, res[e - 1] = max(mn + 1, res[e - 1] + 1));
    for (int &e: res)
        e = max(e, mn);
    return res;
}
