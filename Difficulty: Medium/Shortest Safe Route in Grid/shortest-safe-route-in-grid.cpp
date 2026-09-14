class Solution {
  public:

    int dx[4] = {-1, 0, 0, 1};

    int dy[4] = {0, -1, 1, 0};

    int shortestPath(vector<vector<int>> &mat) {
        int n = mat.size();
        if (n == 0)
            return -1;
        int m = mat[0].size();
        if (m == 0)
            return -1;

        queue<array<int, 3>> q;

        vector<vector<int>> d(n, vector<int>(m, 1e9));

        auto isValid = [&](int i, int j) ->bool {
            return (i >= 0 && i < n && j >= 0 && j < m);
        };

        auto check = [&](int i, int j) {
            if (!isValid(i, j))
                return false;

            if (mat[i][j] == 0)
                return false;

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (isValid(nx, ny) && mat[nx][ny] == 0) {
                    return false;
                }
            }
            return true;
        };

        for (int i = 0; i < n; i++) {
            if (check(i, m - 1)) {
                q.push({i, m - 1, 1});

                d[i][m - 1] = 1;
            }
        }

        while (!q.empty()) {
            auto z = q.front();
            int x = z[0], y = z[1], dis = z[2];
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (check(nx, ny) && d[nx][ny] > dis + 1) {
                    d[nx][ny] = dis + 1; 
                    q.push({nx, ny, dis + 1});
                }
            }
        }

        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            ans = min(ans, d[i][0]);
        }

        return (ans >= 1e9) ? -1 : ans;
    }
};