
int dx[] = { 0, 0, +1, -1, -1,  +1, -1, +1 };
int dy[] = { +1, -1, 0, 0, -1, +1, +1, -1 };

class Solution {
  public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int newColor) {
        // Code here
        int n=image.size(),m = image[0].size();
        vector<vector<bool>>dp(n,vector<bool>(m,false));
        int origiColor = image[sr][sc];
        if (origiColor == newColor) return image;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        dp[sr][sc] = true;
        while(!q.empty())
        {
            auto it = q.front();
            int x = it.first,y=it.second;
            image[x][y] = newColor;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x1 = x + dx[i], y1 = y + dy[i];
                if(x1>=n || x1<0 || y1 >=m || y1<0) continue;
                if(!dp[x1][y1] && image[x1][y1] == origiColor)
                {
                    dp[x1][y1] = true;
                    //image[x1][y1] = newColor;
                    q.push({x1,y1});
                }
            }
            
        }
        
        return image;
        
    }
};

