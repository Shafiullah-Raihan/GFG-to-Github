class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        // code here
        int n = arr.size();

		   
		    if (n == 1) {
		        return 1;
		    }

		  
		    unordered_map<int, int> dp;
		    int ans = 1;

		    for (int i = 0; i < n; ++i) {

		       
		        if (dp.count(arr[i] + 1) > 0 
		                       || dp.count(arr[i] - 1) > 0) {

		            dp[arr[i]] = 1 + 
		                  max(dp[arr[i] + 1], dp[arr[i] - 1]);
		        } 
		        else {
		            dp[arr[i]] = 1;  
		        }

		      
		        ans = max(ans, dp[arr[i]]);
		    }

		    return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        // int ans=0,cnt=1;
        // sort(arr.begin(),arr.end());
        // int n= arr.size();
        // map<int,int>mp;
        // for(int i=0;i<n;i++)
        // {
        //     mp[arr[i]]++;
        // }
        // for(auto u:mp)
        // {
        //     int val = u.first;int fre = u.second;
            
        //     if(mp.count(val-1))
        //     {
        //         cnt += mp[val-1];
        //         cnt += fre;
        //     }
        //     else{
        //         cnt = fre;
        //     }
        //     ans = max(cnt,ans);
        // }
        // return ans;
        
    }
};