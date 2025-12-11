class Solution {
  public:
    int minSquares(int n) {
        // Code here
        vector<int>dp(10001),square(100);
        for(int i=0;i<=10000;i++)
        {
            dp[i] = i;
        }

        for(int i=2;i<=n;i++)
        {
            dp[i] = min(dp[i],dp[i-1]+1);
            for(int j=1;j*j<=i;j++)
            {
                dp[i] =min(dp[i],dp[i-j*j]+1);
            }
        }


        // for(int i=0;i<=100;i++)
        // {
        //     dp[i*i]=1;
        // }
        // for(int i=2;i<=n;i++)
        // {
        //     for(int j=1;j<i*i;j++)
        //     {
        //         if(i-dp[j*j]>=0)
        //         {
        //             dp[i] = min(dp[i],dp[i-dp[j*j]]+1);
        //         }
        //     }
        // }




        return dp[n];
    }
};