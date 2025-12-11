
class Solution {
  public:
    // Function to find the maximum money the thief can get.
    int findMaxSum(vector<int>& arr) {
        // Your code here
        int n= arr.size();
        vector<int>dp(n,0);
        dp[0] = arr[0], dp[1] = max(arr[0],arr[1]);
        for(int i=2;i<n;i++)
        {
            dp[i] = max(arr[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
        
    }
};

