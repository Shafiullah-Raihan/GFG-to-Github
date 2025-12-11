class Solution {
  public:
    int bellNumber(int n) {
        // Code Here
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int k=1;k<=i;k++)
            {
                dp[i][k] = k*dp[i-1][k]+dp[i-1][k-1];
            }
        }
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            ans+= dp[n][i];
        }
        return ans;
    }
};
