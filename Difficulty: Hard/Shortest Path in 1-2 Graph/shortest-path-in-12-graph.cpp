class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {

        int extra = V;

        vector<vector<int>> adj(V + edges.size());

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if (wt == 1) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            } else {
               
                adj[u].push_back(extra);
                adj[extra].push_back(v);

                adj[v].push_back(extra);
                adj[extra].push_back(u);

                extra++;
            }
        }

       
        vector<int> dist(extra, -1);

        queue<int> q;
        q.push(src);
        dist[src] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == dest)
                return dist[node];

            for (int nxt : adj[node]) {
                if (dist[nxt] == -1) {
                    dist[nxt] = dist[node] + 1;
                    q.push(nxt);
                }
            }
        }

        return -1;
    }
};