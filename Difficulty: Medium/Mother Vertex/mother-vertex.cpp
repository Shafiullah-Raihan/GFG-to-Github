class Solution {
  public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis) {
    
        vis[u] = true;

       
        for (auto v : adj[u]) {
           
            if (!vis[v])
                dfs(v, adj, vis);
        }
    }


    int findMotherVertex(int V, vector<vector<int>>& edges) {

        vector<bool> vis(V, false);

        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        int v;

        for (int i = 0; i < V; i++) {

            if (!vis[i]) {
                dfs(i, adj, vis);
                v = i;
            }
        }

       
        vis.assign(V, false);

       
        dfs(v, adj, vis);

        
        for (auto i : vis)
            if (!i)
                return -1;

    
        return v;
    }
};