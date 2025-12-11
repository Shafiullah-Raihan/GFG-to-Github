
// User function Template for C++

class Solution {
  public:
    int solve(int n,int k,vector<vector<int>>& dp)
    {
        if(k>n) return 0;
        if(k==0 || k == n) return 1;
        if(dp[n][k] != -1) return dp[n][k];
        return dp[n][k] = solve(n-1,k-1,dp) + solve(n-1,k,dp);
    }
    
    
    
    int nCr(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }
};


