class Solution {
public:
    unordered_map<string, int> m;
    int helper(string s, string t, int i, int j, int sn, int tn) {
        string str = to_string(i)+"_"+to_string(j);
        if(m.find(str)!=m.end()) return m[str];
        if(j == tn) return m[str] = 1;
        if(i == sn) return m[str] = 0;
        int take = 0;
        int notTake = 0;
        if(s[i] == t[j]) {
            take = helper(s, t, i+1, j+1, sn, tn);
        }
        notTake = helper(s, t, i+1, j, sn, tn);
        return m[str] = take+notTake;
    }
    int numDistinct(string s, string t) {
        int sn = s.size();
        int tn = t.size();
        return helper(s, t, 0, 0, sn, tn);
    }
};