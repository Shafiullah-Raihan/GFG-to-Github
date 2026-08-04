class Solution {
  public:
    vector<int> primeRange(int l, int r) {
        vector<int> ans;
        if (r < 2)
            return ans;

        vector<bool> isPrime(r + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i <= r; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= r; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = max(l, 2); i <= r; i++) {
            if (isPrime[i])
                ans.push_back(i);
        }

        return ans;
    }
};