#include <stack>

int solution(vector<int> &h) {
    int ans = 0;
    stack<int> s({0});
    for (int const &e: h) {
        while (s.top() > e)
            s.pop();
        if (s.top() < e) {
            s.push(e);
            ++ans;
        }
    }
    return ans;
}
