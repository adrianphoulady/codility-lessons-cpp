int solution(int a, int b, int k) {
    // floor(b / k) + floor((a - 1) / k)
    // + k to keep the numerator positive
    return b / k - ((a - 1ll + k) / k - 1);
}
