int solution(vector<int> &a) {
    int constexpr max_intersictions = 10'000'000;
    int n = a.size(), intersections = 0;
    vector<int> left(n), right(n);
    for (long long int i = 0; i < n; ++i) {
        ++left[max(i - a[i], 0ll)];
        ++right[min(i + a[i], n - 1ll)];
    }
    for (long long int i = 0, inside = 0; i < n; ++i) {
        intersections += (2 * inside + left[i] - 1ll) * left[i] / 2;
        if (intersections > max_intersictions)
            return -1;
        inside += left[i] - right[i];
    }
    return intersections;
}

// calculate the number of leftmost points of the disks with centers on the right of the current one
// which are to the left of the rightmost point of the current disk
int solution2(vector<int> &a) {
    int constexpr max_intersictions = 10'000'000;
    int intersections = 0;
    vector<long long int> left(a.size());
    for (int i = 0; i < (int) a.size(); ++i)
        left[i] = (long long int) i - a[i];
    sort(begin(left), end(left));
    for (int i = 0; i < (int) a.size(); ++i) {
        int lft = upper_bound(begin(left), end(left), (long long int) i + a[i]) - begin(left);
        intersections += lft - (i + 1);
        if (intersections > max_intersictions)
            return -1;
    }
    return intersections;
}
