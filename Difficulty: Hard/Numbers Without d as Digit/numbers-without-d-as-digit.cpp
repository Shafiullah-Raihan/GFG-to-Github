class Solution {
  public:
    int countWithout(int n, int d) {
        if (n <= 0)
            return 0;

        string s = to_string(n);
        int length = s.length();


        int dp[2][2];

    
        for (int tight = 0; tight < 2; tight++)
            for (int started = 0; started < 2; started++)
                dp[tight][started] = started;

        for (int pos = length - 1; pos >= 0; pos--) {
            int newDp[2][2] = {0};

            for (int tight = 0; tight < 2; tight++) {
                for (int started = 0; started < 2; started++) {
                    int limit = tight ? (s[pos] - '0') : 9;
                    int total = 0;

                    for (int digit = 0; digit <= limit; digit++) {
                        int willStart = started || (digit != 0);

                        if (willStart && digit == d)
                            continue;

                        int newTight = tight && (digit == limit);
                        total += dp[newTight][willStart];
                    }

                    newDp[tight][started] = total;
                }
            }

            memcpy(dp, newDp, sizeof(dp));
        }

        return dp[1][0];
    }
};