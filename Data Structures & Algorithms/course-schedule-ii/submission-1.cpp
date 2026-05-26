class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for(auto i: prerequisites) {
            indegree[i[0]]++;
            adj[i[1]].emplace_back(i[0]);
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++) {
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> res;
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            res.emplace_back(node);
            for(auto neigh: adj[node]) {
                indegree[neigh]--;
                if(indegree[neigh] == 0) q.push(neigh);
            }
        }
        if(res.size() == numCourses) return res;
        return {};
    }
};
