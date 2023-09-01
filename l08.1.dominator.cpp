int solution(vector<int> &a) {
    int rep = 0, can = 0;
    for (int i = 0; i < (int) a.size(); ++i)
        if (!rep) {
            can = i;
            rep = 1;
        }
        else
            rep += a[i] == a[can]? +1: -1;
    rep = 0;
    for (int const &e: a)
        rep += e == a[can];
    return rep > (int) a.size() / 2? can: -1;
}
