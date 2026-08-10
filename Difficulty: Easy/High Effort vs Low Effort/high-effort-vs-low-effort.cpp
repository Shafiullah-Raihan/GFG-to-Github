// class Solution {
//   public:
//     int maxTask(vector<int>& h, vector<int>& l) {
//         // code here
//         int n= h.size();

        
//         vector<int>dp(n,0);
//         dp[0] = max(h[0],l[0]);
//         if(n==1) return dp[0];
//         for(int i=1;i<n;i++)
//         {
//             dp[i] = dp[i - 1] + l[i];
//             if(i>=2)
//             {
//                 dp[i] = max(dp[i], dp[i-2]+h[i]);
//             }
//         }
//         return dp[n-1];
        
        
        
//     }
// };

class Solution {
public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = h.size();

        if (n == 0)
            return 0;

        vector<int> dp(n, 0);

        dp[0] = max(h[0], l[0]);

        if (n == 1)
            return dp[0];

  
        dp[1] = max(h[1], l[1] + dp[0]);


        for (int i = 2; i < n; i++) {
            dp[i] = max(l[i] + dp[i - 1], h[i] + dp[i - 2]);
        }

        return dp[n - 1];
    }
};
