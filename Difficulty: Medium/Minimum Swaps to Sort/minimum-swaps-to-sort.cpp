class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> vis(n,false);
        int ans=0;
        vector<pair<int,int>> pr;
        for(int i=0;i<n;i++)
        {
            pr.push_back({arr[i],i});
        }
        sort(pr.begin(),pr.end());
        
        for(int i=0;i<n;i++)
        {
            if(vis[i] || pr[i].second == i) continue;
            int curr=i;
            int cnt=0;
            while(!vis[curr])
            {
                cnt++;
                vis[curr]=true;
                curr= pr[curr].second;
            }
            ans += (cnt-1);
            
        }
        return ans;
    }
};