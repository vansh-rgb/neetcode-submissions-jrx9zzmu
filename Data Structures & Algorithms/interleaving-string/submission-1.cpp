class Solution {
public:
    unordered_map<string, bool> m;
    bool helper(string s1, string s2, string s3, int n1, int n2, int n3, int l, int r, int i) {
        string ret = to_string(l) + to_string(r);
        if(m.find(ret)!= m.end()) return m[ret];
        if(i == n3 && l == n1 && r == n2) return m[ret] = true;
        if(i == n3 && (l < n1 || r < n2)) return m[ret] = false;


        bool left = false;
        bool right = false;
        if(l < n1 && s3[i] == s1[l]) left = helper(s1, s2, s3, n1, n2, n3, l+1, r, i+1);
        if(r < n2 && s3[i] == s2[r]) right = helper(s1, s2, s3, n1, n2, n3, l, r+1, i+1);
        return m[ret] = (left || right);

    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        return helper(s1, s2, s3, n1, n2, n3, 0, 0, 0);
    }
};
