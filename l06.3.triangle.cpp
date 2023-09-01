int solution(vector<int> &a) {
    // just the maximum should be smaller than the other two,
    // and if there exists a triplet, there exists a consecutive one
    sort(begin(a), end(a));
    for (int i = 2; i < (int) a.size(); ++i)
        if (a[i] - a[i - 1] < a[i - 2])
            return true;
    return false;
}
