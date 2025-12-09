class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int>ans;
        unordered_map<int,int>mp;
        
        for(auto u:arr)
        {
            mp[u]++;
        }
        for(auto u:mp)
        {
            if(u.second>1){
          
                    ans.push_back(u.first);
                
                
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
