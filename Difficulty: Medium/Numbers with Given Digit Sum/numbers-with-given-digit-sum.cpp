class Solution {
  public:

    int countWays(int n, int sum) {
        if (sum > 9 * n)
            return -1;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        dp[0][0] = 1;

        // Build the DP table.
        for (int len = 1; len <= n; len++) {
            for (int s = 0; s <= sum; s++) {
                for (int digit = 0; digit <= 9; digit++) {
                    if (s >= digit) {
                        dp[len][s] += dp[len - 1][s - digit];
                    }
                }
            }
        }

        int ans = 0;

        for (int digit = 1; digit <= 9; digit++) {
            if (sum >= digit) {
                ans += dp[n - 1][sum - digit];
            }
        }

        return (ans == 0) ? -1 : ans;
    }
};