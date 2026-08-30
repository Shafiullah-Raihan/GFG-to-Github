class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        int id =1;
        int n = l.size();
        vector<pair<int,int>>pr;
        for(int i=0;i<n;i++)
        {
            pr.push_back({l[i],r[i]});
        }
        map<int,int>mp;
        for(auto u:pr)
        {
            for(int i=u.first ;i<=u.second;i++)
            {
                  mp[id] = i;id++;
            }
        }
        vector<int>ans;
        for(auto u:rank)
        {
            ans.push_back(mp[u]);
        }
        return ans;
    }
};