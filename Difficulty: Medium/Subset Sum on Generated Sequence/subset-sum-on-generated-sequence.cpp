using ll = long long;
class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int x) {
        // code here
        vector<ll>pre;
        pre.push_back(s);
        ll sum=s;
        for(int i=0;i<arr.size();i++)
        {
            ll curr = sum + arr[i];

            pre.push_back(curr);
            sum += curr;
        }
        ll target = x;
        for(int i=pre.size()-1;i>=0;i--)
        {
            if(target>=pre[i])
            {
                target -= pre[i];
            }
        }
        return target==0;
        
        
    }
};