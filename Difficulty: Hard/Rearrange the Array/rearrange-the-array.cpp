class Solution {
  public:
    static const long long MOD = 1000000007;

    long long modPow(long long x, long long y) {
        long long res = 1;
        while (y) {
            if (y & 1)
                res = (res * x) % MOD;
            x = (x * x) % MOD;
            y >>= 1;
        }
        return res;
    }

    int minOperations(vector<int> &b) {
        int n = b.size();
        vector<bool> vis(n, false);
        vector<int> cycles;

        // Find cycle lengths
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int len = 0;
                int cur = i;

                while (!vis[cur]) {
                    vis[cur] = true;

                    // 1-based -> 0-based
                    cur = b[cur] - 1;
                    len++;
                }

                cycles.push_back(len);
            }
        }

        // Sieve for primes up to n
        vector<int> spf(n + 1);
        for (int i = 0; i <= n; i++)
            spf[i] = i;

        for (int i = 2; i * i <= n; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= n; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        unordered_map<int, int> maxPower;

        // Factorize each cycle length
        for (int len : cycles) {
            unordered_map<int, int> freq;

            while (len > 1) {
                int p = spf[len];
                int cnt = 0;

                while (len % p == 0) {
                    len /= p;
                    cnt++;
                }

                freq[p] = cnt;
            }

            for (auto &it : freq) {
                maxPower[it.first] = max(maxPower[it.first], it.second);
            }
        }

        long long res = 1;

        // Construct LCM modulo MOD
        for (auto &it : maxPower) {
            res = (res * modPow(it.first, it.second)) % MOD;
        }

        return (int)res;
    }
};