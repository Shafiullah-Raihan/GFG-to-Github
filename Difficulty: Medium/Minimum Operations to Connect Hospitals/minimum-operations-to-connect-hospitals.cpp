class Solution {
  public:
    const int mx = 1000+12;
    vector<bool>vis;
    //vector<int>ans;
    void dfs(vector<vector<int>>& adj,int src)
    {
        vis[src]= true;
        for(auto child: adj[src])
        {
            if(!vis[child])
            {
                dfs(adj,child);
            }
        }
    }
  
    int minConnect(int n, vector<vector<int>>& edges) {
        // Code here
        int totalEdge=0;
        vector<vector<int>> adj(n);
        for(auto u: edges)
        {
            adj[u[0]].push_back(u[1]);
            adj[u[1]].push_back(u[0]);
        }
        for(int i=0;i<n;i++)
        {
            totalEdge += adj[i].size();
        }
        totalEdge /=2;
        int component=0;
        vis.assign(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(adj,i);
                component++;
            }
        }
        
        if(totalEdge<n-1) return -1;
        int extra = totalEdge - n + component;
        if(extra>=(component-1)) return component-1;
        return -1;
        
        
    }
};
