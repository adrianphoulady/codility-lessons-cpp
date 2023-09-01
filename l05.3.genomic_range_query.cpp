// range minimum query, but just for 4 values
vector<int> solution(string &s, vector<int> &p, vector<int> &q) {
    char acgt[] = "ACGT";
    vector<vector<int>> ps(4, vector<int>(s.size() + 1));
    vector<int> res;
    for (int j = 0; j < (int) s.size(); ++j)
        for (int i = 0; i < 4; ++i)
            ps[i][j + 1] = ps[i][j] + (s[j] == acgt[i]);
    for (int j = 0; j < (int) p.size(); ++j)
        for (int i = 0; i < 4; ++i)
            if (ps[i][q[j] + 1] - ps[i][p[j]] > 0) {
                res.emplace_back(i + 1);
                break;
            }
    return res;
}
