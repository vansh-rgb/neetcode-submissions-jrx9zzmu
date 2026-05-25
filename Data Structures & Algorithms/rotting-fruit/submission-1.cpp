class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                } else if(grid[i][j] == 1) fresh++;
            }
        }   
        int maxTime = 0;

        vector<vector<int>> dirs = {{-1,0}, {1, 0}, {0, 1}, {0, -1}};

        while(fresh > 0 && !q.empty()) {
            int len = q.size();
            while(len--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int i=0;i<4;i++) {
                    int r = row+dirs[i][0];
                    int c = col+dirs[i][1];

                    if(r<0 || r>=n || c<0 || c>=m || grid[r][c]!=1) continue;

                    grid[r][c] = 2;
                    q.push({r, c});
                    fresh--;
                }
            }
            maxTime++;
        }
        return fresh == 0 ? maxTime: -1;
    }
};
