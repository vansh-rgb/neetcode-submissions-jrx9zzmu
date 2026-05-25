class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &state) {
        if(state[node] == 1) return false; // cycle
        if(state[node] == 2) return true;  // already safe

        state[node] = 1;
        for(int nei : adj[node])
            if(!dfs(nei, adj, state)) return false;
        state[node] = 2;
        return true;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto &pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);

        vector<int> state(n, 0);
        for(int i = 0; i < n; i++)
            if(!dfs(i, adj, state)) return false;
        return true;
    }
};