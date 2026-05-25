class Solution {
public:
    bool dfs(int curr, int parent, vector<vector<int>> &adj, vector<bool> &visited) {
        visited[curr] = true;

        for(auto i: adj[curr]) {
            if(i == parent) continue;
            if(visited[i]) return true;

            if(dfs(i, curr, adj, visited)) return true;
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        int count = 0;
        for(auto i: edges) {
            adj[i[0]].emplace_back(i[1]);
            adj[i[1]].emplace_back(i[0]);
            count++;
        }
        if(count != n-1) return false;
        for(int i=0;i<n;i++) {
            if(visited[i]) continue;

            if(dfs(i, -1, adj, visited)) return false;
        }

        return true;
    }
};
