#include <numeric>

vector<int> solution(int n, vector<int> &p, vector<int> &q) {
    vector<int> factor(n + 1), prefix_semiprime_sum(n + 1), res(p.size());
    for (int i = 2; i * i <= n; ++i)
        if (!factor[i])
            for (int j = i * i; j <= n; j += i)
                factor[j] = i;
    for (int i = 1; i <= n; ++i)
        prefix_semiprime_sum[i] = prefix_semiprime_sum[i - 1] + (factor[i] && !factor[i / factor[i]]);
    for (int i = 0; i < (int) p.size(); ++i)
        res[i] = prefix_semiprime_sum[q[i]] - prefix_semiprime_sum[p[i] - 1];
    return res;
}

#include <numeric>

vector<int> solution2(int n, vector<int> &p, vector<int> &q) {
    vector<bool> is_prime(n / 2 + 1, true);
    // is_semiprime could be bool, but partial_sum would not work as we need
    vector<int> is_semiprime(n + 1), primes, prefix_semiprime_sum(n + 1), res(p.size());
    for (int i = 2; i <= n / 2; ++i)
        if (is_prime[i]) {
            primes.emplace_back(i);
            for (int j = i * i; j <= n / 2; j += i)
                is_prime[j] = false;
        }
    for (int i = 0; i < (int) primes.size(); ++i)
        for (int j = i; j < (int) primes.size() && primes[i] * primes[j] <= n; ++j)
            is_semiprime[primes[i] * primes[j]] = true;
    partial_sum(begin(is_semiprime), end(is_semiprime), begin(prefix_semiprime_sum));
    for (int i = 0; i < (int) p.size(); ++i)
        res[i] = prefix_semiprime_sum[q[i]] - prefix_semiprime_sum[p[i] - 1];
    return res;
}
