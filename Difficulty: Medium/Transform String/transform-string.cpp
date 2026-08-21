class Solution {
  public:
    int transform(string &s1, string &s2) {

        if (s1.length() != s2.length())
            return -1;

        unordered_map<char, int> freq;

        int n = s1.length();

        for (int i = 0; i < n; i++) {
            freq[s1[i]]++;
        }

        for (int i = 0; i < n; i++) {
            freq[s2[i]]--;
        }

        for (auto &p : freq) {
            if (p.second != 0)
                return -1;
        }

        int i = n - 1;
        int j = n - 1;

        int operations = 0;

        while (i >= 0 && j >= 0) {

            while (i >= 0 && s1[i] != s2[j]) {
                i--;
                operations++;
            }

            if (i >= 0) {
                i--;
                j--;
            }
        }

        return operations;
    }
};