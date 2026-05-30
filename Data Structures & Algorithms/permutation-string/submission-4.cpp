class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> count(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }

        int diff = 0;
        for (int x : count) if (x != 0) diff++;

        for (int r = s1.length(); r < s2.length(); r++) {
            if (diff == 0) return true;

            int in = s2[r] - 'a';
            if (--count[in] == 0) diff--; else if (count[in] == -1) diff++;

            int out = s2[r - s1.length()] - 'a';
            if (++count[out] == 0) diff--; else if (count[out] == 1) diff++;
        }

        return diff == 0;
    }
};