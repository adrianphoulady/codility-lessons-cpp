int solution(vector<int> &a) {
    int tricnt = 0;
    sort(begin(a), end(a));
    for (auto p3 = begin(a); p3 < end(a); ++p3)
        for (auto p1 = begin(a), p2 = p3 - 1; p1 < p2; --p2) {
            while (p1 < p2 && *p1 + *p2 <= *p3)
                ++p1;
            tricnt += p2 - p1;
        }
    return tricnt;
}
