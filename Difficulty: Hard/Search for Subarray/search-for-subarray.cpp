

class Solution {
public:
    void constructLps(const vector<int> &pat, vector<int> &lps) {
        int m = pat.size();
        lps.assign(m, 0);
        int len = 0;
        int i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
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
    }

    vector<int> search(const vector<int> &a, const vector<int> &b) {
        vector<int> res;
        int n = a.size();
        int m = b.size();
        if (m == 0) return res;            
        if (n == 0 || n < m) return res;   

        vector<int> lps;
        constructLps(b, lps);

        int i = 0; 
        int j = 0; 

        while (i < n) {
            if (a[i] == b[j]) {
                i++; j++;
                if (j == m) {
                    res.push_back(i - j);
                    j = lps[j - 1];
                }
            } else {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }
        return res;
    }
};