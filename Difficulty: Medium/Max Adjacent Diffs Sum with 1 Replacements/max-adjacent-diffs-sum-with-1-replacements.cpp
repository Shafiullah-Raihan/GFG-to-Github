class Solution {
  public:
    // int raihan(int i,vector<int>& arr,vector<int>& dp)
    // {
    //     if(dp[i] != -1) return dp[i];
    //     if(i>=arr.size())
    //     {
    //         return 0;
    //     }
    //     int ret1=0,ret2=0;
    //     ret1 += abs(arr[i] - raihan(i+1,arr,dp));
    //     ret2 += abs(1 - raihan(i+1,arr,dp));
    //     dp[i] = max(ret1,ret2);
    //     return dp[i];
    // }
    
    int maxDiffSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<vector<int>>dp(n,vector<int>(2,0));
        for(int i=0;i<n-1;i++)
        {
            dp[i+1][0] = max(dp[i][0],dp[i][1] + abs(1-arr[i]));
            dp[i+1][1] = max(dp[i][0]+abs(1-arr[i+1]),dp[i][1] + abs(arr[i]-arr[i+1]));;
        }
        return max(dp[n-1][0],dp[n-1][1]);
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // vector<int>dp(n,-1);
        // int ans = raihan(0,arr,dp);
        // return ans;
        // int sum= accumulate(arr.begin(),arr.end(),0);
        // vector<int>dp1(n),dp2(n);
        // dp1[0] = 1,dp2[0] = arr[i];
        // for(int i=1;i<n;i++)
        // {
                
        // }
        
    }
};