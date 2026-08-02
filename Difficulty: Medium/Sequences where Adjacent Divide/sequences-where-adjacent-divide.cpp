class Solution {
  public:
    int count(int n, int m) {
        int dp[12][12] = {};


        vector<int> di[12], mu[12];

        for (int i = 1; i <= m; i++) {
            for (int j = 2 * i; j <= m; j += i) {
                di[j].push_back(i);
                mu[i].push_back(j);
            }
            di[i].push_back(i);
        }

        for (int i = 1; i <= m; i++)
            dp[1][i] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = 0;

                for (auto x : di[j])
                    dp[i][j] += dp[i - 1][x];

                for (auto x : mu[j])
                    dp[i][j] += dp[i - 1][x];
            }
        }

        int ans = 0;
        for (int i = 1; i <= m; i++)
            ans += dp[n][i];
        return ans;
    }
};