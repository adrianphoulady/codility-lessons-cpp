int solution(vector<int> &a) {
    // consider the slices with smallest average, and between these a slice with smallenst length.
    // a slice of length l >= 4 can be divided to two slices of length 2 and l - 2 >= 2.
    // the smaller average of these two is not larger than the average of the whole slice.
    // so, we just need to consider the slices of length 2 and 3.
    double mn = 1e100;
    int ans = 0;
    for (int i = 0; i + 1 < (int) a.size(); ++i)
        if (mn > (a[i] + a[i + 1]) / 2.) {
            mn = (a[i] + a[i + 1]) / 2.;
            ans = i;
        }
    for (int i = 0; i + 2 < (int) a.size(); ++i)
        if (mn > (a[i] + a[i + 1] + a[i + 2]) / 3.) {
            mn = (a[i] + a[i + 1] + a[i + 2]) / 3.;
            ans = i;
        }
    return ans;
}
