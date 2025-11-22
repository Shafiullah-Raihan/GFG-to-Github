class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(n);
        for(auto e: edges)
        {
            int u = e[0], v = e[1], dis=e[2];
            adj[u].push_back({v,dis});
            adj[v].push_back({u,dis});
        }
        
        vector<int> path(n,0);
        vector<int> minTime(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        minTime[0]=0,path[0]=1;
        
        
        while(!pq.empty())
        {
            
            auto tp=pq.top();pq.pop();
            int node = tp.second, currTime = tp.first;
            if(currTime>minTime[node]) continue;
            for(auto u: adj[node])
            {
                int child = u.first,childTime = u.second;
                int newTime = currTime+childTime;
                
                if(newTime< minTime[child])
                {
                    minTime[child] = newTime;
                    path[child] = path[node];
                    pq.push({newTime,child});
                }
                else if(newTime == minTime[child])
                {
                    path[child] += path[node];
                }
                
            }
            
            
        }
        return path[n-1];
        
        
        
    }
};