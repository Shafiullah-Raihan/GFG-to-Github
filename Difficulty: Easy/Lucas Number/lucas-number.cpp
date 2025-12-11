class Solution {
  public:
    const long long mod = 1e9+7;
    long long lucas(int n) {
        // code here.
        vector<long long>dp(n+1);
        dp[0]= 2,dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i] = (dp[i-1] + dp[i-2])%mod;
            
        }
        return dp[n];
    }
};
