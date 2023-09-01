int solution(int x, int y, int d) {
    // + d because y may be equal to x
    return (y - x - 1 + d) / d;
}
