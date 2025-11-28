class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // code here
        int allxor = 0;
        vector<int>ans,sub;
        for(int i=1;i<=n;i++)
        {
            allxor ^=i;
            ans.push_back(i);
        }
        if(allxor == n)
        {
            return ans;
        }
        else{
            int beshi = allxor ^ n;
            for(auto u: ans)
            {
                if(beshi != u)
                {
                    sub.push_back(u);
                }
            }
        }
        return sub;
        
    }
};
