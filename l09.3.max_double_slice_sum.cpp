int solution(vector<int> &a) {
    int ds_max = 0;
    vector<int> left_max(a.size()), right_max(a.size());
    for (int i = 1; i < (int) a.size(); ++i)
        left_max[i] = max(left_max[i - 1] + a[i], 0);
    for (int i = (int) a.size() - 2; i >= 0; --i)
        right_max[i] = max(right_max[i + 1] + a[i], 0);
    for (int i = 1; i < (int) a.size() - 1; ++i)
        ds_max = max(ds_max, left_max[i - 1] + right_max[i + 1]);
    return ds_max;
}
