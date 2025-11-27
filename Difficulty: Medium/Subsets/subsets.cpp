class Solution {
  public:
    void backtrack(int idx, vector<int>& arr, vector<int>& temp,vector<vector<int>>& ans, int n) {
        ans.push_back(temp);  // current subset

        for (int i = idx; i < n; i++) {
            temp.push_back(arr[i]);
            backtrack(i + 1, arr, temp, ans, n);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
         vector<vector<int>> ans;
        vector<int> temp;
        int n = arr.size();
        backtrack(0, arr, temp, ans, n);
        return ans;
        
    }
};

