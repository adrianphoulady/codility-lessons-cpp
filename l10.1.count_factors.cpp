int solution(int n) {
    int i, divs = 0;
    for (i = 1; 1ll * i * i < n; ++i)
        divs += 2 * (n % i == 0);
    divs += i * i == n;
    return divs;
}
