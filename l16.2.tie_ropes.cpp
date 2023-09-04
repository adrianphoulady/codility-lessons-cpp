int solution(int k, vector<int> &a) {
    int cnt = 0, sum = 0;
    for (int const &e: a)
        if ((sum += e) >= k) {
            ++cnt;
            sum = 0;
        }
    return cnt;
}
