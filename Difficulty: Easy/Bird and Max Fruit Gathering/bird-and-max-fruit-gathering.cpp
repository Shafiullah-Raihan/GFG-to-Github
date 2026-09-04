class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();
        int sum = 0;

        for (int i = 0; i < m; i++) {
            sum += arr[i];
        }

        int res = sum;
        int left = 0;

        for (int right = m; right < n + m; right++) {
            sum -= arr[left];
            sum += arr[right % n];
            res = max(res, sum);
            left++;
        }

        return res;
    }
};