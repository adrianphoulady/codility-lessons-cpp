vector<int> solution(vector<int> &a, int k) {
    if (a.size())
        rotate(begin(a), prev(end(a), k % a.size()), end(a));
    return a;
}

vector<int> solution2(vector<int> &a, int k) {
    int const n = a.size();
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        b[(i + k) % n] = a[i];
    return b;
}

vector<int> solution3(vector<int> &a, int k) {
    if (a.size()) {
        // converting to a left rotation
        k = (int) a.size() - k % a.size();
        vector<int> t(k);
        copy(begin(a), begin(a) + k, begin(t));
        copy(begin(a) + k, end(a), begin(a));
        copy(begin(t), end(t), end(a) - k);
    }
    return a;
}
