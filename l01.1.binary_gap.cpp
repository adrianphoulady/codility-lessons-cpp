int solution(int n) {
    int ans = 0;
    // current gap, initially set to -1 to wait for a 1
    for (int cur_gap = -1; n; n >>= 1)
        if (n & 1) {
            ans = max(ans, cur_gap);
            cur_gap = 0;
        }
        else if (cur_gap != -1)
            ++cur_gap;
    return ans;
}
