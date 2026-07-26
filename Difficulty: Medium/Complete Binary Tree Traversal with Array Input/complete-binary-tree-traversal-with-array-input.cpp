class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        vector<vector<int>> res;
        int n = arr.size();

        int start = 0;

        int level = 1;

        while (start < n) {
            // Compute the ending index (exclusive) of the current level.
            int end = min((1 << level) - 1, n);

            sort(arr.begin() + start, arr.begin() + end);

            // Store the sorted values of the current level.
            vector<int> curr;
            for (int i = start; i < end; i++) {
                curr.push_back(arr[i]);
            }

            res.push_back(curr);

            start = end;
            level++;
        }

        return res;
    }
};