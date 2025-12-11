class Solution {
  public:
    // Function to find the nth catalan number.
    int findCatalan(int n) {
        // code here
        vector<int> ans(n+1,0);
        ans[0] = ans[1] = 1;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                ans[i] += (ans[j]*ans[i-j-1]);
            }
        }
        return ans[n];
    }
};