int solution(vector<int> &a, vector<int> &b) {
    int mxnon = 0;
    for (int i = 0, lst = -1; i < (int) a.size(); ++i)
        if (lst < a[i]) {
            ++mxnon;
            lst = b[i];
        }
    return mxnon;
}
