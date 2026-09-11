class Solution {
  public:
    int sameMod(vector<int> &arr) {
        int n = arr.size();

        int g = 0;

        // Compute the GCD of all differences.
        for (int i = 1; i < n; i++) {
            g = __gcd(g, abs(arr[i] - arr[0]));
        }

        // If all elements are equal, infinitely many values of k exist.
        if (g == 0) {
            return -1;
        }

        int cnt = 0;

        // Count all positive divisors of the GCD.
        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                cnt++;

                if (i != g / i) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};