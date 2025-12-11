class Solution {
  public:
    int raihan(vector<int>& dp,int i)
    {
        if(i<0) return 0;
        if(i==0 || i==1) return dp[i]= i;
        if(dp[i] != -1) return dp[i];
        return dp[i] = raihan(dp,i-1) + raihan(dp,i-2);
        
        
    }
    int nthFibonacci(int n) {
        // code here
        vector<int>dp(n+1,-1);
        raihan(dp,n);
        return dp[n];
    }
};