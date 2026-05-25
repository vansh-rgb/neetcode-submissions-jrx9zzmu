class Solution {
public:
    int find(int node, vector<int> &par, vector<int> &rank) {
        while(node!=par[node]) {
            par[node] = par[par[node]];
            node = par[node];
        }
        return node;
    }

    bool unionFind(int n1, int n2, vector<int> &par, vector<int> &rank) {
        int par1 = find(n1, par, rank);
        int par2 = find(n2, par, rank);

        if(par1 == par2) return false;

        if(rank[par2]>rank[par1]) swap(par1, par2);

        par[par2] = par1;
        rank[par1] += rank[par2];
        return true;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> par;
        vector<int> rank(n,1);

        for(int i=0;i<n;i++) {
            par.emplace_back(i);
        }

        int res = n;

        for(auto edge: edges) {
            if(unionFind(edge[0], edge[1], par, rank)) {
                res--;
            }
        }
        return res;
    }
};
