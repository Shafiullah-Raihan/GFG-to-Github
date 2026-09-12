#define pii pair<int,int>
class Solution {
  public:
    pii bfs(vector<vector<int>>& adj,int src)
    {
        int n= adj.size();
        vector<int>dist(n,-1);
        int lastNode=src,mxdist=0;
        queue<int>q;
        q.push(src);
        dist[src]= 0;
        while(!q.empty())
        {
            int node = q.front();q.pop();
            for(auto child: adj[node])
            {
                child--;
                if(dist[child] == -1)
                {
                    dist[child] = 1 + dist[node];
                    if(mxdist<dist[child])
                    {
                        lastNode = child;
                        mxdist = dist[child];
                    }
                    
                    q.push(child);
                }
            }
            
        }
        return {lastNode,mxdist};
        
    }
    int partyHouse(vector<vector<int>> &adj) {
        // code here
        pii f = bfs(adj,0);
        int node = f.first;int mx = f.second;
        pii s = bfs(adj,node);
        int node2 = s.first;int mx2 = s.second;
        return (mx2+1)/2;
        
        
    }
};










