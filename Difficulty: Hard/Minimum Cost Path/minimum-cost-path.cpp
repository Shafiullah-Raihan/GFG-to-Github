
class Solution
{
    public:
    long long inf = 1e10;
    int dx[4] = { 0, 0, 1, -1, };
    int dy[4] = { 1, -1, 0, 0 };
    
    bool isValid(int x,int y ,int n){
       return (x>=0 && x<n && y>=0 && y<n);
        
    }
    
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<long long>> dist(n,vector<long long>(n,inf));
        
        
        dist[0][0] = grid[0][0] ;
        
        priority_queue<pair<long long , pair<int,int>>, vector<pair<long long , pair<int,int>>> , greater<pair<long long , pair<int,int>>>> pq;
        pq.push({dist[0][0],{0,0}});
        while(!pq.empty()){
            pair<int,int> u = pq.top().second;
            long long curD = pq.top().first;
            int x = u.first, y = u.second;
            pq.pop();
            if(dist[x][y] <curD) continue;
            
            
            for(int i=0;i<4;i++){
                int x1 = x + dx[i] , y1 = y + dy[i];
                if(isValid(x1,y1,n) && curD+ grid[x1][y1]<dist[x1][y1]){
                    dist[x1][y1] = curD + grid[x1][y1];
                    pq.push({dist[x1][y1] , {x1,y1}});
                }
            }
            
            
        }
        
        return dist[n-1][n-1];
        
        
        
    }
};










