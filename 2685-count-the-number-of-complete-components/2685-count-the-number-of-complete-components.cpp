class Solution {
public:
    bool isConnectedComp(int src, int n, vector<int> adj[],
                         vector<int>& visited) {
        queue<int> q;
        q.push(src);
        visited[src] = 1;

        int node = 1;
        int edgeNumber = 0;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            edgeNumber += adj[top].size();
            for (auto child : adj[top]) {
                if (visited[child] == 0) {
                    q.push(child);
                    visited[child] = 1;
                    node++;
                }
            }
        }

        return edgeNumber / 2 == node * (node - 1) / 2;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (isConnectedComp(i, n, adj, visited)) {
                    count++;
                }
            }
        }
        return count;
    }
};