class Solution {
  public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        // Your code here
        vector<int>arr = {x,y,z};
        sort(arr.begin(),arr.end());
        vector<int>dp(n+1,-1);
        dp[0]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<arr.size();j++)
            {
                if(i-arr[j]>=0 && dp[i-arr[j]] != -1)
                {
                    dp[i] = max(dp[i],dp[i-arr[j]]+1);
                }
            }
            
        }
        return max(0,dp[n]);
    }
};

