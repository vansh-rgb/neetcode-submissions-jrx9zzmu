class Solution {
public:
    bool helper(string s, vector<string>& wordDict, int n, int ind, vector<int> &dp) {
        if(ind == n) return true;
        if(ind > n) return false;
        if(dp[ind] != -1) return dp[ind]; 
        for(int i = 0; i<wordDict.size(); i++) {
            if(ind + wordDict[i].size() > n)  {
                dp[ind] = false;
                continue;
            }
            if(matcher(wordDict[i], s, ind)) {
                if(helper(s, wordDict, n, ind+wordDict[i].size(), dp)) {
                    return dp[ind] = true;
                }
            }
        }
        return dp[ind] = false;
    }
    bool matcher(string wordToMatch, string target, int ind) {
        for(int i=0;i<wordToMatch.size();i++) {
            if(wordToMatch[i] != target[ind+i]) return false;
        }
        return true;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        return helper(s, wordDict, n, 0, dp);
    }
};
