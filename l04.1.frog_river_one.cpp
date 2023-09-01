int solution(int x, vector<int> &a) {
    vector<bool> f(x + 1);
    for (int i = 0; i < (int) a.size(); ++i)
        if (!f[a[i]]) {
            if (!--x)
                return i;
            f[a[i]] = true;
        }
    return -1;
}
