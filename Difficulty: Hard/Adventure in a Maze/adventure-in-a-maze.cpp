class Solution {
  public:
    vector<int> findWays(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int n = grid.size();

        vector<int> nextWays(n, 0);

        vector<int> nextAdv(n, -1);

        for (int i = n - 1; i >= 0; i--) {
            vector<int> currWays(n, 0);
            vector<int> currAdv(n, -1);

            for (int j = n - 1; j >= 0; j--) {
                if (i == n - 1 && j == n - 1) {
                    currWays[j] = 1;
                    currAdv[j] = grid[i][j];
                    continue;
                }

                long long totalWays = 0;
                int maxAdventure = -1;
                int cellValue = grid[i][j];

                if (cellValue == 1 || cellValue == 3) {
                    if (j + 1 < n && currAdv[j + 1] != -1) {
                        totalWays = (totalWays + currWays[j + 1]) % MOD;
                        maxAdventure = max(maxAdventure, grid[i][j] + currAdv[j + 1]);
                    }
                }

                if (cellValue == 2 || cellValue == 3) {

                    if (i + 1 < n && nextAdv[j] != -1) {
                        totalWays = (totalWays + nextWays[j]) % MOD;
                        maxAdventure = max(maxAdventure, grid[i][j] + nextAdv[j]);
                    }
                }

                currWays[j] = totalWays;
                currAdv[j] = maxAdventure; 
            }

            nextWays = move(currWays);
            nextAdv = move(currAdv);
        }

        int finalPaths = nextWays[0];
        int finalAdv = (nextAdv[0] == -1) ? 0 : nextAdv[0];

        return {finalPaths, finalAdv};
    }
};