class Solution {
  public:
    static const int MOD = 1e9 + 7;

    int modPow(int exp) {
        int res = 1, base = 2;

        while (exp) {
            if (exp & 1)

              
                res = (1LL * res * base) % MOD;

            base = (1LL * base * base) % MOD;
            exp >>= 1;
        }

        return res;
    }

    int countSubsets(vector<int>& arr) {
        vector<int> mask(31, 0);
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        for (int num = 2; num <= 30; num++) {

            if (num % 4 == 0 || num % 9 == 0 || num == 25)
                continue;

            for (int i = 0; i < 10; i++) {
                if (num % primes[i] == 0)
                    mask[num] |= (1 << i);
            }
        }

        vector<int> cnt(31, 0);
        vector<int> dp(1024, 0);

        int ones = 0;
        dp[0] = 1;

        for (int x : arr) {
            if (x == 1)
                ones++;
            else if (mask[x] != 0)
                cnt[x]++;
        }

        for (int num = 2; num <= 30; num++) {
            if (cnt[num] == 0)
                continue;

            for (int state = 1023; state >= 0; state--) {

                if (state & mask[num])
                    continue;

                dp[state | mask[num]] =
                    (dp[state | mask[num]] + 1LL * dp[state] * cnt[num]) % MOD;
            }
        }

        int ans = 0;

        for (int ways : dp)
            ans = (ans + ways) % MOD;

        ans = (ans - 1 + MOD) % MOD;

        ans = (1LL * ans * modPow(ones)) % MOD;

        return ans;
    }
};