class Solution {
  public:
    int maxArea(vector<vector<int>> &mat) {
        int r = mat.size();
        int c = mat[0].size();

        // Compute heights of consecutive 1s
        for (int i = 1; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j])
                    mat[i][j] += mat[i - 1][j];
            }
        }

        int ans = 0;

        // Process each row
        for (int i = 0; i < r; i++) {
            vector<int> arr = mat[i];

            // Bring taller columns together
            sort(arr.begin(), arr.end(), greater<int>());

            // Find the maximum area for this row
            for (int j = 0; j < c; j++) {
                ans = max(ans, arr[j] * (j + 1));
            }
        }

        return ans;
    }
};