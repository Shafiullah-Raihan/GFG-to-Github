class Solution {
  public:
    int countSubsequences(string& s, int n) {
        const int mod = 1000000007;

        vector<int> dp(n, 0);

        for (char ch : s) {
            int digit = ch - '0';
            vector<int> curr(dp);

            curr[digit % n] = (curr[digit % n] + 1) % mod;
            for (int rem = 0; rem < n; rem++) {

                int nextRem = (rem * 10 + digit) % n;
                curr[nextRem] = (curr[nextRem] + dp[rem]) % mod;
            }

            dp = curr;
        }
        return dp[0];
    }
};