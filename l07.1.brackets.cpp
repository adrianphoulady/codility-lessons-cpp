#include <cstring>
#include <stack>

int solution(string &s) {
    stack<char> b;
    char opening[] = "([{", closing[] = ")]}", *p;
    for (char const &c: s)
        if ((p = strchr(closing, c))) {
            if (!b.size() || b.top() != opening[p - closing])
                return false;
            b.pop();
        }
        else
            b.push(c);
    return !b.size();
}
