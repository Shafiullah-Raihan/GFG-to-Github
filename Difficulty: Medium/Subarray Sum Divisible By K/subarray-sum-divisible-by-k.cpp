#define ll long long
class Solution {
  public:
    // Function to count the number of subarrays with a sum that is divisible by K
    int subCount(vector<int>& arr, int k) {
        // Your code goes here
        int n=arr.size();
        unordered_map<int,ll>mp;
        ll pre=0;int ans=0;
        for(int i=0;i<n;i++)
        {
            pre = (((pre+arr[i])%k)+k)%k;
            if(pre==0)
            {
                ans++;
            }
            
            ans += mp[pre];
            mp[pre]++;
        }
        return ans;
    }
};
