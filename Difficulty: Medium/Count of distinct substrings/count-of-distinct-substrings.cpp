
class Solution {
  public:
    int countSubs(string& s) {
        int n = (int)s.size();
        if (n == 0) return 0;

        
        vector<vector<int>> lcp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s[i] == s[j]) lcp[i][j] = 1 + lcp[i + 1][j + 1];
                else lcp[i][j] = 0;
            }
        }

        long long distinct = 0;
        for (int i = 0; i < n; ++i) {
            int max_lcp = 0;
            for (int j = 0; j < i; ++j) {
                if (lcp[j][i] > max_lcp) max_lcp = lcp[j][i];
            }
         
            distinct += (n - i) - max_lcp;
        }

        return (int)distinct;
    }
};

