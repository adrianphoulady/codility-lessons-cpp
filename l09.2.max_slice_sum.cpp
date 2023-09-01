int solution(vector<int> &a) {
    int post_max = 0, slice_max = a[0];
    for (int const &e: a) {
        post_max = max(post_max + e, e);
        slice_max = max(slice_max, post_max);
    }
    return slice_max;
}
