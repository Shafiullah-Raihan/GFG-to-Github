class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        int n= arr.size();
        vector<int> freq(k, 0);
        int ans = 0;
    
        for (int x : arr)
        {
            int rem = x % k;
            int need = (k - rem) % k;
    
            ans += freq[need];
    
            freq[rem]++;
        }
    
        return ans;
    }
};