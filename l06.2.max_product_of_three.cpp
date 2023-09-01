int solution(vector<int> &a) {
    // either three maximum positives,
    // or a maximum positive and two minimum negatives,
    // or if all negative, three maximum negatives
    for (int i = 0; i < 3; ++i) {
        swap(*(begin(a) + i), *min_element(begin(a) + i, end(a)));
        swap(*(end(a) - i - 1), *max_element(begin(a), end(a) - i));
    }
    return max(a[0] * a[1] * a[a.size() - 1],
               a[a.size() - 3] * a[a.size() - 2] * a[a.size() - 1]);
}
