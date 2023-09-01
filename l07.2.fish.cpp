#include <stack>

int solution(vector<int> &a, vector<int> &b) {
    stack<int> s;
    for (int i = 0; i < (int) a.size(); ++i) {
        if (b[i] == 0) {
            while (s.size() && b[s.top()] == 1 && a[i] > a[s.top()])
                s.pop();
            if (s.size() && b[s.top()] == 1 && a[i] < a[s.top()])
                continue;
        }
        s.push(i);
    }
    return s.size();
}
