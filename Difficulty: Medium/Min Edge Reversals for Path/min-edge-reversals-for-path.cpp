class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // Original edge has zero reversal cost.
            adj[u].push_back({v, 0});

            // Reversed edge costs one reversal.
            adj[v].push_back({u, 1});
        }

        deque<int> dq;
        vector<int> dist(n + 1, INT_MAX);

        dist[src] = 0;
        dq.push_front(src);

        while (!dq.empty()) {
            int node = dq.front();
            dq.pop_front();

            for (auto &[next, wt] : adj[node]) {
                if (dist[node] + wt < dist[next]) {
                    dist[next] = dist[node] + wt;

                    // Prioritize zero-cost edges in 0-1 BFS.
                    if (wt == 0)
                        dq.push_front(next);
                    else
                        dq.push_back(next);
                }
            }
        }

        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};