class Solution {
  public:
    string sevenSegments(string &s) {
        int n = s.size();

        int seg[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

        int total = 0;
        for (int i = 0; i < n; i++)
            total += seg[s[i] - '0'];

        string res(n, '0');
        for (int i = 0; i < n; i++) {
            int left = n - i - 1;

            for (int d = 0; d <= 9; d++) {
                int rem = total - seg[d];
                if (rem >= 2 * left && rem <= 7 * left) {
                    res[i] = '0' + d;
                    total = rem;
                    break;
                }
            }
        }

        return res;
    }
};