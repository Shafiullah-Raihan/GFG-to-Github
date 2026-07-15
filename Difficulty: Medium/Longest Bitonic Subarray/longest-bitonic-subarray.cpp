class Solution {
  public:
    int bitonic(vector<int> &arr) {
        // code here
        int n = arr.size();

       
        vector<int> inc(n);
    
       
        vector<int> dec(n);
        int i, max;
    
       
        inc[0] = 1;
    
       
        dec[n - 1] = 1;
    
       
        for (i = 1; i < n; i++)
            inc[i] = (arr[i] >= arr[i - 1]) ? inc[i - 1] + 1 : 1;
    
        for (i = n - 2; i >= 0; i--)
            dec[i] = (arr[i] >= arr[i + 1]) ? dec[i + 1] + 1 : 1;
    
      
        max = inc[0] + dec[0] - 1;
        for (i = 1; i < n; i++)
            if (inc[i] + dec[i] - 1 > max)
                max = inc[i] + dec[i] - 1;
    
        return max;
    }
};