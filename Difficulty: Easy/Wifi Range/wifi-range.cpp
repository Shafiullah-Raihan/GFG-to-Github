class Solution {
  public:
    bool wifiRange(string &s, int x) {
        // code here
        int n = s.length();

    // left[i]  -> nearest wifi index on left
    // right[i] -> nearest wifi index on right
    vector<int> left(n, -1e9), right(n, 1e9);

    int last = -1e9;

    // fill nearest left wifi
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            last = i;
        }
        left[i] = last;
    }

    last = 1e9;

    // fill nearest right wifi
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            last = i;
        }
        right[i] = last;
    }

    // check coverage
    for (int i = 0; i < n; i++) {
        if (abs(i - left[i]) > x && 
            abs(i - right[i]) > x) {
            return false;
        }
    }

    return true;
        
    }
};