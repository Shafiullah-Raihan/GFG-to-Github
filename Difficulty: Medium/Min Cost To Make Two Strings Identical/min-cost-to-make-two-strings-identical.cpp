class Solution {
  public:

    int lcs(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // If characters match, include this character in LCS.
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = prev[j - 1] + 1;

                // Otherwise, skip one character from either string.
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }

            // Move current row to previous row.
            prev = curr;
        }

        return prev[m];
    }

    int findMinCost(string &s1, string &s2, int costS1, int costS2) {

        int n = s1.size();
        int m = s2.size();

        if (m > n) {
            swap(s1, s2);
            swap(costS1, costS2);
            swap(n, m);
        }


        int lcsLength = lcs(s1, s2);

        int deleteFromS1 = n - lcsLength;
        int deleteFromS2 = m - lcsLength;

        return deleteFromS1 * costS1 + deleteFromS2 * costS2;
    }
};