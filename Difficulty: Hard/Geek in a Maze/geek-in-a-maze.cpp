class Solution {
  public:
    bool isValid(int row, int col, int n, int m) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }

    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {

        int n = mat.size();
        if (n == 0) {
            return 0;
        }

        int m = mat[0].size();

        if (r < 0 || r >= n || c < 0 || c >= m) {
            return 0;
        }

        if (mat[r][c] == '#') {
            return 0;
        }

        priority_queue<pair<pair<int, int>, pair<int, int>>,vector<pair<pair<int, int>, pair<int, int>>>,greater<pair<pair<int, int>, pair<int, int>>>>pq;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        pq.push({{0, 0}, {r, c}});
        vis[r][c] = true;

        while (!pq.empty()) {

            int up = pq.top().first.first;
            int down = pq.top().first.second;

            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();

            if (isValid(x - 1, y, n, m) && !vis[x - 1][y] && mat[x - 1][y] == '.' &&
                up + 1 <= u) {

                vis[x - 1][y] = true;
                pq.push({{up + 1, down}, {x - 1, y}});
            }

            if (isValid(x + 1, y, n, m) && !vis[x + 1][y] && mat[x + 1][y] == '.' &&
                down + 1 <= d) {

                vis[x + 1][y] = true;
                pq.push({{up, down + 1}, {x + 1, y}});
            }

            if (isValid(x, y - 1, n, m) && !vis[x][y - 1] && mat[x][y - 1] == '.') {

                vis[x][y - 1] = true;
                pq.push({{up, down}, {x, y - 1}});
            }

            if (isValid(x, y + 1, n, m) && !vis[x][y + 1] && mat[x][y + 1] == '.') {

                vis[x][y + 1] = true;
                pq.push({{up, down}, {x, y + 1}});
            }
        }

        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res += vis[i][j];
            }
        }

        return res;
    }
};