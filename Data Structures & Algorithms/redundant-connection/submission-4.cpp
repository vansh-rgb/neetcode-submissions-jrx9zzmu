class Solution {
public:
    int find(int node, vector<int> &par) {
        while(node!=par[node]) {
            par[node] = par[par[node]];
            node = par[node];
        }
        return node;
    }
    int unionFind(int n1, int n2, vector<int> &par, vector<int> &rank) {
        int p1 = find(n1, par);
        int p2 = find(n2, par);

        if(p1 == p2) return false;

        if(rank[p2]>rank[p1]) swap(p1, p2);

        par[p2] = p1;
        rank[p1]+=rank[p2];
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par;

        vector<int> rank(n+1, 1);

        for(int i=0;i<=n;i++) {
            par.emplace_back(i);
        }

        for(auto edge: edges) {
            if(!unionFind(edge[0], edge[1], par, rank)) {
                return edge;
            }
        }
        return {};
    }
};
