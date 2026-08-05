class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 0;

        while (true) {
            bool allZero = true; 

            for (int i = arr.size() - 1; i >= 0; --i) {
                if (arr[i] % 2 == 1) {
                    arr[i]--; 
                    ans++;   
                }
                if (arr[i] != 0)
                    allZero = false; 
                arr[i] /= 2;        
            }

            if (allZero)
                break;
            ans++;    
        }
        return ans; 
    }
};
