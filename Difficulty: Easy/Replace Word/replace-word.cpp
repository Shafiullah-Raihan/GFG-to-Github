class Solution {
  public:
    vector<int> buildLps(string& s1) {
        int n = s1.size();
        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;

        // Build longest prefix suffix array for KMP.
        while (i < n) {
            if (s1[i] == s1[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    string replaceAll(string& s, string& s1, string& s2) {
        if (s1.empty()) {
            return s;
        }

        vector<int> lps = buildLps(s1);

        int i = 0;
        int j = 0;
        int last = 0;
        int n = s.size();
        int m = s1.size();

        string res = "";

        while (i < n) {
            if (s[i] == s1[j]) {
                i++;
                j++;
            }

            if (j == m) {
                int start = i - m;

                // Add text before matched pattern.
                res += s.substr(last, start - last);

                // Replace matched pattern with s2.
                res += s2;

                last = i;
                j = 0;
            } else if (i < n && s[i] != s1[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        res += s.substr(last);

        return res;
    }
};