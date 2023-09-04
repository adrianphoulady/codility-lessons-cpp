int solution(int m, vector<int> &a) {
    int constexpr max_dislices = 1'000'000'000;
    int dislices = 0;
    vector<int> last(m + 1, -1);
    for (int p1 = 0, p2 = 0; p2 < (int) a.size(); ) {
        if (last[a[p2]] >= p1)
            p1 = last[a[p2]] + 1;
        last[a[p2]] = p2;
        dislices += ++p2 - p1;
        if (dislices > max_dislices)
            return max_dislices;
    }
    return dislices;
}

int solution2(int m, vector<int> &a) {
    int constexpr max_dislices = 1'000'000'000;
    int dislices = 0;
    vector<bool> exists(m + 1);
    for (auto p1 = begin(a), p2 = p1; p2 < end(a); ) {
        while (exists[*p2])
            exists[*p1++] = false;
        exists[*p2++] = true;
        dislices += p2 - p1;
        if (dislices > max_dislices)
            return max_dislices;
    }
    return dislices;
}
