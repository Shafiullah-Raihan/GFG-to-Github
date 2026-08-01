class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        vector<int> arr(n + 1, 0);

        for (int i = 0; i < a.size(); i++) {
            int lowerbound = a[i];
            int upperbound = b[i];

            arr[lowerbound] += k[i];

            if (upperbound + 1 < arr.size())
                arr[upperbound + 1] -= k[i];
        }

        int sum = 0, res = INT_MIN;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            res = max(res, sum);
        }
        return res;
    }
};