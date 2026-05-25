class Solution {
public:
    void dfs(int curr, int parent, vector<vector<int>> &adj, vector<bool> &visited) {
        visited[curr] = true;

        for(auto i: adj[curr]) {
            if(parent == i) continue;
            if(visited[i]) continue;

            dfs(i, curr, adj, visited);
        }

    }


    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        int count = 0;
        for(auto i: edges) {
            adj[i[0]].emplace_back(i[1]);
            adj[i[1]].emplace_back(i[0]);
        }

        for(int i=0;i<n;i++) {
            if(visited[i]) continue;

            dfs(i, -1, adj, visited);
            count++;
        }

        return count;
    }
};
