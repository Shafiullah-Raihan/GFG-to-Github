class Solution {
  public:
    int tsp(vector<vector<int>>& cost) {
        // Code here
        int n= cost.size();
        int full = 1<<n,inf=1e9;
        vector<vector<int>>dp(full,vector<int>(n,inf));
        dp[1<<0][0]=0;
        for(int mask=0;mask<full;mask++)
        {
            for(int last =0;last<n;last++)
            {
                if(dp[mask][last] == inf) continue;
                for(int nxt =0;nxt<n;nxt++)
                {
                    if(mask &(1<<nxt)) continue;
                    int nextMask = mask | (1<<nxt);
                    dp[nextMask][nxt] = min(dp[nextMask][nxt],dp[mask][last]+cost[last][nxt]);
                }
            }
        }
        
        int ans = inf;
        int allMask = full - 1;
        for(int last = 0; last < n; last++){
            if (dp[allMask][last] < inf) {
                ans = min(ans, dp[allMask][last] + cost[last][0]);
            }
        }
        return ans;

    }
};