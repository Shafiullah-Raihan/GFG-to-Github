
class Solution {
  public:
    int minPathSum(vector<vector<int>>& triangle) {
        // Code here
        int n = triangle.size();
        vector<int>ans(n,0),indi(n,0);
        for(int i=0;i<n;i++)
        {
            ans[i] = triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j = i;j>=0;j--)
            {
                int down = triangle[i][j]+ans[j];
                int diag = triangle[i][j] + ans[j+1];
                indi[j] = min(down,diag);
            }
            ans = indi;
        }
        return ans[0];
    }
};

