class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
         map<char,int>mp;
    	for(auto u:s)
    	{
    	    mp[u]++;
    	}
    	vector<pair<char,int>>ans(mp.begin(),mp.end());
    // 	if(ans.size()==1)
    // 	{
    // 	    return ans[0].first;
    // 	}
    	sort(ans.begin(),ans.end(),[](const pair<char,int>& a, const pair<char,int>& b)
    	{
    	   if(a.second>b.second) return true;
    	   if (a.second < b.second) return false;
            return a.first < b.first; 
    	});
    	
    	return  ans[0].first;
        
    }
};