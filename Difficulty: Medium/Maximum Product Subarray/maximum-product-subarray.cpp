class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        // code here
        int ans=INT_MIN,pro=1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            pro *= nums[i];
            ans=max(pro,ans);
            if(pro==0) pro=1;
        }
        pro=1;
        for(int i=n-1;i>=0;i--)
        {
            pro *= nums[i];
            ans = max(pro,ans);
            if(pro==0) pro=1;
        }
        return ans;
        
    }
};