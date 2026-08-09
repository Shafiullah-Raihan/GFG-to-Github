class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int j = 0; j < n; j++) {
            dp[0][j] = mat[0][j];
        }

        for(int i = 1; i < n; i++) {

            for(int j = 0; j < n; j++) {

                for(int k = 0; k < n; k++) {

                    if(k != j) {
                        dp[i][j] = max(dp[i][j], dp[i-1][k] + mat[i][j]);
                    }
                }
            }
        }

        int ans = 0;

        for(int j = 0; j < n; j++) {
            ans = max(ans, dp[n-1][j]);
        }

        return ans;
    }
};