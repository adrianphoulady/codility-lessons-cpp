bool check(vector<int> &a, int k, int v) {
    int sum = v + 1, cnt = 0;
    for (int const &e: a) {
        sum += e;
        if (sum > v) {
            sum = e;
            ++cnt;
        }
        if (sum > v || cnt > k)
            return false;
    }
    return true;
}

int solution(int k, int m, vector<int> &a) {
    int l = -1, r = (a.size() + k - 1) / k * m;
    while (r - l != 1)
        (check(a, k, (l + r) >> 1)? r: l) = (l + r) >> 1;
    return l + 1;
}
