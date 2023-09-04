int solution(vector<int> &a) {
    for (int i = 1; i < (int) a.size(); ++i)
        a[i] += *max_element(begin(a) + max(0, i - 6), begin(a) + i);
    return a.back();
}
