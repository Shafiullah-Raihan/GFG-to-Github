class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
        int oneCount = 0;
    
        // Minimum toggles required
        int toggle = 0;
    
        for (int x : arr)
        {
            // If current element is 1
            if (x == 1)
            {
                oneCount++;
            }
            else
            {
                // Two choices:
                // 1. Toggle current 0 to 1  -> toggle + 1
                // 2. Toggle all previous 1s to 0 -> oneCount
                toggle = min(toggle + 1, oneCount);
            }
        }
    
        return toggle;
            
    }
};