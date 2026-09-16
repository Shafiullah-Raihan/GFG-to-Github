class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        // Code here
        int n= arr.size();
        int half = n/2;
        vector<int>l,r;
        for(int i=0;i<n/2;i++) l.push_back(arr[i]);
        for(int i=n/2;i<n;i++) r.push_back(arr[i]);
        sort(l.begin(),l.end());sort(r.begin(),r.end());
        int ans=0;
        for(int i=0;i<r.size();i++)
        {
            auto it = lower_bound(l.begin(),l.end(),5*r[i]);
            ans += (l.end() - it);
        }
        return ans;
    }
};