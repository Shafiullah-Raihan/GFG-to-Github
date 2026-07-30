class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        int mod = 1000000007;
        int n = arr.size();
        priority_queue<int> q;

        for (int i = 0; i < n; i++)
            q.push(arr[i]);

        int ans = 0, x;

        while (k && !q.empty()) {
            x = q.top();
            q.pop();
            ans = (ans + x) % mod;
            x--;
            k--;
            if (x)
                q.push(x);
        }
        return ans;
    }
};