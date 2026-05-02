class Solution {
public:
    bool helper(string &s, string &p, int n, int m, 
    int i, int j, vector<vector<int>> &dp) {

        if(j == m) {
            return i==n;
        }

        bool charMatch = false;
        if(dp[i][j] != -1) return dp[i][j];

        if(i < n && (p[j] == '.' || p[j] == s[i])) {
            charMatch = true;
        }

        bool take = false;
        bool notTake = false;
        if(p[j+1] == '*') {
            notTake = helper(s, p, n, m, i, j+2, dp);
            take = charMatch && helper(s, p, n, m, i+1, j, dp);

            return dp[i][j] = take || notTake;
        }

        return dp[i][j] = charMatch && helper(s, p, n, m, i+1, j+1, dp);
    }
    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return helper(s, p, n, m, 0, 0, dp); 
    }
};
