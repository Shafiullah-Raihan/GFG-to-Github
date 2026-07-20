class Solution {
  public:

    void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited) {
        visited[node] = true;

        for (int neigh : adjList[node]) {
            if (!visited[neigh]) {
                dfs(neigh, adjList, visited);
            }
        }
    }

    int countConnected(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adjList(V);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<bool> visited(V, false);
        int components = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adjList, visited);
                components++;
            }
        }

        return components;
    }
};