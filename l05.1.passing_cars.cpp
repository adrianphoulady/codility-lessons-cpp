int solution(vector<int> &a) {
    int passing = 0;
    for (int i = 0, zeros = 0; i < (int) a.size(); ++i)
        if ((passing += a[i] * (zeros += 1 - a[i])) > 1'000'000'000)
            return -1;
    return passing;
}
