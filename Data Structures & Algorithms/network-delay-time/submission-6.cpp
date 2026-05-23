class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i: times) {
            int dist = i[2];
            int node = i[1];
            adj[i[0]].emplace_back(make_pair(dist, node));
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        dist[0] = 0;

        for(auto i: adj[k]) {
            dist[i.second] = i.first;
            pq.push(i);
        }

        while(!pq.empty()) {
            auto i = pq.top();
            pq.pop();
            int oldDist = i.first;
            for(auto &neigh: adj[i.second]) {
                int newDist = neigh.first;
                if(dist[neigh.second] > oldDist+newDist) {
                    dist[neigh.second] = oldDist+newDist;
                    pq.push(make_pair(oldDist+newDist, neigh.second));
                }
            }
        }
        int res = -1;
        for(auto i: dist) {
            if(i == INT_MAX) return -1;
            res = max(res, i);
        }
        return res;
    }
};
