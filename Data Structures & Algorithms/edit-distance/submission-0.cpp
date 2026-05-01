class Solution {
public:

    int helper(string &word1, string &word2, int n, int m, int i, int j, vector<vector<int>> &dp) {
        if(i == n) return m-j;
        if(j == m) return n-i;

        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i] == word2[j]) {
            return helper(word1, word2, n, m, i+1, j+1, dp);
        }

        int res = min(helper(word1, word2, n, m, i+1, j, dp), helper(word1, word2, n, m, i, j+1, dp));

        res = min(res, helper(word1, word2, n, m, i+1, j+1, dp));

        return dp[i][j] = res+1;

    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return helper(word1, word2, n, m, 0, 0, dp);
    }
};
