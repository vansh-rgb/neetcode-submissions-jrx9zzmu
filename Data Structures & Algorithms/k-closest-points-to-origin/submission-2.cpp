class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;

        for(int i=0;i<points.size();i++) {
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.emplace(make_pair(dist, i));
        }
        vector<vector<int>> res;
        while(k--) {
            auto t = pq.top();
            res.push_back({points[t.second][0],points[t.second][1]});
            pq.pop();
        }
        return res;
    }
};
