class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adj(V);
        
        // Build adjacency list
        for (auto& it : prerequisites) {
            adj[it[1]].push_back(it[0]); // Note: Edge direction is [a, b] means b -> a
        }
        
        // Compute indegree
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto& neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        // Queue for nodes with 0 indegree
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo; // Stores topological order
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto& neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If topological sort includes all courses, return true
        return topo.size() == V;
    }
};
