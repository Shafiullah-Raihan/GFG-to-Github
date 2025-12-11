
//Back-end complete function Template for C++

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n = cost.size();
        vector<int>dp(n+1,0);
        dp[0]=cost[0];
        dp[1]= min(dp[0]+cost[1],cost[1]);
        for(int i=2;i<=n;i++)
        {
            if(i==n) 
            {
                dp[i] = min(dp[i-1],dp[i-2]);continue;
            }
            dp[i]= min(dp[i-1],dp[i-2])+cost[i];
        }
        return dp[n];
    }
};

