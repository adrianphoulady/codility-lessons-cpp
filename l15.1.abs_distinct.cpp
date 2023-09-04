int solution(vector<int> &a) {
    int cnt = 0;
    for (auto p1 = begin(a), p2 = end(a) - 1; p1 <= p2; ++cnt) {
        int ap1 = *p1, ap2 = *p2;
        if (0ll + ap1 + ap2 <= 0)
            while (p1 < end(a) && *p1 == ap1)
                ++p1;
        if (0ll + ap1 + ap2 >= 0)
            while (p2 >= begin(a) && *p2 == ap2)
                --p2;
    }
    return cnt;
}
